# Tools

In this file you'll find detailed informations about external helper tools. 

## SID2ASM

This one is a tiny command line tool helper to convert zak's binary data from *.sid files into assembler source code include file. Then you can include such source code into the IDE, add another `#define` directive and play the zak.

### Usage

``` cmd
sid2asm sid_file.sid
```

Output will be

``` cmd
sid_file.sid.inc
```

which is a plain-text assembler include file. 

### How to Add Zaks

1. Choose the `.sid` file to convert (you'll find a great collection of those at [High Voltage SID Collection](http://www.hvsc.c64.org/))
1. Use `sid2asm` tool
1. Copy the output `.inc` file into `/src/xmega/zaks/` folder
1. Edit `/src/xmega/c64_resources.inc` file. There are 3 sections marked as "Edit and uncomment this block" - find them all and edit accordingly. I think the code is self explanatory

> **PRO TIP:** If you'd like to write a custom player, add new text file into `/src/xmega/c64_code/` folder and write Turbo Assembler compatible code in it. Don't forget to make the IDE 'see' your file by adding appropriate line in pre-build event in Atmel Studio.

### Remarks

In the current version only PSID v2 format is allowed. What's more, the `.sid` file can't be more than $1c00 bytes long and the load address must be at $1000. If load address is different, the conversion will succeed but music won't play anyway.