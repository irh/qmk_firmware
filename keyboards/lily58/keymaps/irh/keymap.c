#include QMK_KEYBOARD_H

#ifdef PROTOCOL_LUFA
  #include "lufa.h"
  #include "split_util.h"
#endif
#ifdef SSD1306OLED
  #include "ssd1306.h"
#endif

extern keymap_config_t keymap_config;

extern uint8_t is_master;

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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  // Layer 0 - Base QWERTY layer
  [L_0] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_F3,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MPLY,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                               KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     LCAG(KC_H),TG(L_4),KC_LCTL,KC_LALT, KC_LCMD, L1_BSPC, KC_DEL,           KC_UNDS, L1_SPACE,KC_RCMD, KC_RALT, KC_RCTL, LCAG(KC_LEFT), LCAG(KC_RIGHT),
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                           KC_F15,  KC_F16,  L3_F17,  L2_TAB,                    L2_ENTER,KC_F18,  KC_F19,  KC_F20
  //                      └────────┴────────┴────────┴────────┘                 └────────┴────────┴────────┴────────┘
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
                      ,    ,    ,    ,             ,    ,    ,
  //             `----+----+----+----'        `----+----+----+----'
  ),

  // Layer 2 - Navigation and connecting symbols
  //           VIM keys reversed through Colemak Mod DH software mapping
  [L_2] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
         ,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,EXLM,EQL ,MINS,PLUS,               M   ,Y   ,N   ,U   ,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,                   ,    ,UP  ,    ,    ,    ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         ,    ,    ,    ,    ,DEL ,    ,         ,UNDS,LEFT,DOWN,RGHT,    ,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                      ,    ,    ,    ,             ,    ,    ,
  //             `----+----+----+----'        `----+----+----+----'
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
                      ,    ,    ,    ,             ,    ,    ,
  //             `----+----+----+----'        `----+----+----+----'
  ),


  // Layer 4 - Reverse of Colemak Mod DH software mapping to QWERTY
  [L_4] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
         ,    ,    , K  , S  , F  ,                O  , I  , L  ,SCLN, R  ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    , D  , V  , E  ,    ,                M  , Y  , N  , U  , P  ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,    ,    , B  , T  ,                J  , H  ,    ,    ,    ,    ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,    ,         ,    ,    ,    ,    ,    ,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                      ,    ,    ,    ,             ,    ,    ,
  //             `----+----+----+----'        `----+----+----+----'
  )
};

void matrix_init_user(void) {
    //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
    #ifdef SSD1306OLED
        iota_gfx_init(!has_usb());   // turns on the display
    #endif
}

//SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED

// When add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

void matrix_scan_user(void) {
   iota_gfx_task();
}

void matrix_render_user(struct CharacterMatrix *matrix) {
  if (is_master) {
    // If you want to change the display of OLED, you need to change here
    matrix_write_ln(matrix, read_layer_state());
    matrix_write_ln(matrix, read_keylog());
    matrix_write_ln(matrix, read_keylogs());
    //matrix_write_ln(matrix, read_mode_icon(keymap_config.swap_lalt_lgui));
    //matrix_write_ln(matrix, read_host_led_state());
    //matrix_write_ln(matrix, read_timelog());
  } else {
    matrix_write(matrix, read_logo());
  }
}

void matrix_update(struct CharacterMatrix *dest, const struct CharacterMatrix *source) {
  if (memcmp(dest->display, source->display, sizeof(dest->display))) {
    memcpy(dest->display, source->display, sizeof(dest->display));
    dest->dirty = true;
  }
}

void iota_gfx_task_user(void) {
  struct CharacterMatrix matrix;
  matrix_clear(&matrix);
  matrix_render_user(&matrix);
  matrix_update(&display, &matrix);
}
#endif//SSD1306OLED

