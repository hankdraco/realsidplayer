# RealSIDPlayer

_Welcome to the new way of playing SID tunes_

## What Is This All About?

There are plenty of similar projects over the internet, where AVR's are used to control SID chip in any way to play the music. However, what do they all have in common is the way the SID registers are driven - in a very simplified way, there is an array of registers 'snapshots' prepared and each time frame these registers are updated with another 'snapshot' from an array.

The goal for me was to be able to play SID music by executing **the native code of 6502 processor**, just the same as it is when you listen to the SID tunes on your real C64. 

Check out the `/miscellaneous/` folder for some examples of how this prototype looks and sounds like.

## Prerequisites

You'll find the hardware-specific details in `/schematics/` folder. There's a KiCad project containing schematics sheet you might find quite helpful in building your own RealSIDPlayer prototype. However, if you're interested only in exploration how emulator works, then all you need is within the `/src/` folder.

### Hardware

Most of all, you will absolutely need the **ATxmega128A3U** uC, since all the code, memory management, use of onboard features etc. are done for this particular model. For more details look into `/docs/` folder, where among the others you'll find a diagram with all necessary elements the circuit is made of.

You will obviously need the SID chip too.

As for the parts not listed on schematics, it might be good to have a larger breadboard, bunch (or better two) of wires, three sources of stabilized power supply: 3.3V (host's logic), 5V (SID's logic) and 9V (both SID's audio output & preamp of line-out output).

As an interface between Atmel Studio and ATxmega128A3U I used the **AVR PROG MKII** programmer, mainly because it's simply convenient to use for me, but it's up to you and your preferences what to use to program your chip.

### Software

You need `KiCad` only in case you'd like to contribute in this project. If all what you want is just the connections diagram, there's a PNG file prepared in `/docs/` folder for you.

Install `Saleae Logic` to open two sample diagrams I grabbed from logic analyzer during tests (also in `/docs/` folder). You don't need that if you don't want to play with zooming in and out - there are PNG files prepared for you as well.

As for the IDE you will need `Atmel Studio 7.0` to run the whole project.

> **NOTE:** Once you're done with installing/setting up `Atmel Studio 7.0` you need to download `TMPx` from [turbo.style64.org](http://turbo.style64.org) and put `TMPx.exe` file into `/src/xmega/` folder. `TMPx` is a multiplatform cross-assembler for the 6502 CPU by STYLE. It's been used in the pre-build event of Atmel Studio IDE to compile C64's source code files.

> **NOTE #2:** As for now the **style64.org** site is down, so here's the [alternative way (from csdb.dk)](http://csdb.dk/release/?id=141431&show=summary) of getting the **TMPx** package.

> **PRO TIP:** In fact, you can use any 6502 cross-assembler you like. There is no problem to use any of your choice unless it supports Turbo Assembler's syntax. Otherwise you might want to consider adjusting the following two things:
> 1. The C64 sources in `/src/xmega/c64_code/` folder
> 1. Atmel Studio's pre-build event to refer to your tool instead of **TMPx**

#### Summary List of the Software You Need

* [Atmel Studio 7.0](http://www.atmel.com/microsite/atmel-studio/) - the IDE
* [TMPx](http://turbo.style64.org) - great cross-assembler for 6502 CPU by STYLE ([alternative download here](http://csdb.dk/release/?id=141431&show=summary))
* [KiCad](http://kicad-pcb.org/download/) - for its schematic editor (optional)
* [Saleae Logic](https://www.saleae.com/downloads) - to open the logic analyzer diagrams (optional)

## Getting Started

### First Run

Having prerequisites fulfilled, you're ready to go!

1. Assembly the circuit
2. **Before** placing your ATxmega128A3U into the circuit, program it first:
	- Open Atmel Studio
	- Build project
	- Program the microcontroller
3. Place ATxmega128A3U into the circuit
4. Check all connections once again
5. Turn the power on

If you connected everything correctly, you should be able to hear music (remember to plug your speakers's jack into the AUDIO OUT connector).

### Choosing other zaks to play

You can select between several included zaks. 

In order to do that:

1. Edit the `/src/xmega/c64_resources.inc` file. You will find set of `#define` directives, similar to these:

	``` asm
		//#define _silence_

	/* 1 time per frame */
		#define zak1
		//#define zak2
		//#define zak3
	```

1. Comment the uncommented line and uncomment another one, so there is still the only one uncommented `#define` directive. Example:

	``` asm
		//#define _silence_

	/* 1 time per frame */
		//#define zak1
		#define zak2
		//#define zak3
	```

1. Re-build project and program your uC. 

### Adding your own zaks

Refer to [/tools/TOOLS.md](tools/TOOLS.md) (**SID2ASM** section) for step-by-step instructions and more detailed informations.

## Memory Limitations

Due to the uC used, the application cannot handle zaks more than 0x1c00 bytes in size. This limitation is because of the memory size implemented in ATxmega128A3U (refer to [/docs/EMU.md](docs/EMU.md) file for more details).

## Todo

The actual shape of this project is the very basic one as this is just an early prototype or kind of proof-of-concept. It lacks of many features and cool functions and I'm not able to work on all of them alone efficiently. Please refer to [TODOS.md](TODOS.md) if you think you could help - your contribution is always warmly welcome.

## Authors

* **Łukasz Drzewiecki (Hank/Draco)** - *Initial work (concept, schematics, programming)*

See also the list of [contributors](https://github.com/hankdraco/realsidplayer/contributors) who participated in this project. I hope that soon it will not only me be listed there.

### Authors of Included Zaks

In alphabetical order:

* AMJ
* DAF
* Dane
* DRAX
* Glenn Rune Gallefoss
* Jeff
* Kristian Røstøen
* KB
* MHD
* Mitch&Dane
* Orcan
* PRI
* Red Devil
* Shogoon
* Vincenzo
* Wayne

and me.

Yes, I know these are quite old nowadays. But I still like them! :)

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details.

## Interesting Readings & Other Stuff

During the work on this project I gathered a small collection of interesting readings and specs regarding various topics. Below is the list of few more valuable positions that might come in handy if you're about to do your own research:

1. [unusedino.de](http://unusedino.de/ec64/index.html) - datasheets and schematics of the C64 hardware (and more)
1. [6502.org](http://6502.org/) - the 6502 microprocessor resource
1. [Using the MOS 6581 SID chip](http://www.deblauweschicht.nl/tinkering/mos6581_1.html) - interesting reading :)
1. [Visual Guide to 65xx CPU Timing](http://laughtonelectronics.com/Arcana/Visualizing%2065xx%20Timing/Visualizing%2065xx%20CPU%20Timing.html) - good article with cool animations
1. [Tests for all valid opcodes of the 6502 and 65C02 processor](https://github.com/Klaus2m5/6502_65C02_functional_tests) - outstanding and reliable set of tests if you develop 6502 CPU emulator and want to test if it works
1. ["Tick Tock, know your Clock!"](http://dustlayer.com/c64-architecture/2013/5/7/hardware-basics-part-1-tick-tock-know-your-clock) - totally awesome article explaining the whole clock-magic of the C64. Very well written and very informative
1. [AVR Assembler](http://www.atmel.com/webdoc/avrassembler/index.html) - AVR assembler docs