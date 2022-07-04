#pragma once

#include <gui/view.h>
#include "desktop_events.h"
#include "../desktop_settings/desktop_settings.h"

typedef struct DesktopDumbView DesktopDumbView;

typedef void (*DesktopDumbViewCallback)(DesktopEvent event, void* context);

void desktop_Dumb_set_callback(
    DesktopDumbView* Dumb_view,
    DesktopDumbViewCallback callback,
    void* context);

View* desktop_Dumb_get_view(DesktopDumbView* Dumb_view);
DesktopDumbView* desktop_Dumb_alloc();
void desktop_Dumb_free(DesktopDumbView* Dumb_view);


typedef struct DesktopViewDumb DesktopViewDumb;

typedef void (*DesktopViewDumbCallback)(DesktopEvent event, void* context);

void desktop_view_Dumb_set_callback(
    DesktopViewDumb* dumb_view,
    DesktopViewDumbCallback callback,
    void* context);
void desktop_view_dumb_update(DesktopViewDumb* dumb_view);
View* desktop_view_dumb_get_view(DesktopViewDumb* dumb_view);
DesktopViewDumb* desktop_view_Dumb_alloc();
void desktop_view_dumb_free(DesktopViewDumb* dumb_view);
void desktop_view_dumb_lock(DesktopViewDumb* dumb_view, bool pin_dumb);
void desktop_view_dumb_unlock(DesktopViewDumb* dumb_view);
void desktop_view_dumb_close_doors(DesktopViewDumb* dumb_view);

//* 
//
//Attempted implementation of dumb mode.
//
//"DUMB MODE"
//        DESKTOP LOOKS THE SAME WITH BATTERY AND IDLE ANIMATION
//        HOLD BACK TO TURN OFF
//        HOLD CENTER TO CHANGE IDLE ANIMATION
//        HOLD RIGHT TO ENTER PIN IF SET AND EXIT DUMB MODE
//        PRESS UP FOR FAVORITE GAME
//        PRESS CENTER FOR GAMES MENU
//        PRESS LEFT FOR CLOCK
//        EXIT GAME GOES BACK TO DUMB MODE
//        RESTARTING REMEMBERS YOU ARE IN DUMB MODE LIKE IT REMEMBERS IF YOU WERE LOCKED