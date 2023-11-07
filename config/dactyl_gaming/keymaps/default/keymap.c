/* Copyright 2018 REPLACE_WITH_YOUR_NAME
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

#define BASE 0
#define L1 1
#define L2 2
#define COLE 3
#define MEDI 5
#define NUMS 9
#define BASE_OLD 15

enum custom_keycodes {
    M_AMLC,
    M_SVUP,
    M_SVDN,
};

#define SCR_PIC LCTL(KC_PSCR)
#define SCR_VID LSFT(LCTL(KC_PSCR))
#define FUL_SCR LGUI(KC_F)
#define STM_OVR HYPR(KC_S)
#define SWTCH_M LGUI(LCTL(KC_P))
#define M_LEFT LGUI(KC_M)
#define M_MID LGUI(KC_COMM)
#define M_RIGHT LGUI(KC_DOT)
// nexte media player
#define MED_NXT LGUI(LALT(LCTL(LSFT(KC_N))))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//    ┌─────┬──────┬──────┬───┬────────┬────────┐
//    │ esc │  m   │  4   │ 5 │   h    │   t    │
//    ├─────┼──────┼──────┼───┼────────┼────────┤
//    │  3  │ tab  │  q   │ w │   e    │   r    │
//    ├─────┼──────┼──────┼───┼────────┼────────┤
//    │  2  │ lsft │  a   │ s │   d    │   f    │
//    ├─────┼──────┼──────┼───┼────────┼────────┤
//    │  1  │ lctl │  z   │ x │   v    │   b    │
//    └─────┴──────┼──────┼───┼────────┴────────┘
//                 │ lalt │ k │
//                 └──────┴───┼────────┬────────┐
//                            │  spc   │   c    │
//                            ├────────┼────────┤
//                            │   g    │   o    │
//                            ├────────┼────────┤
//                            │ MO(L1) │ MO(L2) │
//    ┌────────────┬──────────┼────────┴────────┤
//    │    mply    │ MED_NXT  │       f11       │
//    └────────────┴──────────┴─────────────────┘
[BASE] = LAYOUT(
  KC_ESC , KC_M    , KC_4    , KC_5 , KC_H   , KC_T  ,
  KC_3   , KC_TAB  , KC_Q    , KC_W , KC_E   , KC_R  ,
  KC_2   , KC_LSFT , KC_A    , KC_S , KC_D   , KC_F  ,
  KC_1   , KC_LCTL , KC_Z    , KC_X , KC_V   , KC_B  ,
                     KC_LALT , KC_K                  ,
                                      KC_SPC , KC_C  ,
                                      KC_G   , KC_O  ,
                                      MO(L1) , MO(L2),
      KC_MPLY      ,    MED_NXT     ,     KC_F11
),

//    ┌─────────┬─────┬────────┬─────────┬─────────┬─────┐
//    │    `    │  1  │   2    │    3    │    4    │  5  │
//    ├─────────┼─────┼────────┼─────────┼─────────┼─────┤
//    │ SCR_PIC │     │        │         │         │     │
//    ├─────────┼─────┼────────┼─────────┼─────────┼─────┤
//    │ SCR_VID │     │ M_LEFT │  M_MID  │ M_RIGHT │     │
//    ├─────────┼─────┼────────┼─────────┼─────────┼─────┤
//    │ STM_OVR │  6  │   7    │    8    │    9    │  0  │
//    └─────────┴─────┼────────┼─────────┼─────────┴─────┘
//                    │  lgui  │ SWTCH_M │
//                    └────────┴─────────┼─────────┬─────┐
//                                       │         │     │
//                                       ├─────────┼─────┤
//                                       │         │     │
//                                       ├─────────┼─────┤
//                                       │         │     │
//    ┌───────────────┬──────────────────┼─────────┴─────┤
//    │               │                  │    QK_BOOT    │
//    └───────────────┴──────────────────┴───────────────┘
[L1] = LAYOUT(
  KC_GRV  , KC_1    , KC_2    , KC_3    , KC_4    , KC_5   ,
  SCR_PIC , _______ , _______ , _______ , _______ , _______,
  SCR_VID , _______ , M_LEFT  , M_MID   , M_RIGHT , _______,
  STM_OVR , KC_6    , KC_7    , KC_8    , KC_9    , KC_0   ,
                      KC_LGUI , SWTCH_M                    ,
                                          _______ , _______,
                                          _______ , _______,
                                          _______ , _______,
       _______      ,      _______      ,      QK_BOOT
),

//    ┌─────┬─────┬─────┬─────┬─────┬─────┐
//    │ f1  │ f2  │     │     │ f11 │ f12 │
//    ├─────┼─────┼─────┼─────┼─────┼─────┤
//    │     │  p  │  o  │  i  │  u  │  y  │
//    ├─────┼─────┼─────┼─────┼─────┼─────┤
//    │     │     │  l  │  k  │  j  │  h  │
//    ├─────┼─────┼─────┼─────┼─────┼─────┤
//    │     │     │     │     │  m  │  n  │
//    └─────┴─────┼─────┼─────┼─────┴─────┘
//                │     │     │
//                └─────┴─────┼─────┬─────┐
//                            │     │     │
//                            ├─────┼─────┤
//                            │     │     │
//                            ├─────┼─────┤
//                            │     │     │
//    ┌───────────┬───────────┼─────┴─────┤
//    │           │           │  QK_BOOT  │
//    └───────────┴───────────┴───────────┘
[L2] = LAYOUT(
  KC_F1   , KC_F2   , _______ , _______ , KC_F11  , KC_F12 ,
  _______ , KC_P    , KC_O    , KC_I    , KC_U    , KC_Y   ,
  _______ , _______ , KC_L    , KC_K    , KC_J    , KC_H   ,
  _______ , _______ , _______ , _______ , KC_M    , KC_N   ,
                      _______ , _______                    ,
                                          _______ , _______,
                                          _______ , _______,
                                          _______ , _______,
       _______      ,      _______      ,      QK_BOOT
)
};

const uint16_t PROGMEM fn_actions[] = {

};

static bool auto_fire;

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
      switch(keycode) {
        case M_AMLC:
          if (record->event.pressed) {
            auto_fire = true;
          } else {
            auto_fire = false;
          }
          break;
        case M_SVUP:
          if (record->event.pressed) {
            auto_fire = true;
          } else {
            auto_fire = false;
          }
          break;
        case M_SVDN:
          if (record->event.pressed) {
            register_code(KC_RSFT);
          } else {
            unregister_code(KC_RSFT);
          }
          break;
      }
    return true;
}


void matrix_init_user(void) {

}

void matrix_scan_user(void) {
  if (auto_fire == true) {
    register_code(KC_BTN1);
    unregister_code(KC_BTN1);
  }
}

void led_set_user(uint8_t usb_led) {

}
