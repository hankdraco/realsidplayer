EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:c64
LIBS:realsidplayer-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "RealSIDPlayer"
Date "2017-07-26"
Rev "1 - PAL"
Comp "Łukasz 'Hank' Drzewiecki"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L ATXMEGA128A3U-AU U1
U 1 1 595BE0C8
P 6700 2400
F 0 "U1" H 5850 4000 50  0000 L BNN
F 1 "ATXMEGA128A3U-AU" H 7050 700 50  0000 L BNN
F 2 "TQFP64" H 6700 2400 50  0001 C CIN
F 3 "" H 6700 2400 50  0001 C CNN
	1    6700 2400
	0    -1   -1   0   
$EndComp
$Comp
L CSG8580R5 U2
U 1 1 595BF7E1
P 2350 5000
F 0 "U2" H 1950 5800 60  0000 C CNN
F 1 "CSG8580R5" V 2350 4950 60  0000 C CNB
F 2 "CSG8580R5" H 2500 4200 60  0001 C CNN
F 3 "" H 2650 4600 60  0001 C CNN
	1    2350 5000
	0    1    1    0   
$EndComp
$Comp
L LvlConv U3
U 1 1 595BFF18
P 2250 6700
F 0 "U3" H 2050 7100 60  0000 C CNN
F 1 "LvlConv" H 2300 6300 60  0000 C CNN
F 2 "" H 2250 6700 60  0001 C CNN
F 3 "" H 2250 6700 60  0001 C CNN
	1    2250 6700
	0    1    1    0   
$EndComp
$Comp
L LvlConv U4
U 1 1 595C02F7
P 2050 3050
F 0 "U4" H 1850 3450 60  0000 C CNN
F 1 "LvlConv" H 2100 2650 60  0000 C CNN
F 2 "" H 2050 3050 60  0001 C CNN
F 3 "" H 2050 3050 60  0001 C CNN
	1    2050 3050
	0    1    -1   0   
$EndComp
$Comp
L LvlConv U5
U 1 1 595C0341
P 1350 6500
F 0 "U5" H 1150 6900 60  0000 C CNN
F 1 "LvlConv" H 1400 6100 60  0000 C CNN
F 2 "" H 1350 6500 60  0001 C CNN
F 3 "" H 1350 6500 60  0001 C CNN
	1    1350 6500
	0    1    1    0   
$EndComp
$Comp
L LvlConv U6
U 1 1 595C0380
P 2950 3050
F 0 "U6" H 2750 3450 60  0000 C CNN
F 1 "LvlConv" H 3000 2650 60  0000 C CNN
F 2 "" H 2950 3050 60  0001 C CNN
F 3 "" H 2950 3050 60  0001 C CNN
	1    2950 3050
	0    1    -1   0   
$EndComp
$Comp
L C C1
U 1 1 595C0C9A
P 3000 4200
F 0 "C1" H 3025 4300 50  0000 L CNN
F 1 "22nF" H 3025 4100 50  0000 L CNN
F 2 "" H 3038 4050 50  0001 C CNN
F 3 "" H 3000 4200 50  0001 C CNN
	1    3000 4200
	1    0    0    -1  
$EndComp
$Comp
L C C2
U 1 1 595C0D2A
P 2800 4200
F 0 "C2" H 2825 4300 50  0000 L CNN
F 1 "22nF" H 2825 4100 50  0000 L CNN
F 2 "" H 2838 4050 50  0001 C CNN
F 3 "" H 2800 4200 50  0001 C CNN
	1    2800 4200
	1    0    0    -1  
$EndComp
$Comp
L Crystal Y1
U 1 1 595C0D50
P 6300 4500
F 0 "Y1" H 6300 4650 50  0000 C CNN
F 1 "17.734475 MHz" H 6300 4350 50  0000 C CNN
F 2 "" H 6300 4500 50  0001 C CNN
F 3 "" H 6300 4500 50  0001 C CNN
	1    6300 4500
	0    1    1    0   
$EndComp
$Comp
L CSG8701 U7
U 1 1 595C4902
P 5250 4550
F 0 "U7" H 4900 5000 60  0000 C CNN
F 1 "CSG8701" V 5250 4550 60  0000 C CNB
F 2 "" H 5250 4550 60  0001 C CNN
F 3 "" H 5250 4550 60  0001 C CNN
	1    5250 4550
	1    0    0    -1  
$EndComp
$Comp
L Ferrite_Bead FB1
U 1 1 595D574C
P 5100 3700
F 0 "FB1" V 4950 3725 50  0000 C CNN
F 1 "Ferrite_Bead" V 5250 3700 50  0001 C CNN
F 2 "" V 5030 3700 50  0001 C CNN
F 3 "" H 5100 3700 50  0001 C CNN
	1    5100 3700
	0    1    1    0   
$EndComp
$Comp
L C C7
U 1 1 595D59F8
P 6450 4950
F 0 "C7" H 6475 5050 50  0000 L CNN
F 1 "10nF" H 6475 4850 50  0000 L CNN
F 2 "" H 6488 4800 50  0001 C CNN
F 3 "" H 6450 4950 50  0001 C CNN
	1    6450 4950
	0    1    1    0   
$EndComp
$Comp
L C_Variable CT1
U 1 1 595D5E2E
P 6300 4000
F 0 "CT1" H 6325 3925 50  0000 L CNN
F 1 "7.7 - 40pF" H 6325 3850 50  0000 L CNN
F 2 "" H 6300 4000 50  0001 C CNN
F 3 "" H 6300 4000 50  0001 C CNN
	1    6300 4000
	1    0    0    -1  
$EndComp
$Comp
L R R4
U 1 1 595D6073
P 5550 3700
F 0 "R4" V 5630 3700 50  0000 C CNN
F 1 "1K" V 5550 3700 50  0000 C CNN
F 2 "" V 5480 3700 50  0001 C CNN
F 3 "" H 5550 3700 50  0001 C CNN
	1    5550 3700
	0    1    1    0   
$EndComp
$Comp
L C C3
U 1 1 595D9629
P 2950 6100
F 0 "C3" H 2975 6200 50  0000 L CNN
F 1 "10nF" H 2975 6000 50  0000 L CNN
F 2 "" H 2988 5950 50  0001 C CNN
F 3 "" H 2950 6100 50  0001 C CNN
	1    2950 6100
	0    1    1    0   
$EndComp
$Comp
L R R1
U 1 1 595D9682
P 3100 6450
F 0 "R1" V 3180 6450 50  0000 C CNN
F 1 "5k6" V 3100 6450 50  0000 C CNN
F 2 "" V 3030 6450 50  0001 C CNN
F 3 "" H 3100 6450 50  0001 C CNN
	1    3100 6450
	-1   0    0    1   
$EndComp
Wire Wire Line
	8150 6450 8150 3400
Wire Wire Line
	6850 6450 8150 6450
Wire Wire Line
	6850 7600 6850 6450
Wire Wire Line
	2300 7600 6850 7600
Wire Wire Line
	2300 7150 2300 7600
Wire Wire Line
	8050 3400 8050 6400
Wire Wire Line
	8050 6400 6800 6400
Wire Wire Line
	6800 6400 6800 7550
Wire Wire Line
	6800 7550 2200 7550
Wire Wire Line
	2200 7550 2200 7150
Wire Wire Line
	7950 6350 7950 3400
Wire Wire Line
	6750 6350 7950 6350
Wire Wire Line
	6750 7500 6750 6350
Wire Wire Line
	2100 7500 6750 7500
Wire Wire Line
	2100 7150 2100 7500
Wire Wire Line
	7850 3400 7850 6300
Wire Wire Line
	7850 6300 6700 6300
Wire Wire Line
	6700 6300 6700 7450
Wire Wire Line
	6700 7450 2000 7450
Wire Wire Line
	2000 7450 2000 7150
Wire Wire Line
	1400 7100 1400 6950
Wire Wire Line
	650  7100 1400 7100
Wire Wire Line
	650  650  650  7100
Wire Wire Line
	8150 650  650  650 
Wire Wire Line
	8150 1400 8150 650 
Wire Wire Line
	8050 700  8050 1400
Wire Wire Line
	700  700  8050 700 
Wire Wire Line
	700  7050 700  700 
Wire Wire Line
	1300 7050 700  7050
Wire Wire Line
	1300 6950 1300 7050
Wire Wire Line
	1200 7000 1200 6950
Wire Wire Line
	750  7000 1200 7000
Wire Wire Line
	750  750  750  7000
Wire Wire Line
	7950 750  750  750 
Wire Wire Line
	7950 1400 7950 750 
Wire Wire Line
	7850 800  7850 1400
Wire Wire Line
	800  800  7850 800 
Wire Wire Line
	800  6950 800  800 
Wire Wire Line
	1100 6950 800  6950
Wire Wire Line
	5700 1200 5700 1400
Wire Wire Line
	1800 1200 5700 1200
Wire Wire Line
	1800 2600 1800 1200
Wire Wire Line
	5600 1250 5600 1400
Wire Wire Line
	1900 1250 5600 1250
Wire Wire Line
	5500 1300 5500 1400
Wire Wire Line
	2000 1300 5500 1300
Wire Wire Line
	5400 1350 5400 1400
Wire Wire Line
	2100 1350 5400 1350
Wire Wire Line
	2700 1400 5300 1400
Wire Wire Line
	2700 2600 2700 1400
Wire Wire Line
	2100 1350 2100 2600
Wire Wire Line
	2000 1300 2000 2600
Wire Wire Line
	1900 1250 1900 2600
Wire Wire Line
	2700 3800 2700 3500
Wire Wire Line
	2200 3800 2700 3800
Wire Wire Line
	2800 3850 2800 3500
Wire Wire Line
	2300 3850 2800 3850
Wire Wire Line
	2900 3900 2900 3500
Wire Wire Line
	2500 3900 2900 3900
Wire Wire Line
	3000 3950 3000 3500
Wire Wire Line
	2600 3950 3000 3950
Wire Wire Line
	2600 4350 2600 3950
Wire Wire Line
	2500 4350 2500 3900
Wire Wire Line
	2300 4350 2300 3850
Wire Wire Line
	2200 4350 2200 3800
Wire Wire Line
	2100 4350 2100 3500
Wire Wire Line
	2000 4350 2000 3500
Wire Wire Line
	1900 4350 1900 3500
Wire Wire Line
	1800 4350 1800 3500
Wire Wire Line
	2300 5950 2300 6250
Wire Wire Line
	2400 5950 2300 5950
Wire Wire Line
	2400 5600 2400 5950
Wire Wire Line
	2200 5900 2200 6250
Wire Wire Line
	2300 5900 2200 5900
Wire Wire Line
	2300 5600 2300 5900
Wire Wire Line
	2100 5850 2100 6250
Wire Wire Line
	2200 5850 2100 5850
Wire Wire Line
	2200 5600 2200 5850
Wire Wire Line
	2000 5800 2000 6250
Wire Wire Line
	2100 5800 2000 5800
Wire Wire Line
	2100 5600 2100 5800
Wire Wire Line
	1400 5750 1400 6050
Wire Wire Line
	2000 5750 1400 5750
Wire Wire Line
	2000 5600 2000 5750
Wire Wire Line
	1300 5700 1300 6050
Wire Wire Line
	1900 5700 1300 5700
Wire Wire Line
	1900 5600 1900 5700
Wire Wire Line
	1200 5650 1200 6050
Wire Wire Line
	1800 5650 1200 5650
Wire Wire Line
	1800 5600 1800 5650
Wire Wire Line
	1100 5600 1100 6050
Wire Wire Line
	1700 5600 1100 5600
Wire Wire Line
	2700 4050 2800 4050
Wire Wire Line
	2700 4350 2700 4050
Wire Wire Line
	2900 4050 3000 4050
Wire Wire Line
	2900 4350 2900 4050
Wire Wire Line
	2800 6100 2800 5600
Wire Wire Line
	6300 3850 6600 3850
Connection ~ 6300 4350
Wire Wire Line
	6300 4350 6300 4150
Connection ~ 6000 4950
Wire Wire Line
	6000 4950 6000 5050
Wire Wire Line
	5850 4950 6000 4950
Wire Wire Line
	6000 4950 6300 4950
Connection ~ 6600 4750
Wire Wire Line
	5950 4750 6600 4750
Wire Wire Line
	6600 4750 6750 4750
Wire Wire Line
	5950 4650 5950 4750
Wire Wire Line
	5850 4650 5950 4650
Wire Wire Line
	5950 4250 6600 4250
Wire Wire Line
	5950 4350 5950 4250
Wire Wire Line
	5850 4350 5950 4350
Wire Wire Line
	6600 4250 6600 4750
Wire Wire Line
	6600 4750 6600 4950
Wire Wire Line
	6050 4650 6300 4650
Wire Wire Line
	6050 4550 6050 4650
Wire Wire Line
	5850 4550 6050 4550
Wire Wire Line
	6050 4350 6300 4350
Wire Wire Line
	6050 4450 6050 4350
Wire Wire Line
	5850 4450 6050 4450
Wire Wire Line
	7600 5300 3900 5300
Wire Wire Line
	3900 5300 3900 1950
Wire Wire Line
	3900 1950 2800 1950
Wire Wire Line
	2800 1950 2800 2600
Wire Wire Line
	3100 6100 3100 6300
Wire Wire Line
	4650 4750 4300 4750
Wire Wire Line
	4300 4750 4300 3700
Wire Wire Line
	4300 3700 4950 3700
Wire Wire Line
	5250 3700 5400 3700
Wire Wire Line
	5700 3700 6000 3700
Wire Wire Line
	6000 3700 6000 3400
Wire Wire Line
	2900 5600 2900 5850
Wire Wire Line
	2900 5850 3550 5850
$Comp
L R R2
U 1 1 595FF53C
P 3700 5850
F 0 "R2" V 3780 5850 50  0000 C CNN
F 1 "10k" V 3700 5850 50  0000 C CNN
F 2 "" V 3630 5850 50  0001 C CNN
F 3 "" H 3700 5850 50  0001 C CNN
	1    3700 5850
	0    1    1    0   
$EndComp
$Comp
L C C4
U 1 1 595FF5A4
P 3950 6150
F 0 "C4" H 3975 6250 50  0000 L CNN
F 1 "1000pF" H 3975 6050 50  0000 L CNN
F 2 "" H 3988 6000 50  0001 C CNN
F 3 "" H 3950 6150 50  0001 C CNN
	1    3950 6150
	-1   0    0    1   
$EndComp
$Comp
L C C5
U 1 1 595FF669
P 4800 6050
F 0 "C5" H 4825 6150 50  0000 L CNN
F 1 "470pF" H 4825 5950 50  0000 L CNN
F 2 "" H 4838 5900 50  0001 C CNN
F 3 "" H 4800 6050 50  0001 C CNN
	1    4800 6050
	0    1    1    0   
$EndComp
$Comp
L Q_NPN_BCE Q1
U 1 1 595FF6D5
P 5050 5850
F 0 "Q1" H 5250 5900 50  0000 L CNN
F 1 "2SC1815" H 5250 5800 50  0000 L CNN
F 2 "" H 5250 5950 50  0001 C CNN
F 3 "" H 5050 5850 50  0001 C CNN
	1    5050 5850
	1    0    0    -1  
$EndComp
Wire Wire Line
	5150 5650 5300 5650
Wire Wire Line
	4950 6050 5150 6050
Wire Wire Line
	5150 6050 5500 6050
Wire Wire Line
	3850 5850 3950 5850
Wire Wire Line
	3950 5850 4650 5850
Wire Wire Line
	4650 5850 4850 5850
Wire Wire Line
	4650 6050 4650 5850
Connection ~ 4650 5850
Wire Wire Line
	3950 6000 3950 5850
Connection ~ 3950 5850
$Comp
L R R3
U 1 1 595FFAF8
P 5150 6300
F 0 "R3" V 5230 6300 50  0000 C CNN
F 1 "1k" V 5150 6300 50  0000 C CNN
F 2 "" V 5080 6300 50  0001 C CNN
F 3 "" H 5150 6300 50  0001 C CNN
	1    5150 6300
	-1   0    0    1   
$EndComp
Connection ~ 5150 6050
$Comp
L CP C6
U 1 1 595FFD03
P 5500 6200
F 0 "C6" H 5525 6300 50  0000 L CNN
F 1 "10uF" H 5525 6100 50  0000 L CNN
F 2 "" H 5538 6050 50  0001 C CNN
F 3 "" H 5500 6200 50  0001 C CNN
	1    5500 6200
	1    0    0    -1  
$EndComp
Wire Wire Line
	5150 6050 5150 6150
Wire Wire Line
	3950 6300 3950 6400
Wire Wire Line
	3100 6700 3100 6600
Wire Wire Line
	5150 6450 5150 6900
Wire Wire Line
	5150 6900 5150 7050
Wire Wire Line
	5500 6350 5500 6650
Wire Wire Line
	5500 6650 5500 6750
$Comp
L JACK_2P J1
U 1 1 59603885
P 5950 6750
F 0 "J1" H 5600 6550 50  0000 C CNN
F 1 "AUDIO LINE-OUT" H 5800 7000 50  0000 C CNN
F 2 "" H 5950 6750 50  0001 C CNN
F 3 "" H 5950 6750 50  0001 C CNN
	1    5950 6750
	-1   0    0    1   
$EndComp
Connection ~ 5150 6900
Wire Wire Line
	5500 6900 5150 6900
Connection ~ 5500 6650
Wire Wire Line
	3000 5600 3100 5600
$Comp
L GND #PWR01
U 1 1 59604A2C
P 2200 2600
F 0 "#PWR01" H 2200 2350 50  0001 C CNN
F 1 "GND" H 2200 2450 50  0000 C CNN
F 2 "" H 2200 2600 50  0001 C CNN
F 3 "" H 2200 2600 50  0001 C CNN
	1    2200 2600
	-1   0    0    1   
$EndComp
$Comp
L GND #PWR02
U 1 1 59604AB4
P 3100 2600
F 0 "#PWR02" H 3100 2350 50  0001 C CNN
F 1 "GND" H 3100 2450 50  0000 C CNN
F 2 "" H 3100 2600 50  0001 C CNN
F 3 "" H 3100 2600 50  0001 C CNN
	1    3100 2600
	-1   0    0    1   
$EndComp
$Comp
L GND #PWR03
U 1 1 59604F59
P 2200 3500
F 0 "#PWR03" H 2200 3250 50  0001 C CNN
F 1 "GND" H 2200 3350 50  0000 C CNN
F 2 "" H 2200 3500 50  0001 C CNN
F 3 "" H 2200 3500 50  0001 C CNN
	1    2200 3500
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR04
U 1 1 59604FB4
P 3100 3500
F 0 "#PWR04" H 3100 3250 50  0001 C CNN
F 1 "GND" H 3100 3350 50  0000 C CNN
F 2 "" H 3100 3500 50  0001 C CNN
F 3 "" H 3100 3500 50  0001 C CNN
	1    3100 3500
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR05
U 1 1 596052E6
P 2400 4350
F 0 "#PWR05" H 2400 4100 50  0001 C CNN
F 1 "GND" H 2400 4200 50  0000 C CNN
F 2 "" H 2400 4350 50  0001 C CNN
F 3 "" H 2400 4350 50  0001 C CNN
	1    2400 4350
	-1   0    0    1   
$EndComp
$Comp
L GND #PWR06
U 1 1 59605336
P 1700 4350
F 0 "#PWR06" H 1700 4100 50  0001 C CNN
F 1 "GND" H 1700 4200 50  0000 C CNN
F 2 "" H 1700 4350 50  0001 C CNN
F 3 "" H 1700 4350 50  0001 C CNN
	1    1700 4350
	-1   0    0    1   
$EndComp
$Comp
L GND #PWR07
U 1 1 59605388
P 6600 3850
F 0 "#PWR07" H 6600 3600 50  0001 C CNN
F 1 "GND" H 6600 3700 50  0000 C CNN
F 2 "" H 6600 3850 50  0001 C CNN
F 3 "" H 6600 3850 50  0001 C CNN
	1    6600 3850
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR08
U 1 1 596053E1
P 6000 5050
F 0 "#PWR08" H 6000 4800 50  0001 C CNN
F 1 "GND" H 6000 4900 50  0000 C CNN
F 2 "" H 6000 5050 50  0001 C CNN
F 3 "" H 6000 5050 50  0001 C CNN
	1    6000 5050
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR09
U 1 1 5960543C
P 4500 4850
F 0 "#PWR09" H 4500 4600 50  0001 C CNN
F 1 "GND" H 4500 4700 50  0000 C CNN
F 2 "" H 4500 4850 50  0001 C CNN
F 3 "" H 4500 4850 50  0001 C CNN
	1    4500 4850
	1    0    0    -1  
$EndComp
Wire Wire Line
	4500 4850 4650 4850
$Comp
L GND #PWR010
U 1 1 5960561B
P 4500 4550
F 0 "#PWR010" H 4500 4300 50  0001 C CNN
F 1 "GND" H 4500 4400 50  0000 C CNN
F 2 "" H 4500 4550 50  0001 C CNN
F 3 "" H 4500 4550 50  0001 C CNN
	1    4500 4550
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR011
U 1 1 5960566B
P 4500 4350
F 0 "#PWR011" H 4500 4100 50  0001 C CNN
F 1 "GND" H 4500 4200 50  0000 C CNN
F 2 "" H 4500 4350 50  0001 C CNN
F 3 "" H 4500 4350 50  0001 C CNN
	1    4500 4350
	1    0    0    -1  
$EndComp
Wire Wire Line
	4500 4350 4650 4350
Wire Wire Line
	4500 4550 4650 4550
$Comp
L GND #PWR012
U 1 1 59605AB5
P 1500 6050
F 0 "#PWR012" H 1500 5800 50  0001 C CNN
F 1 "GND" H 1500 5900 50  0000 C CNN
F 2 "" H 1500 6050 50  0001 C CNN
F 3 "" H 1500 6050 50  0001 C CNN
	1    1500 6050
	-1   0    0    1   
$EndComp
$Comp
L GND #PWR013
U 1 1 59605B4E
P 2400 6250
F 0 "#PWR013" H 2400 6000 50  0001 C CNN
F 1 "GND" H 2400 6100 50  0000 C CNN
F 2 "" H 2400 6250 50  0001 C CNN
F 3 "" H 2400 6250 50  0001 C CNN
	1    2400 6250
	-1   0    0    1   
$EndComp
$Comp
L GND #PWR014
U 1 1 59605CC9
P 5150 7050
F 0 "#PWR014" H 5150 6800 50  0001 C CNN
F 1 "GND" H 5150 6900 50  0000 C CNN
F 2 "" H 5150 7050 50  0001 C CNN
F 3 "" H 5150 7050 50  0001 C CNN
	1    5150 7050
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR015
U 1 1 59605D30
P 3950 6400
F 0 "#PWR015" H 3950 6150 50  0001 C CNN
F 1 "GND" H 3950 6250 50  0000 C CNN
F 2 "" H 3950 6400 50  0001 C CNN
F 3 "" H 3950 6400 50  0001 C CNN
	1    3950 6400
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR016
U 1 1 59605D97
P 3100 6700
F 0 "#PWR016" H 3100 6450 50  0001 C CNN
F 1 "GND" H 3100 6550 50  0000 C CNN
F 2 "" H 3100 6700 50  0001 C CNN
F 3 "" H 3100 6700 50  0001 C CNN
	1    3100 6700
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR017
U 1 1 59605E00
P 2400 7150
F 0 "#PWR017" H 2400 6900 50  0001 C CNN
F 1 "GND" H 2400 7000 50  0000 C CNN
F 2 "" H 2400 7150 50  0001 C CNN
F 3 "" H 2400 7150 50  0001 C CNN
	1    2400 7150
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR018
U 1 1 59605F9F
P 1500 6950
F 0 "#PWR018" H 1500 6700 50  0001 C CNN
F 1 "GND" H 1500 6800 50  0000 C CNN
F 2 "" H 1500 6950 50  0001 C CNN
F 3 "" H 1500 6950 50  0001 C CNN
	1    1500 6950
	1    0    0    -1  
$EndComp
$Comp
L +3V3 #PWR019
U 1 1 596081A6
P 5000 2550
F 0 "#PWR019" H 5000 2400 50  0001 C CNN
F 1 "+3V3" H 5000 2690 50  0000 C CNN
F 2 "" H 5000 2550 50  0001 C CNN
F 3 "" H 5000 2550 50  0001 C CNN
	1    5000 2550
	0    -1   -1   0   
$EndComp
$Comp
L +3V3 #PWR020
U 1 1 59608269
P 3200 2600
F 0 "#PWR020" H 3200 2450 50  0001 C CNN
F 1 "+3V3" H 3200 2740 50  0000 C CNN
F 2 "" H 3200 2600 50  0001 C CNN
F 3 "" H 3200 2600 50  0001 C CNN
	1    3200 2600
	0    1    1    0   
$EndComp
$Comp
L +3V3 #PWR021
U 1 1 596082C4
P 2300 2600
F 0 "#PWR021" H 2300 2450 50  0001 C CNN
F 1 "+3V3" H 2300 2740 50  0000 C CNN
F 2 "" H 2300 2600 50  0001 C CNN
F 3 "" H 2300 2600 50  0001 C CNN
	1    2300 2600
	0    1    1    0   
$EndComp
$Comp
L +3V3 #PWR022
U 1 1 596084A6
P 2500 7150
F 0 "#PWR022" H 2500 7000 50  0001 C CNN
F 1 "+3V3" H 2500 7290 50  0000 C CNN
F 2 "" H 2500 7150 50  0001 C CNN
F 3 "" H 2500 7150 50  0001 C CNN
	1    2500 7150
	0    1    1    0   
$EndComp
$Comp
L +3V3 #PWR023
U 1 1 59608501
P 1600 6950
F 0 "#PWR023" H 1600 6800 50  0001 C CNN
F 1 "+3V3" H 1600 7090 50  0000 C CNN
F 2 "" H 1600 6950 50  0001 C CNN
F 3 "" H 1600 6950 50  0001 C CNN
	1    1600 6950
	0    1    1    0   
$EndComp
$Comp
L +9V #PWR024
U 1 1 596089E1
P 3100 5600
F 0 "#PWR024" H 3100 5450 50  0001 C CNN
F 1 "+9V" H 3100 5740 50  0000 C CNN
F 2 "" H 3100 5600 50  0001 C CNN
F 3 "" H 3100 5600 50  0001 C CNN
	1    3100 5600
	0    1    1    0   
$EndComp
$Comp
L +9V #PWR025
U 1 1 59608A3A
P 5300 5650
F 0 "#PWR025" H 5300 5500 50  0001 C CNN
F 1 "+9V" H 5300 5790 50  0000 C CNN
F 2 "" H 5300 5650 50  0001 C CNN
F 3 "" H 5300 5650 50  0001 C CNN
	1    5300 5650
	0    1    1    0   
$EndComp
$Comp
L +5V #PWR026
U 1 1 59608D8C
P 2700 5600
F 0 "#PWR026" H 2700 5450 50  0001 C CNN
F 1 "+5V" H 2700 5740 50  0000 C CNN
F 2 "" H 2700 5600 50  0001 C CNN
F 3 "" H 2700 5600 50  0001 C CNN
	1    2700 5600
	-1   0    0    1   
$EndComp
$Comp
L +5V #PWR027
U 1 1 59608F58
P 2300 3500
F 0 "#PWR027" H 2300 3350 50  0001 C CNN
F 1 "+5V" H 2300 3640 50  0000 C CNN
F 2 "" H 2300 3500 50  0001 C CNN
F 3 "" H 2300 3500 50  0001 C CNN
	1    2300 3500
	0    1    1    0   
$EndComp
$Comp
L +5V #PWR028
U 1 1 59608FB4
P 3200 3500
F 0 "#PWR028" H 3200 3350 50  0001 C CNN
F 1 "+5V" H 3200 3640 50  0000 C CNN
F 2 "" H 3200 3500 50  0001 C CNN
F 3 "" H 3200 3500 50  0001 C CNN
	1    3200 3500
	0    1    1    0   
$EndComp
$Comp
L +5V #PWR029
U 1 1 5960917F
P 2500 6250
F 0 "#PWR029" H 2500 6100 50  0001 C CNN
F 1 "+5V" H 2500 6390 50  0000 C CNN
F 2 "" H 2500 6250 50  0001 C CNN
F 3 "" H 2500 6250 50  0001 C CNN
	1    2500 6250
	0    1    1    0   
$EndComp
$Comp
L +5V #PWR030
U 1 1 596091DA
P 1600 6050
F 0 "#PWR030" H 1600 5900 50  0001 C CNN
F 1 "+5V" H 1600 6190 50  0000 C CNN
F 2 "" H 1600 6050 50  0001 C CNN
F 3 "" H 1600 6050 50  0001 C CNN
	1    1600 6050
	0    1    1    0   
$EndComp
$Comp
L +5V #PWR031
U 1 1 59609564
P 6750 4750
F 0 "#PWR031" H 6750 4600 50  0001 C CNN
F 1 "+5V" H 6750 4890 50  0000 C CNN
F 2 "" H 6750 4750 50  0001 C CNN
F 3 "" H 6750 4750 50  0001 C CNN
	1    6750 4750
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR032
U 1 1 5960A0EC
P 9450 6100
F 0 "#PWR032" H 9450 5850 50  0001 C CNN
F 1 "GND" H 9450 5950 50  0000 C CNN
F 2 "" H 9450 6100 50  0001 C CNN
F 3 "" H 9450 6100 50  0001 C CNN
	1    9450 6100
	1    0    0    -1  
$EndComp
$Comp
L +9V #PWR033
U 1 1 5960A12E
P 9900 6100
F 0 "#PWR033" H 9900 5950 50  0001 C CNN
F 1 "+9V" H 9900 6240 50  0000 C CNN
F 2 "" H 9900 6100 50  0001 C CNN
F 3 "" H 9900 6100 50  0001 C CNN
	1    9900 6100
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR034
U 1 1 5960A170
P 10350 6100
F 0 "#PWR034" H 10350 5950 50  0001 C CNN
F 1 "+5V" H 10350 6240 50  0000 C CNN
F 2 "" H 10350 6100 50  0001 C CNN
F 3 "" H 10350 6100 50  0001 C CNN
	1    10350 6100
	1    0    0    -1  
$EndComp
$Comp
L +3V3 #PWR035
U 1 1 5960A1B2
P 10800 6100
F 0 "#PWR035" H 10800 5950 50  0001 C CNN
F 1 "+3V3" H 10800 6240 50  0000 C CNN
F 2 "" H 10800 6100 50  0001 C CNN
F 3 "" H 10800 6100 50  0001 C CNN
	1    10800 6100
	1    0    0    -1  
$EndComp
$Comp
L PWR_FLAG #FLG036
U 1 1 5960A1F4
P 9450 6100
F 0 "#FLG036" H 9450 6175 50  0001 C CNN
F 1 "PWR_FLAG" H 9450 6250 50  0000 C CNN
F 2 "" H 9450 6100 50  0001 C CNN
F 3 "" H 9450 6100 50  0001 C CNN
	1    9450 6100
	1    0    0    -1  
$EndComp
$Comp
L PWR_FLAG #FLG037
U 1 1 5960A24B
P 9900 6100
F 0 "#FLG037" H 9900 6175 50  0001 C CNN
F 1 "PWR_FLAG" H 9900 6250 50  0000 C CNN
F 2 "" H 9900 6100 50  0001 C CNN
F 3 "" H 9900 6100 50  0001 C CNN
	1    9900 6100
	-1   0    0    1   
$EndComp
$Comp
L PWR_FLAG #FLG038
U 1 1 5960A29B
P 10350 6100
F 0 "#FLG038" H 10350 6175 50  0001 C CNN
F 1 "PWR_FLAG" H 10350 6250 50  0000 C CNN
F 2 "" H 10350 6100 50  0001 C CNN
F 3 "" H 10350 6100 50  0001 C CNN
	1    10350 6100
	-1   0    0    1   
$EndComp
$Comp
L PWR_FLAG #FLG039
U 1 1 5960A330
P 10800 6100
F 0 "#FLG039" H 10800 6175 50  0001 C CNN
F 1 "PWR_FLAG" H 10800 6250 50  0000 C CNN
F 2 "" H 10800 6100 50  0001 C CNN
F 3 "" H 10800 6100 50  0001 C CNN
	1    10800 6100
	-1   0    0    1   
$EndComp
Wire Wire Line
	2900 2600 2900 2000
Wire Wire Line
	2900 2000 3850 2000
Wire Wire Line
	3850 2000 3850 5350
Wire Wire Line
	3850 5350 7000 5350
Wire Wire Line
	7600 5300 7600 3400
Wire Wire Line
	7000 5350 7000 3400
Wire Wire Line
	7400 3400 7400 5400
Wire Wire Line
	7400 5400 3800 5400
Wire Wire Line
	3800 5400 3800 2050
Wire Wire Line
	3800 2050 3000 2050
Wire Wire Line
	3000 2050 3000 2600
Wire Notes Line
	3400 7300 3400 5550
Wire Notes Line
	3400 5550 6550 5550
Wire Notes Line
	6550 5550 6550 7300
Wire Notes Line
	6550 7300 3400 7300
$EndSCHEMATC
