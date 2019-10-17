# Helper component for ESP32 Remote Control module

This implementation uses the RMT driver from `ESP-IDF`.

## About timings

Timings are from datasheets.
According to [Worldsemi's datasheets](http://www.world-semi.com) there are a few timings sets:

- one for WS2812
- one for WS2812B, WS2812C, WS2812S, WS2813 and WS2815
- one for WS2812D

In [Tim's Blog (cpldcpu)](https://cpldcpu.wordpress.com) are some interesting investigations about timings of various digital LEDs.

## Dependencies

[Espressif IoT Development Framework](https://github.com/espressif/esp-idf).

## Hardware details

The code was tested on the following boards:

- ESP32-DevKitC board with a level convertor made from two 74HCT1G04 inverters
- Dev33-DLED - uses SN74LV1T34 logic level shifter connected to an ESP32-WROOM-32 module

and:

- a LED strip with 300 WS2812B digital LEDs
- Mean Well EPS-65S-5 power source

## Development Environment

Main tools used where [Espressif IoT Development Framework](https://github.com/espressif/esp-idf) and *ESP32 toolchain for Linux*
(see [Standard Setup of Toolchain for Linux](https://github.com/espressif/esp-idf/blob/master/docs/get-started/linux-setup.rst)
for the latest version).

Editing was done in [Visual Studio Code](https://code.visualstudio.com).

Version control with [Git](https://git-scm.com).

## License

This software and related documentation is released under the [GNU GPLv3](http://www.gnu.org/licenses/gpl-3.0.html) License. See the `LICENSE-GPLv3.txt` file.

## Note

This should be a faster and more efficient version of the one published by me previously in the (esp32_digitalLEDs)[https://github.com/CalinRadoni/esp32_digitalLEDs] repository.
