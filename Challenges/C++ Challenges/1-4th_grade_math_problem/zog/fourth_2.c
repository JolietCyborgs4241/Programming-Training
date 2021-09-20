#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {

    unsigned long  val;
    int            badDigitFlag, pos1, pos2, pos3, pos4, pos5, pos6, pos7, pos8, pos9;
    char           *ptr, buf[10], usedDigit[9];
    int            tested = 0;

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

                        val = pos1 * 100000 + pos2 * 10000 + pos3 * 1000 + pos4 * 100 + pos5 * 10 + pos6;

                        if (val % 6) {
                            continue;                                       // fails div by 6
                        }

                        for (pos7 = 1 ; pos7 <= 9 ; pos7 += 2) {            // 7th must be odd

                            val = pos1 * 100000 + pos2 * 10000 + pos3 * 1000 + pos4 * 100 + pos5 * 10 + pos6;

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

                                    val = pos1 * 100000000 + pos2 * 10000000 + pos3 * 1000000 + pos4 * 100000 + pos5 * 10000 + pos6 * 1000 + pos7 * 100 + pos8 * 10 + pos9;
                                         
                                    sprintf(buf, "%ld", val);    // convert to ASCII - easy to find repeats

                                    bzero(usedDigit, sizeof(usedDigit));

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

                                    printf("Solution: %ld\n", val);
                                    printf("Tested %d values\n", tested);

                                    exit(0);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

