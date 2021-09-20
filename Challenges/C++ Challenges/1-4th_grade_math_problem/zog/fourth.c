#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MIN_VAL             123456789
#define MAX_VAL             987654321

int main(int argc, char *argv[]) {

unsigned long  val, testVal;
int            badDigitFlag;
char           *ptr, buf[10], usedDigit[9];


  for (val = MIN_VAL ; val < MAX_VAL; val += 9) {        // we start divisible by 9 and go by 9's

    // start checking divisibility - we *know* it's divisible by 9

    testVal = val / 10;                                  // drop the 9th digit

    if ( ! (testVal % (unsigned long)8)) {               // first 8 divisible by 8

      testVal /= 10;                                     // drop the 8th digit

      if ( ! (testVal % (unsigned long)7)) {

        testVal /= 10;

        if ( ! (testVal % (unsigned long)6)) {

          testVal /= 10;

          if ( ! (testVal % (unsigned long)5)) {

            testVal /= 10;

            if ( ! (testVal % (unsigned long)4)) {

              testVal /= 10;

              if ( ! (testVal % (unsigned long)3)) {

                  testVal /= 10;

                if ( ! (testVal % (unsigned long)2)) {

                  //printf("FOUND POTENTIAL: %ld\n", val);

                  sprintf(buf, "%ld", val);    // convert to ASCII - easy to find any 0's and check for repeats

                  bzero(usedDigit, sizeof(usedDigit));

                  ptr = buf;

                  // check for repeating digits or '0'

                  badDigitFlag = 0;

                  while (*ptr) {
                    if (usedDigit[*ptr - '0' - 1] || *ptr == '\0') {      // already used this digit or '0'
                      badDigitFlag++;
                      break;                                              // no need to keep checking
                    } else {
                      usedDigit[*ptr - '0' - 1]++;
                    }

                    ptr++;
                  }

                  if (badDigitFlag) {
                    continue;
                  }

                  printf("Solution: %ld\n", val);

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

