#pragma once

typedef enum {
    DesktopMainEventOpenLockMenu,
    DesktopMainEventOpenArchive,
    DesktopMainEventOpenFavoritePrimary,
    DesktopMainEventOpenFavoriteSecondary,
    DesktopMainEventOpenFavoriteGame,
    DesktopMainEventOpenMenu,
    DesktopMainEventOpenDebug,
    DesktopMainEventOpenPassport, /**< Broken, don't use it */
    DesktopMainEventOpenPowerOff,

    DesktopLockedEventUnlocked,
    DesktopLockedEventUpdate,
    DesktopLockedEventShowPinInput,

    DesktopPinInputEventResetWrongPinLabel,
    DesktopPinInputEventUnlocked,
    DesktopPinInputEventUnlockFailed,
    DesktopPinInputEventBack,

    DesktopPinTimeoutExit,

    DesktopDebugEventDeed,
    DesktopDebugEventWrongDeed,
    DesktopDebugEventSaveState,
    DesktopDebugEventExit,

    DesktopLockMenuEventLock,
    DesktopLockMenuEventPinLock,
    DesktopLockMenuEventExit,

    DesktopAnimationEventCheckAnimation,
    DesktopAnimationEventNewIdleAnimation,
    DesktopAnimationEventInteractAnimation,

    DesktopSlideshowCompleted,


    // TESTING DUMB MODE THIS DOESN'T WORK YET
    DesktopDumbEventOpenLockMenu,
    DesktopDumbEventOpenArchive,
    DesktopDumbEventOpenFavoritePrimary,
    DesktopDumbEventOpenFavoriteSecondary,
    DesktopDumbEventOpenFavoriteGame,
    DesktopDumbEventOpenMenu,
    DesktopDumbEventOpenDebug,
    DesktopDumbEventOpenPassport, /**< Broken, don't use it */
    DesktopDumbEventOpenPowerOff,

    // Global events
    DesktopGlobalBeforeAppStarted,
    DesktopGlobalAfterAppFinished,
    DesktopGlobalAutoLock,
} DesktopEvent;
