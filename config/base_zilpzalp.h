#include <behaviors.dtsi>
#include <dt-bindings/zmk/keys.h>

#define APT 0
#define SYM 1
#define NAV 2
#define FUN 3

/ {};

#define CG(x) LG(LC(x))

#define SHIFT_OVERRIDE(KEY1, KEY2)                                             \
  override_##KEY1_##KEY2 {                                                     \
    compatible = "zmk,behavior-mod-morph";                                     \
    #binding - cells = <0>;                                                    \
    bindings = <&kp KEY1>, <&kp KEY2>;                                         \
    mods = <(MOD_LSFT)>;                                                       \
  }

#define NUM(KC, NUMBER) shift_morph_##KC_##NUMBER : SHIFT_OVERRIDE(KC, NUMBER)

#define COMBO(NAME, BINDINGS, KEYPOS)                                          \
  combo_##NAME {                                                               \
    timeout - ms = <25>;                                                       \
    bindings = <BINDINGS>;                                                     \
    key - positions = <KEYPOS>;                                                \
  };

/ {
  combos {
    compatible = "zmk,combos";
    /* usually on base layer */
    COMBO(q, &kp Q, 0 1)
    COMBO(z, &kp Z, 18 19)
    COMBO(v, &kp V, 0 1)
    COMBO(enter, &kp ENTER, 21 23)
    /* deletion */
    COMBO(bspc, &kp BSPC, 5 6)
    COMBO(del, &kp DEL, 6 7)
    COMBO(delword, &kp LC(BSPC), 5 7)
  };
};

//     __________________________  __________________________
//    /     0  |  1  |  2  |  3  \/   4 |   5 |   6 |   7    \
// |  8  |  9  | 10  | 11  | 12  /\  13 |  14 |  15 |  16 | 17  |
//    \    18  | 19  | 20    /        \    21 |  22 |  23   /
//          \    24  | 25  /            \  26 |  27    /
//           --------------              --------------

/ {

  behaviors {
  hl:
    homerow_mods_left {
      compatible = "zmk,behavior-hold-tap";
      label = "homerow mods left";
#binding - cells = < 2>;
      flavor = "balanced";
      tapping - term - ms = <200>;
      quick - tap - ms = <140>;
      require - prior - idle - ms = <140>;
      bindings = <&kp>, <&kp>;
      // opposite side hand keys
      hold - trigger - key - positions =
          <4 5 6 7 13 14 15 16 17 21 22 23 24 25 26 27>;
    };
  hr:
    homerow_mods_right {
      compatible = "zmk,behavior-hold-tap";
      label = "homerow mods right";
#binding - cells = < 2>;
      flavor = "balanced";
      tapping - term - ms = <200>;
      quick - tap - ms = <140>;
      require - prior - idle - ms = <140>;
      bindings = <&kp>, <&kp>;
      // opposite side hand keys
      hold - trigger - key - positions =
          <0 1 2 3 8 9 10 11 12 18 19 20 24 25 26 27>;
    };
  qmt:
    quick_mod_tap {
      compatible = "zmk,behavior-hold-tap";
#binding - cells = < 2>;
      flavor = "hold-preferred";
      bindings = <&kp>, <&kp>;
      tapping - term - ms = <200>;
      quick - tap - ms = <140>;
      hold - trigger - on - release;
    };

  my_lt:
    my_layer_taps {
      compatible = "zmk,behavior-hold-tap";
      label = "my layer taps";
#binding - cells = < 2>;
      flavor = "balanced";
      tapping - term - ms = <200>;
      require - prior - idle - ms = <140>;
      quick - tap - ms = <100>;
      bindings = <&mo & kp>, <&kp>;
    };
  qlt:
    quick_layer_tab {
      compatible = "zmk,behavior-hold-tap";
#binding - cells = < 2>;
      bindings = <&mo>, <&kp>;
      flavor = "hold-preferred";
      tapping - term - ms = <200>;
      quick - tap - ms = <140>;
      hold - trigger - on - release;
    };

  dotcol:
    dot_colon {
      compatible = "zmk,behavior-mod-morph";
      label = "DOT_COL";
#binding - cells = < 0>;
      bindings = <&kp DOT>, <&kp COLON>;
      mods = <(MOD_LSFT | MOD_RSFT)>;
    };
  comsem:
    comma_semicolon {
      compatible = "zmk,behavior-mod-morph";
      label = "COM_SEM";
#binding - cells = < 0>;
      bindings = <&kp COMMA>, <&kp SEMI>;
      mods = <(MOD_LSFT | MOD_RSFT)>;
    };
  num1:
    SHIFT_OVERRIDE(SQT, N1);
  num2:
    SHIFT_OVERRIDE(LBKT, N2);
  num3:
    SHIFT_OVERRIDE(LBRC, N3);
  num4:
    SHIFT_OVERRIDE(LPAR, N4);
  num5:
    SHIFT_OVERRIDE(PRCNT, N5);
  num6:
    SHIFT_OVERRIDE(AT, N6);
  num7:
    SHIFT_OVERRIDE(RPAR, N7);
  num8:
    SHIFT_OVERRIDE(RBRC, N8);
  num9:
    SHIFT_OVERRIDE(RBKT, N9);
  num0:
    SHIFT_OVERRIDE(DQT, N0);
  minus:
    SHIFT_OVERRIDE(MINUS, MINUS);
  equal:
    SHIFT_OVERRIDE(EQUAL, EQUAL);
  };
};
