#pragma once

// =============================================================================
// HARDWARE & SYSTEM
// =============================================================================

#define DEBOUNCE 15
#define ENCODER_RESOLUTION 2

// Recommended for heavy chording
#define QMK_KEYS_PER_SCAN 4

#define NO_MUSIC_MODE
#define LAYER_STATE_16BIT

// =============================================================================
// DEBUGGING
// =============================================================================

#ifndef NO_DEBUG
#define NO_DEBUG
#endif // !NO_DEBUG

#if !defined(NO_PRINT) && !defined(CONSOLE_ENABLE)
#define NO_PRINT
#endif // !NO_PRINT

// =============================================================================
// TAP-HOLD CONFIGURATION
// =============================================================================

// Cusotm implementation of adaptive key behaviour
// #define ADAPTIVE_KEYS_ENABLED

#define TAPPING_TERM 200
#define TAPPING_TERM_PER_KEY

// Quick Tap Term - Without this: Quick Double Tapping makes Autorepeat
#define QUICK_TAP_TERM 90
#define QUICK_TAP_TERM_PER_KEY
// #define QUICK_TAP_TERM

// If key is pressed quickly and released while Tap-Hold button is pressed: do hold action
#define PERMISSIVE_HOLD
// #define PERMISSIVE_HOLD_PER_KEY

// Immediately activate hold when another key is pressed (per-key for thumb keys)
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY

// Bilateral Combos for Shift (Homerow Rollover)
// #define BILATERAL_COMBINATIONS 100

// =============================================================================
// COMBO CONFIGURATION
// =============================================================================

#ifdef COMBO_ENABLE
  #define COMBO_VARIABLE_LEN
  #define COMBO_COUNT COMBO_VARIABLE_LEN
  #define COMBO_TERM 40
  #define COMBO_TERM_PER_COMBO
  #define COMBO_MUST_PRESS_IN_ORDER
  #define COMBO_MUST_PRESS_IN_ORDER_PER_COMBO
  #define COMBO_MUST_TAP_PER_COMBO
#endif

// =============================================================================
// LEADER KEY & LAYER LOCK
// =============================================================================

#define LEADER_TIMEOUT 300
#define LAYER_LOCK_IDLE_TIMEOUT 60000

// =============================================================================
// CAPS WORD
// =============================================================================

#define CAPS_WORD_IDLE_TIMEOUT 5000
#define CAPS_WORD_INVERT_ON_SHIFT
// #define BOTH_SHIFTS_TURNS_ON_CAPS_WORD

// =============================================================================
// COMMAND MODE
// =============================================================================

// // Change Both CTLs to Magic Command
// #define IS_COMMAND() (get_mods() == MOD_MASK_CTRL)

// =============================================================================
// MOUSE KEYS
// =============================================================================

#undef MOUSEKEY_DELAY
#define MOUSEKEY_DELAY          0
#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL       16
#undef MOUSEKEY_WHEEL_DELAY
#define MOUSEKEY_WHEEL_DELAY    0
#undef MOUSEKEY_MAX_SPEED
#define MOUSEKEY_MAX_SPEED      8
#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX    52

// =============================================================================
// RGB LIGHTING
// =============================================================================

#ifdef RGBLIGHT_ENABLE
  #define RGBLIGHT_ANIMATIONS
  #define RGBLIGHT_HUE_STEP 8
  #define RGBLIGHT_SAT_STEP 8
  #define RGBLIGHT_VAL_STEP 8
  #define RGBLIGHT_SLEEP
#endif

// =============================================================================
// OLED DISPLAY
// =============================================================================

#ifdef OLED_DRIVER_ENABLE
  #define OLED_DISPLAY_128X64
#endif
