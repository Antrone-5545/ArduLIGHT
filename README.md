# Antrone - ArduLIGHT Project
The ArduLIGHT project allows you to control the Addressable Lighting with an Arduino via a COM port. With ArduLIGHT, you can set the color of each LED individually, or use and customize the built-in modes. ArduLIGHT is based on the FastLED library, which provides support for many different LED models. For convenient control of ArduLIGHT, I also write an application for Windows called Project ILLUMIX.
Attention: Projects are at an early stage of development! I will be very grateful for your help in the design and development of the project. Enjoy!
Project ILLUMIX: https://github.com/Antrone-5545/ProjectILLUMIX

# What can ArduLIGHT
After downloading ArduLIGHT to Arduino, you can control the Addressable Lighting using the COM port on your computer. To simplify this task, I wrote a Windows application called Project ILLUMIX. But if you would like to control ArduLIGHT manually you can read the documentation. )))
You can set the color for each LED separately (indicating its number and color) or use ready-made lighting effects such as Rainbow or Ping Pong, and also set their parameters.

# How to use (basic)
1)	Download any release of ArduLIGHT and extract all files to one folder.
2)	Open the ArduLIGHT.ino with Arduino IDE and change the values of the "LEDS" and "NUM_LEDS" variables to the number of LEDs in your strip. In the "PIN" variable, specify the pin to which you connect your LED strip.
3)	Download sketch to Arduino
4)	Connect the pins of your LED Strip to Arduino (V to 5v, D to selected Arduino pin, and G to GND)
5) Download Project ILLUMIX app to control ArduLIGHT.

# All Effects
1) Manual controll (Set color of LEDs individually)
2) Runing Light
3) Colour cycle
4) Rainbow
5) Twink
6) Ping-pong
