#include <dmx.h>
#include <FastLED.h>
#include <fastpin.h>
#include <colorpalettes.h>
#include <controller.h>
#include <fastspi.h>
#include <noise.h>
#include <fastspi_nop.h>
#include <hsv2rgb.h>
#include <color.h>
#include <pixelset.h>
#include <fastspi_types.h>
#include <chipsets.h>
#include <pixeltypes.h>
#include <fastspi_dma.h>
#include <power_mgt.h>
#include <bitswap.h>
#include <fastspi_ref.h>
#include <lib8tion.h>
#include <fastled_progmem.h>
#include <colorutils.h>
#include <led_sysdefs.h>
#include <fastspi_bitbang.h>
#include <platforms.h>
#include <cpp_compat.h>
#include <fastled_delay.h>
#include <fastled_config.h>

#define LED_PIN         5
#define BRIGHTNESS      255
#define LED_TYPE        WS2811
#define COLOR_ORDER     GRB

#define LED_HEARTBEAT   13


#define LEDS_PER_STRIP  12        // the number of LEDs per leg of the arm support
#define LED_STRIPS      8         // number of strips total

#define NUM_OF_LEDS     (LEDS_PER_STRIP * LED_STRIPS)        // total number of LEDs

// LED strips can be wired in 2 different ways:
//
// WIRING_ZIG_ZAG
//              Wiring at the end of top or bottom of one strip right to the
//              nearby top or bottom of the next strip
//
//              This can save a lot of wiring when strips terminate close to each
//              other since we won't have to wire from the top of one strip all the
//              way back to the bottom of the next strip
//
//              It is assumed that the strips alternate ends in order to define the
//              connection sequence
//
//              For example, if there are 3 strips of 4 LEDs, the LEDs are wired in
//              the electrical order of 0-3, 7-4, 8-11
//
//  WIRING_LINEAR
//
//              All LEDS are wired in order; the top of one strip is wired to the bottom
//              of the next
//
//              3 strips of 4 LEDs each are wired 0-11
//
//  WIRING_ORDER should be set to either WIRING_ZIG_ZAG or WIRING_LINEAR

#define WIRING_LINEAR       0
#define WIRING_ZIG_ZAG      1

#define WIRING_ORDER        WIRING_ZIG_ZAG

#define SERIAL_BAUD_RATE    115200


CRGB  leds[NUM_OF_LEDS];




CRGBPalette16 currentPalette;
TBlendType    currentBlending;


void setup() {
  Serial.begin(SERIAL_BAUD_RATE);

  delay(3000); // power-up safety delay
  
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_OF_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.setBrightness(BRIGHTNESS);
    
  currentPalette = RainbowColors_p;
  currentBlending = LINEARBLEND;

  Serial.println("Starting super fast algorithm...");
}



void loop() {
    unsigned long  val;
    int            badDigitFlag, pos1, pos2, pos3, pos4, pos5, pos6, pos7, pos8, pos9;
    char           *ptr, buf[10], usedDigit[9];
    int            tested = 0;

    pos1 = pos2 = pos3 = pos4 = pos5 = pos6 = pos7 = pos8 = pos9 = 0;
    
    for (pos1 = 1 ; pos1 <= 9 ; pos1 += 2) {                                // 1st digit has to be odd because the even digits
                                                                            // all have to be used in the even positions

        for (pos2 = 2 ; pos2 <= 8 ; pos2 += 2) {                            // 2nd must be even

            // we've only generate potentially valid numbers up till now but now we need to starte checking
            for (pos3 = 1 ; pos3 <= 9 ; pos3 += 2) {                        // 3rd has to be odd

                if ((pos1 + pos2 + pos3) % 3) {
                    continue;                                               // fails div by 3 rule
                }

                for (pos4 = 2 ; pos4 <= 8 ; pos4 += 2) {                    // 4th must be even

                    if ((pos3 * 10 + pos4) % 4) {
                        continue;                                           // fails div by 4 rule
                    }

                    pos5 = 5;                                               // 5th can only be '5' since '0' is not allowed

                    for (pos6 = 2 ; pos6 <= 8 ; pos6 += 2) {                // 6th must be even

                        // we try to avoid turning our digits into a real binary number but we can't avoid it here

                        val = pos1 * (unsigned long)100000 + pos2 * (unsigned long)10000 + pos3 * (unsigned long)1000 + pos4 * (unsigned long)100 + pos5 * (unsigned long)10 + pos6;

                        if (val % 6) {
                            continue;                                       // fails div by 6
                        }
                        
                        for (pos7 = 1 ; pos7 <= 9 ; pos7 += 2) {            // 7th must be odd

                            val = pos1 * (unsigned long)100000 + pos2 * (unsigned long)10000 + pos3 * (unsigned long)1000 + pos4 * 100 + pos5 * (unsigned long)10 + pos6;

                            if ((val - 2 * pos7) % 7) {
                                continue;                                   // fails div by 7 rule
                            }

                            for (pos8 = 2 ; pos8 <= 8 ; pos8 += 2) {        // 8th must be even

                                if ((pos6 * 100 + pos7 * 10 + pos8) % 8) {  // fails div by 8 rule
                                    continue;
                                }

                                for (pos9 = 1 ; pos9 <= 9 ; pos9 += 2) {     // 9th must be odd

                                    if ((pos1 + pos2 + pos3 + pos4 + pos5 + pos6 + pos7 + pos8 + pos9) % 9) {
                                        continue;                            // fails div by 9 rule
                                    }
                                    
                                    tested++;

                                    // well, we've got a potential candidate
                                    //
                                    // lets check for any repeated digits - we should have no '0's in here

                                    val = pos1 * (unsigned long)100000000 + pos2 * (unsigned long)10000000 + pos3 * (unsigned long)1000000 + pos4 * (unsigned long)100000 + pos5 * (unsigned long)10000 + pos6 * (unsigned long)1000 + pos7 * (unsigned long)100 + pos8 * (unsigned long)10 + pos9;

                                    sprintf(buf, "%ld", val);    // convert to ASCII - easy to find repeats

                                    usedDigit[0] = usedDigit[1] = usedDigit[2] = usedDigit[3] = usedDigit[4] = usedDigit[5] = usedDigit[6] = usedDigit[7] = usedDigit[8] = 0;

                                    ptr = buf;

                                    badDigitFlag = 0;
                                    
                                    while (*ptr) {
                                        if (usedDigit[*ptr - '0' - 1]) {    // already used this digit
                                            badDigitFlag++;
                                            break;                          // no need to keep checking
                                        } else {
                                            usedDigit[*ptr - '0' - 1]++;
                                        }

                                        ptr++;
                                    }

                                    if (badDigitFlag) {
                                        continue;
                                    }

                                    Serial.print("Solution: ");
                                    Serial.println(val);
                                    Serial.print("Tested ");
                                    Serial.print(tested);
                                    Serial.println(" values");

                                    while (1);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
