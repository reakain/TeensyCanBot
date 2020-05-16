# TeensyBot - Teensy 2.0 Can Robot
This is the source for a Teensy 2.0 two-wheel robot based on [this](https://www.thingiverse.com/thing:965449) 3D design, but using what I had available instead.

## Hardware
1. [Teensy 2.0 microcontroller board](https://www.pjrc.com/teensy/)
2. 2x [DC motors in servo motor body](https://www.adafruit.com/product/2941)
3. 1x [DC motor driver board](https://www.adafruit.com/product/2448) - Or build your own H-Bridge! I did that too as an exercise
4. 1x [IR sensor](https://www.adafruit.com/product/157)
5. 1x [Ultrasonic sensor](https://www.adafruit.com/product/4007)
6. 1x [Lil' power switch]()
7. 1x LiPo battery (I went with 1.75 Ah)
8. 1x [PowerBoost 1000C](https://www.adafruit.com/product/2465)
9. LG TV Remote, or modify the IR codes for your preferred remote.

## Program
You'll need the Arduino IDE, and of course the Teensy add on components. The only extra library required is the [Arduino IR Remote Library](https://www.arduinolibraries.info/libraries/i-rremote)

## Resources
1. [LG Remote IR Codes](https://gist.github.com/francis2110/8f69843dd57ae07dce80)