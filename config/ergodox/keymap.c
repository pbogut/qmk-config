#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"
#include "mousekey.h"

#define BASE 0 // Default layer
#define DEVP 1 // Developer layer
#define NAVI 2 // Navigation layer
#define MDIA 3 // Media / numpad keys
#define GAME 4 // For gameing - no layers
#define WSAD 5 // For gameing - no layers - wsad

//combos
#define KILL LGUI(LSFT(KC_Q))
#define LANG LCTL(LSFT(LALT(KC_SPC)))

enum custom_keycodes {
    M_H = SAFE_RANGE,
    M_D,
    M_CTL_QUOTE,
    M_CTL_ESC,
    M_CTL,
    M_ARR_L,
    M_ARR_R,
    M_DARR_L,
    M_DARR_R,
    M_LSHIFT_BR,
    M_RSHIFT_BR,
    M_EX_EQ,
    M_GT_EQ,
    M_PIPE_GT,
    M_LT_PIPE,
    M_AND,
    M_OR,
    M_LT_EQ,
    M_L1_TAB,
    M_L1_BSLS,
    M_FAR_RIGHT,
    M_FAR_LEFT,
};

static report_mouse_t mouse_report = {0};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//    ┌─────────────┬──────────┬───────────┬───────┬───────────┬──────────┬─────────────┐
//    │      `      │    1     │     2     │   3   │     4     │    5     │    KILL     │
//    ├─────────────┼──────────┼───────────┼───────┼───────────┼──────────┼─────────────┤
//    │   l1 tab    │    q     │     w     │   e   │     r     │    t     │ LT(MDIA, +) │
//    ├─────────────┼──────────┼───────────┼───────┼───────────┼──────────┼─────────────┘
//    │   ctl esc   │    a     │     s     │ d del │     f     │    g     │
//    ├─────────────┼──────────┼───────────┼───────┼───────────┼──────────┼─────────────┐
//    │    shf (    │    z     │     x     │   c   │     v     │    b     │ LT(NAVI, [) │
//    ├─────────────┼──────────┼───────────┼───────┼───────────┼──────────┴─────────────┘
//    │      {      │   meh    │ csag-none │ lgui  │   lalt    │
//    └─────────────┴──────────┴───────────┴───────┴───────────┼──────────┬─────────────┐
//                                                             │   bspc   │    home     │
//                                                             └──────────┼─────────────┤
//                                                                        │     end     │
//                                                 ┌───────────┬──────────┼─────────────┤
//                                                 │    spc    │ MO(NAVI) │   SH_MON    │
//                                                 └───────────┴──────────┴─────────────┘
//
//    ┌─────────────┬──────────┬───────────┬───────┬───────────┬──────────┬─────────────┐
//    │    LANG     │    6     │     7     │   8   │     9     │    0     │      -      │
//    ├─────────────┼──────────┼───────────┼───────┼───────────┼──────────┼─────────────┤
//    │ LT(MDIA, =) │    y     │     u     │   i   │     o     │    p     │    l1 \     │
//    └─────────────┼──────────┼───────────┼───────┼───────────┼──────────┼─────────────┤
//                  │   h bs   │     j     │   k   │     l     │    ;     │    ctl '    │
//    ┌─────────────┼──────────┼───────────┼───────┼───────────┼──────────┼─────────────┤
//    │ LT(NAVI, ]) │    n     │     m     │   ,   │     .     │    /     │    shf )    │
//    └─────────────┴──────────┼───────────┼───────┼───────────┼──────────┼─────────────┤
//                             │   ralt    │ rgui  │ csag-none │   meh    │    rctl     │
//    ┌─────────────┬──────────┼───────────┴───────┴───────────┴──────────┴─────────────┘
//    │    pgup     │   del    │
//    ├─────────────┼──────────┘
//    │    pgdn     │
//    ├─────────────┼──────────┬───────────┐
//    │   SH_MON    │ MO(NAVI) │    ent    │
//    └─────────────┴──────────┴───────────┘
[BASE] = LAYOUT_ergodox(
  KC_GRV            , KC_1     , KC_2    , KC_3    , KC_4    , KC_5     , KILL             ,
  M_L1_TAB          , KC_Q     , KC_W    , KC_E    , KC_R    , KC_T     , LT(MDIA, KC_PPLS),
  M_CTL_ESC         , KC_A     , KC_S    , M_D     , KC_F    , KC_G                        ,
  M_LSHIFT_BR       , KC_Z     , KC_X    , KC_C    , KC_V    , KC_B     , LT(NAVI, KC_LBRC),
  KC_LCBR           , KC_MEH   , KC_HYPR , KC_LGUI , KC_LALT                               ,
                                                               KC_BSPC  , KC_HOME          ,
                                                                          KC_END           ,
                                                     KC_SPC  , MO(NAVI) , SH_MON           ,
                                                                                              ,
  LANG              , KC_6     , KC_7    , KC_8    , KC_9    , KC_0     , KC_MINS          ,
  LT(MDIA, KC_EQL)  , KC_Y     , KC_U    , KC_I    , KC_O    , KC_P     , M_L1_BSLS        ,
                      M_H      , KC_J    , KC_K    , KC_L    , KC_SCLN  , M_CTL_QUOTE      ,
  LT(NAVI, KC_RBRC) , KC_N     , KC_M    , KC_COMM , KC_DOT  , KC_SLSH  , M_RSHIFT_BR      ,
                                 KC_RALT , KC_RGUI , KC_HYPR , KC_MEH   , KC_RCTL          ,
  KC_PGUP           , KC_DEL                                                               ,
  KC_PGDN                                                                                  ,
  SH_MON            , MO(NAVI) , KC_ENT
),

//    ┌─────┬──────┬─────┬─────┬─────┬─────┬─────┐
//    │     │      │     │     │     │     │     │
//    ├─────┼──────┼─────┼─────┼─────┼─────┼─────┤
//    │     │  !   │  *  │  $  │ <-  │ ->  │ =>  │
//    ├─────┼──────┼─────┼─────┼─────┼─────┼─────┘
//    │     │  &   │  #  │  ^  │  {  │  }  │
//    ├─────┼──────┼─────┼─────┼─────┼─────┼─────┐
//    │     │  ~   │  %  │  @  │  [  │  ]  │ |>  │
//    ├─────┼──────┼─────┼─────┼─────┼─────┴─────┘
//    │     │      │     │     │     │
//    └─────┴──────┴─────┴─────┴─────┼─────┬─────┐
//                                   │     │     │
//                                   └─────┼─────┤
//                                         │     │
//                             ┌─────┬─────┼─────┤
//                             │     │     │     │
//                             └─────┴─────┴─────┘
//
//    ┌─────┬──────┬─────┬─────┬─────┬─────┬─────┐
//    │     │      │     │     │     │     │     │
//    ├─────┼──────┼─────┼─────┼─────┼─────┼─────┤
//    │     │  =   │  7  │  8  │  9  │  +  │     │
//    └─────┼──────┼─────┼─────┼─────┼─────┼─────┤
//          │ bspc │  4  │  5  │  6  │  -  │     │
//    ┌─────┼──────┼─────┼─────┼─────┼─────┼─────┤
//    │ <|  │  0   │  1  │  2  │  3  │ ent │     │
//    └─────┴──────┼─────┼─────┼─────┼─────┼─────┤
//                 │     │     │     │     │     │
//    ┌─────┬──────┼─────┴─────┴─────┴─────┴─────┘
//    │     │      │
//    ├─────┼──────┘
//    │     │
//    ├─────┼──────┬─────┐
//    │     │      │     │
//    └─────┴──────┴─────┘
[DEVP] = LAYOUT_ergodox(
  KC_TRNS   , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS  ,
  KC_TRNS   , KC_EXLM , KC_ASTR , KC_DLR  , M_ARR_L , M_ARR_R , M_DARR_R ,
  KC_TRNS   , KC_AMPR , KC_HASH , KC_CIRC , KC_LCBR , KC_RCBR            ,
  KC_TRNS   , KC_TILD , KC_PERC , KC_AT   , KC_LBRC , KC_RBRC , M_PIPE_GT,
  KC_TRNS   , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS                      ,
                                                      KC_TRNS , KC_TRNS  ,
                                                                KC_TRNS  ,
                                            KC_TRNS , KC_TRNS , KC_TRNS  ,
                                                                            ,
  KC_TRNS   , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS  ,
  KC_TRNS   , KC_EQL  , KC_7    , KC_8    , KC_9    , KC_PLUS , KC_TRNS  ,
              KC_BSPC , KC_4    , KC_5    , KC_6    , KC_MINS , KC_TRNS  ,
  M_LT_PIPE , KC_0    , KC_1    , KC_2    , KC_3    , KC_PENT , KC_TRNS  ,
                        KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS  ,
  KC_TRNS   , KC_TRNS                                                    ,
  KC_TRNS                                                                ,
  KC_TRNS   , KC_TRNS , KC_TRNS
),

//    ┌─────┬──────┬────────────┬──────┬──────┬────────────┬──────┐
//    │     │  f1  │     f2     │  f3  │  f4  │     f5     │ KILL │
//    ├─────┼──────┼────────────┼──────┼──────┼────────────┼──────┤
//    │     │      │ LCTL(rght) │ wh_d │  up  │            │      │
//    ├─────┼──────┼────────────┼──────┼──────┼────────────┼──────┘
//    │     │ end  │            │ pgdn │      │    pgdn    │
//    ├─────┼──────┼────────────┼──────┼──────┼────────────┼──────┐
//    │     │      │            │      │      │ LCTL(left) │      │
//    ├─────┼──────┼────────────┼──────┼──────┼────────────┴──────┘
//    │     │      │            │      │      │
//    └─────┴──────┴────────────┴──────┴──────┼────────────┬──────┐
//                                            │            │      │
//                                            └────────────┼──────┤
//                                                         │      │
//                                     ┌──────┬────────────┼──────┤
//                                     │      │            │      │
//                                     └──────┴────────────┴──────┘
//
//    ┌─────┬──────┬────────────┬──────┬──────┬────────────┬──────┐
//    │ f12 │  f6  │     f7     │  f8  │  f9  │    f10     │ f11  │
//    ├─────┼──────┼────────────┼──────┼──────┼────────────┼──────┤
//    │     │ wh_u │    pgup    │ home │      │            │ f12  │
//    └─────┼──────┼────────────┼──────┼──────┼────────────┼──────┤
//          │ left │    down    │  up  │ rght │            │      │
//    ┌─────┼──────┼────────────┼──────┼──────┼────────────┼──────┤
//    │     │  f3  │    btn1    │ btn2 │ btn3 │  LCTL(f)   │      │
//    └─────┴──────┼────────────┼──────┼──────┼────────────┼──────┤
//                 │            │      │      │            │      │
//    ┌─────┬──────┼────────────┴──────┴──────┴────────────┴──────┘
//    │     │      │
//    ├─────┼──────┘
//    │     │
//    ├─────┼──────┬────────────┐
//    │     │      │            │
//    └─────┴──────┴────────────┘
[NAVI] = LAYOUT_ergodox(
  KC_TRNS , KC_F1   , KC_F2         , KC_F3   , KC_F4   , KC_F5         , KILL   ,
  KC_TRNS , KC_TRNS , LCTL(KC_RGHT) , KC_WH_D , KC_UP   , KC_TRNS       , KC_TRNS,
  KC_TRNS , KC_END  , KC_TRNS       , KC_PGDN , KC_TRNS , KC_PGDN                ,
  KC_TRNS , KC_TRNS , KC_TRNS       , KC_TRNS , KC_TRNS , LCTL(KC_LEFT) , KC_TRNS,
  KC_TRNS , KC_TRNS , KC_TRNS       , KC_TRNS , KC_TRNS                          ,
                                                          KC_TRNS       , KC_TRNS,
                                                                          KC_TRNS,
                                                KC_TRNS , KC_TRNS       , KC_TRNS,
                                                                                    ,
  KC_F12  , KC_F6   , KC_F7         , KC_F8   , KC_F9   , KC_F10        , KC_F11 ,
  KC_TRNS , KC_WH_U , KC_PGUP       , KC_HOME , KC_TRNS , KC_TRNS       , KC_F12 ,
            KC_LEFT , KC_DOWN       , KC_UP   , KC_RGHT , KC_TRNS       , KC_TRNS,
  KC_TRNS , KC_F3   , KC_BTN1       , KC_BTN2 , KC_BTN3 , LCTL(KC_F)    , KC_TRNS,
                      KC_TRNS       , KC_TRNS , KC_TRNS , KC_TRNS       , KC_TRNS,
  KC_TRNS , KC_TRNS                                                              ,
  KC_TRNS                                                                        ,
  KC_TRNS , KC_TRNS , KC_TRNS
),

//    ┌─────────┬──────────┬─────────────┬──────┬──────┬──────┬─────────┐
//    │         │   pscr   │    sCRL     │ paus │      │      │  caps   │
//    ├─────────┼──────────┼─────────────┼──────┼──────┼──────┼─────────┤
//    │         │   ins    │    home     │ pgup │ mprv │ mnxt │         │
//    ├─────────┼──────────┼─────────────┼──────┼──────┼──────┼─────────┘
//    │         │   del    │     end     │ pgdn │ mstp │ mply │
//    ├─────────┼──────────┼─────────────┼──────┼──────┼──────┼─────────┐
//    │         │ www_back │ www_forward │ mute │ vold │ volu │         │
//    ├─────────┼──────────┼─────────────┼──────┼──────┼──────┴─────────┘
//    │         │          │             │      │      │
//    └─────────┴──────────┴─────────────┴──────┴──────┼──────┬─────────┐
//                                                     │      │ QK_BOOT │
//                                                     └──────┼─────────┤
//                                                            │         │
//                                              ┌──────┬──────┼─────────┤
//                                              │      │      │         │
//                                              └──────┴──────┴─────────┘
//
//    ┌─────────┬──────────┬─────────────┬──────┬──────┬──────┬─────────┐
//    │   nUM   │    ,     │             │  /   │  *   │  -   │  sYRQ   │
//    ├─────────┼──────────┼─────────────┼──────┼──────┼──────┼─────────┤
//    │         │    .     │      7      │  8   │  9   │  +   │    f    │
//    └─────────┼──────────┼─────────────┼──────┼──────┼──────┼─────────┤
//              │   bspc   │      4      │  5   │  6   │  =   │    e    │
//    ┌─────────┼──────────┼─────────────┼──────┼──────┼──────┼─────────┤
//    │         │    0     │      1      │  2   │  3   │ ent  │    i    │
//    └─────────┴──────────┼─────────────┼──────┼──────┼──────┼─────────┤
//                         │             │      │      │      │         │
//    ┌─────────┬──────────┼─────────────┴──────┴──────┴──────┴─────────┘
//    │ QK_BOOT │          │
//    ├─────────┼──────────┘
//    │         │
//    ├─────────┼──────────┬─────────────┐
//    │         │          │             │
//    └─────────┴──────────┴─────────────┘
[MDIA] = LAYOUT_ergodox(
  KC_TRNS , KC_PSCR   , KC_SCRL , KC_PAUS , KC_TRNS , KC_TRNS , KC_CAPS,
  KC_TRNS , KC_INS    , KC_HOME , KC_PGUP , KC_MPRV , KC_MNXT , KC_TRNS,
  KC_TRNS , KC_DELETE , KC_END  , KC_PGDN , KC_MSTP , KC_MPLY          ,
  KC_TRNS , KC_WBAK   , KC_WFWD , KC_MUTE , KC_VOLD , KC_VOLU , KC_TRNS,
  KC_TRNS , KC_TRNS   , KC_TRNS , KC_TRNS , KC_TRNS                    ,
                                                      KC_TRNS , QK_BOOT,
                                                                KC_TRNS,
                                            KC_TRNS , KC_TRNS , KC_TRNS,
                                                                          ,
  KC_NUM  , KC_PCMM   , KC_TRNS , KC_PSLS , KC_PAST , KC_PMNS , KC_SYRQ,
  KC_TRNS , KC_PDOT   , KC_P7   , KC_P8   , KC_P9   , KC_PPLS , KC_F   ,
            KC_BSPC   , KC_P4   , KC_P5   , KC_P6   , KC_PEQL , KC_E   ,
  KC_TRNS , KC_P0     , KC_P1   , KC_P2   , KC_P3   , KC_PENT , KC_I   ,
                        KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS,
  QK_BOOT , KC_TRNS                                                    ,
  KC_TRNS                                                              ,
  KC_TRNS , KC_TRNS   , KC_TRNS
),

//    ┌─────────────┬──────────┬──────┬──────┬───────────┬──────────┬──────────┐
//    │      `      │    1     │  2   │  3   │     4     │    5     │    6     │
//    ├─────────────┼──────────┼──────┼──────┼───────────┼──────────┼──────────┤
//    │     tab     │    q     │  w   │  f   │     p     │    g     │    +     │
//    ├─────────────┼──────────┼──────┼──────┼───────────┼──────────┼──────────┘
//    │     ctl     │    a     │  r   │  s   │     t     │    d     │
//    ├─────────────┼──────────┼──────┼──────┼───────────┼──────────┼──────────┐
//    │    lsft     │    z     │  x   │  c   │     v     │    b     │    [     │
//    ├─────────────┼──────────┼──────┼──────┼───────────┼──────────┴──────────┘
//    │     esc     │    7     │  8   │  9   │   lalt    │
//    └─────────────┴──────────┴──────┴──────┴───────────┼──────────┬──────────┐
//                                                       │   bspc   │   pgup   │
//                                                       └──────────┼──────────┤
//                                                                  │   pgdn   │
//                                           ┌───────────┬──────────┼──────────┤
//                                           │    spc    │   home   │   end    │
//                                           └───────────┴──────────┴──────────┘
//
//    ┌─────────────┬──────────┬──────┬──────┬───────────┬──────────┬──────────┐
//    │    LANG     │    6     │  7   │  8   │     9     │    0     │    -     │
//    ├─────────────┼──────────┼──────┼──────┼───────────┼──────────┼──────────┤
//    │ LT(MDIA, =) │    j     │  l   │  u   │     y     │    ;     │   l1 \   │
//    └─────────────┼──────────┼──────┼──────┼───────────┼──────────┼──────────┤
//                  │   h bs   │  n   │  e   │     i     │    o     │  ctl '   │
//    ┌─────────────┼──────────┼──────┼──────┼───────────┼──────────┼──────────┤
//    │ LT(NAVI, ]) │    k     │  m   │  ,   │     .     │    /     │  shf )   │
//    └─────────────┴──────────┼──────┼──────┼───────────┼──────────┼──────────┤
//                             │ ralt │ rgui │ csag-none │ TG(WSAD) │ TG(GAME) │
//    ┌─────────────┬──────────┼──────┴──────┴───────────┴──────────┴──────────┘
//    │    pgup     │   del    │
//    ├─────────────┼──────────┘
//    │    pgdn     │
//    ├─────────────┼──────────┬──────┐
//    │  MO(MDIA)   │ MO(NAVI) │ ent  │
//    └─────────────┴──────────┴──────┘
[GAME] = LAYOUT_ergodox(
  KC_GRV            , KC_1     , KC_2    , KC_3    , KC_4    , KC_5     , KC_6       ,
  KC_TAB            , KC_Q     , KC_W    , KC_F    , KC_P    , KC_G     , KC_PPLS    ,
  M_CTL             , KC_A     , KC_R    , KC_S    , KC_T    , KC_D                  ,
  KC_LSFT           , KC_Z     , KC_X    , KC_C    , KC_V    , KC_B     , KC_LBRC    ,
  KC_ESC            , KC_7     , KC_8    , KC_9    , KC_LALT                         ,
                                                               KC_BSPC  , KC_PGUP    ,
                                                                          KC_PGDN    ,
                                                     KC_SPC  , KC_HOME  , KC_END     ,
                                                                                        ,
  LANG              , KC_6     , KC_7    , KC_8    , KC_9    , KC_0     , KC_MINS    ,
  LT(MDIA, KC_EQL)  , KC_J     , KC_L    , KC_U    , KC_Y    , KC_SCLN  , M_L1_BSLS  ,
                      M_H      , KC_N    , KC_E    , KC_I    , KC_O     , M_CTL_QUOTE,
  LT(NAVI, KC_RBRC) , KC_K     , KC_M    , KC_COMM , KC_DOT  , KC_SLSH  , M_RSHIFT_BR,
                                 KC_RALT , KC_RGUI , KC_HYPR , TG(WSAD) , TG(GAME)   ,
  KC_PGUP           , KC_DEL                                                         ,
  KC_PGDN                                                                            ,
  MO(MDIA)          , MO(NAVI) , KC_ENT
),

//    ┌─────────────┬──────────┬──────┬──────┬───────────┬──────────┬──────────┐
//    │      `      │    1     │  2   │  3   │     4     │    5     │    6     │
//    ├─────────────┼──────────┼──────┼──────┼───────────┼──────────┼──────────┤
//    │     tab     │    q     │  w   │  e   │     r     │    t     │    +     │
//    ├─────────────┼──────────┼──────┼──────┼───────────┼──────────┼──────────┘
//    │     ctl     │    a     │  s   │  d   │     f     │    g     │
//    ├─────────────┼──────────┼──────┼──────┼───────────┼──────────┼──────────┐
//    │    lsft     │    z     │  x   │  c   │     v     │    b     │    [     │
//    ├─────────────┼──────────┼──────┼──────┼───────────┼──────────┴──────────┘
//    │     esc     │    6     │  7   │  8   │   lalt    │
//    └─────────────┴──────────┴──────┴──────┴───────────┼──────────┬──────────┐
//                                                       │   bspc   │   pgup   │
//                                                       └──────────┼──────────┤
//                                                                  │   pgdn   │
//                                           ┌───────────┬──────────┼──────────┤
//                                           │    spc    │   home   │   end    │
//                                           └───────────┴──────────┴──────────┘
//
//    ┌─────────────┬──────────┬──────┬──────┬───────────┬──────────┬──────────┐
//    │    LANG     │    6     │  7   │  8   │     9     │    0     │    -     │
//    ├─────────────┼──────────┼──────┼──────┼───────────┼──────────┼──────────┤
//    │ LT(MDIA, =) │    j     │  l   │  u   │     y     │    ;     │   l1 \   │
//    └─────────────┼──────────┼──────┼──────┼───────────┼──────────┼──────────┤
//                  │   h bs   │  n   │  e   │     i     │    o     │  ctl '   │
//    ┌─────────────┼──────────┼──────┼──────┼───────────┼──────────┼──────────┤
//    │ LT(NAVI, ]) │    k     │  m   │  ,   │     .     │    /     │  shf )   │
//    └─────────────┴──────────┼──────┼──────┼───────────┼──────────┼──────────┤
//                             │ ralt │ rgui │ csag-none │ TG(WSAD) │ TG(GAME) │
//    ┌─────────────┬──────────┼──────┴──────┴───────────┴──────────┴──────────┘
//    │    pgup     │   del    │
//    ├─────────────┼──────────┘
//    │    pgdn     │
//    ├─────────────┼──────────┬──────┐
//    │  MO(MDIA)   │ MO(NAVI) │ ent  │
//    └─────────────┴──────────┴──────┘
[WSAD] = LAYOUT_ergodox(
  KC_GRV            , KC_1     , KC_2    , KC_3    , KC_4    , KC_5     , KC_6       ,
  KC_TAB            , KC_Q     , KC_W    , KC_E    , KC_R    , KC_T     , KC_PPLS    ,
  M_CTL             , KC_A     , KC_S    , KC_D    , KC_F    , KC_G                  ,
  KC_LSFT           , KC_Z     , KC_X    , KC_C    , KC_V    , KC_B     , KC_LBRC    ,
  KC_ESC            , KC_6     , KC_7    , KC_8    , KC_LALT                         ,
                                                               KC_BSPC  , KC_PGUP    ,
                                                                          KC_PGDN    ,
                                                     KC_SPC  , KC_HOME  , KC_END     ,
                                                                                        ,
  LANG              , KC_6     , KC_7    , KC_8    , KC_9    , KC_0     , KC_MINS    ,
  LT(MDIA, KC_EQL)  , KC_J     , KC_L    , KC_U    , KC_Y    , KC_SCLN  , M_L1_BSLS  ,
                      M_H      , KC_N    , KC_E    , KC_I    , KC_O     , M_CTL_QUOTE,
  LT(NAVI, KC_RBRC) , KC_K     , KC_M    , KC_COMM , KC_DOT  , KC_SLSH  , M_RSHIFT_BR,
                                 KC_RALT , KC_RGUI , KC_HYPR , TG(WSAD) , TG(GAME)   ,
  KC_PGUP           , KC_DEL                                                         ,
  KC_PGDN                                                                            ,
  MO(MDIA)          , MO(NAVI) , KC_ENT
)
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(NAVI)                // FN1 - Momentary Layer 1 (Symbols)
};

static bool ctrl_h_bs_pressed;
static bool ctrl_d_del_pressed;
static bool ctrl_left_pressed;
static bool ctrl_right_pressed;
// because shift works as bracket when tap separate state is needed
// to prevent conflicts with \ and tab
static bool shift_interrupted;
static bool key_pressed;
static bool l1_by_tab = false;
static bool l1_by_bsls = false;
static uint16_t ctrl_esc_timer;
static uint16_t ctrl_quote_timer;
static uint16_t l_shift_br_timer;
static uint16_t l1_tab_timer;
static uint16_t l1_bsls_timer;
static uint16_t r_shift_br_timer;

static int8_t i;

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_3_on();
            break;
        case 3:
            ergodox_right_led_2_on();
            break;
        case 4:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            break;
        case 5:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            break;
        default:
            // none
            break;
    }

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        key_pressed = true;
        shift_interrupted = true;
    }

    switch (keycode) {
    /* case 0: */
    /*     if (record->event.pressed) { */
    /*         SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION); */
    /*     } */
    /*     break; */
    case M_FAR_LEFT:
        for (i=0; i<5; i++) {
            mouse_report.x = -100;
            host_mouse_send(&mouse_report);
        }
        break;
    case M_FAR_RIGHT:
        for (i=0; i<5; i++) {
            mouse_report.x = 100;
            host_mouse_send(&mouse_report);
        }
        break;
    case M_PIPE_GT:
        if (record->event.pressed) {
            SEND_STRING("|>");
        }
        break;
    case M_LT_PIPE:
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
    case M_ARR_R:
        if (record->event.pressed) {
            SEND_STRING("->");
        }
        break;
    case M_ARR_L:
        if (record->event.pressed) {
            SEND_STRING("<-");
        }
        break;
    case M_L1_TAB: //L1 on hold, TAB on tap, GRV if already on L1
        if (record->event.pressed) {
            if (get_highest_layer(layer_state) != DEVP) {
                l1_by_tab = true;
                l1_by_bsls = false;
                layer_on(DEVP);
                l1_tab_timer = timer_read();
                key_pressed = false;
            } else {
                register_code(KC_GRV);
            }
        } else {
            if (l1_by_tab) {
                layer_off(DEVP);
            } else {
                unregister_code(KC_GRV);
            }
            if (timer_elapsed(l1_tab_timer) < 250 && !key_pressed) {
                register_code(KC_TAB);
                unregister_code(KC_TAB);
            }
        }
        break;
    case M_L1_BSLS: //L1 on hold, BSLS on tap, MINS if already on L1
        if (record->event.pressed) {
            if (get_highest_layer(layer_state) != DEVP) {
                l1_by_tab = false;
                l1_by_bsls = true;
                layer_on(DEVP);
                l1_bsls_timer = timer_read();
                key_pressed = false;
            } else {
                register_code(KC_LSFT);
                register_code(KC_MINUS);
            }
        } else {
            if (l1_by_bsls) {
                layer_off(DEVP);
            } else {
                unregister_code(KC_MINUS);
                unregister_code(KC_LSFT);
            }
            if (timer_elapsed(l1_bsls_timer) < 250 && !key_pressed) {
                register_code(KC_BSLS);
                unregister_code(KC_BSLS);
            }
        }
        break;
    case M_LSHIFT_BR:
        if (record->event.pressed) {
            register_code(KC_LSFT);
            l_shift_br_timer = timer_read();
            shift_interrupted = false;
        } else {
            if (timer_elapsed(l_shift_br_timer) < 250 && !shift_interrupted) {
                register_code(KC_9);
                unregister_code(KC_9);
            }
            unregister_code(KC_LSFT);
        }
        break;
    case M_RSHIFT_BR:
        if (record->event.pressed) {
            shift_interrupted = false;
            register_code(KC_RSFT);
            r_shift_br_timer = timer_read();
        } else {
            if (timer_elapsed(r_shift_br_timer) < 250 && !shift_interrupted) {
                register_code(KC_0);
                unregister_code(KC_0);
            }
            unregister_code(KC_RSFT);
        }
        break;
    case M_CTL_QUOTE:
        if (record->event.pressed) {
            register_code(KC_RCTL);
            ctrl_quote_timer = timer_read();
            ctrl_right_pressed = true;
            key_pressed = false;
        } else {
            unregister_code(KC_RCTL);
            ctrl_right_pressed = false;
            if (timer_elapsed(ctrl_quote_timer) < 250 && !key_pressed) {
                register_code(KC_QUOTE);
                unregister_code(KC_QUOTE);
            }
        }
        break;
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
    case M_CTL_ESC:
        if (record->event.pressed) {
            register_code(KC_LCTL);
            ctrl_esc_timer = timer_read();
            ctrl_left_pressed = true;
            key_pressed = false;
        } else {
            unregister_code(KC_LCTL);
            ctrl_left_pressed = false;
            if (timer_elapsed(ctrl_esc_timer) < 250 && !key_pressed) {
                register_code(KC_ESC);
                unregister_code(KC_ESC);
            }
        }
        break;
    case M_D:
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
    case M_H:
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

#ifdef ST7565_ENABLE

void lcd_color(uint8_t r, uint8_t g, uint8_t b) {
    ergodox_infinity_lcd_color(
        (r * UINT16_MAX / UINT8_MAX),
        (g * UINT16_MAX / UINT8_MAX),
        (b * UINT16_MAX / UINT8_MAX)
    );
}

void lcd_write(char* text) {
    st7565_write_P(PSTR(text), false);
}

void st7565_task_user(void) {

    led_t led_state = host_keyboard_led_state();
    st7565_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    st7565_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    st7565_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);

    st7565_write_P(PSTR(" d(^_^)b\n\n"), false);

    // Host Keyboard Layer Status
    switch (get_highest_layer(layer_state)) {
        case BASE :
            lcd_write("Default\n");
            lcd_color(128, 100, 255);
            break;
        case DEVP:
            lcd_write("Symbols & Num-s\n");
            lcd_color(168, 255, 100);
            break;
        case NAVI:
            lcd_write("Navigate & Mouse\n");
            lcd_color(0, 100, 255);
            break;
        case MDIA:
            lcd_write("Media & Numpad\n");
            lcd_color(220, 100, 255);
            break;
        default:
            lcd_write("\n");
            lcd_color(128, 100, 255);
    }
}

#endif
