# Romi light test

Original code from https://github.com/6391-Ursuline-Bearbotics/6391Romi

This code uses the three Romi buttons (A, B, and C) and drives the of the
general Digital I/O lines on the front left corner of the Romi controller
boards (labeled 8, 9, and 10).
If you connect an LED to each of these pins
(cathode to the front row labeled GND and the anode to the rear row - be sure to use a current limiting resistor; 1K ohms works fine).

| Button | Digital Output |
| :----- | -------------: |
|    A   |      10        |
|    B   |       9        |
|    C   |       8        |

Note that you'll need to set these to Digital Outputs using the Romi web interface before this code will work correctly.

![image](https://user-images.githubusercontent.com/10516156/113965320-c18c2880-97f2-11eb-9197-aa54ca7e1d57.png)

You only need to set the first three - the others don't matter.

