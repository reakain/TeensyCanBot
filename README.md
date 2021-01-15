# TeensyCanBot - Teensy 2.0 Can Robot
This is the source for a Teensy 2.0 two-wheel robot based on [this](https://www.thingiverse.com/thing:965449) 3D design, with my own [modified wheels](https://www.thingiverse.com/thing:4307878), but using the electronics I had on hand, and nearly completely rewriting the source code.

So, may I introduce Sports! They look like a tiny tennis ball tube, and are probably less useful.

![Sports!](https://github.com/reakain/TeensyCanBot/raw/master/images/Sports.jpg "Hello, I am Sports!")

## [Video](https://youtu.be/gd8FmKdmDJA)

## Hardware
1. [Teensy 2.0 microcontroller board](https://www.pjrc.com/teensy/)
2. 2x [DC motors in servo motor body](https://www.adafruit.com/product/2941)
3. 1x [DC motor driver board](https://www.adafruit.com/product/2448) - Or build your own H-Bridge! I did that too as an exercise
4. 1x [IR sensor](https://www.adafruit.com/product/157)
5. 1x [Ultrasonic sensor](https://www.adafruit.com/product/4007)
6. 1x [Lil' slide switch](https://www.mouser.com/ProductDetail/611-OS202011MA0QN1) (Any switch with outer dimensions of ~4mm by ~8mm will fit nicely)
7. 1x LiPo battery (I went with 1.75 Ah)
8. 1x [PowerBoost 1000C](https://www.adafruit.com/product/2465)
9. LG TV Remote, or modify the defined IR codes in the TeensyBot.ino file for your remote.
10. 4x M2x8 self-tapping screws (For the body)
11. 2x M2x6 self-tapping screws (For the wheels)

## Wiring
The actual wiring is kind of a mess, and you want to route and think about your cables in terms of determining how you're going to fit everything into the casing, so as I was soldering it got progressively harder, because I was soldering all of my wires into pulling the components into a very tight ball.

Feel free to move where you put your logic pins. Some of mine were for ease of use, and some of them were because I was re-using an old old old Teensy where I had burned out some of the pins. (Namely pin 12 (D7) where I had first put my left motor PWM signal.) A sketch of the wiring is below.

![Circuit Schematic](https://github.com/reakain/TeensyCanBot/raw/master/images/Circuit.png "A drawing of the circuit for the bot.")

## Programming
You'll need the Arduino IDE, and of course the Teensy add on components. The only extra library required is the [Arduino IR Remote Library](https://www.arduinolibraries.info/libraries/i-rremote)

## Assembly
I wasn't able to get a lot of photos during assembly, as I don't have enough hands for that, but I do have some open top photos, and will discuss the assembly just a bit.

![Internals Top](https://github.com/reakain/TeensyCanBot/raw/master/images/Internals_1.jpg "The internals from top down")

The battery is in the back, which does make it unbalanced, causing the rocking motion when it travels. Tucked with the jst connector facing down behind the battery is the power boost board.

The two motors have slots to keep them in place, but nothing like that up top. This caused issues when trying to attach the wheels, as the motors would just rotate up rather than snapping in place. To counter this, I added the small piece of MDF between them, as it was what I had on hand. The motor driver board is on top, components pointed down, and rotated so the motor pins are above the motors.

Where's the Teensy, you ask? It's underneath the ultrasonic sensor (the eyes). It fit snuggly with the usb connector pointed to the left, when you're looking at the robot's eyes. This kept it close to power, and in a sort of central spot so all the sensors could be close-by.

![Internals Front](https://github.com/reakain/TeensyCanBot/raw/master/images/Internals_2.jpg "The internals from the front")

From this photo you can see that the motor control power is routed behind the ultrasonic sensor, and the control pins are routed around front and down to reach the Teensy. You can also see the IR sensor routed up from around the side of the ultrasonic sensor.

For final assembly, I recommend a power drill to screw in the body screws, and then by hand carefully screw in the two little wheel screws. Additional photos are below for people who like having visual information.

![Internals 3](https://github.com/reakain/TeensyCanBot/raw/master/images/Internals_3.jpg "The internals 3")

![Internals 4](https://github.com/reakain/TeensyCanBot/raw/master/images/Internals_4.jpg "The internals 4")

![Internals 5](https://github.com/reakain/TeensyCanBot/raw/master/images/Internals_5.jpg "The internals 5")

![Wheels 1](https://github.com/reakain/TeensyCanBot/raw/master/images/Wheels_1.jpg "Wheels 1")

![Wheels 2](https://github.com/reakain/TeensyCanBot/raw/master/images/Wheels_2.jpg "Wheels 2")

## Resources
1. [LG Remote IR Codes](https://gist.github.com/francis2110/8f69843dd57ae07dce80)