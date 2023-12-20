// Copyright 2022 Cole Smith <cole@boadsource.xyz>
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#define KC_ KC_TRNS

#define LAYOUT_kc( \
    L00, L01, L02, L03, L04, L05,           R00, R01, R02, R03, R04, R05, \
    L10, L11, L12, L13, L14, L15,           R10, R11, R12, R13, R14, R15, \
    L20, L21, L22, L23, L24, L25,           R20, R21, R22, R23, R24, R25, \
    L30, L31, L32, L33, L34, L35, LT4, RT4, R30, R31, R32, R33, R34, R35, \
                   LT0, LT1, LT2, LT3, RT3, RT2, RT1, RT0 \
    ) \
    LAYOUT( \
        KC_##L00, KC_##L01, KC_##L02, KC_##L03, KC_##L04, KC_##L05,                     KC_##R00, KC_##R01, KC_##R02, KC_##R03, KC_##R04, KC_##R05, \
        KC_##L10, KC_##L11, KC_##L12, KC_##L13, KC_##L14, KC_##L15,                     KC_##R10, KC_##R11, KC_##R12, KC_##R13, KC_##R14, KC_##R15, \
        KC_##L20, KC_##L21, KC_##L22, KC_##L23, KC_##L24, KC_##L25,                     KC_##R20, KC_##R21, KC_##R22, KC_##R23, KC_##R24, KC_##R25, \
        KC_##L30, KC_##L31, KC_##L32, KC_##L33, KC_##L34, KC_##L35, KC_##LT4, KC_##RT4, KC_##R30, KC_##R31, KC_##R32, KC_##R33, KC_##R34, KC_##R35, \
                                      KC_##LT0, KC_##LT1, KC_##LT2, KC_##LT3, KC_##RT3, KC_##RT2, KC_##RT1, KC_##RT0 \
    )

#define LTX(n, key) LT(L_##n, KC_##key)

enum layers {
    L_0, // Base layer
    L_1, // Symbols
    L_2, // Navigation
    L_3, // Mouse
    L_4, // Qwerty
    L_5, // Debugging
};

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Layer 0 - Base layer
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | F3   |   Q  |   W  |   F  |   P  |   B  |                    |   J  |   L  |   U  |   Y  |   ;  |  L4  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   G  |                    |   M  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   D  |   V  |-------.    ,-------|   K  |   H  |   ,  |   .  |   /  |RShift|
 * |------+------+------+------+------+------| Play  |    |  Tab  |------+------+------+------+------+------|
 * |LAG+F |  L4  | LCtl | LAlt | LCmd |Bks/L1|-------|    |-------|Spc/L1| RCmd | RAlt | RCtl |LAG+← |LAG+→ |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |F14/L5| F15  |F16/L3| /Tab/L2 /       \Ent/L2\  | F17  | F18  | F19  |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [L_0] = LAYOUT(
    KC_F3,     KC_Q,      KC_W,    KC_F,    KC_P,    KC_B,                           KC_J,          KC_L,    KC_U,    KC_Y,    KC_SCLN,     TG(L_4),
    KC_ESC,    KC_A,      KC_R,    KC_S,    KC_T,    KC_G,                           KC_M,          KC_N,    KC_E,    KC_I,    KC_O,        KC_QUOT,
    KC_LSFT,   KC_Z,      KC_X,    KC_C,    KC_D,    KC_V,                           KC_K,          KC_H,    KC_COMM, KC_DOT,  KC_SLSH,     KC_RSFT,
    LAG(KC_F), LAG(KC_C), KC_LCTL, KC_LALT, KC_LCMD, LTX(1, BSPC), KC_MPLY,     KC_TAB, LTX(1, SPACE), KC_RCMD, KC_RALT, KC_RCTL, LAG(KC_LEFT),LAG(KC_RIGHT),
                            LTX(5, F14), KC_F15, LTX(3, F16), LTX(2, TAB),       LTX(2, ENTER), KC_F17,  KC_F18,  KC_F19
  ),

  // Layer 1 - Numbers and symbols
  [L_1] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
         ,EXLM,AT  ,LCBR,RCBR,PIPE,               BSLS, 7  , 8  , 9  ,ASTR,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,HASH,DLR ,LPRN,RPRN,GRV ,               PIPE, 4  , 5  , 6  ,SLSH,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,PERC,CIRC,LBRC,RBRC,TILD,               AMPR, 1  , 2  , 3  ,PLUS,    ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,    ,         ,    , 0  , EQL, DOT,MINS,    ,
  //`----+----+----+----+----+----+----/    \----+----+----+----+----+----+----'
                      ,    ,    ,SCLN,         COLN,    ,    ,
  //             `----+----+----+----'        `----+----+----+----'
  ),

  // Layer 2 - Navigation
  [L_2] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
         ,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,EXLM,EQL ,MINS,PLUS,                H  , J  , K  , L  ,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,                   ,    ,UP  ,    ,    ,    ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         ,    ,    ,    ,    ,DEL ,    ,         ,UNDS,LEFT,DOWN,RGHT,    ,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                      ,    ,    ,    ,             ,    ,    ,
  //             `----+----+----+----'        `----+----+----+----'
  ),

  // Layer 3 - Mouse + Bootloader
  [L_3] = LAYOUT(
      QK_BOOT, KC_, KC_, KC_, KC_, KC_,                       KC_WH_U, KC_,     KC_MS_U, KC_,     KC_, KC_,
      KC_,     KC_, KC_, KC_, KC_, KC_,                       KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, KC_, KC_,
      KC_,     KC_, KC_, KC_, KC_, KC_,                       KC_,     KC_,     KC_,     KC_,     KC_, KC_,
      KC_,     KC_, KC_, KC_, KC_, KC_, KC_,             KC_, KC_BTN1, KC_BTN2, KC_,     KC_,     KC_, KC_,
                          KC_, KC_, KC_, KC_,            KC_,  KC_, KC_, KC_
  ),

  // Layer 4 - Qwerty
  [L_4] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
         , Q  , W  , E  , R  , T  ,                Y  , U  , I  , O  , P  ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         , A  , S  , D  , F  , G  ,                H  , J  , K  , L  ,SCLN,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         , Z  , X  , C  , V  , B  ,                N  , M  ,    ,    ,    ,    ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,    ,         ,    ,    ,    ,    ,    ,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                      ,    ,    ,    ,             ,    ,    ,
  //             `----+----+----+----'        `----+----+----+----'
  ),

  // Layer 5 - Debugging
  [L_5] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
         ,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,                F6 , F7 , F8 , F9 ,F10 ,F11 ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,    ,         ,    ,    ,    ,    ,    ,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                      ,    ,    ,    ,             ,    ,    ,
  //             `----+----+----+----'        `----+----+----+----'
  ),

};

#ifdef RGBLIGHT_ENABLE

const rgblight_segment_t PROGMEM layer_0[] = RGBLIGHT_LAYER_SEGMENTS({0, RGBLED_NUM, HSV_OFF});
const rgblight_segment_t PROGMEM layer_1[] = RGBLIGHT_LAYER_SEGMENTS({0, RGBLED_NUM, HSV_OFF});
const rgblight_segment_t PROGMEM layer_2[] = RGBLIGHT_LAYER_SEGMENTS({0, RGBLED_NUM, HSV_OFF});
const rgblight_segment_t PROGMEM layer_3[] = RGBLIGHT_LAYER_SEGMENTS({0, RGBLED_NUM, HSV_ORANGE});
const rgblight_segment_t PROGMEM layer_4[] = RGBLIGHT_LAYER_SEGMENTS({0, RGBLED_NUM, HSV_WHITE});
const rgblight_segment_t PROGMEM layer_5[] = RGBLIGHT_LAYER_SEGMENTS({0, RGBLED_NUM, HSV_BLUE});

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    layer_0, layer_1, layer_2, layer_3, layer_4, layer_5
);

void keyboard_post_init_user(void) {
    // Show a power-on flash
    rgblight_enable_noeeprom();
    rgblight_sethsv_noeeprom(HSV_GREEN);
    wait_ms(100);
    rgblight_sethsv_noeeprom(HSV_OFF);

    // Enable the LED layers
    rgblight_enable();
    rgblight_layers = my_rgb_layers;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, L_0));
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, L_0));
    rgblight_set_layer_state(1, layer_state_cmp(state, L_1));
    rgblight_set_layer_state(2, layer_state_cmp(state, L_2));
    rgblight_set_layer_state(3, layer_state_cmp(state, L_3));
    rgblight_set_layer_state(4, layer_state_cmp(state, L_4));
    rgblight_set_layer_state(5, layer_state_cmp(state, L_5));

    return state;
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_MNXT);
        } else {
            tap_code(KC_MPRV);
        }
    } else if (index == 1) {
        if (clockwise) {
            tap_code(KC_WH_U);
        } else {
            tap_code(KC_WH_D);
        }
    }
    return false;
}

#endif // RGBLIGHT_ENABLE
