#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"
              //
enum layers {
    L_0, // base
    L_1, // qwerty
    L_2, // symbols
    L_3, // navigation
    L_4, // mouse
};

#define LAG(kc) (QK_LALT | QK_LGUI | (kc))

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Layer 0 - base layer, Colemak Mod DH
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | F3     |   Q  |   W  |   F  |   P  |   B  |      |           |      |   J  |   L  |   U  |   Y  |   ;  |  PLAY  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Esc    |   A  |   R  |   S  |   T  |   G  |      |           |      |   M  |   N  |   E  |   I  |   O  |   '    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   D  |   V  |------|           |------|   K  |   H  |   ,  |   .  |   /  | RShift |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Full   |  L1  | LCtl | LAlt | LCmd |Bks/L2|Tab/L3|           |Ent/L3|Spc/L2| RCmd | RAlt | RCtl |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |  <<  | >>/L4|                                       |  F18 |  F19 |  F20 |  <-- | -->    |
 *   `----------------------------------'                                       `------------------------------------'
 *                                        ,-------------.       ,------------.
 *                                        |  __  |  __  |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |  F16 |      |------|       |------|      | F17  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[L_0] = LAYOUT_ergodox(
        // left hand
        KC_F3,   KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,   _______,
        KC_ESC,  KC_A,    KC_R,    KC_S,    KC_T,    KC_G,   _______,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,
        LAG(KC_F), TG(L_1), KC_LCTL, KC_LALT, KC_LCMD, LT(L_2, KC_BSPC), LT(L_3, KC_TAB),
        _______, _______, _______, KC_MRWD, LT(L_4, KC_MFFD),
                                                    _______, _______,
                                                             _______,
                                            KC_F16, _______, _______,

        // right hand
        _______, KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_MPLY,
        _______, KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
                 KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
        LT(L_3, KC_ENTER), LT(L_2, KC_SPACE), KC_RCMD, KC_RALT, KC_RCTL, LAG(KC_LEFT), LAG(KC_RIGHT),
                 KC_F18,  KC_F19,  KC_F20,  _______, _______,
        _______, _______,
        _______,
        _______, _______, KC_F17
    ),

/* Layer 1 - QWERTY
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |   Q  |   W  |   E  |   R  |   T  |      |           |      |   Y  |   U  |   I  |   O  |   P  |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   A  |   S  |   D  |   F  |   G  |      |           |      |   H  |   J  |   K  |   L  |   ;  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   Z  |   X  |   C  |   V  |   B  |------|           |------|   N  |   M  |   ,  |   .  |   /  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |        |
 *   `----------------------------------'                                       `------------------------------------'
 *                                        ,-------------.       ,------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[L_1] = LAYOUT_ergodox(
        // left hand
        _______, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    _______,
        _______, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    _______,
        _______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,
        _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______,  _______,
                                                     _______, _______,
                                                              _______,
                                            _______, _______, _______,

        // right hand
        _______, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MPLY,
        _______, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
                 KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
        _______, _______, _______, _______, _______, _______, _______,
                 _______, _______, _______, _______, _______,
        _______, _______,
        _______,
        _______, _______, _______
),

/* Layer 2 - symbols
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |         |   !  |   @  |   {  |   }  |   |  |      |           |      |   \  |   7  |   8  |   9  |   *  |        |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |   #  |   $  |   (  |   )  |   `  |      |           |      |   |  |   4  |   5  |   6  |   /  |   \    |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   %  |   ^  |   [  |   ]  |   ~  |------|           |------|   &  |   1  |   2  |   3  |   +  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |      |      |      |      |   ;  |           |   :  |      |   0  |   =  |   .  |   -  |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      |      |      |                                       |      |      |      |      |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[L_2] = LAYOUT_ergodox(
       // left hand
       _______, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE, _______,
       _______, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,  _______,
       _______, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD,
       _______, _______, _______, _______, _______, _______, KC_SCLN,
       _______, _______, _______, _______, _______,
                                                    _______, _______,
                                                             _______,
                                           _______, _______, _______,

       // right hand
       _______, KC_BSLS, KC_7,    KC_8,    KC_9,    KC_ASTR, _______,
       _______, KC_PIPE, KC_4,    KC_5,    KC_6,    KC_SLSH, KC_BSLS,
                KC_AMPR, KC_1,    KC_2,    KC_3,    KC_PLUS, _______,
       KC_COLN, _______, KC_0,    KC_EQL,  KC_DOT,  KC_MINS, _______,
                         _______, _______, _______, _______, _______,
       _______, _______,
       _______,
       _______, _______, _______
),

/* Layer 3 - navigation
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |  !   |  =   |  -   |  +   |      |           |      |  H   |  J   |  K   |  L   |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |  Up  |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      | Del  |      |           |      |  _   | Left | Down | Right|      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[L_3] = LAYOUT_ergodox(
       // left hand
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, KC_EXLM, KC_EQL,  KC_MINS, KC_PLUS, _______,
       _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, KC_DEL,  _______,
       _______, _______, _______, _______, _______,
                                           _______, _______,
                                                    _______,
                                  _______, _______, _______,

       // right hand
       _______, _______, _______, _______, _______, _______, _______,
       _______, KC_H,    KC_J,    KC_K,    KC_L,    _______, _______,
                _______, _______, KC_UP,   _______, _______, _______,
       _______, KC_UNDS, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
                _______, _______, _______, _______, _______,
       _______, _______,
       _______,
       _______, _______, _______
),

/* Layer 4 - mouse
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |ScrllU|      |  Up  |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |ScrllD| Left | Down | Right|      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |ClickL|ClickR|      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[L_4] = LAYOUT_ergodox(
       // left hand
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______,
                                           _______, _______,
                                                    _______,
                                  _______, _______, _______,

       // right hand
       _______, KC_WH_U, _______, KC_MS_U, _______, _______, _______,
       _______, KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______,
                _______, _______, _______, _______, _______, _______,
       _______, KC_BTN1, KC_BTN2, _______, _______, _______, _______,
                _______, _______, _______, _______, _______,
       _______, _______,
       _______,
       _______, _______, _______
),

}; // End of layers

// const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
// {
//   // MACRODOWN only works in this function
//   switch(id) {
//     case 0:
//       if (record->event.pressed) {
//         SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
//       }
//       break;
//     case 1:
//       if (record->event.pressed) { // For resetting EEPROM
//         eeconfig_init();
//       }
//       break;
//   }
//   return MACRO_NONE;
// };
//
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode(1);
        #endif
      }
      return false;
      break;
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

};

// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = biton32(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #else
        #ifdef RGBLIGHT_ENABLE
          rgblight_init();
        #endif
        #endif
        break;
      case 1:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        /* ergodox_right_led_2_on(); */
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        /* ergodox_right_led_3_on(); */
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      default:
        break;
    }

  return state;
};
