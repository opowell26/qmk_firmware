#include QMK_KEYBOARD_H

#define SPC_F1 LT(1,KC_SPC)
#define BS_F2 LT(2,KC_BSPC)
#define C_F3 LT(3,KC_C)
#define V_F4 LT(4,KC_V)
#define B_F5 LT(5,KC_B)
#define Z_CTL MT(MOD_LCTL, KC_Z)
#define X_ALT MT(MOD_LALT, KC_X)
#define N_ALT MT(MOD_RALT, KC_N)
#define M_CTL MT(MOD_RCTL, KC_M)
#define ENT_SFT MT(MOD_RSFT, KC_ENT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Level 0: Default Layer
   * ,-------------------------------------------------------------------------------.
   * |   Q   |   W   |   E   |   R   |   T   |   Y   |   U   |   I   |   O   |   P   |
   * |-------------------------------------------------------------------------------|
   * |   A   |   S   |   D   |   F   |   G   |   H   |   J   |   K   |   L   |  ESC  |
   * |-------------------------------------------------------------------------------|
   * |   Z   |   X   |   C   |   V   |  BSPC |  SPC  |   B   |   N   |   M   |  ENT  |
   * '-------------------------------------------------------------------------------'
   */
  LAYOUT_ortho_3x10
    ( KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P
    , KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_ESC
    , Z_CTL,  X_ALT,  C_F3,   V_F4,   BS_F2,  SPC_F1, B_F5,   N_ALT,  M_CTL,  ENT_SFT
    ),
  /* Level 1: Numbers Layer
   * ,-------------------------------------------------------------------------------.
   * |   1   |   2   |   3   |   4   |   5   |   6   |   7   |   8   |   9   |   0   |
   * |-------------------------------------------------------------------------------|
   * |   F1  |   F2  |   F3  |   F4  |   F5  |   F6  |   F7  |   F8  |   F9  |  F10  |
   * |-------------------------------------------------------------------------------|
   * |       |       |       |       |  DEL  |       |       |       |       |       |
   * '-------------------------------------------------------------------------------'
   */
  LAYOUT_ortho_3x10
    ( KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0
    , KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10
    , _______,_______,_______,_______,KC_DEL, _______,_______,_______,_______,_______
    ),
  /* Level 2: Symbols Layer
   * ,-------------------------------------------------------------------------------.
   * |   !   |   @   |   #   |   $   |   %   |   ^   |   &   |   *   |   (   |   )   |
   * |-------------------------------------------------------------------------------|
   * |  F11  |  F12  |       |       |       |       |       |       |       |   `   |
   * |-------------------------------------------------------------------------------|
   * |       |       |       |       |       |       |       |       |       |       |
   * '-------------------------------------------------------------------------------'
   */
  LAYOUT_ortho_3x10
    ( KC_EXLM,KC_AT,  KC_HASH,KC_DLR, KC_PERC,KC_CIRC,KC_AMPR,KC_ASTR,KC_LPRN,KC_RPRN
    , KC_F11,  KC_F12,_______,_______,_______,_______,_______,_______,_______,KC_GRAVE
    , _______,_______,_______,_______,_______,_______,_______,_______,_______,_______
    ),
  /* Level 3: RGB Layer
   * ,-------------------------------------------------------------------------------.
   * |       |       |       |       |       |   -   |   =   |   [   |   ]   |   \   |
   * |-------------------------------------------------------------------------------|
   * |  Tab  |       |       |       |       |   ,   |   .   |   /   |   ;   |   '   |
   * |-------------------------------------------------------------------------------|
   * |       |       |       |       |       |       | Left  | Down  |   Up  | Right |
   * '-------------------------------------------------------------------------------'
   */
  LAYOUT_ortho_3x10
    ( _______,_______,_______,_______,_______,KC_MINS,KC_EQL, KC_LBRC,KC_RBRC,KC_BSLS
    , KC_TAB, _______,_______,_______,_______,KC_COMM,KC_DOT, KC_SLSH,KC_SCLN,KC_QUOT
    , _______,_______,_______,_______,_______,_______,KC_LEFT,KC_DOWN,KC_UP,  KC_RGHT
    ),
  /* Level 4: RGB Layer
   * ,-------------------------------------------------------------------------------.
   * |       |       |       |       |       |   _   |   +   |   {   |   }   |   |   |
   * |-------------------------------------------------------------------------------|
   * |  Tab  |       |       |       |       |   <   |   >   |   ?   |   :   |   "   |
   * |-------------------------------------------------------------------------------|
   * |       |       |       |       |       |       | Home  | PgDn  |  PgUp | End  |
   * '-------------------------------------------------------------------------------'
   */
  LAYOUT_ortho_3x10
    ( _______,_______,_______,_______,_______,KC_UNDS,KC_PLUS,KC_LCBR,KC_RCBR,KC_PIPE
    , KC_TAB, _______,_______,_______,_______,KC_LT,  KC_GT,  KC_QUES,KC_COLN,KC_DQUO
    , _______,_______,_______,_______,_______,_______,KC_HOME,KC_PGUP,KC_PGDN,KC_END
    ),
  /* Level 5: RGB Layer
   * ,-------------------------------------------------------------------------------.
   * | Calc  |  Web  | Mail  |Explore|       |       |       |       |       |       |
   * |-------------------------------------------------------------------------------|
   * |UG_TOGG|UG_NEXT|UG_HUEU|UG_HUED|xxxxxxx|xxxxxxx|UG_SATU|UG_SATD|UG_VALU|UG_VALD|
   * |-------------------------------------------------------------------------------|
   * |       |       |       |       | Flash |       |       |       |       |       |
   * '-------------------------------------------------------------------------------'
   */
  LAYOUT_ortho_3x10
    ( KC_CALC,KC_WSCH,KC_MAIL,KC_MYCM,_______,_______,_______,_______,_______,_______
    , UG_TOGG,UG_NEXT,UG_HUEU,UG_HUED,XXXXXXX,XXXXXXX,UG_SATU,UG_SATD,UG_VALU,UG_VALD
    , _______,_______,_______,_______,QK_BOOT,_______,_______,_______,_______,_______
    ),
};
