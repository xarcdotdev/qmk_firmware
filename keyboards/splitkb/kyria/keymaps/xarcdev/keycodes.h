#pragma once

//German Umlaute
#define DE_SS KC_MINS
#define DE_AE KC_QUOT
#define DE_UE KC_LBRC
#define DE_OE KC_SCLN

// Dummy Keycodes
#define KC_NP KC_NO // key is not present
#define KC_NA KC_NO // present but not available for use
#define KC_NU KC_NO // available but not used

//Non-KC_ keycodes
// #define KC_RST RESET
// #define KC_TOG RGB_TOG
// #define KC_MOD RGB_MOD
// #define KC_HUI RGB_HUI
// #define KC_SAI RGB_SAI
// #define KC_VAI RGB_VAI

//Clipboard
#define KC_UNDO_C LCTL(DE_Z)
#define KC_REDO_C LCTL(DE_Y)
#define KC_CUT_C LCTL(DE_X)
#define KC_COPY_C LCTL(DE_C)
#define KC_PASTE_C LCTL(DE_V)

// // Left-hand Bottom row mods BUTECK (zvwg)
// // Now plain keys - modifiers activated via UC_TL2 + key combos
// #define ALT_Z DE_Z
// #define CTL_V DE_V
// #define SHT_W DE_W
// #define GUI_G DE_G

// // Right-hand Bottom row mods BUTECK (äöyk)
// #define GUI_AE DE_AE
// #define SHT_OE DE_OE
// #define CTL_Y DE_Y
// #define ALT_K DE_K

/*****************************/
// Left-hand Home row mods HANDS DOWN GOLD (middle row: R S N D)
#define ALT_R_HD DE_R
#define CTL_S_HD DE_S
#define SHT_N_HD DE_N
#define GUI_D_HD DE_D

// Right-hand Home row mods HANDS DOWN GOLD (middle row: A E I H)
#define GUI_A_HD DE_A
#define SHT_E_HD DE_E
#define CTL_I_HD DE_I
#define ALT_H_HD DE_H
/*****************************/

// Left-hand Bottom row mods QWERTY
#define ALT_Z_Q DE_Z
#define CTL_X DE_X
#define SHT_C DE_C
#define GUI_V DE_V

// Right-hand Bottom row mods QWERTY
#define GUI_M DE_M
#define SHT_COMM DE_COMM
#define CTL_DOT DE_DOT
#define ALT_SLSH DE_SLSH

// Thumbcluster
#define UC_TL1 LT(INVRT, KC_ESC)
#define UC_TL2 LT(WINM,  KC_ESC)
#define UC_TL3 LT(NAVR,  KC_SPC)
#define UC_TL4 LT(MOUR,  KC_TAB)
#define UC_TL5 LT(MOURI, KC_TAB)

#define UC_TR1 LT(SYMBOL, KC_ENT)
#define UC_TR2 LT(NSL,    KC_BSPC)
#define UC_TR3 LT(FUNL,   KC_T)

// MISC
#define KC_LOCK QK_LOCK
#define KC_LEAD QK_LEAD

enum custom_layers { BASE, INVRT, MEDR, NAVR, NAVRI, MOUR, MOURI, FUNL, NSL, SYMBOL, QWERTY, GAME, GAME_2, WINM };
