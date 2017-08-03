# Clock Circuit

Generally clocking is a very broad subject, too large to cover it here. Instead, I will try to highlight two major concepts that some people I talked to about this project found difficult to distinguish.

## The Performance

I know that much depends on the emulator's code efficiency and this is the quite important factor, but in your opinion what do you think/feel/estimate: **how many times faster the uC has to be to carry emulation of 6502 opcodes in realtime?**

Try not to mix concepts - performance/efficiency has nothing to do with the frequency. Forget for a while about the frequency and focus just on performance. In other words, it doesn't matter how much time in micro seconds does it take the 6502 to execute the `NOP` opcode. What matters is how many **cycles** your host needs to emulate this **two-cycles** long `NOP`. 

**I came up with the result of 64 host's cycles per single 6502 CPU cycle.** It is just to be able to carry all the work load related to proccessing any 6502's opcode.

In order to understand what happens behind the scenes in emulator in terms of clock circuit, you need to know the proportion of 64 host's ticks to one 6502's tick.

## Frequency

The **ATxmega128A3U** uC is equipped with 32MHz internal oscillator onboard, but that doesn't mean it can't work at higher frequency. The Phase Locked Loop (PLL) built-in module is the key to boost the frequency up to 64MHz or even more than 80MHz. Refer to the **ATxmega128A3U**'s datasheet for more details. 

The PLL together with the ability of using external crystal as a clock source make us good to go for clocking SID exactly the same frequency as in the real C64. So now it comes time for appropriate clock source.

## Clock Circuit

I didn't want to give up accuracy of clocking SID with the exactly same frequency as it is clocked in its native environment of C64: **the 0.985 MHz**.

The problem is that it's quite hard to get such frequency, since it's quite uncommon. Therefore I reused the clock circuit of my broken C64's board, giving to some elements a second life. 

In the result, here is the final solution:

The crystal oscillator resonates with frequency of **17.734475 MHz** (PAL version). It feeds the **CSG8701** chip, which is kind of sophisticated frequency divider. From its DotClock pin the **7.88 MHz** signal is forwarded to ATxmega128A3U XTAL external clock input where in turn it is divided by 8. As a result the expected frequency of **0.985 MHz** is obtained.

Next, using PLL module this frequency is multiplied by 64 to comply performance requirements. 

Finally, the host is clocked with effective **63.04 MHz** which is exactly the goal (remind the 64:1 proportion).