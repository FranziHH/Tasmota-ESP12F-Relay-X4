# Tasmota ESP12F Relay X4 - ! Fork From Tasmota !
This is Forked From https://github.com/arendst/Tasmota

![Tasmota logo](/tools/logo/TASMOTA_FullLogo_Vector.svg#gh-light-mode-only)![Tasmota logo](/tools/logo/TASMOTA_FullLogo_Vector_White.svg#gh-dark-mode-only)

Alternative firmware for [ESP8266](https://en.wikipedia.org/wiki/ESP8266) and [ESP32](https://en.wikipedia.org/wiki/ESP32) based devices with **easy configuration using webUI, OTA updates, automation using timers or rules, expandability and entirely local control over MQTT, HTTP, Serial or KNX**.
_Written for PlatformIO._

[Original Tasmota Readme.md](/TASMOTA-README.MD)

<hr>

This project deals with the [4-CHANNEL X4 RELAY MODULE](https://ayatec.eu/introducing-the-esp12f-x4-relay-module/)

<img src="/images/X4_peripherals-1-1024x974.jpg" height="400px" title="X4 Relay Module Peripherals">   

### Connections

<img src="/images/IMG_20250311_135625.jpg" height="400px" title="Relay Connections">   

##### Relays
- RY1 - IO 15
- RY2 - IO 14
- RY3 - IO 12
- RY4 - IO 13

##### I2C Display And Sensors   
- SDA - IO 0
- SCL - IO 2

##### The name of the files
- tasmota-ESP12F-Relay-X4: 
    The board is ready for use
- -Display
    Display driver is available, a separate display must be configured via the console
- -Sensors
    Sensors are available, custom sensors must be configured via the console
- -SH1106
    The 1.3 inch OLED SH1106 Display I2C 128 x 64 is ready for use
- -SSD1306
    The 0,96 inch OLED SSD1306 Display I2C 128 x 64 is ready for use
- -BMP280-AHT20
    The combined Sensor BMP280/AHT20 is ready for use
- -DE
    Build in German

##### in the example a device with SSH1106 display and BMP280/AHT20 sensor
tasmota-ESP12F-Relay-X4-SSD1306-BMP280-AHT20-DE.bin

<img src="/images/2025-03-21_11-12-29.png" width="533px" title="Web View"> 

<img src="/images/IMG_20250320_180755.jpg" height="400px" title="Relay with Display and Sensors"> 

### 3D printed housing

[The template for the print comes from Thingiverse](https://www.thingiverse.com/thing:6432078)

I have adapted the case for the SH1106 display. This is for the newer - smaller - version of the display.

I haven't created a Thingiverse entry yet.

Only my files modified with MeshMixer are available here. The original files can be found at the link on Thingiverse.
[<img src="/3D-Print/AI3M_X4_Relay_Case_Top_Display_pgm.aw.png">](/3D-Print/X4_Relay_Case_Top_Display_pgm.stl)
