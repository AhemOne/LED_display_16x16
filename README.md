# 16x16-LED-display
LED display project for a generic 'maker' 16x16 LED module

# Description


# Software

## Library
Check out the [API](/API.md) page.

## Demo Project
An example program is included in this library which will accept data from the microcontroller's USB to serial interface.


# Hardware

## Parts
Part | Qty | Image
-|-|-
Arduino Leonardo or equivalent | 1 | ![Arduino Leonardo](Arduino.jpg)
USB Cable for above | 1 | ![Arduino Leonardo](USBCable.jpg)
16x16 LED Display module | 1 | ![LED Display](16x16Display.jpg)
Socket to Socket jumper leads | 4 | ![Socket to Socket jumper lead](SSJumper.jpg)
Pin to Socket jumper leads | 5 | ![Pin to Socket jumper lead](SPJumper.jpg)

### Useful Datasheets

Part | Description | Link
-|-|-
74HC595 | 8-Bit Shift RegistersWith3-StateOutput Registers | https://www.ti.com/lit/ds/scls041i/scls041i.pdf
74HC138 | High-Speed CMOS Logic 3-to-8 Line Decoder/ Demultiplexer | https://www.ti.com/lit/ds/schs147i/schs147i.pdf
ATmega16U4 | 8-bit Microcontroller with 16/32K bytes of ISP Flash and USB Controller | https://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-7766-8-bit-AVR-ATmega16U4-32U4_Datasheet.pdf

## Wiring

### Arduino

![Arduino Wiring](images/ArduinoWire.jpg)

Wire | Colour | Pin
-|-|-
1 | Red | ISCP-1
2 | Black| ISCP-2
3 | Grey | ISCP-3
4 | White | ISCP-4
5 | Purple | DIGITAL 7
6 | Blue | DIGITAL 8
7 | Green | DIGITAL 9
8 | Orange | DIGITAL 10
9 | Yellow | DIGITAL 11


### LED Display Board

![Display Wiring](images/DisplayWire.jpg)

Wire | Colour | Pin
-|-|-
1 | Red | +5V
2 | Black| GND/G
3 | Grey | CLK
4 | White | DI
5 | Purple | LAT
6 | Blue | A
7 | Green | B
8 | Orange | C
9 | Yellow | D


## Enclosure

![Enclosure](images/Enclosure.jpg)

### Case

![Case](images/Case.jpg)

#### Engineering Drawings
![CaseDrawing](images/CaseDrawing.jpg)
![CaseDrawing](images/CaseDrawingUS.jpg)

### Screen

![Screen](images/Screen.jpg)

#### Engineering Drawings
![ScreenDrawing](images/ScreenDrawing.jpg)
![ScreenDrawing](images/ScreenDrawingUS.jpg)
