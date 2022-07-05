#include <gui/gui_i.h>
#include <gui/view.h>
#include <gui/elements.h>
#include <gui/canvas.h>
#include <furi.h>
#include <input/input.h>
#include <dolphin/dolphin.h>

#include "../desktop_i.h"
#include "desktop_view_main.h"

struct DesktopDumbView {
    View* view;
    DesktopDumbViewCallback callback;
    void* context;
    TimerHandle_t poweroff_timer;
};

#define DESKTOP_MAIN_VIEW_POWEROFF_TIMEOUT 5000

static void desktop_main_poweroff_timer_callback(TimerHandle_t timer) {
    DesktopDumbView* dumb_view = pvTimerGetTimerID(timer);
    dumb_view->callback(DesktopMainEventOpenPowerOff, dumb_view->context);
}

void desktop_dumb_set_callback(
    DesktopDumbView* dumb_view,
    DesktopDumbViewCallback callback,
    void* context) {
    furi_assert(dumb_view);
    furi_assert(callback);
    dumb_view->callback = callback;
    dumb_view->context = context;
}

View* desktop_dumb_get_view(DesktopDumbView* dumb_view) {
    furi_assert(dumb_view);
    return dumb_view->view;
}

bool desktop_dumb_input(InputEvent* event, void* context) {
    furi_assert(event);
    furi_assert(context);

    DesktopDumbView* dumb_view = context;

    if(event->type == InputTypeShort) {
        if(event->key == InputKeyOk) {
            dumb_view->callback(DesktopMainEventOpenMenu, dumb_view->context);
        } else if(event->key == InputKeyUp) {
            dumb_view->callback(DesktopMainEventOpenLockMenu, dumb_view->context);
        } else if(event->key == InputKeyDown) {
            dumb_view->callback(DesktopMainEventOpenArchive, dumb_view->context);
        } else if(event->key == InputKeyLeft) {
            dumb_view->callback(DesktopMainEventOpenFavoritePrimary, dumb_view->context);
        } else if(event->key == InputKeyRight) {
            dumb_view->callback(DesktopMainEventOpenPassport, dumb_view->context);
        }
    } else if(event->type == InputTypeLong) {
        if(event->key == InputKeyDown) {
            dumb_view->callback(DesktopMainEventOpenDebug, dumb_view->context);
        } else if(event->key == InputKeyLeft) {
            dumb_view->callback(DesktopMainEventOpenFavoriteSecondary, dumb_view->context);
        } else if(event->key == InputKeyUp) {
            dumb_view->callback(DesktopMainEventOpenFavoriteGame, dumb_view->context);
        } else if (event->key == InputKeyOk) {
            dumb_view->callback(DesktopAnimationEventNewIdleAnimation, dumb_view->context);
        }
    }

    if(event->key == InputKeyBack) {
        if(event->type == InputTypePress) {
            xTimerChangePeriod(
                dumb_view->poweroff_timer,
                pdMS_TO_TICKS(DESKTOP_MAIN_VIEW_POWEROFF_TIMEOUT),
                portMAX_DELAY);
        } else if(event->type == InputTypeRelease) {
            xTimerStop(dumb_view->poweroff_timer, portMAX_DELAY);
        }
    }

    return true;
}

DesktopDumbView* desktop_dumb_alloc() {
    DesktopDumbView* dumb_view = malloc(sizeof(DesktopDumbView));

    dumb_view->view = view_alloc();
    view_allocate_model(dumb_view->view, ViewModelTypeLockFree, 1);
    view_set_context(dumb_view->view, dumb_view);
    view_set_input_callback(dumb_view->view, desktop_dumb_input);

    dumb_view->poweroff_timer = xTimerCreate(
        NULL,
        pdMS_TO_TICKS(DESKTOP_MAIN_VIEW_POWEROFF_TIMEOUT),
        pdFALSE,
        dumb_view,
        desktop_main_poweroff_timer_callback);

    return dumb_view;
}

void desktop_dumb_free(DesktopDumbView* dumb_view) {
    furi_assert(dumb_view);
    view_free(dumb_view->view);
    osTimerDelete(dumb_view->poweroff_timer);
    free(dumb_view);
}
