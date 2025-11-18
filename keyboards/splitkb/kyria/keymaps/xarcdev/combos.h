#pragma once
#include <stdint.h>
#include <stdbool.h>
#include "keycodes.h"
#include "quantum.h"

/************************
* COMBOS
***********************/
//Name of combos
enum combo_events  {
    COMBO_CTL_C,
    COMBO_CTL_V,
    COMBO_CTL_X,
    COMBO_CTL_S,
    COMBO_CTL_Z,
    COMBO_SHT_CTL_Z,

    WIN_CTL_LEFT,
    WIN_CTL_RIGHT,

    ALT_UP,
    ALT_LEFT,
    ALT_RIGHT,
    ALT_DOWN,
    RWIN_SHT_S,

    QUICK_TERMINAL,

    BSPC_LSFT_CLEAR,
    QUICK_WINDOWS,
    QUICK_VBOX,

    COMBO_CTL_A,

    // Hands Down Gold combos
    SEMICOLON_COMBO,
    AE_UMLAUT,
    QU_COMBO,
    GJ_COMBO,

    // H-digraph combos
    TH_COMBO,
    CH_COMBO,
    SH_COMBO,
    GH_COMBO,
    PH_COMBO,

    // Leader key combo
    LEADER_COMBO,

    // Specific modifier + key combos (Hands Down Gold)
    GUI_TAB,             // D + Tab = GUI+Tab
    SHT_TAB,             // N + Tab = Shift+Tab
    ALT_TAB,             // R + Tab = Alt+Tab
    CTL_TAB,             // S + Tab = Ctrl+Tab
    ALT_SPACE,           // R + Space = Alt+Space
    SHT_CTL_TAB,         // S + N + Tab = Shift+Ctrl+Tab

    // Two-modifier + Space combos
    GUI_SHT_SPACE,          // D + N + Space = GUI+Shift+Space
    GUI_CTL_SPACE,          // D + S + Space = GUI+Ctrl+Space
    GUI_ALT_SPACE,          // D + R + Space = GUI+Alt+Space
    CTL_SHT_SPACE,          // S + N + Space = Ctrl+Shift+Space
    CTL_ALT_SPACE,          // S + R + Space = Ctrl+Alt+Space
    SHT_ALT_SPACE,          // N + R + Space = Shift+Alt+Space

    // Three-modifier + Space combos
    GUI_SHT_CTL_SPACE,      // D + N + S + Space = GUI+Shift+Ctrl+Space
    GUI_SHT_ALT_SPACE,      // D + N + R + Space = GUI+Shift+Alt+Space
    GUI_CTL_ALT_SPACE,      // D + S + R + Space = GUI+Ctrl+Alt+Space
    CTL_SHT_ALT_SPACE,      // S + N + R + Space = Ctrl+Shift+Alt+Space

    // Thumb-gated HRM combos - Single modifiers
    // BUTECK layout
    HRM_ALT_Z,
    HRM_CTL_V,
    HRM_SHT_W,
    HRM_GUI_G,
    HRM_GUI_AE,
    HRM_SHT_OE,
    HRM_CTL_Y,
    HRM_ALT_K,

    // Hands Down Gold layout (middle row: R S N D | A E I H)
    HRM_ALT_R_HD,
    HRM_CTL_S_HD,
    HRM_SHT_N_HD,
    HRM_GUI_D_HD,
    HRM_GUI_A_HD,
    HRM_SHT_E_HD,
    HRM_CTL_I_HD,
    HRM_ALT_H_HD,

    // QWERTY layout
    HRM_ALT_Z_Q,
    HRM_CTL_X_Q,
    HRM_SHT_C_Q,
    HRM_GUI_V_Q,
    HRM_GUI_M_Q,
    HRM_SHT_COMM_Q,
    HRM_CTL_DOT_Q,
    HRM_ALT_SLSH_Q,

    // Thumb-gated multi-modifier combos (UC_TL2 + 2 homerow keys) - Hands Down Gold
    HRM_GUI_SHT,     // UC_TL2 + D + N = GUI+Shift
    HRM_GUI_CTL,     // UC_TL2 + D + S = GUI+Ctrl
    HRM_GUI_ALT,     // UC_TL2 + D + R = GUI+Alt
    HRM_CTL_SHT,     // UC_TL2 + S + N = Ctrl+Shift
    HRM_CTL_ALT,     // UC_TL2 + S + R = Ctrl+Alt
    HRM_SHT_ALT,     // UC_TL2 + N + R = Shift+Alt

    // Thumb-gated three-modifier combos (UC_TL2 + 3 homerow keys) - Hands Down Gold
    HRM_GUI_CTL_SHT, // UC_TL2 + D + S + N = GUI+Ctrl+Shift
    HRM_GUI_CTL_ALT, // UC_TL2 + D + S + R = GUI+Ctrl+Alt
    HRM_GUI_SHT_ALT, // UC_TL2 + D + N + R = GUI+Shift+Alt
    HRM_CTL_SHT_ALT, // UC_TL2 + S + N + R = Ctrl+Shift+Alt

    // Thumb-gated four-modifier combo (UC_TL2 + 4 homerow keys) - Hands Down Gold
    HRM_ALL_MODS,    // UC_TL2 + D + S + N + R = GUI+Ctrl+Shift+Alt

    // Thumb-gated multi-modifier combos (UC_TL2 + 2 homerow keys) - Hands Down Gold RIGHT SIDE
    HRM_GUI_SHT_R,     // UC_TL2 + A + E = GUI+Shift
    HRM_GUI_CTL_R,     // UC_TL2 + A + I = GUI+Ctrl
    HRM_GUI_ALT_R,     // UC_TL2 + A + H = GUI+Alt
    HRM_CTL_SHT_R,     // UC_TL2 + I + E = Ctrl+Shift
    HRM_CTL_ALT_R,     // UC_TL2 + I + H = Ctrl+Alt
    HRM_SHT_ALT_R,     // UC_TL2 + E + H = Shift+Alt

    // Thumb-gated three-modifier combos (UC_TL2 + 3 homerow keys) - Hands Down Gold RIGHT SIDE
    HRM_GUI_CTL_SHT_R, // UC_TL2 + A + I + E = GUI+Ctrl+Shift
    HRM_GUI_CTL_ALT_R, // UC_TL2 + A + I + H = GUI+Ctrl+Alt
    HRM_GUI_SHT_ALT_R, // UC_TL2 + A + E + H = GUI+Shift+Alt
    HRM_CTL_SHT_ALT_R, // UC_TL2 + I + E + H = Ctrl+Shift+Alt

    // Thumb-gated four-modifier combo (UC_TL2 + 4 homerow keys) - Hands Down Gold RIGHT SIDE
    HRM_ALL_MODS_R,    // UC_TL2 + A + I + E + H = GUI+Ctrl+Shift+Alt

    // NAV layer + modifier combos (UC_TL3 + left homerow keys) - Hands Down Gold
    // Single modifier + NAV
    NAV_ALT,           // UC_TL3 + R = Alt + Nav layer
    NAV_CTL,           // UC_TL3 + S = Ctrl + Nav layer
    NAV_SHT,           // UC_TL3 + N = Shift + Nav layer
    NAV_GUI,           // UC_TL3 + D = GUI + Nav layer

    // Two modifiers + NAV
    NAV_GUI_SHT,       // UC_TL3 + D + N = GUI+Shift + Nav layer
    NAV_GUI_CTL,       // UC_TL3 + D + S = GUI+Ctrl + Nav layer
    NAV_GUI_ALT,       // UC_TL3 + D + R = GUI+Alt + Nav layer
    NAV_CTL_SHT,       // UC_TL3 + S + N = Ctrl+Shift + Nav layer
    NAV_CTL_ALT,       // UC_TL3 + S + R = Ctrl+Alt + Nav layer
    NAV_SHT_ALT,       // UC_TL3 + N + R = Shift+Alt + Nav layer

    // Three modifiers + NAV
    NAV_GUI_CTL_SHT,   // UC_TL3 + D + S + N = GUI+Ctrl+Shift + Nav layer
    NAV_GUI_CTL_ALT,   // UC_TL3 + D + S + R = GUI+Ctrl+Alt + Nav layer
    NAV_GUI_SHT_ALT,   // UC_TL3 + D + N + R = GUI+Shift+Alt + Nav layer
    NAV_CTL_SHT_ALT,   // UC_TL3 + S + N + R = Ctrl+Shift+Alt + Nav layer

    // Four modifiers + NAV
    NAV_ALL_MODS,      // UC_TL3 + D + S + N + R = GUI+Ctrl+Shift+Alt + Nav layer

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

const uint16_t PROGMEM win_ctrl_left_combo[] = { ALT_Z, GUI_G, KC_LEFT, COMBO_END };
const uint16_t PROGMEM win_ctrl_right_combo[] = { ALT_Z, GUI_G, KC_RGHT, COMBO_END };

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

// Combos for efficiency
const uint16_t PROGMEM gj_combo[] = { DE_G, DE_J, COMBO_END };              // G + J = Escape

// H-digraph combos (Hands Down Gold recommended)
const uint16_t PROGMEM th_combo[] = { DE_D, DE_N, COMBO_END };              // D + N = TH
const uint16_t PROGMEM ch_combo[] = { GUI_D_HD, SHT_N_HD, COMBO_END };            // D + N = CH
const uint16_t PROGMEM sh_combo[] = { DE_S, DE_N, COMBO_END };              // S + N = SH
const uint16_t PROGMEM gh_combo[] = { DE_G, DE_M, COMBO_END };              // G + M = GH
const uint16_t PROGMEM ph_combo[] = { DE_P, DE_M, COMBO_END };              // P + M = PH

// Leader key combo
const uint16_t PROGMEM leader_combo[] = { UC_TL3, UC_TR2, COMBO_END };      // Space + Backspace = Leader

// Specific modifier + key combos (Hands Down Gold)
const uint16_t PROGMEM gui_tab_combo[] = { GUI_D_HD, UC_TL4, COMBO_END };
const uint16_t PROGMEM sht_tab_combo[] = { SHT_N_HD, UC_TL4, COMBO_END };
const uint16_t PROGMEM alt_tab_combo[] = { ALT_R_HD, UC_TL4, COMBO_END };
const uint16_t PROGMEM ctl_tab_combo[] = { CTL_S_HD, UC_TL4, COMBO_END };
const uint16_t PROGMEM alt_space_combo[] = { ALT_R_HD, UC_TL3, COMBO_END };

const uint16_t PROGMEM alt_up_combo[] = { ALT_R_HD, KC_UP, COMBO_END };
const uint16_t PROGMEM alt_down_combo[] = { ALT_R_HD, KC_DOWN, COMBO_END };
const uint16_t PROGMEM alt_left_combo[] = { ALT_R_HD, KC_LEFT, COMBO_END };
const uint16_t PROGMEM alt_right_combo[] = { ALT_R_HD, KC_RGHT, COMBO_END };

// Two-modifier + key combos
const uint16_t PROGMEM sht_ctl_tab_combo[] = { CTL_S_HD, SHT_N_HD, UC_TL4, COMBO_END };


// Two-modifier + Space combos
const uint16_t PROGMEM gui_sht_space_combo[] = { GUI_D_HD, SHT_N_HD, UC_TL3, COMBO_END };
const uint16_t PROGMEM gui_ctl_space_combo[] = { GUI_D_HD, CTL_S_HD, UC_TL3, COMBO_END };
const uint16_t PROGMEM gui_alt_space_combo[] = { GUI_D_HD, ALT_R_HD, UC_TL3, COMBO_END };
const uint16_t PROGMEM ctl_sht_space_combo[] = { CTL_S_HD, SHT_N_HD, UC_TL3, COMBO_END };
const uint16_t PROGMEM ctl_alt_space_combo[] = { CTL_S_HD, ALT_R_HD, UC_TL3, COMBO_END };
const uint16_t PROGMEM sht_alt_space_combo[] = { SHT_N_HD, ALT_R_HD, UC_TL3, COMBO_END };

// Three-modifier + Space combos
const uint16_t PROGMEM gui_sht_ctl_space_combo[] = { GUI_D_HD, SHT_N_HD, CTL_S_HD, UC_TL3, COMBO_END };
const uint16_t PROGMEM gui_sht_alt_space_combo[] = { GUI_D_HD, SHT_N_HD, ALT_R_HD, UC_TL3, COMBO_END };
const uint16_t PROGMEM gui_ctl_alt_space_combo[] = { GUI_D_HD, CTL_S_HD, ALT_R_HD, UC_TL3, COMBO_END };
const uint16_t PROGMEM ctl_sht_alt_space_combo[] = { CTL_S_HD, SHT_N_HD, ALT_R_HD, UC_TL3, COMBO_END };

// Thumb-gated HRM combos - Single modifiers
// BUTECK layout
const uint16_t PROGMEM hrm_alt_z_combo[] = { UC_TL2, ALT_Z, COMBO_END };
const uint16_t PROGMEM hrm_ctl_v_combo[] = { UC_TL2, CTL_V, COMBO_END };
const uint16_t PROGMEM hrm_sht_w_combo[] = { UC_TL2, SHT_W, COMBO_END };
const uint16_t PROGMEM hrm_gui_g_combo[] = { UC_TL2, GUI_G, COMBO_END };
const uint16_t PROGMEM hrm_gui_ae_combo[] = { UC_TL2, GUI_AE, COMBO_END };
const uint16_t PROGMEM hrm_sht_oe_combo[] = { UC_TL2, SHT_OE, COMBO_END };
const uint16_t PROGMEM hrm_ctl_y_combo[] = { UC_TL2, CTL_Y, COMBO_END };
const uint16_t PROGMEM hrm_alt_k_combo[] = { UC_TL2, ALT_K, COMBO_END };

// Hands Down Gold layout
const uint16_t PROGMEM hrm_alt_r_hd_combo[] = { UC_TL2, ALT_R_HD, COMBO_END };
const uint16_t PROGMEM hrm_ctl_s_hd_combo[] = { UC_TL2, CTL_S_HD, COMBO_END };
const uint16_t PROGMEM hrm_sht_n_hd_combo[] = { UC_TL2, SHT_N_HD, COMBO_END };
const uint16_t PROGMEM hrm_gui_d_hd_combo[] = { UC_TL2, GUI_D_HD, COMBO_END };
const uint16_t PROGMEM hrm_gui_a_hd_combo[] = { UC_TL2, GUI_A_HD, COMBO_END };
const uint16_t PROGMEM hrm_sht_e_hd_combo[] = { UC_TL2, SHT_E_HD, COMBO_END };
const uint16_t PROGMEM hrm_ctl_i_hd_combo[] = { UC_TL2, CTL_I_HD, COMBO_END };
const uint16_t PROGMEM hrm_alt_h_hd_combo[] = { UC_TL2, ALT_H_HD, COMBO_END };

// QWERTY layout
const uint16_t PROGMEM hrm_alt_z_q_combo[] = { UC_TL2, ALT_Z_Q, COMBO_END };
const uint16_t PROGMEM hrm_ctl_x_q_combo[] = { UC_TL2, CTL_X, COMBO_END };
const uint16_t PROGMEM hrm_sht_c_q_combo[] = { UC_TL2, SHT_C, COMBO_END };
const uint16_t PROGMEM hrm_gui_v_q_combo[] = { UC_TL2, GUI_V, COMBO_END };
const uint16_t PROGMEM hrm_gui_m_q_combo[] = { UC_TL2, GUI_M, COMBO_END };
const uint16_t PROGMEM hrm_sht_comm_q_combo[] = { UC_TL2, SHT_COMM, COMBO_END };
const uint16_t PROGMEM hrm_ctl_dot_q_combo[] = { UC_TL2, CTL_DOT, COMBO_END };
const uint16_t PROGMEM hrm_alt_slsh_q_combo[] = { UC_TL2, ALT_SLSH, COMBO_END };

// Thumb-gated multi-modifier combos (UC_TL2 + 2 homerow keys) - Hands Down Gold
const uint16_t PROGMEM hrm_gui_sht_combo[] = { UC_TL2, GUI_D_HD, SHT_N_HD, COMBO_END };
const uint16_t PROGMEM hrm_gui_ctl_combo[] = { UC_TL2, GUI_D_HD, CTL_S_HD, COMBO_END };
const uint16_t PROGMEM hrm_gui_alt_combo[] = { UC_TL2, GUI_D_HD, ALT_R_HD, COMBO_END };
const uint16_t PROGMEM hrm_ctl_sht_combo[] = { UC_TL2, CTL_S_HD, SHT_N_HD, COMBO_END };
const uint16_t PROGMEM hrm_ctl_alt_combo[] = { UC_TL2, CTL_S_HD, ALT_R_HD, COMBO_END };
const uint16_t PROGMEM hrm_sht_alt_combo[] = { UC_TL2, SHT_N_HD, ALT_R_HD, COMBO_END };

// Thumb-gated three-modifier combos (UC_TL2 + 3 homerow keys) - Hands Down Gold
const uint16_t PROGMEM hrm_gui_ctl_sht_combo[] = { UC_TL2, GUI_D_HD, CTL_S_HD, SHT_N_HD, COMBO_END };
const uint16_t PROGMEM hrm_gui_ctl_alt_combo[] = { UC_TL2, GUI_D_HD, CTL_S_HD, ALT_R_HD, COMBO_END };
const uint16_t PROGMEM hrm_gui_sht_alt_combo[] = { UC_TL2, GUI_D_HD, SHT_N_HD, ALT_R_HD, COMBO_END };
const uint16_t PROGMEM hrm_ctl_sht_alt_combo[] = { UC_TL2, CTL_S_HD, SHT_N_HD, ALT_R_HD, COMBO_END };

// Thumb-gated four-modifier combo (UC_TL2 + 4 homerow keys) - Hands Down Gold
const uint16_t PROGMEM hrm_all_mods_combo[] = { UC_TL2, GUI_D_HD, CTL_S_HD, SHT_N_HD, ALT_R_HD, COMBO_END };

// Thumb-gated multi-modifier combos (UC_TL2 + 2 homerow keys) - Hands Down Gold RIGHT SIDE
const uint16_t PROGMEM hrm_gui_sht_r_combo[] = { UC_TL2, GUI_A_HD, SHT_E_HD, COMBO_END };
const uint16_t PROGMEM hrm_gui_ctl_r_combo[] = { UC_TL2, GUI_A_HD, CTL_I_HD, COMBO_END };
const uint16_t PROGMEM hrm_gui_alt_r_combo[] = { UC_TL2, GUI_A_HD, ALT_H_HD, COMBO_END };
const uint16_t PROGMEM hrm_ctl_sht_r_combo[] = { UC_TL2, CTL_I_HD, SHT_E_HD, COMBO_END };
const uint16_t PROGMEM hrm_ctl_alt_r_combo[] = { UC_TL2, CTL_I_HD, ALT_H_HD, COMBO_END };
const uint16_t PROGMEM hrm_sht_alt_r_combo[] = { UC_TL2, SHT_E_HD, ALT_H_HD, COMBO_END };

// Thumb-gated three-modifier combos (UC_TL2 + 3 homerow keys) - Hands Down Gold RIGHT SIDE
const uint16_t PROGMEM hrm_gui_ctl_sht_r_combo[] = { UC_TL2, GUI_A_HD, CTL_I_HD, SHT_E_HD, COMBO_END };
const uint16_t PROGMEM hrm_gui_ctl_alt_r_combo[] = { UC_TL2, GUI_A_HD, CTL_I_HD, ALT_H_HD, COMBO_END };
const uint16_t PROGMEM hrm_gui_sht_alt_r_combo[] = { UC_TL2, GUI_A_HD, SHT_E_HD, ALT_H_HD, COMBO_END };
const uint16_t PROGMEM hrm_ctl_sht_alt_r_combo[] = { UC_TL2, CTL_I_HD, SHT_E_HD, ALT_H_HD, COMBO_END };

// Thumb-gated four-modifier combo (UC_TL2 + 4 homerow keys) - Hands Down Gold RIGHT SIDE
const uint16_t PROGMEM hrm_all_mods_r_combo[] = { UC_TL2, GUI_A_HD, CTL_I_HD, SHT_E_HD, ALT_H_HD, COMBO_END };

// NAV layer + modifier combos (UC_TL3 + left homerow keys) - Hands Down Gold
// Single modifier + NAV
const uint16_t PROGMEM nav_alt_combo[] = { UC_TL3, ALT_R_HD, COMBO_END };
const uint16_t PROGMEM nav_ctl_combo[] = { UC_TL3, CTL_S_HD, COMBO_END };
const uint16_t PROGMEM nav_sht_combo[] = { UC_TL3, SHT_N_HD, COMBO_END };
const uint16_t PROGMEM nav_gui_combo[] = { UC_TL3, GUI_D_HD, COMBO_END };

// Two modifiers + NAV
const uint16_t PROGMEM nav_gui_sht_combo[] = { UC_TL3, GUI_D_HD, SHT_N_HD, COMBO_END };
const uint16_t PROGMEM nav_gui_ctl_combo[] = { UC_TL3, GUI_D_HD, CTL_S_HD, COMBO_END };
const uint16_t PROGMEM nav_gui_alt_combo[] = { UC_TL3, GUI_D_HD, ALT_R_HD, COMBO_END };
const uint16_t PROGMEM nav_ctl_sht_combo[] = { UC_TL3, CTL_S_HD, SHT_N_HD, COMBO_END };
const uint16_t PROGMEM nav_ctl_alt_combo[] = { UC_TL3, CTL_S_HD, ALT_R_HD, COMBO_END };
const uint16_t PROGMEM nav_sht_alt_combo[] = { UC_TL3, SHT_N_HD, ALT_R_HD, COMBO_END };

// Three modifiers + NAV
const uint16_t PROGMEM nav_gui_ctl_sht_combo[] = { UC_TL3, GUI_D_HD, CTL_S_HD, SHT_N_HD, COMBO_END };
const uint16_t PROGMEM nav_gui_ctl_alt_combo[] = { UC_TL3, GUI_D_HD, CTL_S_HD, ALT_R_HD, COMBO_END };
const uint16_t PROGMEM nav_gui_sht_alt_combo[] = { UC_TL3, GUI_D_HD, SHT_N_HD, ALT_R_HD, COMBO_END };
const uint16_t PROGMEM nav_ctl_sht_alt_combo[] = { UC_TL3, CTL_S_HD, SHT_N_HD, ALT_R_HD, COMBO_END };

// Four modifiers + NAV
const uint16_t PROGMEM nav_all_mods_combo[] = { UC_TL3, GUI_D_HD, CTL_S_HD, SHT_N_HD, ALT_R_HD, COMBO_END };


//Combo Action
combo_t key_combos[COMBO_LENGTH] = {
    [COMBO_CTL_C]  = COMBO(copy_combo, LCTL(DE_C)),
    [COMBO_CTL_V] = COMBO(paste_combo, LCTL(DE_V)),
    [COMBO_CTL_X] = COMBO(cut_combo, LCTL(DE_X)),
    [COMBO_CTL_S]  = COMBO(save_combo, LCTL(DE_S)),
    [COMBO_CTL_Z] = COMBO(undo_combo, LCTL(DE_Z)),
    [COMBO_SHT_CTL_Z] = COMBO(redo_combo, LCTL(LSFT(DE_Z))),
    [WIN_CTL_LEFT] = COMBO(win_ctrl_left_combo, LGUI(LCTL(KC_LEFT))),
    [WIN_CTL_RIGHT] = COMBO(win_ctrl_right_combo, LGUI(LCTL(KC_RGHT))),
    [ALT_UP] = COMBO(alt_up_combo, LALT(KC_UP)),
    [ALT_DOWN] = COMBO(alt_down_combo, LALT(KC_DOWN)),
    [ALT_LEFT] = COMBO(alt_left_combo, LALT(KC_LEFT)),
    [ALT_RIGHT] = COMBO(alt_right_combo, LALT(KC_RGHT)),
    [RWIN_SHT_S] = COMBO(rwin_shift_s_combo, LGUI(LSFT(DE_S))),

    [QUICK_TERMINAL] = COMBO_ACTION(quick_terminal_combo),

    // [CTL_W] = COMBO(close_combo, LCTL(DE_W)),
    // [CTL_W_B] = COMBO(close_combo_b, LCTL(DE_W)),
    [BSPC_LSFT_CLEAR] = COMBO_ACTION(clear_line_combo),
    [QUICK_WINDOWS] = COMBO_ACTION(quick_win_combo),
    [QUICK_VBOX] = COMBO_ACTION(quick_vbox_combo),
    [COMBO_CTL_A] = COMBO_ACTION(select_all_combo),

    // Hands Down Gold combos
    [SEMICOLON_COMBO] = COMBO(semicolon_combo, DE_SCLN),
    [AE_UMLAUT] = COMBO(ae_umlaut_combo, DE_AE),
    [QU_COMBO] = COMBO_ACTION(qu_combo),

    // Combos for efficiency
    [GJ_COMBO] = COMBO_ACTION(gj_combo),

    // H-digraph combos
    [TH_COMBO] = COMBO_ACTION(th_combo),
    [CH_COMBO] = COMBO_ACTION(ch_combo),
    [SH_COMBO] = COMBO_ACTION(sh_combo),
    [GH_COMBO] = COMBO_ACTION(gh_combo),
    [PH_COMBO] = COMBO_ACTION(ph_combo),

    // Leader key combo
    [LEADER_COMBO] = COMBO(leader_combo, QK_LEADER),

    // Specific modifier + key combos
    [GUI_TAB] = COMBO_ACTION(gui_tab_combo),
    [SHT_TAB] = COMBO_ACTION(sht_tab_combo),
    [ALT_TAB] = COMBO_ACTION(alt_tab_combo),
    [CTL_TAB] = COMBO_ACTION(ctl_tab_combo),
    [ALT_SPACE] = COMBO(alt_space_combo, LALT(KC_SPC)),

    // Two-modifier + key combos
    [SHT_CTL_TAB] = COMBO_ACTION(sht_ctl_tab_combo),
 
    // Two-modifier + Space combos
    [GUI_SHT_SPACE] = COMBO(gui_sht_space_combo, LGUI(LSFT(KC_SPC))),
    [GUI_CTL_SPACE] = COMBO(gui_ctl_space_combo, LGUI(LCTL(KC_SPC))),
    [GUI_ALT_SPACE] = COMBO(gui_alt_space_combo, LGUI(LALT(KC_SPC))),
    [CTL_SHT_SPACE] = COMBO(ctl_sht_space_combo, LCTL(LSFT(KC_SPC))),
    [CTL_ALT_SPACE] = COMBO(ctl_alt_space_combo, LCTL(LALT(KC_SPC))),
    [SHT_ALT_SPACE] = COMBO(sht_alt_space_combo, LSFT(LALT(KC_SPC))),

    // Three-modifier + Space combos
    [GUI_SHT_CTL_SPACE] = COMBO(gui_sht_ctl_space_combo, LGUI(LSFT(LCTL(KC_SPC)))),
    [GUI_SHT_ALT_SPACE] = COMBO(gui_sht_alt_space_combo, LGUI(LSFT(LALT(KC_SPC)))),
    [GUI_CTL_ALT_SPACE] = COMBO(gui_ctl_alt_space_combo, LGUI(LCTL(LALT(KC_SPC)))),
    [CTL_SHT_ALT_SPACE] = COMBO(ctl_sht_alt_space_combo, LCTL(LSFT(LALT(KC_SPC)))),

    // Thumb-gated HRM combos - BUTECK layout
    [HRM_ALT_Z] = COMBO_ACTION(hrm_alt_z_combo),
    [HRM_CTL_V] = COMBO_ACTION(hrm_ctl_v_combo),
    [HRM_SHT_W] = COMBO_ACTION(hrm_sht_w_combo),
    [HRM_GUI_G] = COMBO_ACTION(hrm_gui_g_combo),
    [HRM_GUI_AE] = COMBO_ACTION(hrm_gui_ae_combo),
    [HRM_SHT_OE] = COMBO_ACTION(hrm_sht_oe_combo),
    [HRM_CTL_Y] = COMBO_ACTION(hrm_ctl_y_combo),
    [HRM_ALT_K] = COMBO_ACTION(hrm_alt_k_combo),

    // Hands Down Gold layout
    [HRM_ALT_R_HD] = COMBO_ACTION(hrm_alt_r_hd_combo),
    [HRM_CTL_S_HD] = COMBO_ACTION(hrm_ctl_s_hd_combo),
    [HRM_SHT_N_HD] = COMBO_ACTION(hrm_sht_n_hd_combo),
    [HRM_GUI_D_HD] = COMBO_ACTION(hrm_gui_d_hd_combo),
    [HRM_GUI_A_HD] = COMBO_ACTION(hrm_gui_a_hd_combo),
    [HRM_SHT_E_HD] = COMBO_ACTION(hrm_sht_e_hd_combo),
    [HRM_CTL_I_HD] = COMBO_ACTION(hrm_ctl_i_hd_combo),
    [HRM_ALT_H_HD] = COMBO_ACTION(hrm_alt_h_hd_combo),

    // QWERTY layout
    [HRM_ALT_Z_Q] = COMBO_ACTION(hrm_alt_z_q_combo),
    [HRM_CTL_X_Q] = COMBO_ACTION(hrm_ctl_x_q_combo),
    [HRM_SHT_C_Q] = COMBO_ACTION(hrm_sht_c_q_combo),
    [HRM_GUI_V_Q] = COMBO_ACTION(hrm_gui_v_q_combo),
    [HRM_GUI_M_Q] = COMBO_ACTION(hrm_gui_m_q_combo),
    [HRM_SHT_COMM_Q] = COMBO_ACTION(hrm_sht_comm_q_combo),
    [HRM_CTL_DOT_Q] = COMBO_ACTION(hrm_ctl_dot_q_combo),
    [HRM_ALT_SLSH_Q] = COMBO_ACTION(hrm_alt_slsh_q_combo),

    // Thumb-gated multi-modifier combos - Hands Down Gold
    [HRM_GUI_SHT] = COMBO_ACTION(hrm_gui_sht_combo),
    [HRM_GUI_CTL] = COMBO_ACTION(hrm_gui_ctl_combo),
    [HRM_GUI_ALT] = COMBO_ACTION(hrm_gui_alt_combo),
    [HRM_CTL_SHT] = COMBO_ACTION(hrm_ctl_sht_combo),
    [HRM_CTL_ALT] = COMBO_ACTION(hrm_ctl_alt_combo),
    [HRM_SHT_ALT] = COMBO_ACTION(hrm_sht_alt_combo),
    [HRM_GUI_CTL_SHT] = COMBO_ACTION(hrm_gui_ctl_sht_combo),
    [HRM_GUI_CTL_ALT] = COMBO_ACTION(hrm_gui_ctl_alt_combo),
    [HRM_GUI_SHT_ALT] = COMBO_ACTION(hrm_gui_sht_alt_combo),
    [HRM_CTL_SHT_ALT] = COMBO_ACTION(hrm_ctl_sht_alt_combo),
    [HRM_ALL_MODS] = COMBO_ACTION(hrm_all_mods_combo),

    // Thumb-gated multi-modifier combos - Hands Down Gold RIGHT SIDE
    [HRM_GUI_SHT_R] = COMBO_ACTION(hrm_gui_sht_r_combo),
    [HRM_GUI_CTL_R] = COMBO_ACTION(hrm_gui_ctl_r_combo),
    [HRM_GUI_ALT_R] = COMBO_ACTION(hrm_gui_alt_r_combo),
    [HRM_CTL_SHT_R] = COMBO_ACTION(hrm_ctl_sht_r_combo),
    [HRM_CTL_ALT_R] = COMBO_ACTION(hrm_ctl_alt_r_combo),
    [HRM_SHT_ALT_R] = COMBO_ACTION(hrm_sht_alt_r_combo),
    [HRM_GUI_CTL_SHT_R] = COMBO_ACTION(hrm_gui_ctl_sht_r_combo),
    [HRM_GUI_CTL_ALT_R] = COMBO_ACTION(hrm_gui_ctl_alt_r_combo),
    [HRM_GUI_SHT_ALT_R] = COMBO_ACTION(hrm_gui_sht_alt_r_combo),
    [HRM_CTL_SHT_ALT_R] = COMBO_ACTION(hrm_ctl_sht_alt_r_combo),
    [HRM_ALL_MODS_R] = COMBO_ACTION(hrm_all_mods_r_combo),

    // NAV layer + modifier combos - Hands Down Gold
    // Single modifier + NAV
    [NAV_ALT] = COMBO_ACTION(nav_alt_combo),
    [NAV_CTL] = COMBO_ACTION(nav_ctl_combo),
    [NAV_SHT] = COMBO_ACTION(nav_sht_combo),
    [NAV_GUI] = COMBO_ACTION(nav_gui_combo),
    // Two modifiers + NAV
    [NAV_GUI_SHT] = COMBO_ACTION(nav_gui_sht_combo),
    [NAV_GUI_CTL] = COMBO_ACTION(nav_gui_ctl_combo),
    [NAV_GUI_ALT] = COMBO_ACTION(nav_gui_alt_combo),
    [NAV_CTL_SHT] = COMBO_ACTION(nav_ctl_sht_combo),
    [NAV_CTL_ALT] = COMBO_ACTION(nav_ctl_alt_combo),
    [NAV_SHT_ALT] = COMBO_ACTION(nav_sht_alt_combo),
    // Three modifiers + NAV
    [NAV_GUI_CTL_SHT] = COMBO_ACTION(nav_gui_ctl_sht_combo),
    [NAV_GUI_CTL_ALT] = COMBO_ACTION(nav_gui_ctl_alt_combo),
    [NAV_GUI_SHT_ALT] = COMBO_ACTION(nav_gui_sht_alt_combo),
    [NAV_CTL_SHT_ALT] = COMBO_ACTION(nav_ctl_sht_alt_combo),
    // Four modifiers + NAV
    [NAV_ALL_MODS] = COMBO_ACTION(nav_all_mods_combo),
};


//Combo Processing
void process_combo_event(uint16_t combo_index, bool pressed) {
    action_tapping_process((keyrecord_t){});
    switch(combo_index) {
        case GUI_TAB:
            if (pressed) {
                register_code(KC_LGUI); // Hold GUI
                tap_code(KC_TAB);       // Press TAB once
            } else {
                unregister_code(KC_LGUI); // Release GUI
            }
            break;
        case SHT_TAB:
            if (pressed) {
                register_code(KC_LSFT); // Hold ALT
                tap_code(KC_TAB);       // Press TAB once
            } else {
                unregister_code(KC_LSFT); // Release SHIFT
            }
            break;
        case ALT_TAB:
            if (pressed) {
                register_code(KC_LALT); // Hold ALT
                tap_code(KC_TAB);       // Press TAB once
            } else {
                unregister_code(KC_LALT); // Release ALT
            }
            break;
        case CTL_TAB:
            if (pressed) {
                register_code(KC_LCTL); // Hold CTRL
                tap_code(KC_TAB);       // Press TAB once
            } else {
                unregister_code(KC_LCTL); // Release CTRL
            }
            break;
        case SHT_CTL_TAB:
            if (pressed) {
                register_code(KC_LSFT); // Hold Shift
                register_code(KC_LCTL); // Hold Ctrl
                tap_code(KC_TAB);       // Press TAB once
            } else {
                unregister_code(KC_LSFT); // Release Shift
                unregister_code(KC_LCTL); // Release Ctrl
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

        case COMBO_CTL_A:
            if (pressed) {
                tap_code16(LCTL(DE_A));
            }
            break;

        // Hands Down Gold combos
        case QU_COMBO:
            if (pressed) {
                tap_code16(DE_Q);
                tap_code16(DE_U);
            }
            break;

        // Combo for efficency
        case GJ_COMBO:
            if (pressed) {
                tap_code16(KC_ESC);
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

        // Thumb-gated HRM combos - Single modifiers (grouped by modifier type)
        // ALT modifiers - BUTECK, Hands Down Gold, QWERTY
        case HRM_ALT_Z:
        case HRM_ALT_K:
        case HRM_ALT_R_HD:
        case HRM_ALT_H_HD:
        case HRM_ALT_Z_Q:
        case HRM_ALT_SLSH_Q:
            if (pressed) {
                register_code(KC_LALT);
            } else {
                unregister_code(KC_LALT);
            }
            break;

        // CTRL modifiers - BUTECK, Hands Down Gold, QWERTY
        case HRM_CTL_V:
        case HRM_CTL_Y:
        case HRM_CTL_S_HD:
        case HRM_CTL_I_HD:
        case HRM_CTL_X_Q:
        case HRM_CTL_DOT_Q:
            if (pressed) {
                register_code(KC_LCTL);
            } else {
                unregister_code(KC_LCTL);
            }
            break;

        // SHIFT modifiers - BUTECK, Hands Down Gold, QWERTY
        case HRM_SHT_W:
        case HRM_SHT_OE:
        case HRM_SHT_N_HD:
        case HRM_SHT_E_HD:
        case HRM_SHT_C_Q:
        case HRM_SHT_COMM_Q:
            if (pressed) {
                register_code(KC_LSFT);
            } else {
                unregister_code(KC_LSFT);
            }
            break;

        // GUI modifiers - BUTECK, Hands Down Gold, QWERTY
        case HRM_GUI_G:
        case HRM_GUI_AE:
        case HRM_GUI_D_HD:
        case HRM_GUI_A_HD:
        case HRM_GUI_V_Q:
        case HRM_GUI_M_Q:
            if (pressed) {
                register_code(KC_LGUI);
            } else {
                unregister_code(KC_LGUI);
            }
            break;

        // Multi-modifier combos - Hands Down Gold
        case HRM_GUI_SHT:
            if (pressed) {
                register_code(KC_LGUI);
                register_code(KC_LSFT);
            } else {
                unregister_code(KC_LGUI);
                unregister_code(KC_LSFT);
            }
            break;
        case HRM_GUI_CTL:
            if (pressed) {
                register_code(KC_LGUI);
                register_code(KC_LCTL);
            } else {
                unregister_code(KC_LGUI);
                unregister_code(KC_LCTL);
            }
            break;
        case HRM_GUI_ALT:
            if (pressed) {
                register_code(KC_LGUI);
                register_code(KC_LALT);
            } else {
                unregister_code(KC_LGUI);
                unregister_code(KC_LALT);
            }
            break;
        case HRM_CTL_SHT:
            if (pressed) {
                register_code(KC_LCTL);
                register_code(KC_LSFT);
            } else {
                unregister_code(KC_LCTL);
                unregister_code(KC_LSFT);
            }
            break;
        case HRM_CTL_ALT:
            if (pressed) {
                register_code(KC_LCTL);
                register_code(KC_LALT);
            } else {
                unregister_code(KC_LCTL);
                unregister_code(KC_LALT);
            }
            break;
        case HRM_SHT_ALT:
            if (pressed) {
                register_code(KC_LSFT);
                register_code(KC_LALT);
            } else {
                unregister_code(KC_LSFT);
                unregister_code(KC_LALT);
            }
            break;

        // Three-modifier combos
        case HRM_GUI_CTL_SHT:
            if (pressed) {
                register_code(KC_LGUI);
                register_code(KC_LCTL);
                register_code(KC_LSFT);
            } else {
                unregister_code(KC_LGUI);
                unregister_code(KC_LCTL);
                unregister_code(KC_LSFT);
            }
            break;
        case HRM_GUI_CTL_ALT:
            if (pressed) {
                register_code(KC_LGUI);
                register_code(KC_LCTL);
                register_code(KC_LALT);
            } else {
                unregister_code(KC_LGUI);
                unregister_code(KC_LCTL);
                unregister_code(KC_LALT);
            }
            break;
        case HRM_GUI_SHT_ALT:
            if (pressed) {
                register_code(KC_LGUI);
                register_code(KC_LSFT);
                register_code(KC_LALT);
            } else {
                unregister_code(KC_LGUI);
                unregister_code(KC_LSFT);
                unregister_code(KC_LALT);
            }
            break;
        case HRM_CTL_SHT_ALT:
            if (pressed) {
                register_code(KC_LCTL);
                register_code(KC_LSFT);
                register_code(KC_LALT);
            } else {
                unregister_code(KC_LCTL);
                unregister_code(KC_LSFT);
                unregister_code(KC_LALT);
            }
            break;

        // Four-modifier combo
        case HRM_ALL_MODS:
        case HRM_ALL_MODS_R:
            if (pressed) {
                register_code(KC_LGUI);
                register_code(KC_LCTL);
                register_code(KC_LSFT);
                register_code(KC_LALT);
            } else {
                unregister_code(KC_LGUI);
                unregister_code(KC_LCTL);
                unregister_code(KC_LSFT);
                unregister_code(KC_LALT);
            }
            break;

        // Multi-modifier combos - Hands Down Gold RIGHT SIDE
        case HRM_GUI_SHT_R:
            if (pressed) {
                register_code(KC_LGUI);
                register_code(KC_LSFT);
            } else {
                unregister_code(KC_LGUI);
                unregister_code(KC_LSFT);
            }
            break;
        case HRM_GUI_CTL_R:
            if (pressed) {
                register_code(KC_LGUI);
                register_code(KC_LCTL);
            } else {
                unregister_code(KC_LGUI);
                unregister_code(KC_LCTL);
            }
            break;
        case HRM_GUI_ALT_R:
            if (pressed) {
                register_code(KC_LGUI);
                register_code(KC_LALT);
            } else {
                unregister_code(KC_LGUI);
                unregister_code(KC_LALT);
            }
            break;
        case HRM_CTL_SHT_R:
            if (pressed) {
                register_code(KC_LCTL);
                register_code(KC_LSFT);
            } else {
                unregister_code(KC_LCTL);
                unregister_code(KC_LSFT);
            }
            break;
        case HRM_CTL_ALT_R:
            if (pressed) {
                register_code(KC_LCTL);
                register_code(KC_LALT);
            } else {
                unregister_code(KC_LCTL);
                unregister_code(KC_LALT);
            }
            break;
        case HRM_SHT_ALT_R:
            if (pressed) {
                register_code(KC_LSFT);
                register_code(KC_LALT);
            } else {
                unregister_code(KC_LSFT);
                unregister_code(KC_LALT);
            }
            break;

        // Three-modifier combos - RIGHT SIDE
        case HRM_GUI_CTL_SHT_R:
            if (pressed) {
                register_code(KC_LGUI);
                register_code(KC_LCTL);
                register_code(KC_LSFT);
            } else {
                unregister_code(KC_LGUI);
                unregister_code(KC_LCTL);
                unregister_code(KC_LSFT);
            }
            break;
        case HRM_GUI_CTL_ALT_R:
            if (pressed) {
                register_code(KC_LGUI);
                register_code(KC_LCTL);
                register_code(KC_LALT);
            } else {
                unregister_code(KC_LGUI);
                unregister_code(KC_LCTL);
                unregister_code(KC_LALT);
            }
            break;
        case HRM_GUI_SHT_ALT_R:
            if (pressed) {
                register_code(KC_LGUI);
                register_code(KC_LSFT);
                register_code(KC_LALT);
            } else {
                unregister_code(KC_LGUI);
                unregister_code(KC_LSFT);
                unregister_code(KC_LALT);
            }
            break;
        case HRM_CTL_SHT_ALT_R:
            if (pressed) {
                register_code(KC_LCTL);
                register_code(KC_LSFT);
                register_code(KC_LALT);
            } else {
                unregister_code(KC_LCTL);
                unregister_code(KC_LSFT);
                unregister_code(KC_LALT);
            }
            break;

        // NAV layer + modifier combos - Single modifiers
        case NAV_ALT:
            if (pressed) {
                layer_on(NAVR);
                register_code(KC_LALT);
            } else {
                unregister_code(KC_LALT);
            }
            break;
        case NAV_CTL:
            if (pressed) {
                layer_on(NAVR);
                register_code(KC_LCTL);
            } else {
                unregister_code(KC_LCTL);
            }
            break;
        case NAV_SHT:
            if (pressed) {
                layer_on(NAVR);
                register_code(KC_LSFT);
            } else {
                unregister_code(KC_LSFT);
            }
            break;
        case NAV_GUI:
            if (pressed) {
                layer_on(NAVR);
                register_code(KC_LGUI);
            } else {
                unregister_code(KC_LGUI);
            }
            break;

        // NAV layer + two modifiers
        case NAV_GUI_SHT:
            if (pressed) {
                layer_on(NAVR);
                register_code(KC_LGUI);
                register_code(KC_LSFT);
            } else {
                unregister_code(KC_LGUI);
                unregister_code(KC_LSFT);
            }
            break;
        case NAV_GUI_CTL:
            if (pressed) {
                layer_on(NAVR);
                register_code(KC_LGUI);
                register_code(KC_LCTL);
            } else {
                unregister_code(KC_LGUI);
                unregister_code(KC_LCTL);
            }
            break;
        case NAV_GUI_ALT:
            if (pressed) {
                layer_on(NAVR);
                register_code(KC_LGUI);
                register_code(KC_LALT);
            } else {
                unregister_code(KC_LGUI);
                unregister_code(KC_LALT);
            }
            break;
        case NAV_CTL_SHT:
            if (pressed) {
                layer_on(NAVR);
                register_code(KC_LCTL);
                register_code(KC_LSFT);
            } else {
                unregister_code(KC_LCTL);
                unregister_code(KC_LSFT);
            }
            break;
        case NAV_CTL_ALT:
            if (pressed) {
                layer_on(NAVR);
                register_code(KC_LCTL);
                register_code(KC_LALT);
            } else {
                unregister_code(KC_LCTL);
                unregister_code(KC_LALT);
            }
            break;
        case NAV_SHT_ALT:
            if (pressed) {
                layer_on(NAVR);
                register_code(KC_LSFT);
                register_code(KC_LALT);
            } else {
                unregister_code(KC_LSFT);
                unregister_code(KC_LALT);
            }
            break;

        // NAV layer + three modifiers
        case NAV_GUI_CTL_SHT:
            if (pressed) {
                layer_on(NAVR);
                register_code(KC_LGUI);
                register_code(KC_LCTL);
                register_code(KC_LSFT);
            } else {
                unregister_code(KC_LGUI);
                unregister_code(KC_LCTL);
                unregister_code(KC_LSFT);
            }
            break;
        case NAV_GUI_CTL_ALT:
            if (pressed) {
                layer_on(NAVR);
                register_code(KC_LGUI);
                register_code(KC_LCTL);
                register_code(KC_LALT);
            } else {
                unregister_code(KC_LGUI);
                unregister_code(KC_LCTL);
                unregister_code(KC_LALT);
            }
            break;
        case NAV_GUI_SHT_ALT:
            if (pressed) {
                layer_on(NAVR);
                register_code(KC_LGUI);
                register_code(KC_LSFT);
                register_code(KC_LALT);
            } else {
                unregister_code(KC_LGUI);
                unregister_code(KC_LSFT);
                unregister_code(KC_LALT);
            }
            break;
        case NAV_CTL_SHT_ALT:
            if (pressed) {
                layer_on(NAVR);
                register_code(KC_LCTL);
                register_code(KC_LSFT);
                register_code(KC_LALT);
            } else {
                unregister_code(KC_LCTL);
                unregister_code(KC_LSFT);
                unregister_code(KC_LALT);
            }
            break;

        // NAV layer + four modifiers
        case NAV_ALL_MODS:
            if (pressed) {
                layer_on(NAVR);
                register_code(KC_LGUI);
                register_code(KC_LCTL);
                register_code(KC_LSFT);
                register_code(KC_LALT);
            } else {
                unregister_code(KC_LGUI);
                unregister_code(KC_LCTL);
                unregister_code(KC_LSFT);
                unregister_code(KC_LALT);
            }
            break;
    }
}

bool get_combo_must_tap(uint16_t combo_index, combo_t *combo) {
    switch (combo_index) {
        // Standard combos
        case COMBO_CTL_A:
        case QUICK_TERMINAL:
            return false;

        // All HRM combos must be holdable (not tap-only)
        // ALT modifiers - BUTECK, Hands Down Gold, QWERTY
        case HRM_ALT_Z:
        case HRM_ALT_K:
        case HRM_ALT_R_HD:
        case HRM_ALT_H_HD:
        case HRM_ALT_Z_Q:
        case HRM_ALT_SLSH_Q:
        // CTRL modifiers - BUTECK, Hands Down Gold, QWERTY
        case HRM_CTL_V:
        case HRM_CTL_Y:
        case HRM_CTL_S_HD:
        case HRM_CTL_I_HD:
        case HRM_CTL_X_Q:
        case HRM_CTL_DOT_Q:
        // SHIFT modifiers - BUTECK, Hands Down Gold, QWERTY
        case HRM_SHT_W:
        case HRM_SHT_OE:
        case HRM_SHT_N_HD:
        case HRM_SHT_E_HD:
        case HRM_SHT_C_Q:
        case HRM_SHT_COMM_Q:
        // GUI modifiers - BUTECK, Hands Down Gold, QWERTY
        case HRM_GUI_G:
        case HRM_GUI_AE:
        case HRM_GUI_D_HD:
        case HRM_GUI_A_HD:
        case HRM_GUI_V_Q:
        case HRM_GUI_M_Q:
        // Multi-modifier combos
        case HRM_GUI_SHT:
        case HRM_GUI_CTL:
        case HRM_GUI_ALT:
        case HRM_CTL_SHT:
        case HRM_CTL_ALT:
        case HRM_SHT_ALT:
        // Three-modifier combos
        case HRM_GUI_CTL_SHT:
        case HRM_GUI_CTL_ALT:
        case HRM_GUI_SHT_ALT:
        case HRM_CTL_SHT_ALT:
        // Four-modifier combo
        case HRM_ALL_MODS:
        // Multi-modifier combos - RIGHT SIDE
        case HRM_GUI_SHT_R:
        case HRM_GUI_CTL_R:
        case HRM_GUI_ALT_R:
        case HRM_CTL_SHT_R:
        case HRM_CTL_ALT_R:
        case HRM_SHT_ALT_R:
        // Three-modifier combos - RIGHT SIDE
        case HRM_GUI_CTL_SHT_R:
        case HRM_GUI_CTL_ALT_R:
        case HRM_GUI_SHT_ALT_R:
        case HRM_CTL_SHT_ALT_R:
        // Four-modifier combo - RIGHT SIDE
        case HRM_ALL_MODS_R:

        // NAV layer + modifier combos
        case NAV_ALT:
        case NAV_CTL:
        case NAV_SHT:
        case NAV_GUI:
        case NAV_GUI_SHT:
        case NAV_GUI_CTL:
        case NAV_GUI_ALT:
        case NAV_CTL_SHT:
        case NAV_CTL_ALT:
        case NAV_SHT_ALT:
        case NAV_GUI_CTL_SHT:
        case NAV_GUI_CTL_ALT:
        case NAV_GUI_SHT_ALT:
        case NAV_CTL_SHT_ALT:
        case NAV_ALL_MODS:
            return false;
    }
    return true;
}

uint16_t get_combo_term(uint16_t combo_index, combo_t *combo) {
    switch (combo_index) {
        // Hands Down Gold combos
        case QU_COMBO:
        case SEMICOLON_COMBO:
        case GJ_COMBO:
            return 30;
        case AE_UMLAUT:
            return 20;  // Shorter window to prevent misfires on common A-E sequences

        // H-digraph combos
        case TH_COMBO:
        case CH_COMBO:
        case SH_COMBO:
        case GH_COMBO:
        case PH_COMBO:
            return 20;

        // Modifier + key combos (single modifier)
        case GUI_TAB:
        case SHT_TAB:
        case CTL_TAB:
            return 40;

        // Two-modifier + Space combos
        case GUI_SHT_SPACE:
        case GUI_CTL_SPACE:
        case GUI_ALT_SPACE:
        case CTL_SHT_SPACE:
        case CTL_ALT_SPACE:
        case SHT_ALT_SPACE:
            return 60;  // 3 keys

        // Three-modifier + Space combos
        case GUI_SHT_CTL_SPACE:
        case GUI_SHT_ALT_SPACE:
        case GUI_CTL_ALT_SPACE:
        case CTL_SHT_ALT_SPACE:
            return 80;  // 4 keys

        // HRM single modifier combos (thumb + homerow)
        // ALT modifiers - BUTECK, Hands Down Gold, QWERTY
        case HRM_ALT_Z:
        case HRM_ALT_K:
        case HRM_ALT_R_HD:
        case HRM_ALT_H_HD:
        case HRM_ALT_Z_Q:
        case HRM_ALT_SLSH_Q:
        // CTRL modifiers - BUTECK, Hands Down Gold, QWERTY
        case HRM_CTL_V:
        case HRM_CTL_Y:
        case HRM_CTL_S_HD:
        case HRM_CTL_I_HD:
        case HRM_CTL_X_Q:
        case HRM_CTL_DOT_Q:
        // SHIFT modifiers - BUTECK, Hands Down Gold, QWERTY
        case HRM_SHT_W:
        case HRM_SHT_OE:
        case HRM_SHT_N_HD:
        case HRM_SHT_E_HD:
        case HRM_SHT_C_Q:
        case HRM_SHT_COMM_Q:
        // GUI modifiers - BUTECK, Hands Down Gold, QWERTY
        case HRM_GUI_G:
        case HRM_GUI_AE:
        case HRM_GUI_D_HD:
        case HRM_GUI_A_HD:
        case HRM_GUI_V_Q:
        case HRM_GUI_M_Q:
            return 50;  // 50ms window for thumb + homerow activation

        // HRM multi-modifier combos (3 keys)
        case HRM_GUI_SHT:
        case HRM_GUI_CTL:
        case HRM_GUI_ALT:
        case HRM_CTL_SHT:
        case HRM_CTL_ALT:
        case HRM_SHT_ALT:
            return 60;

        // HRM three-modifier combos (4 keys)
        case HRM_GUI_CTL_SHT:
        case HRM_GUI_CTL_ALT:
        case HRM_GUI_SHT_ALT:
        case HRM_CTL_SHT_ALT:
            return 80;

        // HRM four-modifier combo (5 keys)
        case HRM_ALL_MODS:
        case HRM_ALL_MODS_R:
            return 100;

        // HRM multi-modifier combos - RIGHT SIDE (3 keys)
        case HRM_GUI_SHT_R:
        case HRM_GUI_CTL_R:
        case HRM_GUI_ALT_R:
        case HRM_CTL_SHT_R:
        case HRM_CTL_ALT_R:
        case HRM_SHT_ALT_R:
            return 60;

        // HRM three-modifier combos - RIGHT SIDE (4 keys)
        case HRM_GUI_CTL_SHT_R:
        case HRM_GUI_CTL_ALT_R:
        case HRM_GUI_SHT_ALT_R:
        case HRM_CTL_SHT_ALT_R:
            return 80;

        // NAV layer + single modifier combos (2 keys)
        case NAV_ALT:
        case NAV_CTL:
        case NAV_SHT:
        case NAV_GUI:
            return 50;

        // NAV layer + two modifier combos (3 keys)
        case NAV_GUI_SHT:
        case NAV_GUI_CTL:
        case NAV_GUI_ALT:
        case NAV_CTL_SHT:
        case NAV_CTL_ALT:
        case NAV_SHT_ALT:
            return 60;

        // NAV layer + three modifier combos (4 keys)
        case NAV_GUI_CTL_SHT:
        case NAV_GUI_CTL_ALT:
        case NAV_GUI_SHT_ALT:
        case NAV_CTL_SHT_ALT:
            return 80;

        // NAV layer + four modifier combo (5 keys)
        case NAV_ALL_MODS:
            return 100;
    }
    return COMBO_TERM;  // Default 40ms from config.h
}

bool get_combo_must_press_in_order(uint16_t combo_index, combo_t *combo) {
    switch (combo_index) {
        // Standard combos
        case RWIN_SHT_S:
        case COMBO_SHT_CTL_Z:
        case WIN_CTL_LEFT:
        case WIN_CTL_RIGHT:
        case BSPC_LSFT_CLEAR:
        case QUICK_WINDOWS:
        case QUICK_TERMINAL:

        // Hands Down Gold combos
        case QU_COMBO:
        case SEMICOLON_COMBO:

        // H-digraph combos
        case TH_COMBO:
        case CH_COMBO:
        case SH_COMBO:
        case GH_COMBO:
        case PH_COMBO:

        // Modifier + key combos (single modifier)
        case GUI_TAB:
        case SHT_TAB:
        case CTL_TAB:
        case ALT_SPACE:
        case SHT_CTL_TAB:

        // Two-modifier + Space combos
        case GUI_SHT_SPACE:
        case GUI_CTL_SPACE:
        case GUI_ALT_SPACE:
        case CTL_SHT_SPACE:
        case CTL_ALT_SPACE:
        case SHT_ALT_SPACE:

        // Three-modifier + Space combos
        case GUI_SHT_CTL_SPACE:
        case GUI_SHT_ALT_SPACE:
        case GUI_CTL_ALT_SPACE:
        case CTL_SHT_ALT_SPACE:

        // HRM single modifier combos (thumb or homerow can come first)
        // ALT modifiers - BUTECK, Hands Down Gold, QWERTY
        case HRM_ALT_Z:
        case HRM_ALT_K:
        case HRM_ALT_R_HD:
        case HRM_ALT_H_HD:
        case HRM_ALT_Z_Q:
        case HRM_ALT_SLSH_Q:
        // CTRL modifiers - BUTECK, Hands Down Gold, QWERTY
        case HRM_CTL_V:
        case HRM_CTL_Y:
        case HRM_CTL_S_HD:
        case HRM_CTL_I_HD:
        case HRM_CTL_X_Q:
        case HRM_CTL_DOT_Q:
        // SHIFT modifiers - BUTECK, Hands Down Gold, QWERTY
        case HRM_SHT_W:
        case HRM_SHT_OE:
        case HRM_SHT_N_HD:
        case HRM_SHT_E_HD:
        case HRM_SHT_C_Q:
        case HRM_SHT_COMM_Q:
        // GUI modifiers - BUTECK, Hands Down Gold, QWERTY
        case HRM_GUI_G:
        case HRM_GUI_AE:
        case HRM_GUI_D_HD:
        case HRM_GUI_A_HD:
        case HRM_GUI_V_Q:
        case HRM_GUI_M_Q:

        // HRM multi-modifier combos
        case HRM_GUI_SHT:
        case HRM_GUI_CTL:
        case HRM_GUI_ALT:
        case HRM_CTL_SHT:
        case HRM_CTL_ALT:
        case HRM_SHT_ALT:

        // HRM three-modifier combos
        case HRM_GUI_CTL_SHT:
        case HRM_GUI_CTL_ALT:
        case HRM_GUI_SHT_ALT:
        case HRM_CTL_SHT_ALT:

        // HRM four-modifier combo
        case HRM_ALL_MODS:

        // HRM multi-modifier combos - RIGHT SIDE
        case HRM_GUI_SHT_R:
        case HRM_GUI_CTL_R:
        case HRM_GUI_ALT_R:
        case HRM_CTL_SHT_R:
        case HRM_CTL_ALT_R:
        case HRM_SHT_ALT_R:

        // HRM three-modifier combos - RIGHT SIDE
        case HRM_GUI_CTL_SHT_R:
        case HRM_GUI_CTL_ALT_R:
        case HRM_GUI_SHT_ALT_R:
        case HRM_CTL_SHT_ALT_R:

        // HRM four-modifier combo - RIGHT SIDE
        case HRM_ALL_MODS_R:

        // NAV layer + modifier combos
        case NAV_ALT:
        case NAV_CTL:
        case NAV_SHT:
        case NAV_GUI:
        case NAV_GUI_SHT:
        case NAV_GUI_CTL:
        case NAV_GUI_ALT:
        case NAV_CTL_SHT:
        case NAV_CTL_ALT:
        case NAV_SHT_ALT:
        case NAV_GUI_CTL_SHT:
        case NAV_GUI_CTL_ALT:
        case NAV_GUI_SHT_ALT:
        case NAV_CTL_SHT_ALT:
        case NAV_ALL_MODS:
            return false;
    }
    return true;
}

