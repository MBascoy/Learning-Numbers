# Learning Numbers
This is a little educational game for kids (around 3-5 years old) to learn numbers and counting.

![example1](/images/example1.jpg)
![example2](/images/example2.jpg)
![example3](/images/example3.jpg)
![example4](/images/example4.jpg)
![example5](/images/example5.gif)

![3d design](/images/3d%20design.png)
![body front](/images/body%20front.jpg)
![body back](/images/body%20back.jpg)
![lit front](/images/lit%20front.jpg)
![lit back](/images/lit%20back.jpg)

## How to play
The game has 3 modes:
- Easy Mode
- Hard Mode
- Practice Mode

In **Easy Mode** the game displays a random number between 1 and 5, you have to use the two button rows on the bottom to turn on the lights to match the number diplayed (eg: if a 3 is shown you have to press 3 buttons to turn on 3 lights), after that you press "**OK**", if the result is correct you will see a "happy face" and a new number will be shown, if the result is incorrect you will see a "sad face" and you have to correct your answer and try it again.

**Hard Mode** is the same as easy but with numbers between 6 and 16.

In **Practice Mode** the game just show how many lights are on, so you can see which number relates to how many lights are on, (eg: if you turn on 2 lights the display will show you a 2), if you press "**OK**" the game will play an audio of the number that is displayed in the screen.

## How to build
You have to do 3 things:
- Make the 3D design
- Make the PCB (And solder all the components)
- Flash a microcontroller with the code

The components list is the following:

(All the components can be found in Aliexpress)

- 2x matrix led 8x8
- 1x Atmega168pa
- 5x 74HC595 chips
- 2x 74HC165 chips
- 16x 5mm Leds
- 1x 8Mhz crystal oscillator
- 33x 1K resistors
- 16x 10K resistors
- 1x 1Ohm resistor
- 2x 22pf smd capacitors
- 1x 100nf smd capacitor
- 1x 470uf electrolitic capacitor
- 17x SMD Push buttons 12mm
- 5x SMD Push buttons 6mm
- 1x ZIF socket 28pin narrow
- 1x Power switch
- 3x JST connector ph2.0
- 1x battery holder 4x AAA
- 2x Screw M2 inserts
- 4x M2 Screws
- 2x M2 Nuts
- 10x Screw M3 inserts
- 8x M3 Screws
- 1x DFPlayer mini
- 1x Speaker 3W 4Ohm PH2.0 terminal

For the **speaker** you need this specific model:

![Speaker](/images/speaker.png)

For the **power switch** you need this specific model:

![Power switch](/images/power%20switch.png)

You need to add a JST connector (PH 2.0) to the power switch and the battery holder, this is an image of the power switch with the PH 2.0 connector:

![Power switch with connector](/images/power%20switch%20with%20connector.png)

### Make the 3D design
Inside **3D design** folder you can find the 3 .stl files ready to print.

If you want to change the text (currently are on spanish), you can do it inside **global_constants.scad** file, after that you have to re-render **learning_numbers.scad** file with **openSCAD** and export the .stl file.

Once you have the 3D design printed you have to put the **screw inserts**:
- 4x M3 inserts for the lit
![inserts m3 body](/images/inserts%20m3%20body.png)
- 2x M3 inserts for battery lit
![inserts m3 battery](/images/inserts%20m3%20battery.png)
- 4x M3 inserts for the PCB
![inserts m3 pcb](/images/inserts%20m3%20pcb.png)
- 2x M2 inserts for the speaker
![inserts m2 speaker](/images/inserts%20m2%20speaker.png)

### Make the PCB
Inside **circuit/Learning_Numbers** folder you can find **Gerber.zip** file which has the PCB ready to be created using a your favorite provider. I've use [jlcpcb.com](https://jlcpcb.com).

When you have the PCB you need to solder the components.

Images of the PCB with no components:

![PCB front no components](/images/PCB%20front%20no%20components.png)
![PCB back no components](/images/PCB%20back%20no%20components.png)

Image of the final result with all the components:

![PCB front with components](/images/PCB%20front.png)
![PCB back with components](/images/PCB%20back.png)

### Flash code to microcontroller
The code is ready to flash with a **usbasp** programmer and an **ATMEGA168pa** microcontroller, you only have to go to the **code** folder and run `make flash` command, if you want to use other programmer or microcontroller (an ATMEGA328p for example) you have to update the **Makefile**.

**NOTE:** you have to enable the fuse to use the external crystal, use the following command (for usbasp programmer and atmega168pa microcontroller):
`avrdude -c usbasp -p m168pa -U lfuse:w:0x7F:m`

Once you have flashed the microcontroller just put it inside the ZIF socket on the PCB.

## Audio files
The game uses a **DFPlayer mini** module to play sounds, you need an micro-SD card to put inside the module, the micro-SD card must be formated with **FAT32** file system.

The files inside the micro-SD card must be the followings:

| File name  | Sound         |
| ---------- | ------------- |
| 001.mp3    | Zero          |
| 002.mp3    | One           |
| 003.mp3    | Two           |
| 004.mp3    | Three         |
| 005.mp3    | Four          |
| 006.mp3    | Five          |
| 007.mp3    | Six           |
| 008.mp3    | Seven         |
| 009.mp3    | Eight         |
| 010.mp3    | Nine          |
| 011.mp3    | Ten           |
| 012.mp3    | Eleven        |
| 013.mp3    | Twelve        |
| 014.mp3    | Thriteen      |
| 015.mp3    | Fourteen      |
| 016.mp3    | Fifteen       |
| 017.mp3    | Sixteen       |
| 018.mp3    | Title sound   |
| 019.mp3    | Easy mode     |
| 020.mp3    | Hard mode     |
| 021.mp3    | Practice mode |
| 022.mp3    | Success sound |
| 023.mp3    | Fail sound    |
| 024.mp3    | Volume Up     |
| 025.mp3    | Volume Down   |

You can find sample sounds inside the **audio samples** folder.

If you want to add your custom audios the mp3 files should have this parameters (it's not critical, but better for a good performance):

| Parameters | Value     |
| ---------- | --------- |
| Format     | mp3       |
| Channels   | Mono      |
| Samples    | 44100Hz   |
| Speed mode | Constant  |
| Quality    | 112kbps   |