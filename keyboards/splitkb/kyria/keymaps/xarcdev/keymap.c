#include QMK_KEYBOARD_H
#include "keymap_german.h"
#include "keycodes.h"
#ifdef COMBO_ENABLE
    #include "combos.h"
#endif

#ifdef ADAPTIVEL_KEYS_ENABLED
    // Adaptive keys - Hands Down Gold
    #define ADAPTIVE_KEY_TIMEOUT 150
    static uint16_t adaptive_key_timer = 0;
    static uint16_t last_keycode = KC_NO;
    static bool last_key_buffered = false;
#endif

void keyboard_pre_init_user(void) {
    gpio_set_pin_output(24);
    gpio_write_pin_high(24);
}

enum custom_keycodes {
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
* Base Layer: Hands Down Gold
*
* ,-----------------------------------------------.                              ,------------------------------------------.
* | NXT LYR    |   J  |   G  |   M  |   P  |   V  |                              |   Ü  |   ,  |   .  |   "  |   '  |   ß   |
* |------------+------+------+------+------+------|                              |------+------+------+------+------+-------|
* | ESC        |   R  |   S  |   N  |   D  |   B  |                              |   Ö  |   A  |   E  |   I  |   H  |   X   |
* |------------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+-------|
* | RESET LYR  |   Z  |   F  |   L  |   C  |   W  | ____ | ____ |  | ____ | ____ |   Q   |   U  |   O  |   Y  |   K  |   -   |
* `----------------------+------+--------+--------+------+------|  |------+------+------+------+------+---------------------'
*                        | ____ | INVRT |  WINM | NAVI  | MOUSE |  | SYM  | NUM    | FUNC   | ____ | ____ |
*                        | ____ | ____  |  Esc  | Space | Tab   |  | Enter| Bspace |  T     | ___  |      |
*                         `-------------------------------------'  `----------------------------------------'
*                         Leader Key: Space + Backspace combo
*/
[BASE] = LAYOUT(
  TO(BUTCK), DE_J,  DE_G,  DE_M,  DE_P,  DE_V,                                    DE_UE, DE_COMM,  DE_DOT, DE_DQUO, DE_QUOT, DE_SS,
  KC_ESC,   DE_R,  DE_S,  DE_N,  DE_D,  DE_B,                                    DE_OE, DE_A,    DE_E,    DE_I,    DE_H,    DE_X,
  TO(BASE), DE_Z,  DE_F,  DE_L,  DE_C,  DE_W,  KC_NU, KC_NU,   KC_NU,  KC_NU,    DE_Q, DE_U,   DE_O,   DE_Y,   DE_K,   DE_MINS,
                       KC_NU, UC_TL1, UC_TL2, UC_TL3, UC_TL4,  UC_TR1, UC_TR2, UC_TR3, KC_NU, KC_TRNS
),

/*
* Navigation Layer: NAVR
*
* ,-----------------------------------------------.                              ,------------------------------------------.
* | RESET LYR  | ____ | ____ | ____ | ____ | ____ |                              | UNDO  | PAST | COPY | CUT  | REDO | ____ |
* |------------+------+------+------+------+------|                              |-------+------+------+------+------+------|
* | LOCK LYR   | ALT  | CTRL  | GUI | SHIFT| ____ |                              | CAPS  | LEFT | DOWN | UP   | RIGHT| ____ |
* |------------+------+------+------+------+------+-------------.  ,-------------+-------+------+------+------+------+------|
* | TOGGLE LYR | ____ | ____ | ____ | ____ | ____ | ____ | ____ |  | ____ | ____ | INS   | HOME | PGDN | PGUP | END  | ____ |
* `----------------------+------+--------+--------+------+------|  |------+------+-------+------+------+--------------------'
*                        | ____ | INVRT | WINM  | NAVI  | MOUSE |  |      |        |        | ____ | ____ |
*                        | ____ | Escape| Enter | Space | Tab   |  | Enter| Bspace | Delete | ____ | ____ |
*                         `-------------------------------------'  `--------------------------------------'
*/

[NAVR] = LAYOUT(
  TO(BASE),  KC_NU,   KC_NU,   KC_NU,   KC_NU,   KC_NU,                                KC_UNDO_C, KC_PASTE_C, KC_COPY_C, KC_CUT_C,  KC_REDO_C, KC_NU,
  LLOCK,  KC_LALT,   KC_LCTL,   KC_LSFT,   KC_LGUI,   KC_NU,                           KC_CAPS,   KC_LEFT,    KC_DOWN,   KC_UP,     KC_RGHT,   KC_NU,
  TO(BASE),  KC_NU, KC_NU, KC_NU, KC_NU, KC_NU, KC_NU, KC_NU,  KC_NU,   KC_NU, KC_INS,    KC_HOME,    KC_PGDN,   KC_PGUP,   KC_END,    KC_NU,
                         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_DEL, KC_TRNS, KC_TRNS
),

/*
 * Function Layer: FUNL
 *
 * DB_TOGG = Debug Toggle - enables/disables debug output via console
 *
 * ,------------------------------------------------.                              ,------------------------------------------------.
 * | RESET LYR  |  F12 |  F7  |  F8  |  F9  | PRINT |                              | EECLR| LOCK | BRID | BRIU | ____ |    ____    |
 * |------------+------+------+------+------+-------|                              |------+------+------+------+------+------------|
 * | LOCK LYR   |  F11 |  F4  |  F5  |  F6  | SLock |                              | ____ | GUI  | SHFT | CTL  | ALT  |   DEBUG    |
 * |------------+------+------+------+------+-------+-------------.  ,-------------+------+------+------+------+------+------------|
 * | RESET LYR  |  F10 |  F1  |  F2  |  F3  | PAUSE | ____ | ____ |  | ____ | ____ | ____ | MPRV | VOLD | VOLU | MNXT | PLAY/PAUSE |
 * `-----------------------+-------+-------+-------+-------+------|  |------+------+------+------+------+--------------------------'
 *                         | _____ | _____ | _____ | _____ | ____ |  | ____ | ____ | ____ | ____ | ____ |
 *                         |       |       |       |       |      |  |      |      |      |      |      |
 *                         `--------------------------------------'  `----------------------------------'
*/
[FUNL] = LAYOUT(
  TO(BASE),  KC_F12, KC_F7,  KC_F8,  KC_F9, KC_PSCR,                                    EE_CLR,  KC_LOCK,  KC_BRIGHTNESS_DOWN, KC_BRIGHTNESS_UP, KC_NU,   KC_NU,
  TO(FUNL),  KC_F11, KC_F4,  KC_F5,  KC_F6, KC_SCROLL_LOCK,                             KC_NU,   KC_LGUI,  KC_LSFT,            KC_LCTL,          KC_LALT, DB_TOGG,
  TO(BASE),  KC_F10, KC_F1,  KC_F2,  KC_F3, KC_PAUS,    KC_NU, KC_NU,  KC_NU,   KC_NU,  KC_NU,   KC_MPRV,  KC_VOLD,            KC_VOLU,          KC_MNXT, KC_MEDIA_PLAY_PAUSE,
                             KC_NU,   KC_NU,KC_NU,      KC_NU, KC_NU,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),

/*
 * Window Navigation Layer: WINM
 *
 * ,-----------------------------------------------------.                          ,-------------------------------------------------------.
 * | RESET LYR  | G+C+← | G+C+↓ | G+C+↑ | G+C+→ | _____ |                           | G+S+C+A+← | G+A+← | G+A+↓ | G+A+↑ | G+A+→ | G+S+C+A+→ |
 * |------------+------+-------+--------+-------+-------|                           |-----------+-------+-------+-------+-------+-----------|
 * | ____       |  ALT  |  CTRL |  SHIFT  | GUI | Layout|                           | _________ | GUI+← | GUI+↓ | GUI+↑ | GUI+→ | _________ |
 * |------------+-------+-------+---------+-----+-------+---------.   ,-------------+-----------+-------+-------+-------+-------+-----------|
 * | ____       | G+S+Tab  |  ____ | _____ | G+Tab | _____ | ____ |  | ____ | ____ | ___________| GUI+HOME|G+PGDN|G+PGUP|G+END  | _________ |
 * `-----------------------+-------+-------+-------+-------+------|  |------+------+------------+---------+------+------+-------+-----------'
 *                         | _____ | _____ | _____ | _____ | ____ |  | ____ | ____ | ____ | ____ | ____ |
 *                         |       |       |       |       |      |  |      |      |      |      |      |
 *                         `--------------------------------------'  `----------------------------------'
*/
[WINM] = LAYOUT(
  TO(BASE),  LCG(KC_LEFT), LCG(KC_DOWN), LCG(KC_UP), LCG(KC_RGHT), KC_NU,                                    HYPR(KC_LEFT), LAG(KC_LEFT),  LAG(KC_DOWN),  LAG(KC_UP),    LAG(KC_RGHT),  HYPR(KC_RGHT),
  KC_TRNS,   KC_LALT,      KC_LCTL,      KC_LSFT,    KC_LGUI,      LCG(DE_U),                                 KC_TRNS,       LGUI(KC_LEFT), LGUI(KC_DOWN), LGUI(KC_UP),   LGUI(KC_RGHT), KC_NU,
  KC_TRNS,   LSG(KC_TAB),  KC_NU,        KC_NU,      LGUI(KC_TAB), KC_NU,  KC_NU,  KC_NU,    KC_NU,  KC_NU,  KC_NU,         LGUI(KC_HOME), LGUI(KC_PGDN), LGUI(KC_PGUP), LGUI(KC_END),  KC_NU,
                           KC_TRNS,      KC_TRNS,    KC_TRNS,      KC_TRNS,KC_TRNS,KC_TRNS,  KC_TRNS,KC_TRNS,KC_TRNS,       KC_TRNS
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
* Base Layer: BUTECK-XCV
*
* ,-----------------------------------------------.                              ,------------------------------------------.
* | RESET LYR  |   F  |   M  |   L  |   C  |   P  |                              |   Ü  |   ,  |   .  |   U  |   B  |   ß   |
* |------------+------+------+------+------+------|                              |------+------+------+------+------+-------|
* | LOCK LYR   |   S  |   N  |   R  |   T  |   D  |                              |   O  |   A  |   E  |   I  |   H  |   X   |
* |------------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+-------|
* | TOGGLE LYR |   Z  |   V  |   W  |   G  |   J  | ____ | RESET|  | ____ | ____ |   Q  |   Ä  |   Ö  |   Y  |   K  |   -   |
* `----------------------+------+--------+--------+------+------|  |------+------+------+------+------+---------------------'
*                        | ____ | INVRT | WINM  | NAVI  | MOUSE |  | SYM  | NUM    | FUNC   | ____ | ____ |
*                        | ____ | ____  | Esc   | Space | Tab   |  | Enter| Bspace | Delete | ___  |      |
*                         `-------------------------------------'  `----------------------------------------'
*                         Leader Key: Space + Backspace combo
*/
[BUTCK] = LAYOUT(
  TO(QWERTY), DE_F,  DE_M,  DE_L,  DE_C,  DE_P,                                  DE_UE,  DE_COMM, DE_DOT, DE_U,  DE_B,  DE_SS,
  KC_ESC,    DE_S,  DE_N,  DE_R,  DE_T,  DE_D,                                  DE_O,   DE_A,    DE_E,   DE_I,  DE_H,  DE_X,
  TO(BASE), ALT_Z, CTL_V, SHT_W, GUI_G, DE_J,  KC_NU, KC_NU,  KC_NU,  KC_NU,  DE_Q,   GUI_AE,  SHT_OE, CTL_Y, ALT_K, DE_MINS,
                       KC_NU, UC_TL1, UC_TL2, UC_TL3, UC_TL4,  UC_TR1, UC_TR2, UC_TR3, KC_NU, KC_TRNS
),

/*
 * Base Layer: QWERTY
 *
 * ,----------------------------------------------.                              ,-------------------------------------------.
 * | RESET LYR |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |  | \   |
 * |-----------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * | LSFT      |   A  |   S  |  D   |   F  |   G  |                              |   H  |   J  |   K  |   L  | ;  : |  ' "   |
 * |-----------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | TOGGLE LYR|   Z  |   X  |   C  |   V  |   B  |      |      |  | Del  |Leader|   N  |   M  | ,  < | . >  | /  ? |  - _   |
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
    return state;
}

/* ********
* TAPPING TERM (FIXED)
**********/

//Base Tapping Term 200
//How long does it have to be pressed to activate layer instead of keypress
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case UC_TR2:
            return TAPPING_TERM - 45; //155
        case UC_TR1:
            return TAPPING_TERM - 50; //150

        default:
            return TAPPING_TERM;

    }
}

/* *********
* QUICK TAPPING TERM (DOUBLE_PRESS_AUTO_REPEAT_TERM)
**********/
//QUICK TAPPING TERM 80
uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        //BSPC -> NUML
        case UC_TR2:
            return QUICK_TAP_TERM -10; //60
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
        case WINM:
            oled_write_P(PSTR("Win-Moves"), false);
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
bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;

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


#ifdef ADAPTIVE_KEYS_ENABLE
// Helper function to check if a key could start an adaptive sequence
bool is_adaptive_start_key(uint16_t keycode) {
    return (keycode == DE_G || keycode == DE_P || keycode == DE_B ||
            keycode == DE_D || keycode == DE_COMM || keycode == DE_M);
}

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

        // Check if we have a buffered key and if it's within the timeout window
        if (last_key_buffered && elapsed < ADAPTIVE_KEY_TIMEOUT) {
            // Check for adaptive key sequences
            bool is_adaptive = false;

            // GM -> GL (G + M = GL)
            if (last_keycode == DE_G && keycode == DE_M) {
                tap_code16(DE_G);
                tap_code16(DE_L);
                is_adaptive = true;
            }
            // PM -> PL (P + M = PL)
            else if (last_keycode == DE_P && keycode == DE_M) {
                tap_code16(DE_P);
                tap_code16(DE_L);
                is_adaptive = true;
            }
            // PV -> LV (P + V = LV)
            else if (last_keycode == DE_P && keycode == DE_V) {
                tap_code16(DE_L);
                tap_code16(DE_V);
                is_adaptive = true;
            }
            // BD -> BL (B + D = BL)
            else if (last_keycode == DE_B && keycode == DE_D) {
                tap_code16(DE_B);
                tap_code16(DE_L);
                is_adaptive = true;
            }
            // DB -> LB (D + B = LB)
            else if (last_keycode == DE_D && keycode == DE_B) {
                tap_code16(DE_L);
                tap_code16(DE_B);
                is_adaptive = true;
            }
            // ,A -> AU (comma + A = AU)
            else if (last_keycode == DE_COMM && keycode == DE_A) {
                tap_code16(DE_A);
                tap_code16(DE_U);
                is_adaptive = true;
            }
            // MV -> MB (M + V = MB)
            else if (last_keycode == DE_M && keycode == DE_V) {
                tap_code16(DE_M);
                tap_code16(DE_B);
                is_adaptive = true;
            }

            if (is_adaptive) {
                // Adaptive sequence detected, clear buffer and skip current key
                last_keycode = KC_NO;
                last_key_buffered = false;
                return false;
            } else {
                // Not an adaptive sequence, send the buffered key first
                tap_code16(last_keycode);
                last_key_buffered = false;
                // Continue to process current key below
            }
        } else if (last_key_buffered) {
            // Timeout expired, send buffered key
            tap_code16(last_keycode);
            last_key_buffered = false;
            // Continue to process current key below
        }

        // Check if current key could start an adaptive sequence
        if (is_adaptive_start_key(keycode)) {
            // Buffer this key instead of sending it
            last_keycode = keycode;
            last_key_buffered = true;
            adaptive_key_timer = timer_read();
            return false;  // Don't send the key yet
        } else {
            // Normal key, update tracker but allow it to be sent
            last_keycode = keycode;
            adaptive_key_timer = timer_read();
            return true;
        }
    } else {
        // Key release - if we have a buffered key, send it now
        if (last_key_buffered && last_keycode == keycode) {
            tap_code16(last_keycode);
            last_key_buffered = false;
            last_keycode = KC_NO;
            return false;
        }
    }
    return true;
}
#endif

