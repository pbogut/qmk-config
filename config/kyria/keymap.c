/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
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

enum layers {
    BASE = 0,
    PROG,
    MDIA,
    NAVI,
    FUNC,
};

enum custom_keycodes {
    H_BSPC = SAFE_RANGE,
    D_DEL,
    CTL_QUT,
    /* CTL_EQL, */
    CTL_ESC,
    /* CTL_TLD, */
    CTL_G_SLASH,
    CTL_G_Z,
    TMX_GRV,
    TMX_DSH,
    LARR,
    RARR,
    LSHT_BR,
    RSHT_BR,
    PIPE_GT,
    LT_PIPE,
    L1_TAB,
    L1_BSLS,
    ENT_ALT,
    SPC_ALT,
    GUI_TLD,
    M_CTL,
    M_DARR_L,
    M_DARR_R,
    M_EX_EQ,
    M_GT_EQ,
    M_AND,
    M_OR,
    M_LT_EQ,
    TMX_1,
    TMX_2,
    TMX_3,
    TMX_4,
};

// Aliases for readability

#define KILL      LGUI(LSFT(KC_Q))
#define F_LBRC    LT(FUNC, KC_LBRC)
#define F_RBRC    LT(FUNC, KC_RBRC)
#define L_NAVI    MO(NAVI)
#define C_LEFT    LCTL(KC_LEFT)
#define C_RIGHT   LCTL(KC_RIGHT)
#define CTRL_F    LCTL(KC_F)
#define PSCR_SC   LSFT(KC_PSCR)
#define PSCR_RT   LGUI(KC_PSCR)

#define GUI_1     LGUI(KC_1)
#define GUI_2     LGUI(KC_2)
#define GUI_3     LGUI(KC_3)
#define GUI_4     LGUI(KC_4)
#define GUI_5     LGUI(KC_5)
#define GUI_6     LGUI(KC_6)
#define GUI_7     LGUI(KC_7)
#define GUI_8     LGUI(KC_8)
#define GUI_9     LGUI(KC_9)

#define ENC_LEFT  0
#define ENC_RIGHT 1
/* #define LALT MT(MOD_LALT, KC_ENT) */
#define ALT_GRV MT(MOD_LALT, KC_GRV)

#define ALT_EQL MT(MOD_RALT, KC_EQL)
#define GUI_MIN MT(MOD_RGUI, KC_MINUS)


const uint16_t TTIMER_MIN = 125;
const uint16_t TTIMER = 255;
// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//    ┌─────────┬───┬───┬───────┬──────┬──────┐                                         ┌────────┬──────┬─────┬───┬───┬─────────┐
//    │ L1_TAB  │ q │ w │   e   │  r   │  t   │                                         │   y    │  u   │  i  │ o │ p │ L1_BSLS │
//    ├─────────┼───┼───┼───────┼──────┼──────┤                                         ├────────┼──────┼─────┼───┼───┼─────────┤
//    │ CTL_ESC │ a │ s │ D_DEL │  f   │  g   │                                         │ H_BSPC │  j   │  k  │ l │ ; │ CTL_QUT │
//    ├─────────┼───┼───┼───────┼──────┼──────┼────────┬─────────┐   ┌─────────┬────────┼────────┼──────┼─────┼───┼───┼─────────┤
//    │ LSHT_BR │ z │ x │   c   │  v   │  b   │ F_LBRC │ TMX_GRV │   │ TMX_DSH │ F_RBRC │   n    │  m   │  ,  │ . │ / │ RSHT_BR │
//    └─────────┴───┴───┼───────┼──────┼──────┼────────┼─────────┤   ├─────────┼────────┼────────┼──────┼─────┼───┴───┴─────────┘
//                      │ mply  │ lgui │ lalt │  spc   │ L_NAVI  │   │ L_NAVI  │  ent   │  ralt  │ rgui │     │
//                      └───────┴──────┴──────┴────────┴─────────┘   └─────────┴────────┴────────┴──────┴─────┘
[BASE] = LAYOUT(
  L1_TAB  , KC_Q , KC_W , KC_E    , KC_R    , KC_T    ,                                           KC_Y    , KC_U    , KC_I    , KC_O   , KC_P    , L1_BSLS,
  CTL_ESC , KC_A , KC_S , D_DEL   , KC_F    , KC_G    ,                                           H_BSPC  , KC_J    , KC_K    , KC_L   , KC_SCLN , CTL_QUT,
  LSHT_BR , KC_Z , KC_X , KC_C    , KC_V    , KC_B    , F_LBRC , TMX_GRV ,     TMX_DSH , F_RBRC , KC_N    , KC_M    , KC_COMM , KC_DOT , KC_SLSH , RSHT_BR,
                          KC_MPLY , KC_LGUI , KC_LALT , KC_SPC , L_NAVI  ,     L_NAVI  , KC_ENT , KC_RALT , KC_RGUI , _______
),

//    ┌─────┬───┬───┬─────┬─────┬─────┐                                   ┌──────┬─────┬─────┬───┬─────┬─────┐
//    │     │ ! │ * │  $  │  -  │  _  │                                   │  .   │  7  │  8  │ 9 │  +  │     │
//    ├─────┼───┼───┼─────┼─────┼─────┤                                   ├──────┼─────┼─────┼───┼─────┼─────┤
//    │     │ & │ # │  ^  │  {  │  }  │                                   │ bspc │  4  │  5  │ 6 │  =  │     │
//    ├─────┼───┼───┼─────┼─────┼─────┼─────────┬─────┐   ┌─────┬─────────┼──────┼─────┼─────┼───┼─────┼─────┤
//    │     │ ~ │ % │  @  │  [  │  ]  │ PIPE_GT │     │   │     │ LT_PIPE │  0   │  1  │  2  │ 3 │ ent │     │
//    └─────┴───┴───┼─────┼─────┼─────┼─────────┼─────┤   ├─────┼─────────┼──────┼─────┼─────┼───┴─────┴─────┘
//                  │     │     │     │         │     │   │     │         │      │     │     │
//                  └─────┴─────┴─────┴─────────┴─────┘   └─────┴─────────┴──────┴─────┴─────┘
[PROG] = LAYOUT(
  _______ , KC_EXLM , KC_ASTR , KC_DLR  , KC_MINS , KC_UNDS ,                                             KC_DOT  , KC_7    , KC_8    , KC_9 , KC_PLUS , _______,
  _______ , KC_AMPR , KC_HASH , KC_CIRC , KC_LCBR , KC_RCBR ,                                             KC_BSPC , KC_4    , KC_5    , KC_6 , KC_EQL  , _______,
  _______ , KC_TILD , KC_PERC , KC_AT   , KC_LBRC , KC_RBRC , PIPE_GT , _______ ,     _______ , LT_PIPE , KC_0    , KC_1    , KC_2    , KC_3 , KC_PENT , _______,
                                _______ , _______ , _______ , _______ , _______ ,     _______ , _______ , _______ , _______ , _______
),

//    ┌─────────┬────┬─────┬─────┬─────┬─────────┐                           ┌──────┬──────┬──────┬──────┬──────┬─────┐
//    │ PSCR_SC │ f1 │ f2  │ f3  │ f4  │  KILL   │                           │ wh_u │ end  │ home │ nUM  │ pgup │     │
//    ├─────────┼────┼─────┼─────┼─────┼─────────┤                           ├──────┼──────┼──────┼──────┼──────┼─────┤
//    │  pscr   │ f5 │ f6  │ f7  │ f8  │  pscr   │                           │ left │ down │  up  │ rght │      │     │
//    ├─────────┼────┼─────┼─────┼─────┼─────────┼─────┬─────┐   ┌─────┬─────┼──────┼──────┼──────┼──────┼──────┼─────┤
//    │ PSCR_RT │ f9 │ f10 │ f11 │ f12 │ PSCR_RT │     │     │   │     │     │ pgdn │      │      │      │      │     │
//    └─────────┴────┴─────┼─────┼─────┼─────────┼─────┼─────┤   ├─────┼─────┼──────┼──────┼──────┼──────┴──────┴─────┘
//                         │     │     │ C_LEFT  │     │     │   │     │     │      │      │      │
//                         └─────┴─────┴─────────┴─────┴─────┘   └─────┴─────┴──────┴──────┴──────┘
[NAVI] = LAYOUT(
  PSCR_SC , KC_F1 , KC_F2  , KC_F3   , KC_F4   , KILL    ,                                             KC_WH_U , KC_END  , KC_HOME , KC_NUM  , KC_PGUP , _______,
  KC_PSCR , KC_F5 , KC_F6  , KC_F7   , KC_F8   , KC_PSCR ,                                             KC_LEFT , KC_DOWN , KC_UP   , KC_RGHT , _______ , _______,
  PSCR_RT , KC_F9 , KC_F10 , KC_F11  , KC_F12  , PSCR_RT , _______ , _______ ,     _______ , _______ , KC_PGDN , _______ , _______ , _______ , _______ , _______,
                             _______ , _______ , C_LEFT  , _______ , _______ ,     _______ , _______ , _______ , _______ , _______
),

//    ┌─────────┬────┬─────┬─────┬─────┬──────┐                           ┌─────┬───────┬───────┬───────┬─────┬─────┐
//    │ PSCR_SC │ f1 │ f2  │ f3  │ f4  │ pscr │                           │     │ GUI_7 │ GUI_8 │ GUI_9 │     │     │
//    ├─────────┼────┼─────┼─────┼─────┼──────┤                           ├─────┼───────┼───────┼───────┼─────┼─────┤
//    │  pscr   │ f5 │ f6  │ f7  │ f8  │ sCRL │                           │     │ GUI_4 │ GUI_5 │ GUI_6 │     │     │
//    ├─────────┼────┼─────┼─────┼─────┼──────┼─────┬─────┐   ┌─────┬─────┼─────┼───────┼───────┼───────┼─────┼─────┤
//    │ PSCR_RT │ f9 │ f10 │ f11 │ f12 │ paus │     │     │   │     │     │     │ GUI_1 │ GUI_2 │ GUI_3 │     │     │
//    └─────────┴────┴─────┼─────┼─────┼──────┼─────┼─────┤   ├─────┼─────┼─────┼───────┼───────┼───────┴─────┴─────┘
//                         │     │     │      │     │     │   │     │     │     │       │       │
//                         └─────┴─────┴──────┴─────┴─────┘   └─────┴─────┴─────┴───────┴───────┘
[FUNC] = LAYOUT(
  PSCR_SC , KC_F1 , KC_F2  , KC_F3   , KC_F4   , KC_PSCR ,                                             _______ , GUI_7   , GUI_8   , GUI_9 , _______ , _______,
  KC_PSCR , KC_F5 , KC_F6  , KC_F7   , KC_F8   , KC_SCRL ,                                             _______ , GUI_4   , GUI_5   , GUI_6 , _______ , _______,
  PSCR_RT , KC_F9 , KC_F10 , KC_F11  , KC_F12  , KC_PAUS , _______ , _______ ,     _______ , _______ , _______ , GUI_1   , GUI_2   , GUI_3 , _______ , _______,
                             _______ , _______ , _______ , _______ , _______ ,     _______ , _______ , _______ , _______ , _______
)
};

static bool ctrl_h_bs_pressed;
static bool ctrl_d_del_pressed;
static bool ctrl_left_pressed;
static bool ctrl_right_pressed;
static bool ctrl_g_slash_pressed;
static bool ctrl_g_z_pressed;
// because shift works as bracket when tap separate state is needed
// to prevent conflicts with \ and tab
static bool shift_interrupted;
static bool key_pressed;
static bool ctrl_g_used;
/* static bool l1_by_tab = false; */
/* static bool l1_by_bsls = false; */
static uint16_t ctrl_esc_timer;
/* static uint16_t ctrl_tild_timer; */
static uint16_t ctrl_quote_timer;
static uint16_t ctrl_g_slash_timer;
static uint16_t ctrl_g_z_timer;
/* static uint16_t ctrl_eql_timer; */
static uint16_t gui_tild_timer;
static uint16_t l_shift_br_timer;
static uint16_t l1_tab_timer;
static uint16_t l1_bsls_timer;
static uint16_t r_shift_br_timer;
static uint16_t ent_alt_timer;
static uint16_t spc_alt_timer;

static uint16_t ctrl_g_key;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        key_pressed = true;
        shift_interrupted = true;
        if (
            (ctrl_g_slash_pressed || ctrl_g_z_pressed)
            && keycode != TMX_GRV
            && keycode != TMX_DSH
        ) {
            ctrl_g_key = keycode;
            return false;
        }
    } else { // release ?
        if (
            (ctrl_g_slash_pressed || ctrl_g_z_pressed)
            && keycode != TMX_GRV
            && keycode != TMX_DSH
            && ctrl_g_key != 0
        ) {
            ctrl_g_used = true;

            register_code(KC_RCTL);
            register_code(KC_G);
            unregister_code(KC_G);
            unregister_code(KC_RCTL);

            register_code(ctrl_g_key);
            unregister_code(ctrl_g_key);

            ctrl_g_key = 0;

            return true;
        }

        if (keycode == ctrl_g_key) {
            register_code(ctrl_g_key);
            unregister_code(ctrl_g_key);

            ctrl_g_key = 0;
        }
    }

    switch (keycode) {
    case TMX_1:
        if (record->event.pressed) {
            register_code(KC_LCTL);
            register_code(KC_G);
            unregister_code(KC_G);
            unregister_code(KC_LCTL);

            register_code(KC_1);
            unregister_code(KC_1);
        }
        break;
    case TMX_2:
        if (record->event.pressed) {
            register_code(KC_LCTL);
            register_code(KC_G);
            unregister_code(KC_G);
            unregister_code(KC_LCTL);

            register_code(KC_2);
            unregister_code(KC_2);
        }
        break;
    case TMX_3:
        if (record->event.pressed) {
            register_code(KC_LCTL);
            register_code(KC_G);
            unregister_code(KC_G);
            unregister_code(KC_LCTL);

            register_code(KC_3);
            unregister_code(KC_3);
        }
        break;
    case TMX_4:
        if (record->event.pressed) {
            register_code(KC_LCTL);
            register_code(KC_G);
            unregister_code(KC_G);
            unregister_code(KC_LCTL);

            register_code(KC_4);
            unregister_code(KC_4);
        }
        break;
    case PIPE_GT:
        if (record->event.pressed) {
            SEND_STRING("|>");
        }
        break;
    case LT_PIPE:
        if (record->event.pressed) {
            SEND_STRING("<|");
        }
        break;
    case M_OR:
        if (record->event.pressed) {
            SEND_STRING("||");
        }
        break;
    case M_AND:
        if (record->event.pressed) {
            SEND_STRING("&&");
        }
        break;
    case M_LT_EQ:
        if (record->event.pressed) {
            SEND_STRING("<=");
        }
        break;
    case M_GT_EQ:
        if (record->event.pressed) {
            SEND_STRING(">=");
        }
        break;
    case M_EX_EQ:
        if (record->event.pressed) {
            SEND_STRING("!=");
        }
        break;
    case M_DARR_R:
        if (record->event.pressed) {
            SEND_STRING("=>");
        }
        break;
    case M_DARR_L:
        if (record->event.pressed) {
            SEND_STRING("<=");
        }
        break;
    case RARR:
        if (record->event.pressed) {
            SEND_STRING("->");
        }
        break;
    case LARR:
        if (record->event.pressed) {
            SEND_STRING("<-");
        }
        break;
    case L1_TAB: //L1 on hold, TAB on tap, GRV if already on L1
        if (record->event.pressed) {
            layer_on(PROG);
            l1_tab_timer = timer_read();
            key_pressed = false;
        } else {
            layer_off(PROG);
            if (timer_elapsed(l1_tab_timer) < TTIMER && !key_pressed) {
                if (!ctrl_left_pressed) {
                    register_code(KC_TAB);
                    unregister_code(KC_TAB);
                } else {
                    key_pressed = true;
                    unregister_code(KC_LCTL);
                    register_code(KC_LSFT);
                    register_code(KC_GRV);
                    unregister_code(KC_GRV);
                    unregister_code(KC_LSFT);
                    register_code(KC_LCTL);
                }
            }
        }
        break;
    case SPC_ALT:
        if (record->event.pressed) {
            register_code(KC_LALT);
            spc_alt_timer = timer_read();
            key_pressed = false;
        } else {
            unregister_code(KC_LALT);
            if (timer_elapsed(spc_alt_timer) < TTIMER && !key_pressed) {
                register_code(KC_SPC);
                unregister_code(KC_SPC);
            }
        }
        break;
    case ENT_ALT:
        if (record->event.pressed) {
            register_code(KC_RALT);
            ent_alt_timer = timer_read();
            key_pressed = false;
        } else {
            unregister_code(KC_RALT);
            if (timer_elapsed(ent_alt_timer) < TTIMER && !key_pressed) {
                register_code(KC_ENT);
                unregister_code(KC_ENT);
            }
        }
        break;
    case L1_BSLS: //L1 on hold, BSLS on tap, MINS if already on L1
        if (record->event.pressed) {
            layer_on(PROG);
            l1_bsls_timer = timer_read();
            key_pressed = false;
        } else {
            layer_off(PROG);
            if (timer_elapsed(l1_bsls_timer) < TTIMER && !key_pressed) {
                if (!ctrl_right_pressed) {
                    register_code(KC_BSLS);
                    unregister_code(KC_BSLS);
                } else {
                    key_pressed = true;
                    unregister_code(KC_RCTL);
                    register_code(KC_MINS);
                    unregister_code(KC_MINS);
                    register_code(KC_RCTL);
                }
            }
        }
        break;
    case LSHT_BR:
        if (record->event.pressed) {
            register_code(KC_LSFT);
            l_shift_br_timer = timer_read();
            shift_interrupted = false;
        } else {
            if (timer_elapsed(l_shift_br_timer) < TTIMER && !shift_interrupted) {
                register_code(KC_9);
                unregister_code(KC_9);
            }
            unregister_code(KC_LSFT);
        }
        break;
    case RSHT_BR:
        if (record->event.pressed) {
            /* record->tap.count = 0; */
            shift_interrupted = false;
            register_code(KC_RSFT);
            r_shift_br_timer = timer_read();
        } else {
            if (timer_elapsed(r_shift_br_timer) < TTIMER && !shift_interrupted) {
                register_code(KC_0);
                unregister_code(KC_0);
            }
            unregister_code(KC_RSFT);
        }
        break;
    case CTL_QUT:
        if (record->event.pressed) {
            register_code(KC_RCTL);
            ctrl_quote_timer = timer_read();
            ctrl_right_pressed = true;
            key_pressed = false;
        } else {
            unregister_code(KC_RCTL);
            ctrl_right_pressed = false;
            if (timer_elapsed(ctrl_quote_timer) < TTIMER && !key_pressed) {
                register_code(KC_QUOTE);
                unregister_code(KC_QUOTE);
            }
        }
        break;
    case TMX_DSH:
        if (record->event.pressed) {
            // register_code(KC_RCTL);
            ctrl_g_slash_timer = timer_read();
            ctrl_g_slash_pressed = true;
            key_pressed = false;
            ctrl_g_used = false;
        } else {
            // unregister_code(KC_RCTL);
            ctrl_g_slash_pressed = false;
            if (timer_elapsed(ctrl_g_slash_timer) < TTIMER && !ctrl_g_used) {
                register_code(KC_MINS);
                unregister_code(KC_MINS);
            }
        }
        break;
    case TMX_GRV:
        if (record->event.pressed) {
            ctrl_g_z_timer = timer_read();
            ctrl_g_z_pressed = true;
            key_pressed = false;
            ctrl_g_used = false;
        } else {
            ctrl_g_z_pressed = false;
            if (timer_elapsed(ctrl_g_z_timer) < TTIMER && !ctrl_g_used) {
                register_code(KC_GRV);
                unregister_code(KC_GRV);
            }
        }
        break;
    /* case CTL_EQL: */
    /*     if (record->event.pressed) { */
    /*         register_code(KC_RCTL); */
    /*         ctrl_eql_timer = timer_read(); */
    /*         ctrl_right_pressed = true; */
    /*         key_pressed = false; */
    /*     } else { */
    /*         unregister_code(KC_RCTL); */
    /*         ctrl_right_pressed = false; */
    /*         if (timer_elapsed(ctrl_eql_timer) < TTIMER && !key_pressed) { */
    /*             register_code(KC_EQL); */
    /*             unregister_code(KC_EQL); */
    /*         } */
    /*     } */
    /*     break; */
    case M_CTL:
        if (record->event.pressed) {
            register_code(KC_LCTL);
            ctrl_esc_timer = timer_read();
            ctrl_left_pressed = true;
            key_pressed = false;
        } else {
            unregister_code(KC_LCTL);
            ctrl_left_pressed = false;
        }
        break;
    case CTL_ESC:
        if (record->event.pressed) {
            register_code(KC_LCTL);
            ctrl_esc_timer = timer_read();
            ctrl_left_pressed = true;
            key_pressed = false;
        } else {
            unregister_code(KC_LCTL);
            ctrl_left_pressed = false;
            if (timer_elapsed(ctrl_esc_timer) < TTIMER && !key_pressed) {
                register_code(KC_ESC);
                unregister_code(KC_ESC);
            }
        }
        break;
    /* case CTL_TLD: */
    /*     if (record->event.pressed) { */
    /*         register_code(KC_LCTL); */
    /*         ctrl_tild_timer = timer_read(); */
    /*         ctrl_left_pressed = true; */
    /*         key_pressed = false; */
    /*     } else { */
    /*         unregister_code(KC_LCTL); */
    /*         ctrl_left_pressed = false; */
    /*         if (timer_elapsed(ctrl_tild_timer) < TTIMER && !key_pressed) { */
    /*             register_code(KC_LSFT); */
    /*             register_code(KC_GRV); */
    /*             unregister_code(KC_GRV); */
    /*             unregister_code(KC_LSFT); */
    /*         } */
    /*     } */
    /*     break; */
    case GUI_TLD:
        if (record->event.pressed) {
            register_code(KC_LGUI);
            gui_tild_timer = timer_read();
            key_pressed = false;
        } else {
            unregister_code(KC_LGUI);
            if (timer_elapsed(gui_tild_timer) < TTIMER && !key_pressed) {
                register_code(KC_LSFT);
                register_code(KC_GRV);
                unregister_code(KC_GRV);
                unregister_code(KC_LSFT);
            }
        }
        break;
    case D_DEL:
        if (record->event.pressed) {
            if (ctrl_right_pressed) {
                ctrl_d_del_pressed = true;
                unregister_code(KC_RCTL);
                register_code(KC_DEL);
            } else {
                ctrl_d_del_pressed = false;
                register_code(KC_D);
            }
        } else {
            if (ctrl_d_del_pressed) {
                unregister_code(KC_DEL);
            } else {
                unregister_code(KC_D);
            }
            if (ctrl_right_pressed) {
                register_code(KC_RCTL);
            }
        }
        break;
    case H_BSPC:
        if (record->event.pressed) {
            if (ctrl_left_pressed) {
                ctrl_h_bs_pressed = true;
                unregister_code(KC_LCTL);
                register_code(KC_BSPC);
            } else {
                ctrl_h_bs_pressed = false;
                register_code(KC_H);
            }
        } else {
            if (ctrl_h_bs_pressed) {
                unregister_code(KC_BSPC);
            } else {
                unregister_code(KC_H);
            }
            if (ctrl_left_pressed) {
                register_code(KC_LCTL);
            }
        }
        break;
    }

    return true;
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    /* if (IS_LAYER_ON(HOTKEYS)) { */
    /*     if (clockwise) { */
    /*         tap_code(KC_VOLD); */
    /*     } else { */
    /*         tap_code(KC_VOLU); */
    /*     } */
    /* } else if (IS_LAYER_ON(TEXT)) { */
    /*     if (clockwise) { */
    /*         tap_code(KC_MS_WH_LEFT); */
    /*     } else { */
    /*         tap_code(KC_MS_WH_RIGHT); */
    /*     } */
    /* } else if (IS_LAYER_ON(NUMBERS)) { */
    /*     if (clockwise) { */
    /*         tap_code16(G(KC_MINS)); */
    /*     } else { */
    /*         register_code(KC_LGUI); */
    /*         tap_code(KC_EQL); */
    /*         unregister_code(KC_LGUI); */
    /*     } */
    /* } else { */

    if (IS_LAYER_ON(NAVI)) {
        if (index == ENC_RIGHT) {
            if (clockwise) {
                tap_code(KC_RIGHT);
            } else {
                tap_code(KC_LEFT);
            }
        }
        if (index == ENC_LEFT) {
            if (clockwise) {
                tap_code(KC_MNXT);
            } else {
                tap_code(KC_MPRV);
            }
        }
    } else {
        if (index == ENC_RIGHT) {
            if (clockwise) {
                tap_code(KC_MS_WH_DOWN);
            } else {
                tap_code(KC_MS_WH_UP);
            }
        }
        if (index == ENC_LEFT) {
            if (clockwise) {
                tap_code(KC_VOLU);
            } else {
                tap_code(KC_VOLD);
            }
        }
    }
    return false;
}

enum combo_events {
  CB_ARROW_RIGHT,
  CB_ARROW_LEFT,
  CB_FAT_ARROW_RIGHT,
  CB_PIPE_LEFT,
  CB_PIPE_RIGHT,
  CB_LEFT_RIGHT_PAREN,
  CB_BRACKETS,
  CB_ASSIGN,
};

const uint16_t PROGMEM arrow_right[] = {KC_R, KC_DOT, COMBO_END};
const uint16_t PROGMEM arrow_left[] = {KC_R, KC_COMM, COMBO_END};
const uint16_t PROGMEM fat_arrow_right[] = {KC_E, KC_DOT, COMBO_END};
const uint16_t PROGMEM pipe_right[] = {KC_D, KC_DOT, COMBO_END};
const uint16_t PROGMEM pipe_left[] = {KC_F, KC_DOT, COMBO_END};
const uint16_t PROGMEM assign[] = {KC_E, KC_SCLN, COMBO_END};
const uint16_t PROGMEM shifts[] = {KC_LSFT, KC_RSFT, COMBO_END};
const uint16_t PROGMEM brackets[] = {KC_D, KC_F, COMBO_END};

combo_t key_combos[] = {
  [CB_ARROW_RIGHT] = COMBO_ACTION(arrow_right),
  [CB_ARROW_LEFT] = COMBO_ACTION(arrow_left),
  [CB_LEFT_RIGHT_PAREN] = COMBO_ACTION(shifts),
  [CB_BRACKETS] = COMBO_ACTION(brackets),
  [CB_ASSIGN] = COMBO_ACTION(assign),
  [CB_PIPE_LEFT] = COMBO_ACTION(pipe_left),
  [CB_PIPE_RIGHT] = COMBO_ACTION(pipe_right),
  [CB_FAT_ARROW_RIGHT] = COMBO_ACTION(fat_arrow_right),
};
/* COMBO_ACTION(x) is same as COMBO(x, KC_NO) */
void process_combo_event(uint16_t combo_index, bool pressed) {
    if (pressed) {
        switch(combo_index) {
            case CB_ARROW_RIGHT:
                SEND_STRING("->");
                break;
            case CB_ARROW_LEFT:
                SEND_STRING("<-");
                break;
            case CB_FAT_ARROW_RIGHT:
                SEND_STRING("=>");
                break;
            case CB_PIPE_LEFT:
                SEND_STRING("<|");
                break;
            case CB_PIPE_RIGHT:
                SEND_STRING("|>");
                break;
            case CB_ASSIGN:
                SEND_STRING(":=");
                break;
            case CB_LEFT_RIGHT_PAREN:
                SEND_STRING("()");
                break;
            case CB_BRACKETS:
                SEND_STRING("[]");
                break;
        }
    }
}

#ifdef OLED_ENABLE
bool oled_task_user(void) {
    if (is_keyboard_master()) {
        // QMK Logo and version information
        // clang-format off
        /* static const char PROGMEM qmk_logo[] = { */
        /*     0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94, */
        /*     0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4, */
        /*     0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0}; */
        // clang-format on

        /* oled_write_P(qmk_logo, false); */
        /* oled_write_P(PSTR("Kyria rev1.0 (pbogut)\n\n"), false); */

        // Host Keyboard LED Status
        led_t led_usb_state = host_keyboard_led_state();
        oled_write_P(led_usb_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
        oled_write_P(led_usb_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
        oled_write_P(led_usb_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
        oled_write_P(PSTR(" d(^_^)b\n\n"), false);

        // Host Keyboard Layer Status
        oled_write_P(PSTR("L: "), false);
        switch (get_highest_layer(layer_state | default_layer_state)) {
            case BASE:
                oled_write_P(PSTR("Default\n"), false);
                break;
            case PROG:
                oled_write_P(PSTR("Symbols & Numbers\n"), false);
                break;
            case NAVI:
                oled_write_P(PSTR("Navigation\n"), false);
                break;
            case FUNC:
                oled_write_P(PSTR("Function + Mods\n"), false);
                break;
            default:
                oled_write_P(PSTR("\n"), false);
                break;
        }

    } else {
        // clang-format off
        static const char PROGMEM axolit_logo[] = {
        // 'logo-text', 128x64px
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x20,
            0x20, 0x30, 0x30, 0x38, 0x38, 0x3c, 0x3c, 0x7c, 0x7c, 0x7c, 0xfc, 0xfe, 0xfe, 0xfe, 0xfc, 0xfc,
            0xfc, 0xfc, 0xfc, 0xfc, 0xf8, 0xf8, 0xf8, 0xf8, 0xf0, 0xf0, 0xf0, 0xf0, 0xe0, 0xe0, 0xe0, 0xe0,
            0xe0, 0xe0, 0xe0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0,
            0xc0, 0xc0, 0xc0, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x03, 0x07, 0x0f,
            0x0f, 0x1f, 0x3f, 0x7f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfc, 0xfc, 0xf8, 0xf0, 0xf0, 0xe0,
            0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x08, 0x0c, 0x0c, 0x0e, 0x0e, 0x0e,
            0x0e, 0x0f, 0x0f, 0x1f, 0x1f, 0x1f, 0x3f, 0x7f, 0x7f, 0xff, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfc,
            0xfc, 0xfc, 0xfc, 0xfc, 0xf8, 0xf8, 0xf8, 0xf9, 0xf9, 0xf9, 0xf9, 0xfb, 0xfb, 0xff, 0xff, 0xff,
            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe1, 0xe0, 0xe0, 0xe0, 0xe0, 0xf9, 0xff, 0xff, 0xff, 0xff,
            0xff, 0xff, 0xff, 0xfe, 0x7c, 0x30, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x03, 0x07, 0x07, 0x0f,
            0x0f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x9f, 0x9f, 0x9f, 0xdf, 0xcf, 0xef, 0xef, 0xff, 0xff, 0xff,
            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
            0xff, 0xff, 0xdf, 0x9f, 0xbf, 0x3f, 0x7f, 0x7f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xfe, 0x3e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x04,
            0x04, 0x0c, 0x0c, 0x1c, 0x1c, 0x3c, 0x3c, 0x7c, 0x7c, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc,
            0xfe, 0xfe, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
            0xff, 0xff, 0x7f, 0x7f, 0x3f, 0x3f, 0x1f, 0x1f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x07, 0x07,
            0x07, 0x07, 0x07, 0x07, 0x0f, 0x0f, 0x0e, 0x0e, 0x0e, 0x0c, 0x0c, 0x0c, 0x08, 0x09, 0x09, 0x09,
            0x09, 0x09, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x00, 0x01, 0x01, 0x01, 0x03, 0x03,
            0x03, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x03, 0x03, 0x03, 0x01, 0x01, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xc0, 0x40, 0x20, 0x20, 0x30, 0x10, 0x10, 0x08, 0x08, 0x08,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xf0, 0x1c, 0x07, 0x01, 0x07, 0x3c, 0xe0, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x08, 0x30, 0x60, 0xc0, 0xc0, 0x20, 0x18, 0x08, 0x00, 0x00, 0xc0, 0xf0, 0x18, 0x08,
            0x08, 0x08, 0x08, 0x18, 0xf0, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 0xf8, 0xf8,
            0x00, 0x00, 0x00, 0x08, 0xff, 0x08, 0x08, 0x08, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x3c, 0x03, 0x00,
            0x00, 0x00, 0x0c, 0x08, 0x08, 0x18, 0x10, 0x10, 0x20, 0x20, 0x20, 0xc0, 0xc0, 0xc0, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x02, 0x02, 0x06, 0x04, 0x04, 0x0c,
            0x00, 0x00, 0x00, 0x10, 0x1c, 0x07, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x07, 0x1c, 0x00,
            0x00, 0x10, 0x18, 0x0c, 0x03, 0x01, 0x03, 0x06, 0x0c, 0x10, 0x00, 0x00, 0x03, 0x0f, 0x18, 0x10,
            0x10, 0x10, 0x10, 0x18, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x1f,
            0x00, 0x00, 0x00, 0x00, 0x0f, 0x10, 0x10, 0x10, 0x10, 0x00, 0x70, 0x0e, 0x01, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x08, 0x04, 0x04, 0x04, 0x02, 0x02, 0x02, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
        };
        // clang-format on
        oled_write_raw_P(axolit_logo, sizeof(axolit_logo));
    }

    return false;
}
#endif
