# Helper component for ESP32 Remote Control module

This implementation uses the RMT driver from `ESP-IDF`.

It can be used to control any of the eight channelsssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss
sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss

## Dependencies

[Espressif IoT Development Framework](https://github.com/espressif/esp-idf).

## Hardware details

The code was tested on the following boards:

- ESP32-DevKitC board with a level convertor made from two 74HCT1G04 inverters
- Dev33-DLED - uses SN74LV1T34 logic level shifter connected to an ESP32-WROOM-32 module
- Dev34-DLEDGrid - uses SN74LV1T34 logic level shifter connected to an ESP32-WROOM-32 module

and:

- a LED strip with 300 WS2812B digital LEDs + Mean Well EPS-65S-5 power source
- a 8x8 LED board with WS2812 digital LEDs + Sony VTC6 18650 Battery

## Development Environment

Main tools used where [Espressif IoT Development Framework](https://github.com/espressif/esp-idf) and *ESP32 toolchain for Linux*
(see [Standard Setup of Toolchain for Linux](https://github.com/espressif/esp-idf/blob/master/docs/get-started/linux-setup.rst)
for the latest version).

Editing was done in [Visual Studio Code](https://code.visualstudio.com).

Version control with [Git](https://git-scm.com).

## License

This software and its documentation are released under the [GNU GPLv3](http://www.gnu.org/licenses/gpl-3.0.html) License. See the `LICENSE-GPLv3.txt` file.

## Note

This is an improved version of the one used by me previously in the (esp32_digitalLEDs)[https://github.com/CalinRadoni/esp32_digitalLEDs] repository.
