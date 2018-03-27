/*
 * plavelo layout
 */
#include "keymap_common.h"

#ifdef KEYMAP_SECTION_ENABLE
const uint8_t keymaps[][MATRIX_ROWS][MATRIX_COLS] __attribute__ ((section (".keymap.keymaps"))) = {
#else
const uint8_t keymaps[][MATRIX_ROWS][MATRIX_COLS] PROGMEM = {
#endif
    /* BASE Level: Default Layer
     |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
     | ESC |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  | -   | =   | \   |  `  |
     |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
     | TAB |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  | [   | ]   |    BS     |
     |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
     | CTL |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  | '   |       ENT       |
     |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
     | SFT |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  |    SFT    |    FN0    |
     |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
           | GUI |    ALT    |         SPACE         |    FN1    | FN2 |
           |-----+-----------+-----------------------+-----------+-----|
    */
    KEYMAP(ESC, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, BSLS,GRV,  \
           TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,BSPC,      \
           LCTL,A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,ENT,            \
           LSFT,Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,RSFT,FN0,            \
                LGUI,LALT,          SPC,                FN1, FN2),

    /* Layer HHKB: HHKB mode (Fn0)
     |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
     |     | F1  | F2  | F3  | F4  | F5  | F6  | F7  | F8  | F9  | F10 | F11 | F12 | INS | DEL |
     |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
     |     | PGU | MCU | PGD | HOM |     |     |     |     |     |     | UP  | ACL |           |
     |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
     |     | MCL | MCD | MCR | END |     |     |     |     |     | LEF | RIG |                 |
     |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
     |     |     |     |     |     |     |     |     |     |     | DWN |           |           |
     |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
           |     |           |          MB1          |           |     |
           |-----+-----------+-----------------------+-----------+-----|
    */
    KEYMAP(TRNS,F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, INS, DEL,  \
           TRNS,PGUP,MS_U,PGDN,HOME,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,UP,  ACL1,TRNS,      \
           TRNS,MS_L,MS_D,MS_R,END, TRNS,TRNS,TRNS,TRNS,TRNS,LEFT,RGHT,TRNS,           \
           TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,DOWN,TRNS,TRNS,           \
                TRNS,TRNS,          BTN1,               TRNS,TRNS),
};

/* id for user defined functions and macros */
enum macro_id {
    SLEEP,
    LOCK,
    DOMO,
};

/*
 * Fn action definition
 */
#ifdef KEYMAP_SECTION_ENABLE
const action_t fn_actions[] __attribute__ ((section (".keymap.fn_actions"))) = {
#else
const action_t fn_actions[] PROGMEM = {
#endif
    [0] = ACTION_LAYER_MOMENTARY(1),
    [1] = ACTION_MACRO(SLEEP),
    [2] = ACTION_MACRO(LOCK),
};

/*
 * Macro definition
 */
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    switch (id) {
        case SLEEP:
            return (record->event.pressed ?
                    MACRO(
                        I(0),
                        D(LCTL), D(LSFT), D(POWER),
                        U(LCTL), U(LSFT), U(POWER),
                        END
                    ) : MACRO_NONE);
        case LOCK:
            return (record->event.pressed ?
                    MACRO(
                        I(0),
                        D(LGUI), D(LCTL), D(Q),
                        U(LGUI), U(LCTL), U(Q),
                        END
                    ) : MACRO_NONE);
        case DOMO:
            return (record->event.pressed ?
                    MACRO(
                        I(0),
                        T(M), D(LSFT), T(9), T(MINS), T(SPC), T(MINS), T(0), U(LSFT), T(M),
                        END
                    ) : MACRO_NONE);
    }
    return MACRO_NONE;
}
