#include QMK_KEYBOARD_H
#include "print.h"

enum custom_keycodes {
    STEAM = SAFE_RANGE, // SAFE_RANGE prevents it from using a clashing keycode
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

//      ESC      F1       F2       F3       F4       F5       F6       F7       F8       F9       F10      F11      F12      Prt           Rotary(Mute)
//      ~        1        2        3        4        5        6        7        8        9        0         -       (=)      BackSpc           Del
//      Tab      Q        W        E        R        T        Y        U        I        O        P        [        ]                          PgUp
//      Caps     A        S        D        F        G        H        J        K        L        ;        "        #        Enter             PgDn
//      Sh_L     /        Z        X        C        V        B        N        M        ,        .        ?                 Sh_R     Up       End
//      Ct_L     Win_L    Alt_L                               SPACE                               Alt_R    FN       Ct_R     Left     Down     Right


    // The FN key by default maps to a momentary toggle to layer 1 to provide access to the RESET key (to put the board into bootloader mode). Without
    // this mapping, you have to open the case to hit the button on the bottom of the PCB (near the USB cable attachment) while plugging in the USB
    // cable to get the board into bootloader mode - definitely not fun when you're working on your QMK builds. Remove this and put it back to KC_RGUI
    // if that's your preference.
    //
    // To put the keyboard in bootloader mode, use FN+backspace. If you accidentally put it into bootloader, you can just unplug the USB cable and
    // it'll be back to normal when you plug it back in.
    //
    // This keyboard defaults to 6KRO instead of NKRO for compatibility reasons (some KVMs and BIOSes are incompatible with NKRO).
    // Since this is, among other things, a "gaming" keyboard, a key combination to enable NKRO on the fly is provided for convenience.
    // Press Fn+N to toggle between 6KRO and NKRO. This setting is persisted to the EEPROM and thus persists between restarts.
    [0] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR,          KC_MUTE,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_DEL,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,                   KC_PGUP,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT,           KC_PGDN,
        KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   KC_END,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, MO(1),   KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [1] = LAYOUT(
        RGB_TOG, KC_MYCM, KC_WHOM, KC_CALC, KC_MSEL, KC_MPRV, KC_MNXT, KC_MPLY, KC_MSTP, _______, _______, _______, _______, DEBUG,            _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET,            _______,
        _______, RGB_HUI, RGB_VAI, RGB_SAI, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______,
        _______, RGB_HUD, RGB_VAD, RGB_SAD, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, STEAM,   _______, NK_TOGG, _______, _______, _______, _______,          _______, RGB_MOD, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, RGB_SPD, RGB_RMOD, RGB_SPI
    ),


    [2] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______, _______
    ),

    [3] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______, _______
    ),


};

void keyboard_post_init_user(void) {
    // Customise these values to desired behaviour
    debug_enable=true;
    //debug_matrix=true;
    //debug_keyboard=true;
    //debug_mouse=true;

}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    uprintf("\nHola %u\n", keycode);
    switch (keycode) {
        case STEAM:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_LGUI) "steam" SS_DELAY(500) SS_TAP(X_ENT));
            } else {
                // when keycode is released
            }
            break;
    }
    return true;
}

// RGB LED layout

//      ESC      F1       F2       F3       F4       F5       F6       F7       F8       F9       F10      F11      F12      Prt           Rotary(Mute)
//      ~        1        2        3        4        5        6        7        8        9        0         -       (=)      BackSpc           Del
//      Tab      Q        W        E        R        T        Y        U        I        O        P        [        ]                          PgUp
//      Caps     A        S        D        F        G        H        J        K        L        ;        "        #        Enter             PgDn
//      Sh_L     /        Z        X        C        V        B        N        M        ,        .        ?                 Sh_R     Up       End
//      Ct_L     Win_L    Alt_L                               SPACE                               Alt_R    FN       Ct_R     Left     Down     Right

// led index number, function of the key

//  69, Side led 01    0, ESC      6, F1       12, F2       18, F3       23, F4       28, F5       34, F6       39, F7       44, F8       50, F9       56, F10      61, F11      66, F12      69, Prt       Rotary(Mute)   68, Side led 12
//  72, Side led 02    1, ~        7, 1        13, 2        19, 3        24, 4        29, 5        35, 6        40, 7        45, 8        51, 9        57, 0        62, -_       78, (=+)     85, BackSpc   72, Del        71, Side led 13
//  75, Side led 03    2, Tab      8, Q        14, W        20. E        25, R        30, T        36, Y        41, U        46, I        52, O        58, P        63, [{       89, ]}       93, \|        75, PgUp       74, Side led 14
//  78, Side led 04    3, Caps     9, A        15, S        21, D        26, F        31, G        37, H        42, J        47, K        53, L        59, ;:       64, '"                    96, Enter     86, PgDn       77, Side led 15
//  82, Side led 05    4, Sh_L     XX, /       10, Z        16, X        22, C        27, V        32, B        38, N        43, M        48, ,<       54, .<       60, /?                    90, Sh_R      94, Up        82, End        81, Side led 16
//  85, Side led 06    5, Ct_L     11,Win_L    17, Alt_L                              33, SPACE                              49, Alt_R    55, FN                    65, Ct_R     95, Left     97, Down      79, Right      84, Side led 17
//  89, Side led 07                                                                                                                                                                                                        88, Side led 18
//  93, Side led 08

uint8_t thisHue = 0;
uint8_t thisSat = 255;
uint8_t thisVal = 255;
const int SIZE = 8;
int leftSideLEDs[] = { 69, 72, 75, 78, 82, 85, 89, 93 };
int rightSideLEDs[] = { 68, 71, 74, 77, 81, 84, 88, 92 };
#if defined(ENCODER_ENABLE) && !defined(ENCODER_DEFAULTACTIONS_ENABLE)

void encoder_action_hsv_change(bool clockwise, uint8_t hueChange, uint8_t satChange, uint8_t valChange) {
    if (clockwise) {
        thisHue += hueChange;
        thisSat += satChange;
        thisVal += valChange;
    } else {
        thisHue -= hueChange;
        thisSat -= satChange;
        thisVal -= valChange;
    }
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    uint8_t mods_state = get_mods();

    if (mods_state & MOD_BIT(KC_LCTL)) {
        encoder_action_hsv_change(clockwise, 2, 0, 0); // Hue change
    } else if (mods_state & MOD_BIT(KC_LSFT)) {
        encoder_action_hsv_change(clockwise, 0, 2, 0); // Saturation change
    } else if (mods_state & MOD_BIT(KC_LALT)) {
        encoder_action_hsv_change(clockwise, 0, 0, 2); // Value/Brightness change
    }
    else {
        uint8_t layer = get_highest_layer(layer_state);

        if (clockwise) {
            if (layer > 0) {
                tap_code(KC_VOLU);
            } else {
                tap_code(KC_WH_D);
            }
        } else {
            if (layer > 0) {
                tap_code(KC_VOLD);
            } else {
                tap_code(KC_WH_U);
            }
        }
    }
    return true;
}

#endif // endif ENCODER

void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (IS_HOST_LED_ON(USB_LED_CAPS_LOCK)) {
        for (int i = 0; i < SIZE; i++) {
            rgb_matrix_set_color(leftSideLEDs[i], RGB_RED);
            rgb_matrix_set_color(rightSideLEDs[i], RGB_RED);
        }
        rgb_matrix_set_color(3, RGB_RED);
    } else {
        HSV hsv = {thisHue, thisSat, thisVal};
        RGB rgb = hsv_to_rgb(hsv);
        for (int i = 0; i < SIZE; i++) {
            rgb_matrix_set_color(leftSideLEDs[i], rgb.r, rgb.g, rgb.b);
            rgb_matrix_set_color(rightSideLEDs[i], rgb.r, rgb.g, rgb.b);
        }

        uint8_t layer = get_highest_layer(layer_state);

        if (layer > 0) {
            for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
                for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
                    uint8_t index = g_led_config.matrix_co[row][col];

                    if (index >= led_min && index <= led_max && index != NO_LED &&
                    keymap_key_to_keycode(layer, (keypos_t){col,row}) > KC_TRNS) {
                        rgb_matrix_set_color(index, RGB_YELLOW);
                    }
                }
            }

            // Set Media control colors
            rgb_matrix_set_color(28, RGB_BLUE); // F9. "Prev Track"
            rgb_matrix_set_color(34, RGB_BLUE); // F10 "Next track"
            rgb_matrix_set_color(39, RGB_GREEN); //F11 "Play"
            rgb_matrix_set_color(44, RGB_RED); // F12 "Stop"
        }
    }
}
