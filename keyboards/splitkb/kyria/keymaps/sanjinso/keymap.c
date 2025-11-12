#include QMK_KEYBOARD_H
#include "keymap_german.h"
#include "keycodes.h"

// #include "features/layer_lock.h"

uint16_t copy_paste_timer;

bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;

// Adaptive keys - Hands Down Gold
#define ADAPTIVE_KEY_TIMEOUT 150
static uint16_t adaptive_key_timer = 0;
static uint16_t last_keycode = KC_NO;


void keyboard_pre_init_user(void) {
    gpio_set_pin_output(24);
    gpio_write_pin_high(24);
}

enum custom_keycodes {
    // SMTD_KEYCODES_BEGIN = SAFE_RANGE,
    // CKC_GUI_Z,
    // CKC_ALT_V,
    // CKC_SHT_W,
    // CKC_CTL_G,
    // CKC_GUI_K,
    // CKC_ALT_Y,
    // CKC_SHT_OE,
    // CKC_CTL_AE,
    // SMTD_KEYCODES_END,

    LLOCK = SAFE_RANGE,
    BACKTICK,         // Types ` (immediate, not dead key)
    TRIPLE_BACKTICK,  // Types ```
};

/* ********
* TAP DANCE
**********/
enum {
    TD_CURNCY,
};

tap_dance_action_t tap_dance_actions[] = {
    [TD_CURNCY] = ACTION_TAP_DANCE_DOUBLE(DE_DLR, DE_EURO),
};

/* ********
* KEYMAPS
**********/
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
* Base Layer: BUTECK-XCV
*
* ,-----------------------------------------------.                              ,------------------------------------------.
* | RESET LYR  |   F  |   M  |   L  |   C  |   P  |                              |   Ü  |   ,  |   .  |   U  |   B  |   ß   |
* |------------+------+------+------+------+------|                              |------+------+------+------+------+-------|
* | LOCK LYR   |   S  |   N  |   R  |   T  |   D  |                              |   O  |   A  |   E  |   I  |   H  |   X   |
* |------------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+-------|
* | TOGGLE LYR |   Z  |   V  |   W  |   G  |   J  | ____ | RESET|  | ____ | ____ |   Q  |   Ä  |   Ö  |   Y  |   K  |   -   |
* `----------------------+------+--------+--------+------+------|  |------+------+------+------+------+---------------------'
*                        | ____ | INVRT | MEDIA | NAVI  | MOUSE |  | SYM  | NUM    | FUNC   | ____ | ____ |
*                        |      | Escape| Enter | Space | Tab   |  | Enter| Bspace | Delete | ___  |      |
*                         `-------------------------------------'  `----------------------------------------'
*                         Leader Key: Space + Backspace combo
*/
[BASE] = LAYOUT(
  TO(HDWN), DE_F,  DE_M,  DE_L,  DE_C,  DE_P,                                  DE_UE,  DE_COMM, DE_DOT, DE_U,  DE_B,  DE_SS,
  KC_ESC,    DE_S,  DE_N,  DE_R,  DE_T,  DE_D,                                  DE_O,   DE_A,    DE_E,   DE_I,  DE_H,  DE_X,
  TO(BASE), ALT_Z, CTL_V, SHT_W, GUI_G, DE_J,  KC_NU, KC_NU,  KC_NU,  KC_NU,  DE_Q,   GUI_AE,  SHT_OE, CTL_Y, ALT_K, DE_MINS,
                       KC_NU, UC_TL1, UC_TL2, UC_TL3, UC_TL4,  UC_TR1, UC_TR2, UC_TR3, KC_NU, KC_TRNS
),

/*
* Base Layer: Hands Down Gold
*
* ,-----------------------------------------------.                              ,------------------------------------------.
* | NXT LYR    |   J  |   G  |   M  |   P  |   V  |                              |   Ü  |   ,  |   .  |   "  |   '  |   ß   |
* |------------+------+------+------+------+------|                              |------+------+------+------+------+-------|
* | ESC        |   R  |   S  |   N  |   D  |   B  |                              |   Ö  |   A  |   E  |   I  |   H  |   X   |
* |------------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+-------|
* | RESET LYR  |   Z  |   F  |   L  |   C  |   W  | ____ | ____ |  | ____ | ____ |   Q   |   U  |   O  |   Y  |   K  |   -   |
* `----------------------+------+--------+--------+------+------|  |------+------+------+------+------+---------------------'
*                        | ____ | INVRT | MEDIA | NAVI  | MOUSE |  | SYM  | NUM    | FUNC   | ____ | ____ |
*                        |      |       | Escape| Space | Tab   |  | Enter| Bspace |  T     | ___  |      |
*                         `-------------------------------------'  `----------------------------------------'
*                         Leader Key: Space + Backspace combo
*/
[HDWN] = LAYOUT(
  TO(GAME), DE_J,  DE_G,  DE_M,  DE_P,  DE_V,                                    DE_UE, DE_COMM,  DE_DOT, DE_DQUO, DE_QUOT, DE_SS,
  KC_ESC,   DE_R,  DE_S,  DE_N,  DE_D,  DE_B,                                    DE_OE, DE_A,    DE_E,    DE_I,    DE_H,    DE_X,
  TO(BASE), ALT_Z, CTL_F, SHT_L, GUI_C, DE_W,  KC_NU, KC_NU,  KC_NU,  KC_NU,    DE_Q, GUI_U,   SHT_O,   CTL_Y_HD,   ALT_K_HD,   DE_MINS,
                       KC_NU, UC_TL1, UC_TL2, UC_TL3, UC_TL4,  UC_TR1, UC_TR2, UC_TR3, KC_NU, KC_TRNS
),

/*
 * Invert Layer: INVRT
 *
 * ,-----------------------------------------------.                              ,-----------------------------------------.
 * |      ß     |   B  |   U  |  .   |   ,  |   Ü  |                              | ____ | ____ | ____ | ____ | ____ | ____ |
 * |------------+------+------+------+------+------|                              |------+------+------+------+------+------|
 * |      X     |   H  |   I  |  E   |   A  |   O  |                              | ____ | ____ | ____ | ____ | ____ | ____ |
 * |------------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+------|
 * | Backspace  |   K  |   Y  |   Ö  |   Ä  |   Q  | ____ | ____ |  | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ |
 * `------------------------+------+--------+------+------+------|  |------+------+------+------+------+--------------------'
*                         | ____ | INVRT | MEDIA | NAVI  | MOUSE |  |      |        |        |        | ____ |
*                         |      | Escape| Enter | Space | Tab   |  | Enter| Bspace | Delete |        |      |
*                          `-------------------------------------'  `----------------------------------------'
*/
[INVRT] = LAYOUT(
  DE_SS,   DE_B, DE_U,   DE_DOT, DE_COMM, DE_UE,                                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  DE_X,    DE_H, DE_I,   DE_E,   DE_A,    DE_O,                                     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_BSPC, ALT_K, CTL_Y, SHT_OE, GUI_AE,  DE_Q,  KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),


/*
* Base Layer: MEDIA
*
* ,----------------------------------------------.                              ,-----------------------------------------.
* | RESET LYR | ____ | ____ | ____ | ____ | ____ |                              | RGB  | RGB  | RGB  | RGB  | RGB  | ____ |
* |-----------+------+------+------+------+------|                              |------+------+------+------+------+------|
* | LOCK LYR  | GUI  | ALT  | CTRL | SHIFT| ____ |                              | ____ | PREV | VOLD | VOLU | NEXT | ____ |
* |-----------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+------|
* | TOGGLELYR | ____ | ALGR | ____ | ____ | ____ | ____ | ____ |  | ____ | ____ | ____ | STOP | PLAY | MUTE | ____ | ____ |
* `-----------------------+------+--------+------+------+------|  |------+------+------+------+------+--------------------'
*                       | ____ | INVRT | MEDIA | NAVI  | MOUSE |  |      |        |        | ____ | ____ |
*                       | ____ | Escape| Enter | Space | Tab   |  | STOP | PLAY  | MUTE    | ____ | ____ |
*                        `-------------------------------------'  `--------------------------------------'
*/
[MEDR] = LAYOUT(
  TO(BASE), KC_NU,  KC_NU,   KC_NU,   KC_NU,   KC_NU,                                        KC_NU,  KC_NU,         KC_NU,               KC_NU,         KC_NU,   KC_NU,
  LLOCK, KC_NU,  KC_F14,  KC_F15,  KC_F16,  KC_NU,                                        KC_NU,  KC_MPRV,       KC_VOLD,             KC_VOLU,       KC_MNXT, KC_NU,
  TO(BASE), KC_LALT,KC_LCTL, KC_LSFT, KC_LGUI,  KC_NU, KC_NU, KC_NU,  KC_NU,         KC_NU,   KC_NU,  KC_MEDIA_STOP, KC_MEDIA_PLAY_PAUSE, KC_AUDIO_MUTE, KC_NU,   KC_NU,
                       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_MEDIA_STOP, KC_MEDIA_PLAY_PAUSE, KC_AUDIO_MUTE, KC_TRNS, KC_TRNS

),


/*
* Navigation Layer: NAVR
*
* ,-----------------------------------------------.                              ,------------------------------------------.
* | RESET LYR  | ____ | ____ | ____ | ____ | ____ |                              | AGAIN | UNDO | CUT  | COPY | PASTE| ____ |
* |------------+------+------+------+------+------|                              |-------+------+------+------+------+------|
* | LOCK LYR   | ALT  | CTRL  | GUI | SHIFT| ____ |                              | CAPS  | LEFT | DOWN | UP   | RIGHT| ____ |
* |------------+------+------+------+------+------+-------------.  ,-------------+-------+------+------+------+------+------|
* | TOGGLE LYR | ____ | ALGR | ____ | ____ | ____ | ____ | ____ |  | ____ | ____ | INS   | HOME | PGDN | PGUP | END  | ____ |
* `----------------------+------+--------+--------+------+------|  |------+------+-------+------+------+--------------------'
*                        | ____ | INVRT | MEDIA | NAVI  | MOUSE |  |      |        |        | ____ | ____ |
*                        | ____ | Escape| Enter | Space | Tab   |  | Enter| Bspace | Delete | ____ | ____ |
*                         `-------------------------------------'  `--------------------------------------'
*/

[NAVR] = LAYOUT(
  TO(BASE),  KC_NU,   KC_NU,   KC_NU,   KC_NU,   KC_NU,                                KC_UNDO_C, KC_PASTE_C,  KC_COPY_C, KC_CUT_C, KC_REDO_C, KC_NU,
  LLOCK,  KC_LALT,   KC_LCTL,   KC_LSFT,   KC_LGUI,   KC_NU,                                KC_CAPS,   KC_LEFT,   KC_DOWN,    KC_UP,     KC_RGHT,   KC_NU,
  TO(BASE),  KC_LALT, KC_LCTL, KC_LSFT, KC_LGUI, KC_NU, KC_NU, KC_NU,  KC_NU,   KC_NU, KC_INS,    KC_HOME,   KC_PGDN,    KC_PGUP,   KC_END,    KC_NU,
                         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_DEL, KC_TRNS, KC_TRNS
),

/*
 * Windows Navigation Layer: WIN_NAV (NAVR + MOUR held together)
 *
 * ,-----------------------------------------------.                              ,-----------------------------------------------------.
 * | RESET LYR  | ____ | ____ | ____ | ____ | ____ |                              | ____ | WIN+ALT+← | WIN+ALT+↓ | WIN+ALT+↑ | WIN+ALT+→ | ____ |
 * |------------+------+------+------+------+------|                              |------+-----------+-----------+-----------+-----------+------|
 * | ____       | ALT  | CTRL | GUI  | SHIFT| ____ |                              | ____ |   WIN+←   |   WIN+↓   |   WIN+↑   |   WIN+→   | ____ |
 * |------------+------+------+------+------+------+-------------.  ,-------------+------+-----------+-----------+-----------+-----------+------|
 * | ____       | ____ | ____ | ____ | ____ | ____ | ____ | ____ |  | ____ | ____ |WIN+TAB|  WIN+HOME | WIN+PGDN  | WIN+PGUP  |  WIN+END  | ____ |
 * `----------------------+------+--------+--------+------+------|  |------+------+-------+-----------+-----------+-----------+-----------+------'
 *                        | ____ | ____ | ____ | HELD  | HELD  |  |      |        |        | ____ | ____ |
 *                        | ____ | ____ | ____ | NAVR  | MOUR  |  |      |        |        | ____ | ____ |
 *                         `-------------------------------------'  `--------------------------------------'
*/
[WIN_NAV] = LAYOUT(
  TO(BASE),  KC_NU,   KC_NU,   KC_NU,   KC_NU,   KC_NU,                                                  KC_TRNS,        LAG(KC_LEFT),   LAG(KC_DOWN),   LAG(KC_UP),     LAG(KC_RGHT),   KC_NU,
  KC_TRNS,   KC_LALT, KC_LCTL, KC_LSFT, KC_LGUI, KC_NU,                                                  KC_TRNS,        LGUI(KC_LEFT),  LGUI(KC_DOWN),  LGUI(KC_UP),    LGUI(KC_RGHT),  KC_NU,
  KC_TRNS,   KC_LALT, KC_LCTL, KC_LSFT, KC_LGUI, KC_NU, KC_NU, KC_NU,  KC_NU,   KC_NU,                 LGUI(KC_TAB),   LGUI(KC_HOME),  LGUI(KC_PGDN),  LGUI(KC_PGUP),  LGUI(KC_END),   KC_NU,
                         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),


/*
 * MouseControl Layer: MOUR
 *
 * ,-----------------------------------------------.                              ,-----------------------------------------.
 * | RESET LYR  | ____ | ____ | ____ | ____ | ____ |                              | ____ | ____ | ____ | ____ | ____ | ____ |
 * |------------+------+------+------+------+------|                              |------+------+------+------+------+------|
 * | LOCK LYR   | GUI  | ALT  | CTRL | SHIFT| ____ |                              | ____ |MLEFT |MDOWN | MUP  |MRIGHT| ____ |
 * |------------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+------|
 * | TOGGLE LYR | ____ | ALGR | ____ | ____ | ____ | ____ | ____ |  | ____ | ____ | ____ |WLEFT |WDOWN | WUP  |WRIGHT| ____ |
 * `----------------------+------+--------+------+--------+------|  |------+------+------+------+------+--------------------'
 *                            | ____ | ____ | ____ | ____ | ____ |  |      |      |      | ____ | ____ |
 *                            | ____ | ____ | ____ | ____ | ____ |  | BTN1 | BTN3 | BTN2 | ____ | ____ |
 *                            `----------------------------- ----'  `----------------------------------'
*/
[MOUR] = LAYOUT(
  TO(BASE), KC_NU,   KC_NU,   KC_NU,   KC_NU,   KC_NU,                                 KC_NU, KC_NU,   KC_NU,   KC_NU,   KC_NU,    KC_NU,
  LLOCK, KC_NU,  KC_NU,   KC_NU,   KC_NU,   KC_NU,                                 KC_NU, MS_LEFT, MS_DOWN, MS_UP, MS_RGHT, KC_NU,
  TO(BASE), KC_LALT, KC_LCTL, KC_LSFT, KC_LGUI, KC_NU, KC_NU, KC_NU,   KC_NU,   KC_NU, KC_NU, MS_WHLL, MS_WHLD, MS_WHLU, MS_WHLR, KC_NU,
                      KC_NP,   KC_NP,  KC_NU,   KC_NU, KC_NU, MS_BTN1, MS_BTN3, MS_BTN2, KC_NP, KC_NP
),


/*
 * MouseControl Layer: MOUR INVRT
 *
* ,-----------------------------------------------.                              ,------------------------------------------.
* | RESET LYR  | ____ | ____ | ____ | ____ | ____ |                              | ____ | ____ | ____ | ____ | ____ | ____ |
 * |------------+------+------+------+------+------|                              |------+------+------+------+------+------|
 * | LOCK LYR   |MLEFT |MDOWN | MUP  |MRIGHT| ____ |                              | ____ |SHIFT | CTRL | ALT  | GUI| ____ |
 * |------------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+------|
 * | RESET LYR |WLEFT |WDOWN | WUP  |WRIGHT| ____ | ____ | ____ |  | ____ | ____ | ____ | ____ | ____ | ALGR | ____ | ____ |
 * `----------------------+------+--------+------+--------+------|  |------+------+------+------+------+--------------------'
 *                            | ____ | ____ | ____ | ____ | ____ |  |      |      |      | ____ | ____ |
 *                            | ____ | ____ | ____ | ____ | ____ |  | BTN1 | BTN3 | BTN2 | ____ | ____ |
 *                            `----------------------------- ----'  `----------------------------------'
*/
[MOURI] = LAYOUT(
  TO(BASE), KC_NU,   KC_NU,   KC_NU,   KC_NU,    KC_NU,                                 KC_NU,   KC_NU,   KC_NU,   KC_NU,   KC_NU,   KC_NU,
  LLOCK,    MS_LEFT, MS_DOWN, MS_UP, MS_RGHT, KC_NU,                                 KC_NU,   KC_NU,   KC_NU,   KC_NU,   KC_NU,   KC_NU,
  TO(BASE), MS_WHLL, MS_WHLD, MS_WHLU, MS_WHLR, KC_NU, KC_NU, KC_NU,   KC_NU,   KC_NU, KC_NU,   KC_LGUI, KC_LSFT, KC_LCTL, KC_LALT, KC_NU,
                              KC_NP, KC_NP, MS_BTN2, MS_BTN3, MS_BTN1, MS_BTN1, MS_BTN3, MS_BTN2, KC_NP, KC_TRNS
),


/*
 * Function Layer: FUNL
 *
 * ,------------------------------------------------.                              ,-----------------------------------------.
 * | RESET LYR  |  F12 |  F7  |  F8  |  F9  | PRINT |                              | ____ | ____ | ____ | ____ | ____ | ____ |
 * |------------+------+------+------+------+-------|                              |------+------+------+------+------+------|
 * | LOCK LYR   |  F11 |  F4  |  F5  |  F6  | SLock |                              | ____ | SHIFT| CTRL | ALT  | GUI  | ____ |
 * |------------+------+------+------+------+-------+-------------.  ,-------------+------+------+------+------+------+------|
 * | TOGGLE LYR |  F10 |  F1  |  F2  |  F3  | PAUSE | ____ | ____ |  | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ |
 * `-----------------------+-------+-------+-------+-------+------|  |------+------+------+------+------+--------------------'
 *                         | _____ | _____ | _____ | _____ | ____ |  | ____ | ____ | ____ | ____ | ____ |
 *                         | _____ | _____ | App   | Space | Tab  |  |      |      |      |      |      |
 *                         `--------------------------------------'  `----------------------------------'
*/
[FUNL] = LAYOUT(
  TO(BASE),  KC_F12, KC_F7,  KC_F8,  KC_F9, KC_PSCR,                                        DM_REC1, DM_PLY1,  DM_REC2,            DM_PLY2,          KC_NU,   DM_RSTP,
  TO(FUNL),  KC_F11, KC_F4,  KC_F5,  KC_F6, KC_SCROLL_LOCK,                                 EE_CLR,  KC_LOCK,  KC_BRIGHTNESS_DOWN, KC_BRIGHTNESS_UP, KC_NU,   KC_NU,
  TO(BASE),  KC_F10, KC_F1,  KC_F2,  KC_F3, KC_PAUS,        KC_NU, KC_NU,  KC_NU,   KC_NU,  KC_NU,   KC_LGUI,  KC_LSFT,            KC_LCTL,          KC_LALT, DB_TOGG,
                             KC_NU,   KC_NU,   KC_NU,   KC_NU,   KC_NU,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),


/*
 * Number Layer: NSL
 *
 * ,-----------------------------------------------.                              ,-------------------------------------------.
 * |            |  [   |  7   |  8   |  9  |   ]   |                              | ___  | ___  | ___  | ___  | ___  |  ___   |
 * |------------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |            |  ;   |  4   |  5   |  6  |   =   |                              | ___  | SHIFT | GUI | CTRL  | ALT  |  ___   |
 * |------------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |            |  ´   |  1   |  2   |  3   |  \   |  ___ |  ___ |  |  ___ |  ___ | ___  | ___  |  ___ |  ___ | ___  |  ___   |
 * `----------------------+------+--------+------+--------+------|  |------+------+------+------+------+----------------------'
 *                        |  ___ |  ___   | _____ |  ___   | ___  |  |  ___ |  ___ |  ___ | ___  | ___  |
 *                        |  ___ |  ___   | Enter |   0    |  -   |  |      |      |      |      |      |
 *                        `--------------------------------------'  `----------------------------------'
*/
[NSL] = LAYOUT(
  TO(BASE),  DE_MINS, DE_7, DE_8, DE_9, DE_PLUS,                                  KC_NA, KC_NA,  KC_NA,   KC_NA,   KC_NU,   KC_NU,
  LLOCK,   DE_DOT,  DE_4, DE_5, DE_6, DE_COMM,                                    KC_NA, KC_LGUI,  KC_LSFT,   KC_LCTL,   KC_LALT,   KC_NU,
  TO(BASE),DE_BSLS, DE_1, DE_2, DE_3, DE_ASTR, KC_NU, KC_NU,       KC_NU,         KC_NU,  KC_NU, KC_NU,   KC_NU, KC_NU, KC_NU, KC_NU,
                         KC_NP, KC_BSPC, KC_SPC, DE_0, DE_EQL,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS
),


 /*
  * Symbol Layer: SYMBOL
  *
  * ,-------------------------------------------.                              ,-------------------------------------------.
  * |        |  !   |  ?   |  [   |  ]   |  ^   |                              |   °  |      |  &   |  %   |  |   |   §    |
  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
  * |        |  \   |  /   |  (   |  )   |  @   |                              |   `  |  {   |  }   |  +   |  =   |   ²    |
  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
  * |        |  #   |  $€  |  <   |  >   |  *   |      |      |  |      |      |   ~  |  `   |  ``` |  "   |  '   |   ³    |
  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
  *                        |      |      |      |      |      |  |      |      |      |      |      |
  *                        |      |      |      |      |      |  |      |      |      |      |      |
  *                        `----------------------------------'  `----------------------------------'
  */
[SYMBOL] = LAYOUT(
TO(BASE), DE_EXLM, DE_QUES,   DE_LBRC, DE_RBRC, DE_CIRC,                                     DE_DEG, KC_TRNS, DE_AMPR,DE_PERC,DE_PIPE,DE_SECT,
TO(SYMBOL), DE_BSLS, DE_SLSH,  DE_LPRN, DE_RPRN, DE_AT,                                      DE_GRV, DE_LCBR, DE_RCBR, DE_PLUS, DE_EQL, DE_SUP2,
TO(BASE), DE_HASH, TD(TD_CURNCY), DE_LABK, DE_RABK, DE_ASTR, KC_NU, KC_NU,  KC_NU,   KC_NU, DE_TILD, BACKTICK,  TRIPLE_BACKTICK, DE_DQUO,  DE_QUOT, DE_SUP3,
                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),


/*
 * Base Layer: QWERTY
 *
 * ,----------------------------------------------.                              ,-------------------------------------------.
 * | RESET LYR |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |  | \   |
 * |-----------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * | LSFT      |   A  |   S  |  D   |   F  |   G  |                              |   H  |   J  |   K  |   L  | ;  : |  ' "   |
 * |-----------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | TOGGLE LYR|   Z  |   X  |   C  |   V  |   B  | CCCV |      |  | Del  |Leader|   N  |   M  | ,  < | . >  | /  ? |  - _   |
 * `-------------------------+------+------+------+------+      |  |------+------+------+------+------+----------------------'
 *                       |  ___ | INVERT | MEDIA | NAVI  | MOUSE|  | SYM  | NUM      | FUNC   |        |       |
 *                       |      | Enter  | Escape| Space | Tab  |  | Enter| Bspace   | Delete |        |       |
 *                       `--------------------------------------'  `-------------------------------------------'
 */
    [QWERTY] = LAYOUT(
    TO(GAME), DE_Q,  DE_W,  DE_E,  DE_R, DE_T,                                                                  KC_Y, KC_U,  KC_I,  KC_O,  KC_P,  KC_PIPE,
    KC_LSFT,  DE_A,  DE_S,  DE_D,  DE_F, DE_G,                                                                  DE_H, DE_J, DE_K, DE_L, DE_X, DE_QUOT,
    TO(BASE), ALT_Z_Q, CTL_X, SHT_C, GUI_V, DE_B, KC_NU, KC_NU,                        KC_NU,     KC_NU,  DE_N,  GUI_M, SHT_COMM, CTL_DOT, ALT_SLSH, DE_MINS,
    KC_NU, LT(INVRT, KC_ESC), LT(MEDR, KC_ENT), LT(NAVR, KC_SPC), LT(MOUR, KC_TAB),  LT(SYMBOL, KC_ENT), LT(NSL, KC_BSPC), LT(FUNL, KC_DEL), KC_NU, KC_TRNS
),


 /*
 * Base Layer: GAMING
 * C V Y X      G T B H Z N M J U     K I
 *
 * Y, B, Z, N, M, J, U
 * ,----------------------------------------------.                              ,------------------------------------------.
 * |    ? 0    |  1  |  2  |  3  |  4  |  5   |                              |      |      |      |      |      |       |
 * |------------+------+------+------+------+-----|                              |------+------+------+------+------+-------|
 * | ?  9      |  I   |   Q  |   T  |   E  |   R   |                               |      |      |      |      |      |        |
 * |-----------+------+------+------+------+------|                               |------+------+------+------+------+--------|
 * | LTAB      | Shift|   A  |   W  |   D  |   F  |                               |      |      |      |      |      |        |
 * |-----------+------+------+------+------+------+--------------.  ,-------------+------+------+------+------+------+--------|
 * |  Z        | CTRL |   X  |   S  |   C  |   G  |       |      |  |      |      |      |      |      |      |      |        |
 * `-------------------------+------+------+------+-------+      |  |------+------+------+------+------+----------------------'
 *                       |   9  |        |        |       |      |  |      |          |         |        |       |
 *                       |      |  ESC   | ALT/V | Space  |MOD1/H|  |      |          |         |        |       |
 *                       `--------------------------------------'  `---------------------------------------------'
 */
[GAME] = LAYOUT(
    KC_9, KC_I,   KC_Q,    KC_T,    KC_E,    KC_R,                                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TAB,  KC_LSFT, KC_A,    KC_W,    KC_D,    KC_F,                                           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_Z,    KC_LCTL, KC_X,    KC_S,    KC_C,    KC_G, KC_NU, KC_NU,      KC_NU,            KC_NU,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
               KC_9, KC_ESC, LALT_T(DE_V), KC_SPC,  LT(GAME_2, KC_H),     KC_ENT, KC_BSPC, KC_DEL, KC_TRNS, KC_TRNS
),


 /*
 * Base Layer: GAMING_2
 *
 * ,-----------------------------------------------.                              ,------------------------------------------.
* |     F6      |  F7 |  F8  |  F9  |   F10 |  F11   |                              |      |      |      |      |      |       |
* |------------+------+------+------+------+------|                              |------+------+------+------+------+-------|
* | RESET LYR |  F1   | F2   |   F3  |  F4   |   F5   |                               |      |      |      |      |      |        |
 * |-----------+------+------+------+------+------|                               |------+------+------+------+------+--------|
 * |     J     | SHFT|   K  |   L  |   O  |   P   |                               |      |      |      |      |      |        |
 * |-----------+------+------+------+------+------+--------------.  ,-------------+------+------+------+------+------+--------|
 * |     U     |   Y  |   B  |   N  |   M  |   ,  |       |      |  |      |      |      |      |      |      |      |        |
 * `-------------------------+------+------+------+-------+      |  |------+------+------+------+------+----------------------'
 *                       | ____ |        |        |       |      |  |      |          |         |        |       |
 *                       |      |        |        | Space |  H   |  |      |          |         |        |       |
 *                       `--------------------------------------'  `---------------------------------------------'
 */
[GAME_2] = LAYOUT(
   TO(BASE),KC_F1, KC_F2,  KC_F3,   KC_F4,   KC_F5,                                           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_J,    KC_LSFT, KC_K,    KC_L,    KC_O,    KC_P,                                           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_U,    KC_Y, KC_B,    KC_N,    KC_M,    DE_COMM, KC_NU, KC_NU,           KC_NU,                 KC_NU,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),

};


layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, BASE, QWERTY, GAME);
    state = update_tri_layer_state(state, NAVR, MOUR, WIN_NAV);  // NAVR + MOUR = WIN_NAV
    return state;
}



/* ********
* TAPPING TERM (FIXED)
**********/

//Tapping Term 200
//How long does it have to be pressed to activate layer instead of keypress
//Lower Tapping term is needed for quicker activation of modifier. However there are Combos too.
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case ALT_Z:
            return TAPPING_TERM + 10; //210
        case CTL_V:
            return TAPPING_TERM - 20; //180
        case SHT_W:
            return TAPPING_TERM - 40; //170
        case GUI_G:
            return TAPPING_TERM - 30; //170
            //return TAPPING_TERM - 30; //170

        case ALT_K:
            return TAPPING_TERM + 10; //210
        case CTL_Y:
            return TAPPING_TERM + 30; //230
        case SHT_OE:
            return TAPPING_TERM + 30; //230
        case GUI_AE:
            return TAPPING_TERM - 90; //110
            //return TAPPING_TERM - 50; //170
            //return TAPPING_TERM - 30; //170

        default:
            return TAPPING_TERM;

        case UC_TR2:
            return TAPPING_TERM - 45; //120
        case UC_TR1:
            return TAPPING_TERM - 50; //140
    }
}

// bool is_flow_tap_key(uint16_t keycode) {
//     if ((get_mods() & (MOD_MASK_CG | MOD_BIT_LALT)) != 0) {
//         return false; // Disable Flow Tap on hotkeys.
//     }

//     // Only enable flow tap for home row mods
//     switch (keycode) {
//         // BUTECK home row mods
//         case GUI_Z:
//         case ALT_V:
//         case SHT_W:
//         case CTL_G:
//         case CTL_AE:
//         case SHT_OE:
//         case ALT_Y:
//         case GUI_K:
//         // HD Gold home row mods
//         case GUI_X:
//         case ALT_F:
//         case SHT_L:
//         case CTL_C:
//         case CTL_U:
//         case SHT_O:
//         // ALT_Y and GUI_K already listed above
//             return true;
//     }
//     return false;
// }

/* *********
* QUICK TAPPING TERM (DOUBLE_PRESS_AUTO_REPEAT_TERM)
**********/
//QUICK TAPPING TERM 80
uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        //BSPC -> NUML
        case UC_TR2:
            return QUICK_TAP_TERM -20; //60
        //DEL -> FUNL
        case UC_TR3:
            return QUICK_TAP_TERM -10; //70
        //ENTER -> SYM
        case UC_TR1:
            return QUICK_TAP_TERM -10; //60
        default:
            return QUICK_TAP_TERM;
    }
}

/************************
* COMBOS
***********************/
//Name of combos
#ifdef COMBO_ENABLE
enum combo_events  {
    CTRL_C,
    CTRL_V,
    CTRL_X,
    CTRL_S,
    CTRL_Z,
    SHIFT_CTRL_Z,

    ALT_TAB,
    CTRL_TAB,
    SHIFT_CTRL_TAB,
    ALT_SPACE,

    WIN_CTRL_LEFT,
    WIN_CTRL_RIGHT,

    ALT_UP,
    ALT_LEFT,
    ALT_RIGHT,
    ALT_DOWN,
    RWIN_SHIFT_S,
    // CTRL_W,
    // CTRL_W_B,

    QUICK_TERMINAL,

    BSPC_LSFT_CLEAR,
    QUICK_WINDOWS,
    QUICK_VBOX,

    CTRL_A,

    // Hands Down Gold combos
    SEMICOLON_COMBO,
    AE_UMLAUT,
    QU_COMBO,

    // H-digraph combos
    TH_COMBO,
    CH_COMBO,
    SH_COMBO,
    GH_COMBO,
    PH_COMBO,

    // Leader key combo
    LEADER_COMBO,

    COMBO_LENGTH

};
int COMBO_LEN = COMBO_LENGTH;

//Combo Activation
const uint16_t PROGMEM copy_combo[]  = { GUI_G, DE_C, COMBO_END };
const uint16_t PROGMEM paste_combo[] = { GUI_G, DE_V, COMBO_END };
const uint16_t PROGMEM cut_combo[] = { GUI_G, DE_X, COMBO_END };
const uint16_t PROGMEM save_combo[]  = { GUI_G, DE_S, COMBO_END };
const uint16_t PROGMEM undo_combo[]  = { GUI_G, DE_Z, COMBO_END };
const uint16_t PROGMEM redo_combo[]  = { GUI_G, SHT_W, DE_Z, COMBO_END };

const uint16_t PROGMEM alt_tab_combo[] = { CTL_V, UC_TL4, COMBO_END };
const uint16_t PROGMEM ctrl_tab_combo[] = { GUI_G, UC_TL4, COMBO_END };
const uint16_t PROGMEM shift_ctrl_tab_combo[] = { GUI_G, SHT_W, UC_TL4, COMBO_END };

const uint16_t PROGMEM alt_space_combo[] = { CTL_V, UC_TL3, COMBO_END };

const uint16_t PROGMEM win_ctrl_left_combo[] = { ALT_Z, GUI_G, KC_LEFT, COMBO_END };
const uint16_t PROGMEM win_ctrl_right_combo[] = { ALT_Z, GUI_G, KC_RGHT, COMBO_END };

const uint16_t PROGMEM alt_up_combo[] = { CTL_V, KC_UP, COMBO_END };
const uint16_t PROGMEM alt_down_combo[] = { CTL_V, KC_DOWN, COMBO_END };
const uint16_t PROGMEM alt_left_combo[] = { CTL_V, KC_LEFT, COMBO_END };
const uint16_t PROGMEM alt_right_combo[] = { CTL_V, KC_RGHT, COMBO_END };
const uint16_t PROGMEM rwin_shift_s_combo[] = { ALT_K, SHT_OE, DE_S, COMBO_END };

const uint16_t PROGMEM quick_terminal_combo[] = { ALT_Z, UC_TR1, COMBO_END };

// const uint16_t PROGMEM close_combo[]  = { CTL_G, DE_W, COMBO_END };
// const uint16_t PROGMEM close_combo_b[]  = { DE_R, DE_W, COMBO_END };

const uint16_t PROGMEM clear_line_combo[] = {KC_BSPC, KC_LSFT, COMBO_END};
const uint16_t PROGMEM quick_win_combo[]  = {UC_TL4, UC_TR1, COMBO_END };
const uint16_t PROGMEM quick_vbox_combo[]  = {ALT_Z, GUI_G, COMBO_END };

const uint16_t PROGMEM select_all_combo[] = { GUI_G, DE_A, COMBO_END };

// Hands Down Gold combos
const uint16_t PROGMEM semicolon_combo[] = { DE_COMM, DE_DOT, COMBO_END };  // , + . = ;
const uint16_t PROGMEM ae_umlaut_combo[] = { DE_A, DE_E, COMBO_END };       // A + E = Ä
const uint16_t PROGMEM qu_combo[] = { DE_G, DE_P, COMBO_END };              // G + P = Q

// H-digraph combos (Hands Down Gold recommended)
const uint16_t PROGMEM th_combo[] = { DE_D, DE_N, COMBO_END };              // D + N = TH
const uint16_t PROGMEM ch_combo[] = { GUI_C, SHT_L, COMBO_END };            // C + L = CH
const uint16_t PROGMEM sh_combo[] = { DE_S, DE_N, COMBO_END };              // S + N = SH
const uint16_t PROGMEM gh_combo[] = { DE_G, DE_M, COMBO_END };              // G + M = GH
const uint16_t PROGMEM ph_combo[] = { DE_P, DE_M, COMBO_END };              // P + M = PH

// Leader key combo
const uint16_t PROGMEM leader_combo[] = { UC_TL3, UC_TR2, COMBO_END };      // Space + Backspace = Leader


//Combo Action
combo_t key_combos[COMBO_COUNT] = {
    [CTRL_C]  = COMBO(copy_combo, LCTL(DE_C)),
    [CTRL_V] = COMBO(paste_combo, LCTL(DE_V)),
    [CTRL_X] = COMBO(cut_combo, LCTL(DE_X)),
    [CTRL_S]  = COMBO(save_combo, LCTL(DE_S)),
    [CTRL_Z] = COMBO(undo_combo, LCTL(DE_V)),
    [SHIFT_CTRL_Z] = COMBO(redo_combo, LCA_T(DE_Z)),
    [ALT_TAB] = COMBO_ACTION(alt_tab_combo),
    [CTRL_TAB] = COMBO(ctrl_tab_combo, LCTL(KC_TAB)),
    [SHIFT_CTRL_TAB] = COMBO(shift_ctrl_tab_combo, LCA_T(KC_TAB)),
    [ALT_SPACE] = COMBO(alt_space_combo, LALT(KC_SPC)),
    [WIN_CTRL_LEFT] = COMBO(win_ctrl_left_combo, LGUI(LCTL(KC_TAB))),
    [WIN_CTRL_RIGHT] = COMBO(win_ctrl_right_combo, LGUI(LCTL(KC_TAB))),
    [ALT_UP] = COMBO(alt_up_combo, LALT(KC_UP)),
    [ALT_DOWN] = COMBO(alt_down_combo, LALT(KC_DOWN)),
    [ALT_LEFT] = COMBO(alt_left_combo, LALT(KC_LEFT)),
    [ALT_RIGHT] = COMBO(alt_right_combo, LALT(KC_RGHT)),
    [RWIN_SHIFT_S] = COMBO(rwin_shift_s_combo, LGUI(LSFT(DE_S))),

    [QUICK_TERMINAL] = COMBO_ACTION(quick_terminal_combo),

    // [CTRL_W] = COMBO(close_combo, LCTL(DE_W)),
    // [CTRL_W_B] = COMBO(close_combo_b, LCTL(DE_W)),
    [BSPC_LSFT_CLEAR] = COMBO_ACTION(clear_line_combo),
    [QUICK_WINDOWS] = COMBO_ACTION(quick_win_combo),
    [QUICK_VBOX] = COMBO_ACTION(quick_vbox_combo),
    [CTRL_A] = COMBO_ACTION(select_all_combo),

    // Hands Down Gold combos
    [SEMICOLON_COMBO] = COMBO(semicolon_combo, DE_SCLN),
    [AE_UMLAUT] = COMBO(ae_umlaut_combo, DE_AE),
    [QU_COMBO] = COMBO_ACTION(qu_combo),

    // H-digraph combos
    [TH_COMBO] = COMBO_ACTION(th_combo),
    [CH_COMBO] = COMBO_ACTION(ch_combo),
    [SH_COMBO] = COMBO_ACTION(sh_combo),
    [GH_COMBO] = COMBO_ACTION(gh_combo),
    [PH_COMBO] = COMBO_ACTION(ph_combo),

    // Leader key combo
    [LEADER_COMBO] = COMBO(leader_combo, QK_LEADER),
};


//Combo Processing
void process_combo_event(uint16_t combo_index, bool pressed) {
    action_tapping_process((keyrecord_t){});
    switch(combo_index) {
        case ALT_TAB:
            if (pressed) {
                register_code(KC_LALT); // Hold ALT
                tap_code(KC_TAB);       // Press TAB once
            } else {
                unregister_code(KC_LALT); // Release ALT
            }
            break;
        case CTRL_TAB:
            if (pressed) {
                register_code(KC_LCTL); // Hold CTRL
                tap_code(KC_TAB);       // Press TAB once
            } else {
                unregister_code(KC_LCTL); // Release CTRL
            }
            break;
        case BSPC_LSFT_CLEAR:
            if (pressed) {
                tap_code16(KC_END);
                tap_code16(S(KC_HOME));
                tap_code16(KC_BSPC);
            }
            break;
        case QUICK_WINDOWS:
            if (pressed) {
                tap_code16(KC_LGUI);
            }
            break;
        case QUICK_VBOX:
            if (pressed) {
                register_code16(KC_LGUI);
                tap_code16(KC_LCTL);
            }
            break;
        case QUICK_TERMINAL:
            if (pressed) {
                register_code16(KC_LGUI);
                tap_code16(KC_ENT);
            } else {
                unregister_code(KC_LGUI); // Release CTRL
            }
            break;

        // Hands Down Gold combos
        case QU_COMBO:
            if (pressed) {
                tap_code16(DE_Q);
                tap_code16(DE_U);
            }
            break;

        // H-digraph combos
        case TH_COMBO:
            if (pressed) {
                tap_code16(DE_T);
                tap_code16(DE_H);
            }
            break;
        case CH_COMBO:
            if (pressed) {
                tap_code16(DE_C);
                tap_code16(DE_H);
            }
            break;
        case SH_COMBO:
            if (pressed) {
                tap_code16(DE_S);
                tap_code16(DE_H);
            }
            break;
        case GH_COMBO:
            if (pressed) {
                tap_code16(DE_G);
                tap_code16(DE_H);
            }
            break;
        case PH_COMBO:
            if (pressed) {
                tap_code16(DE_P);
                tap_code16(DE_H);
            }
            break;
    }
}

bool get_combo_must_tap(uint16_t combo_index, combo_t *combo) {
    switch (combo_index) {
        // case CTRL_W_B:
           // return false;
        case CTRL_A:
            return false;
        case QUICK_TERMINAL:
            return false;
    }

    /*
    switch (combo_index) {
        case CTRL_TAB:
           return false;
    }
    */
    return true;
}

uint16_t get_combo_term(uint16_t combo_index, combo_t *combo) {
    switch (combo_index) {
        case QU_COMBO:
            return 30;  // 60ms window for QU combo
        case SEMICOLON_COMBO:
            return 30;
        case AE_UMLAUT:
            return 20;  // Shorter window to prevent misfires on common A-E sequences
        // H-digraph combos - slightly longer timing
        case TH_COMBO:
        case CH_COMBO:
        case SH_COMBO:
        case GH_COMBO:
        case PH_COMBO:
            return 40;
    }
    return COMBO_TERM;  // Default 45ms from config.h
}

bool get_combo_must_press_in_order(uint16_t combo_index, combo_t *combo) {
    switch (combo_index) {
        case RWIN_SHIFT_S:
           return false;
        case SHIFT_CTRL_Z:
           return false;
        case SHIFT_CTRL_TAB:
           return false;
        case CTRL_TAB:
           return false;
        case WIN_CTRL_LEFT:
           return false;
        case WIN_CTRL_RIGHT:
           return false;
        case BSPC_LSFT_CLEAR:
            return false;
        case QUICK_WINDOWS:
            return false;
        case QUICK_TERMINAL:
            return false;
        case ALT_SPACE:
            return false;
        case QU_COMBO:
            return false;
        case SEMICOLON_COMBO:
            return false;
        // AE_UMLAUT requires A before E to prevent misfires
    }
    return true;
}


#endif

/************************
* OLED
***********************/
#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	return OLED_ROTATION_180;
}

static void render_kyria_logo(void) {
    static const char PROGMEM kyria_logo[] = {
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,192,224,240,112,120, 56, 60, 28, 30, 14, 14, 14,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 14, 14, 14, 30, 28, 60, 56,120,112,240,224,192,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,192,224,240,124, 62, 31, 15,  7,  3,  1,128,192,224,240,120, 56, 60, 28, 30, 14, 14,  7,  7,135,231,127, 31,255,255, 31,127,231,135,  7,  7, 14, 14, 30, 28, 60, 56,120,240,224,192,128,  1,  3,  7, 15, 31, 62,124,240,224,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,240,252,255, 31,  7,  1,  0,  0,192,240,252,254,255,247,243,177,176, 48, 48, 48, 48, 48, 48, 48,120,254,135,  1,  0,  0,255,255,  0,  0,  1,135,254,120, 48, 48, 48, 48, 48, 48, 48,176,177,243,247,255,254,252,240,192,  0,  0,  1,  7, 31,255,252,240,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,255,255,255,  0,  0,  0,  0,  0,254,255,255,  1,  1,  7, 30,120,225,129,131,131,134,134,140,140,152,152,177,183,254,248,224,255,255,224,248,254,183,177,152,152,140,140,134,134,131,131,129,225,120, 30,  7,  1,  1,255,255,254,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0,255,255,  0,  0,192,192, 48, 48,  0,  0,240,240,  0,  0,  0,  0,  0,  0,240,240,  0,  0,240,240,192,192, 48, 48, 48, 48,192,192,  0,  0, 48, 48,243,243,  0,  0,  0,  0,  0,  0, 48, 48, 48, 48, 48, 48,192,192,  0,  0,  0,  0,  0,
        0,  0,  0,255,255,255,  0,  0,  0,  0,  0,127,255,255,128,128,224,120, 30,135,129,193,193, 97, 97, 49, 49, 25, 25,141,237,127, 31,  7,255,255,  7, 31,127,237,141, 25, 25, 49, 49, 97, 97,193,193,129,135, 30,120,224,128,128,255,255,127,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0, 63, 63,  3,  3, 12, 12, 48, 48,  0,  0,  0,  0, 51, 51, 51, 51, 51, 51, 15, 15,  0,  0, 63, 63,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 48, 48, 63, 63, 48, 48,  0,  0, 12, 12, 51, 51, 51, 51, 51, 51, 63, 63,  0,  0,  0,  0,  0,
        0,  0,  0,  0, 15, 63,255,248,224,128,  0,  0,  3, 15, 63,127,255,239,207,141, 13, 12, 12, 12, 12, 12, 12, 12, 30,127,225,128,  0,  0,255,255,  0,  0,128,225,127, 30, 12, 12, 12, 12, 12, 12, 12, 13,141,207,239,255,127, 63, 15,  3,  0,  0,128,224,248,255, 63, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  3,  7, 15, 62,124,248,240,224,192,128,  1,  3,  7, 15, 30, 28, 60, 56,120,112,112,224,224,225,231,254,248,255,255,248,254,231,225,224,224,112,112,120, 56, 60, 28, 30, 15,  7,  3,  1,128,192,224,240,248,124, 62, 15,  7,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  3,  7, 15, 14, 30, 28, 60, 56,120,112,112,112,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,112,112,112,120, 56, 60, 28, 30, 14, 15,  7,  3,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
    };
    oled_write_raw_P(kyria_logo, sizeof(kyria_logo));
}

static void render_qmk_logo(void) {
  static const char PROGMEM qmk_logo[] = {
    0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
    0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
    0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};

  oled_write_P(qmk_logo, false);
}

static void render_status(void) {
    // QMK Logo and version information
    render_qmk_logo();
    //oled_write_P(PSTR("       Kyria rev1.0\n\n"), false);

    // Host Keyboard Layer Status
    oled_write_P(PSTR("\n       "), false);

    switch (get_highest_layer(layer_state)) {
        case BASE:
            oled_write_P(PSTR("BUTECK-CV"), false);
            break;
        case HDWN:
            oled_write_P(PSTR("HD Gold"), false);
            break;
        case MEDR:
            oled_write_P(PSTR("Media"), false);
            break;
        case NAVR:
            oled_write_P(PSTR("Navigation"), false);
            break;
        case MOUR:
            oled_write_P(PSTR("Mouse"), false);
            break;
        case NSL:
            oled_write_P(PSTR("Numbers"), false);
            break;
        case FUNL:;
            oled_write_P(PSTR("Functions"), false);
            break;
        case INVRT:
            oled_write_P(PSTR("Onehand"), false);
            break;
        case SYMBOL:
            oled_write_P(PSTR("Symbols"), false);
            break;
        case QWERTY:
            oled_write_P(PSTR("QWERTY"), false);
            break;
        case GAME:
            oled_write_P(PSTR("Game"), false);
            break;
        case WIN_NAV:
            oled_write_P(PSTR("Win+Nav"), false);
            break;
        default:
            oled_write_P(PSTR("Undefined"), false);
    }
    oled_write_P(PSTR("\n"), false);

    // Host Keyboard LED Status
    // uint8_t led_usb_state = host_keyboard_leds();
    // oled_write_P(IS_LED_ON(led_usb_state, USB_LED_NUM_LOCK)    ? PSTR("NUMLCK ") : PSTR("       "), false);
    // oled_write_P(IS_LED_ON(led_usb_state, USB_LED_CAPS_LOCK)   ? PSTR("CAPLCK ") : PSTR("       "), false);
    // oled_write_P(IS_LED_ON(led_usb_state, USB_LED_SCROLL_LOCK) ? PSTR("SCRLCK ") : PSTR("       "), false);
    led_t led_usb_state = host_keyboard_led_state();
    oled_write_P(led_usb_state.num_lock    ? PSTR("NUMLCK ") : PSTR("       "), false);
    oled_write_P(led_usb_state.caps_lock   ? PSTR("CAPLCK ") : PSTR("       "), false);
    oled_write_P(led_usb_state.scroll_lock ? PSTR("SCRLCK ") : PSTR("       "), false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        render_status(); // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
        render_kyria_logo();
    }
    return false;
}
#endif


#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        switch (biton32(layer_state)) {
            case QWERTY:
                // History scrubbing. For Adobe products, hold shift while moving
                // backward to go forward instead.
                if (clockwise) {
                    tap_code16(C(KC_Z));
                } else {
                    tap_code16(C(KC_Y));
                }
                break;
            default:
                // Switch between windows on Windows with alt tab.
                if (clockwise) {
                    if (!is_alt_tab_active) {
                        is_alt_tab_active = true;
                        register_code(KC_LALT);
                    }
                    alt_tab_timer = timer_read();
                    tap_code16(KC_TAB);
                } else {
                    tap_code16(S(KC_TAB));
                }
                break;
        }
    } else if (index == 1) {
        switch (biton32(layer_state)) {
            case QWERTY:
                // Scrolling with PageUp and PgDn.
                if (clockwise) {
                    tap_code(KC_PGDN);
                } else {
                    tap_code(KC_PGUP);
                }
                break;
            default:
                // Volume control.
                if (clockwise) {
                    tap_code(KC_VOLU);
                } else {
                    tap_code(KC_VOLD);
                }
                break;
        }
    }
    return true;
}
#endif

// Adaptive Keys - Hands Down Gold
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Handle custom keycodes
    switch (keycode) {
        case BACKTICK:
            if (record->event.pressed) {
                tap_code16(DE_GRV);  // Dead key
                tap_code16(KC_SPC);  // Space to finalize it
            }
            return false;
        case TRIPLE_BACKTICK:
            if (record->event.pressed) {
                // Send three backticks
                tap_code16(DE_GRV);
                tap_code16(KC_SPC);
                tap_code16(DE_GRV);
                tap_code16(KC_SPC);
                tap_code16(DE_GRV);
                tap_code16(KC_SPC);
            }
            return false;
    }

    if (record->event.pressed) {
        uint16_t elapsed = timer_elapsed(adaptive_key_timer);

        // Check if this is a fast roll (within ADAPTIVE_KEY_TIMEOUT)
        if (elapsed < ADAPTIVE_KEY_TIMEOUT) {
            // GM -> GL (G + M = GL)
            if (last_keycode == DE_G && keycode == DE_M) {
                tap_code16(DE_G);
                tap_code16(DE_L);
                last_keycode = KC_NO;
                return false;
            }
            // PM -> PL (P + M = PL)
            if (last_keycode == DE_P && keycode == DE_M) {
                tap_code16(DE_P);
                tap_code16(DE_L);
                last_keycode = KC_NO;
                return false;
            }
            // PV -> LV (P + V = LV)
            if (last_keycode == DE_P && keycode == DE_V) {
                tap_code16(DE_L);
                tap_code16(DE_V);
                last_keycode = KC_NO;
                return false;
            }
            // BD -> BL (B + D = BL)
            if (last_keycode == DE_B && keycode == DE_D) {
                tap_code16(DE_B);
                tap_code16(DE_L);
                last_keycode = KC_NO;
                return false;
            }
            // DB -> LB (D + B = LB)
            if (last_keycode == DE_D && keycode == DE_B) {
                tap_code16(DE_L);
                tap_code16(DE_B);
                last_keycode = KC_NO;
                return false;
            }
            // ,A -> AU (comma + A = AU)
            if (last_keycode == DE_COMM && keycode == DE_A) {
                tap_code16(DE_A);
                tap_code16(DE_U);
                last_keycode = KC_NO;
                return false;
            }
            // MV -> MB (M + V = MB)
            if (last_keycode == DE_M && keycode == DE_V) {
                tap_code16(DE_M);
                tap_code16(DE_B);
                last_keycode = KC_NO;
                return false;
            }
        }

        // Update last key and timer
        last_keycode = keycode;
        adaptive_key_timer = timer_read();
    }

    return true;
}

