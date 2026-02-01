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

    ALT_UP,
    ALT_LEFT,
    ALT_RIGHT,
    ALT_DOWN,
    ALT_F4_COMBO,

    // Hands Down Gold combos
    SEMICOLON_COMBO,
    COLON_COMBO,
    UNDERSCORE_COMBO,
    AE_UMLAUT,
    QU_COMBO,
    GJ_COMBO,

    // H-digraph combos
    TH_COMBO,
    CH_COMBO,
    SH_COMBO,
    GH_COMBO,
    PH_COMBO,
    SCH_COMBO,

    // Leader key combo
    LEADER_COMBO,

    // Specific modifier + key combos (Hands Down Gold)
    GUI_TAB,             // D + Tab = GUI+Tab
    SHT_TAB,             // N + Tab = Shift+Tab
    ALT_TAB,             // R + Tab = Alt+Tab
    CTL_TAB,             // S + Tab = Ctrl+Tab
    // ALT_SPACE,           // R + Space = Alt+Space
    SHT_CTL_TAB,         // S + N + Tab = Shift+Ctrl+Tab

    // // Two-modifier + Space combos
    // GUI_SHT_SPACE,          // D + N + Space = GUI+Shift+Space
    // GUI_CTL_SPACE,          // D + S + Space = GUI+Ctrl+Space
    // GUI_ALT_SPACE,          // D + R + Space = GUI+Alt+Space
    // CTL_SHT_SPACE,          // S + N + Space = Ctrl+Shift+Space
    // CTL_ALT_SPACE,          // S + R + Space = Ctrl+Alt+Space
    // SHT_ALT_SPACE,          // N + R + Space = Shift+Alt+Space

    // // Three-modifier + Space combos
    // GUI_SHT_CTL_SPACE,      // D + N + S + Space = GUI+Shift+Ctrl+Space
    // GUI_SHT_ALT_SPACE,      // D + N + R + Space = GUI+Shift+Alt+Space
    // GUI_CTL_ALT_SPACE,      // D + S + R + Space = GUI+Ctrl+Alt+Space
    // CTL_SHT_ALT_SPACE,      // S + N + R + Space = Ctrl+Shift+Alt+Space

    // Thumb-gated HRM combos - Single modifiers
    // Hands Down Gold layout (middle row: R S N D | A E I H)
    HRM_ALT_R_HD,
    HRM_CTL_S_HD,
    HRM_SHT_N_HD,
    HRM_GUI_D_HD,
    HRM_GUI_A_HD,
    HRM_SHT_E_HD,
    HRM_CTL_I_HD,
    HRM_ALT_H_HD,

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

    // Simple cut/copy/paste combos
    COMBO_CUT,         // Z + F = Cut
    COMBO_CUT_SHT,     // Z + F + L = Shift+Cut
    COMBO_COPY,        // F + C = Copy
    COMBO_COPY_SHT,    // F + C + L = Shift+Copy
    COMBO_PASTE,       // L + C = Paste
    COMBO_PASTE_SHT,   // L + C + W = Shift+Paste

    COMBO_LENGTH

};
int COMBO_LEN = COMBO_LENGTH;

//Combo Activation wenn ich es 

// Hands Down Gold combos
const uint16_t PROGMEM semicolon_combo[] = { DE_COMM, DE_DOT, COMBO_END };  // , + . = ;
const uint16_t PROGMEM colon_combo[] = { DE_DOT, DE_DQUO, COMBO_END };      // . + " = :
const uint16_t PROGMEM underscore_combo[] = { DE_DQUO, DE_QUOT, COMBO_END };   // " + ' = _
const uint16_t PROGMEM ae_umlaut_combo[] = { DE_OE, DE_A, COMBO_END };       // A + E = Ä
const uint16_t PROGMEM qu_combo[] = { DE_G, DE_P, COMBO_END };              // G + P = Q

// Combos for efficiency
const uint16_t PROGMEM gj_combo[] = { DE_G, DE_J, COMBO_END };              // G + J = Alt+F4

// H-digraph combos (Hands Down Gold recommended)
const uint16_t PROGMEM th_combo[] = { ALT_R_HD, GUI_D_HD, COMBO_END };      // R + D = TH
const uint16_t PROGMEM ch_combo[] = { GUI_D_HD, SHT_N_HD, COMBO_END };      // D + N = CH
const uint16_t PROGMEM sh_combo[] = { DE_S, DE_N, COMBO_END };              // S + N = SH
const uint16_t PROGMEM gh_combo[] = { DE_G, DE_M, COMBO_END };              // G + M = GH
const uint16_t PROGMEM ph_combo[] = { DE_P, DE_M, COMBO_END };              // P + M = PH
const uint16_t PROGMEM sch_combo[] = { ALT_R_HD, CTL_S_HD, SHT_N_HD, COMBO_END };  // R + S + N = SCH

// Leader key combo
const uint16_t PROGMEM leader_combo[] = { UC_TL3, UC_TR2, COMBO_END };      // Space + Backspace = Leader

// Specific modifier + key combos (Hands Down Gold)
const uint16_t PROGMEM gui_tab_combo[] = { GUI_D_HD, UC_TL4, COMBO_END };
const uint16_t PROGMEM sht_tab_combo[] = { SHT_N_HD, UC_TL4, COMBO_END };
const uint16_t PROGMEM alt_tab_combo[] = { ALT_R_HD, UC_TL4, COMBO_END };
const uint16_t PROGMEM ctl_tab_combo[] = { CTL_S_HD, UC_TL4, COMBO_END };
// const uint16_t PROGMEM alt_space_combo[] = { DE_R, UC_TL3, COMBO_END };

const uint16_t PROGMEM alt_up_combo[] = { ALT_R_HD, KC_UP, COMBO_END };
const uint16_t PROGMEM alt_down_combo[] = { ALT_R_HD, KC_DOWN, COMBO_END };
const uint16_t PROGMEM alt_left_combo[] = { ALT_R_HD, KC_LEFT, COMBO_END };
const uint16_t PROGMEM alt_right_combo[] = { ALT_R_HD, KC_RGHT, COMBO_END };
const uint16_t PROGMEM alt_f4_combo[] = { ALT_H_HD, UC_TR3, KC_F4, COMBO_END };

// Two-modifier + key combos
const uint16_t PROGMEM sht_ctl_tab_combo[] = { CTL_S_HD, SHT_N_HD, UC_TL4, COMBO_END };

// // Two-modifier + Space combos
// const uint16_t PROGMEM gui_sht_space_combo[] = { GUI_D_HD, SHT_N_HD, UC_TL3, COMBO_END };
// const uint16_t PROGMEM gui_ctl_space_combo[] = { GUI_D_HD, CTL_S_HD, UC_TL3, COMBO_END };
// const uint16_t PROGMEM gui_alt_space_combo[] = { GUI_D_HD, ALT_R_HD, UC_TL3, COMBO_END };
// const uint16_t PROGMEM ctl_sht_space_combo[] = { CTL_S_HD, SHT_N_HD, UC_TL3, COMBO_END };
// const uint16_t PROGMEM ctl_alt_space_combo[] = { CTL_S_HD, ALT_R_HD, UC_TL3, COMBO_END };
// const uint16_t PROGMEM sht_alt_space_combo[] = { SHT_N_HD, ALT_R_HD, UC_TL3, COMBO_END };

// // Three-modifier + Space combos 
// const uint16_t PROGMEM gui_sht_ctl_space_combo[] = { GUI_D_HD, SHT_N_HD, CTL_S_HD, UC_TL3, COMBO_END };
// const uint16_t PROGMEM gui_sht_alt_space_combo[] = { GUI_D_HD, SHT_N_HD, ALT_R_HD, UC_TL3, COMBO_END };
// const uint16_t PROGMEM gui_ctl_alt_space_combo[] = { GUI_D_HD, CTL_S_HD, ALT_R_HD, UC_TL3, COMBO_END };
// const uint16_t PROGMEM ctl_sht_alt_space_combo[] = { CTL_S_HD, SHT_N_HD, ALT_R_HD, UC_TL3, COMBO_END };

// Thumb-gated HRM combos - Single modifiers
// Hands Down Gold layout
const uint16_t PROGMEM hrm_alt_r_hd_combo[] = { UC_TL2, ALT_R_HD, COMBO_END };
const uint16_t PROGMEM hrm_ctl_s_hd_combo[] = { UC_TL2, CTL_S_HD, COMBO_END };
const uint16_t PROGMEM hrm_sht_n_hd_combo[] = { UC_TL2, SHT_N_HD, COMBO_END };
const uint16_t PROGMEM hrm_gui_d_hd_combo[] = { UC_TL2, GUI_D_HD, COMBO_END };
const uint16_t PROGMEM hrm_gui_a_hd_combo[] = { UC_TL2, GUI_A_HD, COMBO_END };
const uint16_t PROGMEM hrm_sht_e_hd_combo[] = { UC_TL2, SHT_E_HD, COMBO_END };
const uint16_t PROGMEM hrm_ctl_i_hd_combo[] = { UC_TL2, CTL_I_HD, COMBO_END };
const uint16_t PROGMEM hrm_alt_h_hd_combo[] = { UC_TL2, ALT_H_HD, COMBO_END };

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

// Simple cut/copy/paste combos
const uint16_t PROGMEM cut_zf_combo[] = { DE_Z, DE_F, COMBO_END };
const uint16_t PROGMEM cut_sht_zfl_combo[] = { DE_Z, DE_F, DE_L, COMBO_END };
const uint16_t PROGMEM copy_fc_combo[] = { DE_F, DE_C, COMBO_END };
const uint16_t PROGMEM copy_sht_fcl_combo[] = { DE_F, DE_C, DE_L, COMBO_END };
const uint16_t PROGMEM paste_lc_combo[] = { DE_L, DE_C, COMBO_END };
const uint16_t PROGMEM paste_sht_lcw_combo[] = { DE_L, DE_C, DE_W, COMBO_END };


//Combo Action
combo_t key_combos[COMBO_LENGTH] = {
    [ALT_UP] = COMBO(alt_up_combo, LALT(KC_UP)),
    [ALT_DOWN] = COMBO(alt_down_combo, LALT(KC_DOWN)),
    [ALT_LEFT] = COMBO(alt_left_combo, LALT(KC_LEFT)),
    [ALT_RIGHT] = COMBO(alt_right_combo, LALT(KC_RGHT)),
    [ALT_F4_COMBO] = COMBO(alt_f4_combo, LALT(KC_F4)),

    // Hands Down Gold combos
    [SEMICOLON_COMBO] = COMBO(semicolon_combo, DE_SCLN),
    [COLON_COMBO] = COMBO(colon_combo, DE_COLN),
    [UNDERSCORE_COMBO] = COMBO(underscore_combo, DE_UNDS),
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
    [SCH_COMBO] = COMBO_ACTION(sch_combo),

    // Leader key combo
    [LEADER_COMBO] = COMBO(leader_combo, QK_LEADER),

    // Specific modifier + key combos
    [GUI_TAB] = COMBO_ACTION(gui_tab_combo),
    [SHT_TAB] = COMBO_ACTION(sht_tab_combo),
    [ALT_TAB] = COMBO_ACTION(alt_tab_combo),
    [CTL_TAB] = COMBO_ACTION(ctl_tab_combo),
    // [ALT_SPACE] = COMBO(alt_space_combo, LALT(KC_SPC)),

    // Two-modifier + key combos
    [SHT_CTL_TAB] = COMBO_ACTION(sht_ctl_tab_combo),
    
    // // Two-modifier + Space combos
    // [GUI_SHT_SPACE] = COMBO(gui_sht_space_combo, LGUI(LSFT(KC_SPC))),
    // [GUI_CTL_SPACE] = COMBO(gui_ctl_space_combo, LGUI(LCTL(KC_SPC))),
    // [GUI_ALT_SPACE] = COMBO(gui_alt_space_combo, LGUI(LALT(KC_SPC))),
    // [CTL_SHT_SPACE] = COMBO(ctl_sht_space_combo, LCTL(LSFT(KC_SPC))),
    // [CTL_ALT_SPACE] = COMBO(ctl_alt_space_combo, LCTL(LALT(KC_SPC))),
    // [SHT_ALT_SPACE] = COMBO(sht_alt_space_combo, LSFT(LALT(KC_SPC))),

    // // Three-modifier + Space combos
    // [GUI_SHT_CTL_SPACE] = COMBO(gui_sht_ctl_space_combo, LGUI(LSFT(LCTL(KC_SPC)))),
    // [GUI_SHT_ALT_SPACE] = COMBO(gui_sht_alt_space_combo, LGUI(LSFT(LALT(KC_SPC)))),
    // [GUI_CTL_ALT_SPACE] = COMBO(gui_ctl_alt_space_combo, LGUI(LCTL(LALT(KC_SPC)))),
    // [CTL_SHT_ALT_SPACE] = COMBO(ctl_sht_alt_space_combo, LCTL(LSFT(LALT(KC_SPC)))),

    // Thumb-gated HRM combos - Hands Down Gold layout (One-Shot Modifiers)
    [HRM_ALT_R_HD] = COMBO_ACTION(hrm_alt_r_hd_combo),
    [HRM_CTL_S_HD] = COMBO_ACTION(hrm_ctl_s_hd_combo),
    [HRM_SHT_N_HD] = COMBO_ACTION(hrm_sht_n_hd_combo),
    [HRM_GUI_D_HD] = COMBO_ACTION(hrm_gui_d_hd_combo),
    [HRM_GUI_A_HD] = COMBO_ACTION(hrm_gui_a_hd_combo),
    [HRM_SHT_E_HD] = COMBO_ACTION(hrm_sht_e_hd_combo),
    [HRM_CTL_I_HD] = COMBO_ACTION(hrm_ctl_i_hd_combo),
    [HRM_ALT_H_HD] = COMBO_ACTION(hrm_alt_h_hd_combo),

    // Thumb-gated multi-modifier combos - Hands Down Gold (One-Shot Modifiers)
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

    // Thumb-gated multi-modifier combos - Hands Down Gold RIGHT SIDE (One-Shot Modifiers)
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

    // Simple cut/copy/paste combos
    [COMBO_CUT] = COMBO(cut_zf_combo, LCTL(DE_X)),
    [COMBO_CUT_SHT] = COMBO(cut_sht_zfl_combo, LSFT(LCTL(DE_X))),
    [COMBO_COPY] = COMBO(copy_fc_combo, LCTL(DE_C)),
    [COMBO_COPY_SHT] = COMBO(copy_sht_fcl_combo, LSFT(LCTL(DE_C))),
    [COMBO_PASTE] = COMBO(paste_lc_combo, LCTL(DE_V)),
    [COMBO_PASTE_SHT] = COMBO(paste_sht_lcw_combo, LSFT(LCTL(DE_V))),
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
                tap_code16(LALT(KC_F4));
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
        case SCH_COMBO:
            if (pressed) {
                tap_code16(DE_S);
                tap_code16(DE_C);
                tap_code16(DE_H);
            }
            break;

        // Thumb-gated HRM combos - One-Shot Modifiers
        // ALT modifiers - Hands Down Gold
        case HRM_ALT_R_HD:
        case HRM_ALT_H_HD:
            if (pressed) {
                set_oneshot_mods(MOD_BIT(KC_LALT));
            }
            break;

        // CTRL modifiers - Hands Down Gold
        case HRM_CTL_S_HD:
        case HRM_CTL_I_HD:
            if (pressed) {
                set_oneshot_mods(MOD_BIT(KC_LCTL));
            }
            break;

        // SHIFT modifiers - Hands Down Gold
        case HRM_SHT_N_HD:
        case HRM_SHT_E_HD:
            if (pressed) {
                set_oneshot_mods(MOD_BIT(KC_LSFT));
            }
            break;

        // GUI modifiers - Hands Down Gold
        case HRM_GUI_D_HD:
        case HRM_GUI_A_HD:
            if (pressed) {
                set_oneshot_mods(MOD_BIT(KC_LGUI));
            }
            break;

        // Two-modifier combos - Left side
        case HRM_GUI_SHT:
            if (pressed) {
                set_oneshot_mods(MOD_BIT(KC_LGUI) | MOD_BIT(KC_LSFT));
            }
            break;
        case HRM_GUI_CTL:
            if (pressed) {
                set_oneshot_mods(MOD_BIT(KC_LGUI) | MOD_BIT(KC_LCTL));
            }
            break;
        case HRM_GUI_ALT:
            if (pressed) {
                set_oneshot_mods(MOD_BIT(KC_LGUI) | MOD_BIT(KC_LALT));
            }
            break;
        case HRM_CTL_SHT:
            if (pressed) {
                set_oneshot_mods(MOD_BIT(KC_LCTL) | MOD_BIT(KC_LSFT));
            }
            break;
        case HRM_CTL_ALT:
            if (pressed) {
                set_oneshot_mods(MOD_BIT(KC_LCTL) | MOD_BIT(KC_LALT));
            }
            break;
        case HRM_SHT_ALT:
            if (pressed) {
                set_oneshot_mods(MOD_BIT(KC_LSFT) | MOD_BIT(KC_LALT));
            }
            break;

        // Three-modifier combos - Left side
        case HRM_GUI_CTL_SHT:
            if (pressed) {
                set_oneshot_mods(MOD_BIT(KC_LGUI) | MOD_BIT(KC_LCTL) | MOD_BIT(KC_LSFT));
            }
            break;
        case HRM_GUI_CTL_ALT:
            if (pressed) {
                set_oneshot_mods(MOD_BIT(KC_LGUI) | MOD_BIT(KC_LCTL) | MOD_BIT(KC_LALT));
            }
            break;
        case HRM_GUI_SHT_ALT:
            if (pressed) {
                set_oneshot_mods(MOD_BIT(KC_LGUI) | MOD_BIT(KC_LSFT) | MOD_BIT(KC_LALT));
            }
            break;
        case HRM_CTL_SHT_ALT:
            if (pressed) {
                set_oneshot_mods(MOD_BIT(KC_LCTL) | MOD_BIT(KC_LSFT) | MOD_BIT(KC_LALT));
            }
            break;

        // Four-modifier combos (HYPR)
        case HRM_ALL_MODS:
        case HRM_ALL_MODS_R:
            if (pressed) {
                set_oneshot_mods(MOD_BIT(KC_LGUI) | MOD_BIT(KC_LCTL) | MOD_BIT(KC_LSFT) | MOD_BIT(KC_LALT));
            }
            break;

        // Two-modifier combos - Right side
        case HRM_GUI_SHT_R:
            if (pressed) {
                set_oneshot_mods(MOD_BIT(KC_LGUI) | MOD_BIT(KC_LSFT));
            }
            break;
        case HRM_GUI_CTL_R:
            if (pressed) {
                set_oneshot_mods(MOD_BIT(KC_LGUI) | MOD_BIT(KC_LCTL));
            }
            break;
        case HRM_GUI_ALT_R:
            if (pressed) {
                set_oneshot_mods(MOD_BIT(KC_LGUI) | MOD_BIT(KC_LALT));
            }
            break;
        case HRM_CTL_SHT_R:
            if (pressed) {
                set_oneshot_mods(MOD_BIT(KC_LCTL) | MOD_BIT(KC_LSFT));
            }
            break;
        case HRM_CTL_ALT_R:
            if (pressed) {
                set_oneshot_mods(MOD_BIT(KC_LCTL) | MOD_BIT(KC_LALT));
            }
            break;
        case HRM_SHT_ALT_R:
            if (pressed) {
                set_oneshot_mods(MOD_BIT(KC_LSFT) | MOD_BIT(KC_LALT));
            }
            break;

        // Three-modifier combos - Right side
        case HRM_GUI_CTL_SHT_R:
            if (pressed) {
                set_oneshot_mods(MOD_BIT(KC_LGUI) | MOD_BIT(KC_LCTL) | MOD_BIT(KC_LSFT));
            }
            break;
        case HRM_GUI_CTL_ALT_R:
            if (pressed) {
                set_oneshot_mods(MOD_BIT(KC_LGUI) | MOD_BIT(KC_LCTL) | MOD_BIT(KC_LALT));
            }
            break;
        case HRM_GUI_SHT_ALT_R:
            if (pressed) {
                set_oneshot_mods(MOD_BIT(KC_LGUI) | MOD_BIT(KC_LSFT) | MOD_BIT(KC_LALT));
            }
            break;
        case HRM_CTL_SHT_ALT_R:
            if (pressed) {
                set_oneshot_mods(MOD_BIT(KC_LCTL) | MOD_BIT(KC_LSFT) | MOD_BIT(KC_LALT));
            }
            break;

    }
}

bool get_combo_must_tap(uint16_t combo_index, combo_t *combo) {
    return true;
}

uint16_t get_combo_term(uint16_t combo_index, combo_t *combo) {
    switch (combo_index) {
        // Hands Down Gold combos
        case QU_COMBO:
        case SEMICOLON_COMBO:
        case COLON_COMBO:
        case UNDERSCORE_COMBO:
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
        case SCH_COMBO:
            return 30;  // 3 keys

        // Modifier + key combos (single modifier)
        case GUI_TAB:
        case SHT_TAB:
        case ALT_TAB:
        case CTL_TAB:
        // case ALT_SPACE:
            // return 40;

        // // Two-modifier + Space combos
        // case GUI_SHT_SPACE:
        // case GUI_CTL_SPACE:
        // case GUI_ALT_SPACE:
        // case CTL_SHT_SPACE:
        // case CTL_ALT_SPACE:
        // case SHT_ALT_SPACE:
        //     return 60;  // 3 keys

        // // Three-modifier + Space combos
        // case GUI_SHT_CTL_SPACE:
        // case GUI_SHT_ALT_SPACE:
        // case GUI_CTL_ALT_SPACE:
        // case CTL_SHT_ALT_SPACE:
        //     return 80;  // 4 keys

        // HRM single modifier combos (thumb + homerow)
        // ALT modifiers - Hands Down Gold
        case HRM_ALT_R_HD:
        case HRM_ALT_H_HD:
        // CTRL modifiers - Hands Down Gold
        case HRM_CTL_S_HD:
        case HRM_CTL_I_HD:
        // SHIFT modifiers - Hands Down Gold
        case HRM_SHT_N_HD:
        case HRM_SHT_E_HD:
        // GUI modifiers - Hands Down Gold
        case HRM_GUI_D_HD:
        case HRM_GUI_A_HD:
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

        // Leader key combo
        case LEADER_COMBO:
            return 50;  // 2 thumb keys - give some room

        // Simple cut/copy/paste combos
        case COMBO_CUT:
        case COMBO_COPY:
        case COMBO_PASTE:
            return 30;  // 2 keys
        case COMBO_CUT_SHT:
        case COMBO_COPY_SHT:
        case COMBO_PASTE_SHT:
            return 50;  // 3 keys
    }
    return COMBO_TERM;  // Default 40ms from config.h
}

bool get_combo_must_press_in_order(uint16_t combo_index, combo_t *combo) {
    switch (combo_index) {
        // Hands Down Gold combos
        case QU_COMBO:
        case SEMICOLON_COMBO:
        case COLON_COMBO:
        case UNDERSCORE_COMBO:
        case AE_UMLAUT: // currently ö is tapdance so it will not work probably

        // H-digraph combos
        case TH_COMBO:
        case CH_COMBO:
        case SH_COMBO:
        case GH_COMBO:
        case PH_COMBO:
        case SCH_COMBO:

        // Modifier + key combos (single modifier)
        case GUI_TAB:
        case SHT_TAB:
        case CTL_TAB:
        // case ALT_SPACE:
        case ALT_F4_COMBO:
        case SHT_CTL_TAB:

        // // Two-modifier + Space combos
        // case GUI_SHT_SPACE:
        // case GUI_CTL_SPACE:
        // case GUI_ALT_SPACE:
        // case CTL_SHT_SPACE:
        // case CTL_ALT_SPACE:
        // case SHT_ALT_SPACE:

        // // Three-modifier + Space combos
        // case GUI_SHT_CTL_SPACE:
        // case GUI_SHT_ALT_SPACE:
        // case GUI_CTL_ALT_SPACE:
        // case CTL_SHT_ALT_SPACE:

        // Leader key combo
        case LEADER_COMBO:

        // HRM single modifier combos (thumb or homerow can come first)
        // ALT modifiers - Hands Down Gold
        case HRM_ALT_R_HD:
        case HRM_ALT_H_HD:
        // CTRL modifiers - Hands Down Gold
        case HRM_CTL_S_HD:
        case HRM_CTL_I_HD:
        // SHIFT modifiers - Hands Down Gold
        case HRM_SHT_N_HD:
        case HRM_SHT_E_HD:
        // GUI modifiers - Hands Down Gold
        case HRM_GUI_D_HD:
        case HRM_GUI_A_HD:

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

        // Simple cut/copy/paste combos
        case COMBO_CUT:
        case COMBO_CUT_SHT:
        case COMBO_COPY:
        case COMBO_COPY_SHT:
        case COMBO_PASTE:
        case COMBO_PASTE_SHT:
            return false;
    }
    return true;
}

