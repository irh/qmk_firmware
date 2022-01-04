#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define KC_ KC_TRNS

#define L_0 0
#define L_1 1
#define L_2 2
#define L_3 3
#define L_4 4

#define L1_BSPC LT(L_1, KC_BSPC)
#define L1_SPACE LT(L_1, KC_SPACE)
#define L2_TAB LT(L_2, KC_TAB)
#define L2_ENTER LT(L_2, KC_ENTER)
#define L3_F17 LT(L_3, KC_F17)

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  // Layer 0 - base layer, Colemak Mod DH
  [L_0] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_F3,   KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                               KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_MPLY,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_ESC,  KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                               KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                               KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     LCAG(KC_M),TG(L_4),KC_LCTL,KC_LALT, KC_LCMD, L1_BSPC, L2_TAB,           L2_ENTER,L1_SPACE,KC_RCMD, KC_RALT, KC_RCTL, LCAG(KC_LEFT), LCAG(KC_RIGHT),
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_F15,  KC_F16,  L3_F17,                    KC_F18,  KC_F19,  KC_F20
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  // Layer 1 - Numbers and symbols
  [L_1] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
         ,EXLM,AT  ,LCBR,RCBR,PIPE,               BSLS, P7 , P8 , P9 ,ASTR,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,HASH,DLR ,LPRN,RPRN,GRV ,               PIPE, P4 , P5 , P6 ,SLSH,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,PERC,CIRC,LBRC,RBRC,TILD,               AMPR, P1 , P2 , P3 ,PLUS,    ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,SCLN,     COLN,    , P0 , EQL, DOT,MINS,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                           ,    ,    ,             ,    ,
  //                  `----+----+----'        `----+----+----'
  ),

  // Layer 2 - Navigation and connecting symbols
  [L_2] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
         ,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,EXLM,EQL ,MINS,PLUS,               H   ,J   ,K   ,L   ,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,                   ,    ,UP  ,    ,    ,    ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         ,    ,    ,    ,    ,DEL ,    ,         ,UNDS,LEFT,DOWN,RGHT,    ,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                           ,    ,    ,             ,    ,
  //                  `----+----+----'        `----+----+----'
  ),

  // Layer 3 - Mouse
  [L_3] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
         ,    ,    ,    ,    ,    ,               WH_U,    ,MS_U,    ,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,               WH_D,MS_L,MS_D,MS_R,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,    ,         ,BTN1,BTN2,    ,    ,    ,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                           ,    ,    ,             ,    ,
  //                  `----+----+----'        `----+----+----'
  ),


  // Layer 4 - QWERTY
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
                           ,    ,    ,             ,    ,
  //                  `----+----+----'        `----+----+----'
  )
};

