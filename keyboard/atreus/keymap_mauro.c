#include "keymap_common.h"

/* Mauro's fork of keymap_colemak.c */

/* This layout implements colemak in the firmware, so you don't have to
   set the OS configuration into colemak layout. Useful if you don't have
   a laptop with an internal keyboard, or if you use other peoples' computers
   a lot. */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  KEYMAP( /* 0: colemak */
         KC_Q,   KC_W,    KC_F,    KC_P,    KC_G,                          KC_J,   KC_L,   KC_U,      KC_Y,    KC_ENT,   \
         KC_A,   KC_R,    KC_S,    KC_T,    KC_D,                          KC_H,   KC_N,   KC_E,      KC_I,    KC_O,     \
         KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,                          KC_K,   KC_M,   KC_SCOLON, KC_QUOT, KC_MINUS, \
         KC_TAB, KC_FN24, KC_LGUI, KC_LSFT, KC_BSPC,   KC_FN23, KC_LCTL,   KC_SPC, KC_FN0, KC_COMM,   KC_DOT,  KC_SLSH   \
  ), KEYMAP( /* 1: qwerty */
         KC_Q,   KC_W,   KC_E,    KC_R,    KC_T,                          KC_Y,   KC_U,   KC_I,    KC_O,    KC_P,    \
         KC_A,   KC_S,   KC_D,    KC_F,    KC_G,                          KC_H,   KC_J,   KC_K,    KC_L,    KC_SCLN, \
         KC_Z,   KC_X,   KC_C,    KC_V,    KC_B,                          KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH, \
         KC_ESC, KC_TAB, KC_LGUI, KC_LSFT, KC_BSPC,   KC_LALT, KC_LCTL,   KC_SPC, KC_FN0, KC_MINS, KC_QUOT, KC_ENT   \
  ), KEYMAP( /* 2: numbers and arrows */
         KC_1,    KC_2,          KC_3,         KC_4,          KC_5,                          KC_PGUP,            KC_HOME,     KC_UP,       KC_END,   KC_DEL,    \
         KC_6,    KC_7,          KC_8,         KC_9,          KC_0,                          KC_PGDN,            KC_LEFT,     KC_DOWN,     KC_RIGHT, KC_BSLASH, \
         KC_UNDO, SHIFT(KC_DEL), CTRL(KC_INS), SHIFT(KC_INS), KC_EQL,                        KC_FN5, /* reset */ SHIFT(KC_9), SHIFT(KC_0), KC_LBRC,  KC_RBRC,   \
         KC_FN1,  KC_TRNS,       KC_TRNS,      KC_TRNS,       KC_TRNS,   KC_TRNS, KC_TRNS,   KC_SPC,             KC_FN0,      KC_TRNS,     KC_TRNS,  KC_FN3     \
  ), KEYMAP( /* 3: mouse */
         KC_FN20, KC_NO,   KC_FN11, KC_NO,   KC_NO,                       KC_FN18, KC_NO,  KC_FN7,             KC_NO,   KC_FN19, \
         KC_FN21, KC_FN13, KC_FN12, KC_FN14, KC_NO,                       KC_NO,   KC_FN9, KC_FN8,             KC_FN10, KC_NO,   \
         KC_FN22, KC_NO,   KC_NO,   KC_NO,   KC_NO,                       KC_NO,   KC_NO,  KC_NO,              KC_NO,   KC_NO,   \
         KC_TRNS, KC_NO,   KC_TRNS, KC_TRNS, KC_NO,   KC_TRNS, KC_TRNS,   KC_FN15, KC_FN2, KC_FN5, /* reset */ KC_FN17, KC_FN16  \
  ), KEYMAP( /* 4: Fn and system */
         KC_F1,   KC_F2,   KC_F3,    KC_F4,   KC_F5,                        KC_F11, KC_F12, KC_F13,             KC_F14, KC_F15, \
         KC_F6,   KC_F7,   KC_F8,    KC_F9,   KC_F10,                       KC_F16, KC_F17, KC_F18,             KC_F19, KC_F20, \
         KC_PSCR, KC_SLCK, KC_PAUSE, KC_NO,   KC_FN5, /* reset */           KC_F21, KC_F22, KC_F23,             KC_F24, KC_NO,  \
         KC_RCTL, KC_NO,   KC_TRNS,  KC_TRNS, KC_FN6,   KC_TRNS, KC_TRNS,   KC_NO,  KC_FN4, KC_FN5, /* reset */ KC_NO,  KC_FN3  \
)};

// KC__VOLUP, KC__VOLDOWN, KC__MUTE

const uint16_t PROGMEM fn_actions[] = {
  [0] = ACTION_LAYER_MOMENTARY(2),     // to Fn overlay
  [1] = ACTION_LAYER_ON(3, ON_PRESS),  // switch to layer 3
  [2] = ACTION_LAYER_OFF(3, ON_PRESS), // switch back to layer 0 from layer 3
  [3] = ACTION_LAYER_MOMENTARY(4), //ON(4, ON_PRESS),  // switch to layer 4
  [4] = ACTION_LAYER_OFF(4, ON_PRESS), // switch back to layer 0 from layer 4
  [5] = ACTION_FUNCTION(BOOTLOADER),
  [6] = ACTION_LAYER_TOGGLE(1),
  [7] = ACTION_MOUSEKEY(KC_MS_U),
  [8] = ACTION_MOUSEKEY(KC_MS_D),
  [9] = ACTION_MOUSEKEY(KC_MS_L),
  [10] = ACTION_MOUSEKEY(KC_MS_R),
  [11] = ACTION_MOUSEKEY(KC_WH_U),
  [12] = ACTION_MOUSEKEY(KC_WH_D),
  [13] = ACTION_MOUSEKEY(KC_WH_L),
  [14] = ACTION_MOUSEKEY(KC_WH_R),
  [15] = ACTION_MOUSEKEY(KC_BTN1),
  [16] = ACTION_MOUSEKEY(KC_BTN2),
  [17] = ACTION_MOUSEKEY(KC_BTN3),
  [18] = ACTION_MOUSEKEY(KC_BTN4),
  [19] = ACTION_MOUSEKEY(KC_BTN5),
  [20] = ACTION_MOUSEKEY(KC_ACL0),
  [21] = ACTION_MOUSEKEY(KC_ACL1),
  [22] = ACTION_MOUSEKEY(KC_ACL2),
  [23] = ACTION_MODS_TAP_KEY(MOD_LALT, KC_ESC),
  [24] = ACTION_MODS_TAP_KEY(MOD_RALT, KC_GRAVE)
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  if (id == BOOTLOADER) {
    bootloader();
  }
}
