EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "Wally"
Date "2021-06-05"
Rev "v1.03"
Comp "www.2-0.dk"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Connector:HDMI_A J3
U 1 1 606EDAB2
P 6750 2150
F 0 "J3" H 7180 2196 50  0000 L CNN
F 1 "HDMI_A" H 7180 2105 50  0000 L CNN
F 2 "Connector_HDMI:HDMI_A_Contact_Technology_HDMI-19APL2_Horizontal" H 6775 2150 50  0001 C CNN
F 3 "https://en.wikipedia.org/wiki/HDMI" H 6775 2150 50  0001 C CNN
	1    6750 2150
	1    0    0    -1  
$EndComp
$Comp
L Connector:HDMI_A J2
U 1 1 606EEB51
P 4800 2150
F 0 "J2" H 5230 2196 50  0000 L CNN
F 1 "HDMI_A" H 5230 2105 50  0000 L CNN
F 2 "Connector_HDMI:HDMI_A_Contact_Technology_HDMI-19APL2_Horizontal" H 4825 2150 50  0001 C CNN
F 3 "https://en.wikipedia.org/wiki/HDMI" H 4825 2150 50  0001 C CNN
	1    4800 2150
	-1   0    0    -1  
$EndComp
Wire Wire Line
	5200 1350 6350 1350
Wire Wire Line
	5200 1450 6350 1450
Wire Wire Line
	5200 1550 6350 1550
Wire Wire Line
	5200 1650 6350 1650
Wire Wire Line
	5200 1750 6350 1750
Wire Wire Line
	5200 1850 6350 1850
Wire Wire Line
	5200 1950 6350 1950
Wire Wire Line
	5200 2050 6350 2050
$Comp
L power:GND #PWR012
U 1 1 606F5E0A
P 6550 3250
F 0 "#PWR012" H 6550 3000 50  0001 C CNN
F 1 "GND" V 6550 3050 50  0000 C CNN
F 2 "" H 6550 3250 50  0001 C CNN
F 3 "" H 6550 3250 50  0001 C CNN
	1    6550 3250
	1    0    0    -1  
$EndComp
Text GLabel 5400 2950 3    50   BiDi ~ 0
hdmi_5v
$Comp
L MCU_ST_STM32F0:STM32F042F6Px U1
U 1 1 60708BE7
P 5000 5650
F 0 "U1" H 5200 6300 50  0000 C CNN
F 1 "STM32F042F6Px" V 5000 5650 50  0000 C CNN
F 2 "Package_SO:TSSOP-20_4.4x6.5mm_P0.65mm" H 4500 4950 50  0001 R CNN
F 3 "http://www.st.com/st-web-ui/static/active/en/resource/technical/document/datasheet/DM00105814.pdf" H 5000 5650 50  0001 C CNN
	1    5000 5650
	1    0    0    -1  
$EndComp
$Comp
L Regulator_Linear:XC6206PxxxMR U2
U 1 1 6070BBC3
P 2300 6300
F 0 "U2" H 2300 6542 50  0000 C CNN
F 1 "XC6206PxxxMR" H 2300 6451 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 2300 6525 50  0001 C CIN
F 3 "https://www.torexsemi.com/file/xc6206/XC6206.pdf" H 2300 6300 50  0001 C CNN
	1    2300 6300
	1    0    0    -1  
$EndComp
$Comp
L Device:C C5
U 1 1 6070E4D7
P 2700 6450
F 0 "C5" H 2815 6496 50  0000 L CNN
F 1 "10u" H 2815 6405 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 2738 6300 50  0001 C CNN
F 3 "~" H 2700 6450 50  0001 C CNN
	1    2700 6450
	1    0    0    -1  
$EndComp
$Comp
L Device:C C4
U 1 1 6070ED53
P 1900 6450
F 0 "C4" H 1786 6404 50  0000 R CNN
F 1 "1u" H 1786 6495 50  0000 R CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 1938 6300 50  0001 C CNN
F 3 "~" H 1900 6450 50  0001 C CNN
	1    1900 6450
	1    0    0    1   
$EndComp
$Comp
L power:GND #PWR014
U 1 1 60710CCB
P 2300 6600
F 0 "#PWR014" H 2300 6350 50  0001 C CNN
F 1 "GND" H 2305 6427 50  0000 C CNN
F 2 "" H 2300 6600 50  0001 C CNN
F 3 "" H 2300 6600 50  0001 C CNN
	1    2300 6600
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR015
U 1 1 607112DD
P 2700 6600
F 0 "#PWR015" H 2700 6350 50  0001 C CNN
F 1 "GND" H 2705 6427 50  0000 C CNN
F 2 "" H 2700 6600 50  0001 C CNN
F 3 "" H 2700 6600 50  0001 C CNN
	1    2700 6600
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR013
U 1 1 6071171B
P 1900 6600
F 0 "#PWR013" H 1900 6350 50  0001 C CNN
F 1 "GND" H 1905 6427 50  0000 C CNN
F 2 "" H 1900 6600 50  0001 C CNN
F 3 "" H 1900 6600 50  0001 C CNN
	1    1900 6600
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR016
U 1 1 607122AA
P 3200 6300
F 0 "#PWR016" H 3200 6150 50  0001 C CNN
F 1 "+3.3V" V 3215 6428 50  0000 L CNN
F 2 "" H 3200 6300 50  0001 C CNN
F 3 "" H 3200 6300 50  0001 C CNN
	1    3200 6300
	0    1    1    0   
$EndComp
Connection ~ 2700 6300
Wire Wire Line
	2700 6300 2600 6300
Connection ~ 1900 6300
Wire Wire Line
	1900 6300 2000 6300
NoConn ~ 2550 2750
NoConn ~ 2550 2850
$Comp
L power:GND #PWR01
U 1 1 6071D799
P 1950 3150
F 0 "#PWR01" H 1950 2900 50  0001 C CNN
F 1 "GND" H 1955 2977 50  0000 C CNN
F 2 "" H 1950 3150 50  0001 C CNN
F 3 "" H 1950 3150 50  0001 C CNN
	1    1950 3150
	1    0    0    -1  
$EndComp
$Comp
L Device:R R1
U 1 1 6071F8EF
P 2800 1850
F 0 "R1" V 2700 1850 50  0000 C CNN
F 1 "5k1" V 2800 1850 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 2730 1850 50  0001 C CNN
F 3 "~" H 2800 1850 50  0001 C CNN
	1    2800 1850
	0    1    1    0   
$EndComp
$Comp
L Device:R R2
U 1 1 6072061B
P 2800 1950
F 0 "R2" V 2700 1950 50  0000 C CNN
F 1 "5k1" V 2800 1950 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 2730 1950 50  0001 C CNN
F 3 "~" H 2800 1950 50  0001 C CNN
	1    2800 1950
	0    1    -1   0   
$EndComp
$Comp
L power:GND #PWR02
U 1 1 60725337
P 2950 1850
F 0 "#PWR02" H 2950 1600 50  0001 C CNN
F 1 "GND" V 2955 1722 50  0000 R CNN
F 2 "" H 2950 1850 50  0001 C CNN
F 3 "" H 2950 1850 50  0001 C CNN
	1    2950 1850
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR03
U 1 1 6072607F
P 2950 1950
F 0 "#PWR03" H 2950 1700 50  0001 C CNN
F 1 "GND" V 2955 1822 50  0000 R CNN
F 2 "" H 2950 1950 50  0001 C CNN
F 3 "" H 2950 1950 50  0001 C CNN
	1    2950 1950
	0    -1   -1   0   
$EndComp
Wire Wire Line
	2550 1850 2650 1850
Wire Wire Line
	2550 1950 2650 1950
Text GLabel 3200 2350 2    50   BiDi ~ 0
usb_dp
Text GLabel 3200 2250 2    50   BiDi ~ 0
usb_dm
Wire Wire Line
	2550 2250 2650 2250
Wire Wire Line
	2550 2150 2650 2150
Wire Wire Line
	2650 2150 2650 2250
Connection ~ 2650 2250
Wire Wire Line
	2550 2350 2650 2350
Wire Wire Line
	2550 2450 2650 2450
Wire Wire Line
	2650 2450 2650 2350
Connection ~ 2650 2350
$Comp
L power:GND #PWR08
U 1 1 60732FC2
P 4800 6450
F 0 "#PWR08" H 4800 6200 50  0001 C CNN
F 1 "GND" H 4805 6277 50  0000 C CNN
F 2 "" H 4800 6450 50  0001 C CNN
F 3 "" H 4800 6450 50  0001 C CNN
	1    4800 6450
	1    0    0    -1  
$EndComp
$Comp
L Device:C C1
U 1 1 607360F9
P 4300 5300
F 0 "C1" H 4185 5254 50  0000 R CNN
F 1 "100n" H 4185 5345 50  0000 R CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 4338 5150 50  0001 C CNN
F 3 "~" H 4300 5300 50  0001 C CNN
	1    4300 5300
	1    0    0    1   
$EndComp
$Comp
L power:GND #PWR05
U 1 1 607377E7
P 4300 5450
F 0 "#PWR05" H 4300 5200 50  0001 C CNN
F 1 "GND" H 4305 5277 50  0000 C CNN
F 2 "" H 4300 5450 50  0001 C CNN
F 3 "" H 4300 5450 50  0001 C CNN
	1    4300 5450
	1    0    0    -1  
$EndComp
Wire Wire Line
	4400 5150 4300 5150
$Comp
L Device:C C2
U 1 1 6073B4E1
P 4600 4550
F 0 "C2" H 4485 4504 50  0000 R CNN
F 1 "100n" H 4485 4595 50  0000 R CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 4638 4400 50  0001 C CNN
F 3 "~" H 4600 4550 50  0001 C CNN
	1    4600 4550
	1    0    0    1   
$EndComp
$Comp
L power:GND #PWR07
U 1 1 6073BEF6
P 4600 4700
F 0 "#PWR07" H 4600 4450 50  0001 C CNN
F 1 "GND" H 4605 4527 50  0000 C CNN
F 2 "" H 4600 4700 50  0001 C CNN
F 3 "" H 4600 4700 50  0001 C CNN
	1    4600 4700
	1    0    0    -1  
$EndComp
$Comp
L Device:C C3
U 1 1 60747D46
P 5100 4550
F 0 "C3" H 4985 4504 50  0000 R CNN
F 1 "100n" H 4985 4595 50  0000 R CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 5138 4400 50  0001 C CNN
F 3 "~" H 5100 4550 50  0001 C CNN
	1    5100 4550
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR010
U 1 1 60747D4C
P 5100 4700
F 0 "#PWR010" H 5100 4450 50  0001 C CNN
F 1 "GND" H 5105 4527 50  0000 C CNN
F 2 "" H 5100 4700 50  0001 C CNN
F 3 "" H 5100 4700 50  0001 C CNN
	1    5100 4700
	-1   0    0    -1  
$EndComp
Wire Wire Line
	5100 4400 4900 4400
Wire Wire Line
	4900 4400 4900 4950
Wire Wire Line
	4800 4400 4600 4400
Wire Wire Line
	4800 4400 4800 4950
$Comp
L power:+3.3V #PWR06
U 1 1 6074B8F0
P 4600 4400
F 0 "#PWR06" H 4600 4250 50  0001 C CNN
F 1 "+3.3V" H 4615 4573 50  0000 C CNN
F 2 "" H 4600 4400 50  0001 C CNN
F 3 "" H 4600 4400 50  0001 C CNN
	1    4600 4400
	1    0    0    -1  
$EndComp
Connection ~ 4600 4400
Connection ~ 5100 4400
$Comp
L power:+3.3V #PWR09
U 1 1 6074D667
P 5100 4400
F 0 "#PWR09" H 5100 4250 50  0001 C CNN
F 1 "+3.3V" H 5115 4573 50  0000 C CNN
F 2 "" H 5100 4400 50  0001 C CNN
F 3 "" H 5100 4400 50  0001 C CNN
	1    5100 4400
	1    0    0    -1  
$EndComp
Text GLabel 5600 5350 2    50   Output ~ 0
uart_tx
Text GLabel 5600 5450 2    50   Input ~ 0
uart_rx
Text GLabel 4400 5950 0    50   BiDi ~ 0
hdmi_scl
Text GLabel 5600 5650 2    50   BiDi ~ 0
hdmi_cec_in
Text GLabel 5600 5950 2    50   BiDi ~ 0
usb_dm
Text GLabel 5600 6050 2    50   BiDi ~ 0
usb_dp
Text GLabel 5600 6150 2    50   BiDi ~ 0
swdio
Text GLabel 5600 6250 2    50   Input ~ 0
swclk
$Comp
L Device:R R3
U 1 1 6075D7E6
P 4300 6400
F 0 "R3" H 4200 6400 50  0000 C CNN
F 1 "100k" V 4300 6400 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 4230 6400 50  0001 C CNN
F 3 "~" H 4300 6400 50  0001 C CNN
	1    4300 6400
	-1   0    0    -1  
$EndComp
$Comp
L power:PWR_FLAG #FLG0101
U 1 1 60774177
P 2550 5650
F 0 "#FLG0101" H 2550 5725 50  0001 C CNN
F 1 "PWR_FLAG" H 2550 5823 50  0000 C CNN
F 2 "" H 2550 5650 50  0001 C CNN
F 3 "~" H 2550 5650 50  0001 C CNN
	1    2550 5650
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0101
U 1 1 607750C5
P 2550 5650
F 0 "#PWR0101" H 2550 5400 50  0001 C CNN
F 1 "GND" H 2555 5477 50  0000 C CNN
F 2 "" H 2550 5650 50  0001 C CNN
F 3 "" H 2550 5650 50  0001 C CNN
	1    2550 5650
	1    0    0    -1  
$EndComp
Text GLabel 2000 4400 2    50   Output ~ 0
uart_tx
Text GLabel 2000 4300 2    50   Input ~ 0
uart_rx
Text GLabel 2000 4000 2    50   BiDi ~ 0
swdio
Text GLabel 2000 4100 2    50   Input ~ 0
swclk
$Comp
L power:GND #PWR0103
U 1 1 6079224F
P 2000 3900
F 0 "#PWR0103" H 2000 3650 50  0001 C CNN
F 1 "GND" V 2005 3772 50  0000 R CNN
F 2 "" H 2000 3900 50  0001 C CNN
F 3 "" H 2000 3900 50  0001 C CNN
	1    2000 3900
	0    -1   1    0   
$EndComp
$Comp
L Device:R R14
U 1 1 607060DF
P 10450 2450
F 0 "R14" H 10520 2496 50  0000 L CNN
F 1 "27k" H 10520 2405 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 10380 2450 50  0001 C CNN
F 3 "~" H 10450 2450 50  0001 C CNN
	1    10450 2450
	1    0    0    -1  
$EndComp
$Comp
L Transistor_FET:AO3400A Q4
U 1 1 60706E37
P 10200 2550
F 0 "Q4" V 10449 2550 50  0000 C CNN
F 1 "AO3400A" V 10540 2550 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 10400 2475 50  0001 L CIN
F 3 "http://www.aosmd.com/pdfs/datasheet/AO3400A.pdf" H 10200 2550 50  0001 L CNN
	1    10200 2550
	0    -1   1    0   
$EndComp
$Comp
L power:+3.3V #PWR029
U 1 1 6070CF83
P 10200 2250
F 0 "#PWR029" H 10200 2100 50  0001 C CNN
F 1 "+3.3V" H 10215 2423 50  0000 C CNN
F 2 "" H 10200 2250 50  0001 C CNN
F 3 "" H 10200 2250 50  0001 C CNN
	1    10200 2250
	1    0    0    -1  
$EndComp
Text GLabel 10000 2650 0    50   BiDi ~ 0
hdmi_cec
Text GLabel 10500 2650 2    50   BiDi ~ 0
hdmi_cec_in
Text GLabel 5550 2950 3    50   BiDi ~ 0
hdmi_cec
Text GLabel 5700 2950 3    50   BiDi ~ 0
hdmi_scl
Text GLabel 5850 2950 3    50   BiDi ~ 0
hdmi_sda
Text GLabel 6000 2950 3    50   BiDi ~ 0
hdmi_utility
Text GLabel 6150 2950 3    50   BiDi ~ 0
hdmi_hpd
Wire Wire Line
	4800 950  4800 1050
Wire Wire Line
	4800 950  5400 950 
Wire Wire Line
	5200 2250 5550 2250
Wire Wire Line
	5200 2450 5700 2450
Wire Wire Line
	5200 2550 5850 2550
Wire Wire Line
	5200 2750 6000 2750
Wire Wire Line
	5200 2850 6150 2850
Wire Wire Line
	6750 1050 6750 950 
Wire Wire Line
	5400 2950 5400 950 
Connection ~ 5400 950 
Wire Wire Line
	5400 950  6750 950 
Wire Wire Line
	5550 2950 5550 2250
Connection ~ 5550 2250
Wire Wire Line
	5550 2250 6350 2250
Wire Wire Line
	5700 2950 5700 2450
Connection ~ 5700 2450
Wire Wire Line
	5700 2450 6350 2450
Wire Wire Line
	5850 2950 5850 2550
Connection ~ 5850 2550
Wire Wire Line
	5850 2550 6350 2550
Wire Wire Line
	6000 2950 6000 2750
Connection ~ 6000 2750
Wire Wire Line
	6000 2750 6350 2750
Wire Wire Line
	6150 2950 6150 2850
Connection ~ 6150 2850
Wire Wire Line
	6150 2850 6350 2850
$Comp
L power:GND #PWR023
U 1 1 607726A1
P 6650 3250
F 0 "#PWR023" H 6650 3000 50  0001 C CNN
F 1 "GND" V 6650 3050 50  0000 C CNN
F 2 "" H 6650 3250 50  0001 C CNN
F 3 "" H 6650 3250 50  0001 C CNN
	1    6650 3250
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR024
U 1 1 607728A5
P 6750 3250
F 0 "#PWR024" H 6750 3000 50  0001 C CNN
F 1 "GND" V 6750 3050 50  0000 C CNN
F 2 "" H 6750 3250 50  0001 C CNN
F 3 "" H 6750 3250 50  0001 C CNN
	1    6750 3250
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR025
U 1 1 60772A59
P 6850 3250
F 0 "#PWR025" H 6850 3000 50  0001 C CNN
F 1 "GND" V 6850 3050 50  0000 C CNN
F 2 "" H 6850 3250 50  0001 C CNN
F 3 "" H 6850 3250 50  0001 C CNN
	1    6850 3250
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR026
U 1 1 60772CFA
P 6950 3250
F 0 "#PWR026" H 6950 3000 50  0001 C CNN
F 1 "GND" V 6950 3050 50  0000 C CNN
F 2 "" H 6950 3250 50  0001 C CNN
F 3 "" H 6950 3250 50  0001 C CNN
	1    6950 3250
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR027
U 1 1 60772EA8
P 7050 3250
F 0 "#PWR027" H 7050 3000 50  0001 C CNN
F 1 "GND" V 7050 3050 50  0000 C CNN
F 2 "" H 7050 3250 50  0001 C CNN
F 3 "" H 7050 3250 50  0001 C CNN
	1    7050 3250
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR017
U 1 1 60781341
P 4500 3250
F 0 "#PWR017" H 4500 3000 50  0001 C CNN
F 1 "GND" V 4500 3050 50  0000 C CNN
F 2 "" H 4500 3250 50  0001 C CNN
F 3 "" H 4500 3250 50  0001 C CNN
	1    4500 3250
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR018
U 1 1 60781347
P 4600 3250
F 0 "#PWR018" H 4600 3000 50  0001 C CNN
F 1 "GND" V 4600 3050 50  0000 C CNN
F 2 "" H 4600 3250 50  0001 C CNN
F 3 "" H 4600 3250 50  0001 C CNN
	1    4600 3250
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR019
U 1 1 6078134D
P 4700 3250
F 0 "#PWR019" H 4700 3000 50  0001 C CNN
F 1 "GND" V 4700 3050 50  0000 C CNN
F 2 "" H 4700 3250 50  0001 C CNN
F 3 "" H 4700 3250 50  0001 C CNN
	1    4700 3250
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR020
U 1 1 60781353
P 4800 3250
F 0 "#PWR020" H 4800 3000 50  0001 C CNN
F 1 "GND" V 4800 3050 50  0000 C CNN
F 2 "" H 4800 3250 50  0001 C CNN
F 3 "" H 4800 3250 50  0001 C CNN
	1    4800 3250
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR021
U 1 1 60781359
P 4900 3250
F 0 "#PWR021" H 4900 3000 50  0001 C CNN
F 1 "GND" V 4900 3050 50  0000 C CNN
F 2 "" H 4900 3250 50  0001 C CNN
F 3 "" H 4900 3250 50  0001 C CNN
	1    4900 3250
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR022
U 1 1 6078135F
P 5000 3250
F 0 "#PWR022" H 5000 3000 50  0001 C CNN
F 1 "GND" V 5000 3050 50  0000 C CNN
F 2 "" H 5000 3250 50  0001 C CNN
F 3 "" H 5000 3250 50  0001 C CNN
	1    5000 3250
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR011
U 1 1 607ADE41
P 2550 1650
F 0 "#PWR011" H 2550 1500 50  0001 C CNN
F 1 "+5V" V 2550 1750 50  0000 L CNN
F 2 "" H 2550 1650 50  0001 C CNN
F 3 "" H 2550 1650 50  0001 C CNN
	1    2550 1650
	0    1    1    0   
$EndComp
Text GLabel 5600 5150 2    50   Input ~ 0
hdmi_5v_in
$Comp
L Device:R R10
U 1 1 6082E838
P 7800 2500
F 0 "R10" H 7870 2546 50  0000 L CNN
F 1 "43k" H 7870 2455 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 7730 2500 50  0001 C CNN
F 3 "~" H 7800 2500 50  0001 C CNN
	1    7800 2500
	-1   0    0    -1  
$EndComp
$Comp
L Device:R R11
U 1 1 6082FE5A
P 7800 2800
F 0 "R11" H 7870 2846 50  0000 L CNN
F 1 "62k" H 7870 2755 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 7730 2800 50  0001 C CNN
F 3 "~" H 7800 2800 50  0001 C CNN
	1    7800 2800
	-1   0    0    -1  
$EndComp
$Comp
L Device:R R15
U 1 1 60832DD5
P 8750 2500
F 0 "R15" H 8820 2546 50  0000 L CNN
F 1 "43k" H 8820 2455 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 8680 2500 50  0001 C CNN
F 3 "~" H 8750 2500 50  0001 C CNN
	1    8750 2500
	-1   0    0    -1  
$EndComp
$Comp
L Device:R R16
U 1 1 60832DDB
P 8750 2800
F 0 "R16" H 8820 2846 50  0000 L CNN
F 1 "62k" H 8820 2755 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 8680 2800 50  0001 C CNN
F 3 "~" H 8750 2800 50  0001 C CNN
	1    8750 2800
	-1   0    0    -1  
$EndComp
$Comp
L power:GND #PWR032
U 1 1 60834718
P 8750 2950
F 0 "#PWR032" H 8750 2700 50  0001 C CNN
F 1 "GND" H 8755 2777 50  0000 C CNN
F 2 "" H 8750 2950 50  0001 C CNN
F 3 "" H 8750 2950 50  0001 C CNN
	1    8750 2950
	-1   0    0    -1  
$EndComp
$Comp
L power:GND #PWR028
U 1 1 608350E2
P 7800 2950
F 0 "#PWR028" H 7800 2700 50  0001 C CNN
F 1 "GND" H 7805 2777 50  0000 C CNN
F 2 "" H 7800 2950 50  0001 C CNN
F 3 "" H 7800 2950 50  0001 C CNN
	1    7800 2950
	-1   0    0    -1  
$EndComp
Text GLabel 7900 2650 2    50   Output ~ 0
hdmi_5v_in
Text GLabel 8850 2650 2    50   Output ~ 0
hdmi_hpd_in
Text GLabel 8750 2350 1    50   Input ~ 0
hdmi_hpd
Text GLabel 7800 2350 1    50   Input ~ 0
hdmi_5v
Wire Wire Line
	7800 2650 7900 2650
Connection ~ 7800 2650
Wire Wire Line
	8850 2650 8750 2650
Connection ~ 8750 2650
Text GLabel 4400 5850 0    50   BiDi ~ 0
hdmi_sda
$Comp
L power:+5V #PWR034
U 1 1 60AB70BC
P 2100 5650
F 0 "#PWR034" H 2100 5500 50  0001 C CNN
F 1 "+5V" H 2115 5823 50  0000 C CNN
F 2 "" H 2100 5650 50  0001 C CNN
F 3 "" H 2100 5650 50  0001 C CNN
	1    2100 5650
	-1   0    0    1   
$EndComp
$Comp
L power:PWR_FLAG #FLG01
U 1 1 60AB7DA6
P 2100 5650
F 0 "#FLG01" H 2100 5725 50  0001 C CNN
F 1 "PWR_FLAG" H 2100 5823 50  0000 C CNN
F 2 "" H 2100 5650 50  0001 C CNN
F 3 "~" H 2100 5650 50  0001 C CNN
	1    2100 5650
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR035
U 1 1 60ABB3DD
P 1500 6300
F 0 "#PWR035" H 1500 6150 50  0001 C CNN
F 1 "+5V" V 1500 6450 50  0000 L CNN
F 2 "" H 1500 6300 50  0001 C CNN
F 3 "" H 1500 6300 50  0001 C CNN
	1    1500 6300
	0    -1   -1   0   
$EndComp
Text GLabel 5600 5250 2    50   Input ~ 0
hdmi_hpd_in
Text GLabel 8700 6250 0    50   BiDi ~ 0
hdmi_cec
Text GLabel 8700 5650 0    50   BiDi ~ 0
hdmi_scl
Text GLabel 8700 5950 0    50   BiDi ~ 0
hdmi_sda
Text GLabel 8700 5050 0    50   BiDi ~ 0
hdmi_hpd
Text GLabel 8700 5350 0    50   BiDi ~ 0
hdmi_5v
$Comp
L power:GND #PWR043
U 1 1 60A6FA48
P 2000 4200
F 0 "#PWR043" H 2000 3950 50  0001 C CNN
F 1 "GND" V 2005 4072 50  0000 R CNN
F 2 "" H 2000 4200 50  0001 C CNN
F 3 "" H 2000 4200 50  0001 C CNN
	1    2000 4200
	0    -1   -1   0   
$EndComp
Text GLabel 2900 3950 2    50   BiDi ~ 0
hdmi_cec
Text GLabel 2900 4050 2    50   BiDi ~ 0
hdmi_utility
Text GLabel 2900 4150 2    50   BiDi ~ 0
hdmi_scl
Text GLabel 2900 4450 2    50   BiDi ~ 0
hdmi_hpd
Text GLabel 2900 4250 2    50   BiDi ~ 0
hdmi_sda
Text GLabel 2900 4350 2    50   BiDi ~ 0
hdmi_5v
$Comp
L power:GND #PWR040
U 1 1 609ADAD7
P 2900 3850
F 0 "#PWR040" H 2900 3600 50  0001 C CNN
F 1 "GND" V 2905 3722 50  0000 R CNN
F 2 "" H 2900 3850 50  0001 C CNN
F 3 "" H 2900 3850 50  0001 C CNN
	1    2900 3850
	0    -1   1    0   
$EndComp
Wire Wire Line
	4400 6250 4300 6250
$Comp
L wally:ESD5Z5.0 D3
U 1 1 608051EF
P 3050 2600
F 0 "D3" V 3004 2680 50  0000 L CNN
F 1 "ESD5Z5.0" H 3100 2750 50  0000 L CNN
F 2 "Diode_SMD:D_SOD-523" H 3050 2400 50  0001 C CNN
F 3 "" H 3000 2600 50  0001 C CNN
	1    3050 2600
	0    1    1    0   
$EndComp
$Comp
L wally:ESD5Z5.0 D2
U 1 1 6080F3A6
P 2750 2600
F 0 "D2" V 2704 2680 50  0000 L CNN
F 1 "ESD5Z5.0" H 2800 2750 50  0000 L CNN
F 2 "Diode_SMD:D_SOD-523" H 2750 2400 50  0001 C CNN
F 3 "" H 2700 2600 50  0001 C CNN
	1    2750 2600
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR031
U 1 1 6081044F
P 2750 2750
F 0 "#PWR031" H 2750 2500 50  0001 C CNN
F 1 "GND" H 2755 2577 50  0000 C CNN
F 2 "" H 2750 2750 50  0001 C CNN
F 3 "" H 2750 2750 50  0001 C CNN
	1    2750 2750
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR036
U 1 1 6081241C
P 3050 2750
F 0 "#PWR036" H 3050 2500 50  0001 C CNN
F 1 "GND" H 3055 2577 50  0000 C CNN
F 2 "" H 3050 2750 50  0001 C CNN
F 3 "" H 3050 2750 50  0001 C CNN
	1    3050 2750
	1    0    0    -1  
$EndComp
Wire Wire Line
	2650 2250 3050 2250
Wire Wire Line
	2650 2350 2750 2350
Wire Wire Line
	2750 2450 2750 2350
Connection ~ 2750 2350
Wire Wire Line
	2750 2350 3200 2350
Wire Wire Line
	3050 2450 3050 2250
Connection ~ 3050 2250
Wire Wire Line
	3050 2250 3200 2250
$Comp
L Device:LED D4
U 1 1 608657D3
P 6550 6300
F 0 "D4" V 6497 6380 50  0000 L CNN
F 1 "Red LED" H 6300 6150 50  0000 L CNN
F 2 "LED_SMD:LED_0603_1608Metric" H 6550 6300 50  0001 C CNN
F 3 "~" H 6550 6300 50  0001 C CNN
	1    6550 6300
	0    1    -1   0   
$EndComp
$Comp
L Device:R R8
U 1 1 6086A414
P 6550 6000
F 0 "R8" H 6620 6046 50  0000 L CNN
F 1 "1k" H 6620 5955 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 6480 6000 50  0001 C CNN
F 3 "~" H 6550 6000 50  0001 C CNN
	1    6550 6000
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR037
U 1 1 6086A8A6
P 6550 6450
F 0 "#PWR037" H 6550 6200 50  0001 C CNN
F 1 "GND" H 6555 6277 50  0000 C CNN
F 2 "" H 6550 6450 50  0001 C CNN
F 3 "" H 6550 6450 50  0001 C CNN
	1    6550 6450
	-1   0    0    -1  
$EndComp
$Comp
L Device:LED D6
U 1 1 608898FD
P 6100 6300
F 0 "D6" V 6047 6380 50  0000 L CNN
F 1 "Green LED" H 5850 6150 50  0000 L CNN
F 2 "LED_SMD:LED_0603_1608Metric" H 6100 6300 50  0001 C CNN
F 3 "~" H 6100 6300 50  0001 C CNN
	1    6100 6300
	0    1    -1   0   
$EndComp
$Comp
L Device:R R12
U 1 1 60889903
P 6100 6000
F 0 "R12" H 6170 6046 50  0000 L CNN
F 1 "1k" H 6170 5955 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 6030 6000 50  0001 C CNN
F 3 "~" H 6100 6000 50  0001 C CNN
	1    6100 6000
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR039
U 1 1 60889909
P 6100 6450
F 0 "#PWR039" H 6100 6200 50  0001 C CNN
F 1 "GND" H 6105 6277 50  0000 C CNN
F 2 "" H 6100 6450 50  0001 C CNN
F 3 "" H 6100 6450 50  0001 C CNN
	1    6100 6450
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR038
U 1 1 608C7290
P 1600 6600
F 0 "#PWR038" H 1600 6350 50  0001 C CNN
F 1 "GND" H 1605 6427 50  0000 C CNN
F 2 "" H 1600 6600 50  0001 C CNN
F 3 "" H 1600 6600 50  0001 C CNN
	1    1600 6600
	-1   0    0    -1  
$EndComp
Wire Wire Line
	1500 6300 1600 6300
Connection ~ 1600 6300
Wire Wire Line
	1600 6300 1900 6300
$Comp
L Connector_Generic:Conn_01x06 J4
U 1 1 6091D52B
P 1800 4100
F 0 "J4" H 1718 4517 50  0000 C CNN
F 1 "Debug" H 1718 4426 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x06_P2.54mm_Vertical" H 1800 4100 50  0001 C CNN
F 3 "~" H 1800 4100 50  0001 C CNN
	1    1800 4100
	-1   0    0    -1  
$EndComp
Wire Wire Line
	10400 2650 10450 2650
Wire Wire Line
	10450 2600 10450 2650
Connection ~ 10450 2650
Wire Wire Line
	10450 2650 10500 2650
$Comp
L wally:ESD5Z5.0 D7
U 1 1 60AA8AD8
P 8850 5350
F 0 "D7" H 8800 5250 50  0000 L CNN
F 1 "ESD5Z5.0" H 8700 5450 50  0000 L CNN
F 2 "Diode_SMD:D_SOD-523" H 8850 5150 50  0001 C CNN
F 3 "" H 8800 5350 50  0001 C CNN
	1    8850 5350
	1    0    0    1   
$EndComp
$Comp
L power:GND #PWR045
U 1 1 60AA8ADE
P 9000 5350
F 0 "#PWR045" H 9000 5100 50  0001 C CNN
F 1 "GND" H 9005 5177 50  0000 C CNN
F 2 "" H 9000 5350 50  0001 C CNN
F 3 "" H 9000 5350 50  0001 C CNN
	1    9000 5350
	0    -1   1    0   
$EndComp
$Comp
L wally:ESD5Z5.0 D8
U 1 1 60AB272D
P 8850 5650
F 0 "D8" H 8800 5550 50  0000 L CNN
F 1 "ESD5Z3.3" H 8700 5750 50  0000 L CNN
F 2 "Diode_SMD:D_SOD-523" H 8850 5450 50  0001 C CNN
F 3 "" H 8800 5650 50  0001 C CNN
	1    8850 5650
	1    0    0    1   
$EndComp
$Comp
L power:GND #PWR046
U 1 1 60AB2733
P 9000 5650
F 0 "#PWR046" H 9000 5400 50  0001 C CNN
F 1 "GND" H 9005 5477 50  0000 C CNN
F 2 "" H 9000 5650 50  0001 C CNN
F 3 "" H 9000 5650 50  0001 C CNN
	1    9000 5650
	0    -1   1    0   
$EndComp
$Comp
L wally:ESD5Z5.0 D9
U 1 1 60AB47E2
P 8850 5950
F 0 "D9" H 8800 5850 50  0000 L CNN
F 1 "ESD5Z3.3" H 8700 6050 50  0000 L CNN
F 2 "Diode_SMD:D_SOD-523" H 8850 5750 50  0001 C CNN
F 3 "" H 8800 5950 50  0001 C CNN
	1    8850 5950
	1    0    0    1   
$EndComp
$Comp
L power:GND #PWR047
U 1 1 60AB47E8
P 9000 5950
F 0 "#PWR047" H 9000 5700 50  0001 C CNN
F 1 "GND" H 9005 5777 50  0000 C CNN
F 2 "" H 9000 5950 50  0001 C CNN
F 3 "" H 9000 5950 50  0001 C CNN
	1    9000 5950
	0    -1   1    0   
$EndComp
$Comp
L wally:ESD5Z5.0 D10
U 1 1 60AB67CD
P 8850 6250
F 0 "D10" H 8800 6150 50  0000 L CNN
F 1 "ESD5Z3.3" H 8700 6350 50  0000 L CNN
F 2 "Diode_SMD:D_SOD-523" H 8850 6050 50  0001 C CNN
F 3 "" H 8800 6250 50  0001 C CNN
	1    8850 6250
	1    0    0    1   
$EndComp
$Comp
L power:GND #PWR048
U 1 1 60AB67D3
P 9000 6250
F 0 "#PWR048" H 9000 6000 50  0001 C CNN
F 1 "GND" H 9005 6077 50  0000 C CNN
F 2 "" H 9000 6250 50  0001 C CNN
F 3 "" H 9000 6250 50  0001 C CNN
	1    9000 6250
	0    -1   1    0   
$EndComp
$Comp
L wally:ESD5Z5.0 D1
U 1 1 60AB88E2
P 8850 5050
F 0 "D1" H 8800 4950 50  0000 L CNN
F 1 "ESD5Z5.0" H 8700 5150 50  0000 L CNN
F 2 "Diode_SMD:D_SOD-523" H 8850 4850 50  0001 C CNN
F 3 "" H 8800 5050 50  0001 C CNN
	1    8850 5050
	1    0    0    1   
$EndComp
$Comp
L power:GND #PWR044
U 1 1 60AB88E8
P 9000 5050
F 0 "#PWR044" H 9000 4800 50  0001 C CNN
F 1 "GND" H 9005 4877 50  0000 C CNN
F 2 "" H 9000 5050 50  0001 C CNN
F 3 "" H 9000 5050 50  0001 C CNN
	1    9000 5050
	0    -1   1    0   
$EndComp
$Comp
L wally:ESD5Z5.0 D5
U 1 1 608C728A
P 1600 6450
F 0 "D5" V 1554 6530 50  0000 L CNN
F 1 "ESD5Z5.0" H 1650 6600 50  0000 L CNN
F 2 "Diode_SMD:D_SOD-523" H 1600 6250 50  0001 C CNN
F 3 "" H 1550 6450 50  0001 C CNN
	1    1600 6450
	0    -1   1    0   
$EndComp
$Comp
L power:GND #PWR0102
U 1 1 608D7DE6
P 4300 6550
F 0 "#PWR0102" H 4300 6300 50  0001 C CNN
F 1 "GND" H 4305 6377 50  0000 C CNN
F 2 "" H 4300 6550 50  0001 C CNN
F 3 "" H 4300 6550 50  0001 C CNN
	1    4300 6550
	1    0    0    -1  
$EndComp
$Comp
L power:PWR_FLAG #FLG02
U 1 1 60AE473B
P 1650 5650
F 0 "#FLG02" H 1650 5725 50  0001 C CNN
F 1 "PWR_FLAG" H 1650 5823 50  0000 C CNN
F 2 "" H 1650 5650 50  0001 C CNN
F 3 "~" H 1650 5650 50  0001 C CNN
	1    1650 5650
	1    0    0    -1  
$EndComp
Text GLabel 6750 4450 0    50   BiDi ~ 0
hdmi_hpd
Text GLabel 7950 4250 2    50   Input ~ 0
hdmi_hpd_en
Text GLabel 9250 4250 0    50   BiDi ~ 0
hdmi_sda
Text GLabel 9250 4450 0    50   BiDi ~ 0
hdmi_scl
Text GLabel 6850 4250 0    50   BiDi ~ 0
hdmi_5v
$Comp
L Device:R R9
U 1 1 6087994E
P 6900 4450
F 0 "R9" V 6800 4450 50  0000 C CNN
F 1 "1k" V 6900 4450 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 6830 4450 50  0001 C CNN
F 3 "~" H 6900 4450 50  0001 C CNN
	1    6900 4450
	0    1    1    0   
$EndComp
Text GLabel 7950 4150 2    50   Input ~ 0
hdmi_5v_en
Wire Wire Line
	10450 2300 10200 2300
Wire Wire Line
	10200 2300 10200 2350
Connection ~ 10200 2300
Wire Wire Line
	10200 2250 10200 2300
Text GLabel 1650 5650 3    50   BiDi ~ 0
hdmi_5v
Text GLabel 4100 6300 3    50   Output ~ 0
hdmi_hpd_en
Text GLabel 5600 5550 2    50   Output ~ 0
hdmi_5v_en
$Comp
L wally:AP2152 U3
U 1 1 6092684F
P 7500 4350
F 0 "U3" H 7500 4915 50  0000 C CNN
F 1 "STMPS2252" H 7500 4824 50  0000 C CNN
F 2 "Package_SO:MSOP-8_3x3mm_P0.65mm" H 7500 4350 50  0001 C CNN
F 3 "https://www.diodes.com/assets/Datasheets/AP2142_52.pdf" H 7500 4350 50  0001 C CNN
	1    7500 4350
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR030
U 1 1 60926855
P 7250 5050
F 0 "#PWR030" H 7250 4800 50  0001 C CNN
F 1 "GND" H 7255 4877 50  0000 C CNN
F 2 "" H 7250 5050 50  0001 C CNN
F 3 "" H 7250 5050 50  0001 C CNN
	1    7250 5050
	-1   0    0    -1  
$EndComp
$Comp
L Device:C C6
U 1 1 6092685B
P 7500 4950
F 0 "C6" V 7250 4950 50  0000 C CNN
F 1 "100n" V 7350 4950 50  0000 C CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 7538 4800 50  0001 C CNN
F 3 "~" H 7500 4950 50  0001 C CNN
	1    7500 4950
	0    -1   -1   0   
$EndComp
Wire Wire Line
	7600 4850 7750 4850
Wire Wire Line
	7750 4850 7750 4950
Wire Wire Line
	7650 4950 7750 4950
Connection ~ 7750 4950
Wire Wire Line
	7750 4950 7750 5050
Wire Wire Line
	7400 4850 7250 4850
Wire Wire Line
	7250 4850 7250 4950
Wire Wire Line
	7350 4950 7250 4950
Connection ~ 7250 4950
Wire Wire Line
	7250 4950 7250 5050
NoConn ~ 7950 4450
NoConn ~ 7950 4550
Wire Wire Line
	9750 4950 9750 5050
Connection ~ 9750 4950
Wire Wire Line
	9850 4950 9750 4950
Wire Wire Line
	9750 4850 9750 4950
Wire Wire Line
	9900 4850 9750 4850
Wire Wire Line
	10250 4950 10250 5050
Connection ~ 10250 4950
Wire Wire Line
	10150 4950 10250 4950
Wire Wire Line
	10250 4850 10250 4950
Wire Wire Line
	10100 4850 10250 4850
$Comp
L Device:C C7
U 1 1 608A22F8
P 10000 4950
F 0 "C7" V 9750 4950 50  0000 C CNN
F 1 "100n" V 9850 4950 50  0000 C CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 10038 4800 50  0001 C CNN
F 3 "~" H 10000 4950 50  0001 C CNN
	1    10000 4950
	0    -1   -1   0   
$EndComp
Wire Wire Line
	10500 4150 10550 4150
Connection ~ 10500 4150
Wire Wire Line
	10500 4250 10500 4150
Wire Wire Line
	10450 4250 10500 4250
Wire Wire Line
	10450 4150 10500 4150
NoConn ~ 10450 4550
NoConn ~ 10450 4450
$Comp
L power:GND #PWR049
U 1 1 608686BB
P 9750 5050
F 0 "#PWR049" H 9750 4800 50  0001 C CNN
F 1 "GND" H 9755 4877 50  0000 C CNN
F 2 "" H 9750 5050 50  0001 C CNN
F 3 "" H 9750 5050 50  0001 C CNN
	1    9750 5050
	-1   0    0    -1  
$EndComp
$Comp
L wally:AP2152 U4
U 1 1 60838C3B
P 10000 4350
F 0 "U4" H 10000 4915 50  0000 C CNN
F 1 "STMPS2252" H 10000 4824 50  0000 C CNN
F 2 "Package_SO:MSOP-8_3x3mm_P0.65mm" H 10000 4350 50  0001 C CNN
F 3 "https://www.diodes.com/assets/Datasheets/AP2142_52.pdf" H 10000 4350 50  0001 C CNN
	1    10000 4350
	1    0    0    -1  
$EndComp
$Comp
L Device:R R18
U 1 1 609894CD
P 9400 4450
F 0 "R18" V 9500 4450 50  0000 C CNN
F 1 "1k5" V 9400 4450 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 9330 4450 50  0001 C CNN
F 3 "~" H 9400 4450 50  0001 C CNN
	1    9400 4450
	0    1    -1   0   
$EndComp
$Comp
L Device:R R17
U 1 1 60988C76
P 9400 4250
F 0 "R17" V 9300 4250 50  0000 C CNN
F 1 "1k5" V 9400 4250 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 9330 4250 50  0001 C CNN
F 3 "~" H 9400 4250 50  0001 C CNN
	1    9400 4250
	0    1    1    0   
$EndComp
Text GLabel 10550 4150 2    50   Input ~ 0
hdmi_5v_en
Wire Wire Line
	6100 5850 5600 5850
$Comp
L power:+5V #PWR04
U 1 1 60B71C7B
P 7750 5050
F 0 "#PWR04" H 7750 4900 50  0001 C CNN
F 1 "+5V" H 7765 5223 50  0000 C CNN
F 2 "" H 7750 5050 50  0001 C CNN
F 3 "" H 7750 5050 50  0001 C CNN
	1    7750 5050
	-1   0    0    1   
$EndComp
$Comp
L power:+5V #PWR052
U 1 1 60B7B042
P 10250 5050
F 0 "#PWR052" H 10250 4900 50  0001 C CNN
F 1 "+5V" H 10265 5223 50  0000 C CNN
F 2 "" H 10250 5050 50  0001 C CNN
F 3 "" H 10250 5050 50  0001 C CNN
	1    10250 5050
	-1   0    0    1   
$EndComp
$Comp
L Device:C C8
U 1 1 6087F87E
P 6950 4100
F 0 "C8" H 6835 4054 50  0000 R CNN
F 1 "100n" H 6835 4145 50  0000 R CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 6988 3950 50  0001 C CNN
F 3 "~" H 6950 4100 50  0001 C CNN
	1    6950 4100
	1    0    0    1   
$EndComp
Wire Wire Line
	6850 4250 6950 4250
Connection ~ 6950 4250
Wire Wire Line
	6950 4250 7050 4250
$Comp
L power:GND #PWR053
U 1 1 6088729D
P 6950 3950
F 0 "#PWR053" H 6950 3700 50  0001 C CNN
F 1 "GND" H 6955 3777 50  0000 C CNN
F 2 "" H 6950 3950 50  0001 C CNN
F 3 "" H 6950 3950 50  0001 C CNN
	1    6950 3950
	1    0    0    1   
$EndComp
Connection ~ 4300 6250
$Comp
L wally:USB_C_Receptacle_USB2.0 J1
U 1 1 60857081
P 1950 2250
F 0 "J1" H 1950 3100 50  0000 C CNN
F 1 "USB C" H 1950 3000 50  0000 C CNN
F 2 "wally:USB_C_Receptacle_HRO_TYPE-C-31-M-12" H 2100 2250 50  0001 C CNN
F 3 "https://www.usb.org/sites/default/files/documents/usb_type-c.zip" H 2100 2250 50  0001 C CNN
	1    1950 2250
	1    0    0    -1  
$EndComp
NoConn ~ 1750 3150
Text Notes 7900 2600 0    50   ~ 0
5v => 2,95v
Text Notes 8850 2600 0    50   ~ 0
5v=> 2,95v
Wire Wire Line
	5600 5750 6550 5750
Wire Wire Line
	6550 5750 6550 5850
$Comp
L Connector_Generic:Conn_01x07 J5
U 1 1 60BC5AE1
P 2700 4150
F 0 "J5" H 2618 4667 50  0000 C CNN
F 1 "HDMI Expansion" H 2618 4576 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x07_P2.54mm_Vertical" H 2700 4150 50  0001 C CNN
F 3 "~" H 2700 4150 50  0001 C CNN
	1    2700 4150
	-1   0    0    -1  
$EndComp
$Comp
L Device:LED D11
U 1 1 60C14E32
P 3100 6750
F 0 "D11" V 3047 6830 50  0000 L CNN
F 1 "Power LED" H 2850 6600 50  0000 L CNN
F 2 "LED_SMD:LED_0603_1608Metric" H 3100 6750 50  0001 C CNN
F 3 "~" H 3100 6750 50  0001 C CNN
	1    3100 6750
	0    1    -1   0   
$EndComp
$Comp
L Device:R R4
U 1 1 60C14E38
P 3100 6450
F 0 "R4" H 3170 6496 50  0000 L CNN
F 1 "1k" H 3170 6405 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 3030 6450 50  0001 C CNN
F 3 "~" H 3100 6450 50  0001 C CNN
	1    3100 6450
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR033
U 1 1 60C14E3E
P 3100 6900
F 0 "#PWR033" H 3100 6650 50  0001 C CNN
F 1 "GND" H 3105 6727 50  0000 C CNN
F 2 "" H 3100 6900 50  0001 C CNN
F 3 "" H 3100 6900 50  0001 C CNN
	1    3100 6900
	-1   0    0    -1  
$EndComp
Wire Wire Line
	2700 6300 3100 6300
Connection ~ 3100 6300
Wire Wire Line
	3100 6300 3200 6300
$Comp
L Device:LED D12
U 1 1 60BD37E7
P 3800 6600
F 0 "D12" V 3747 6680 50  0000 L CNN
F 1 "Yellow LED" H 3550 6450 50  0000 L CNN
F 2 "LED_SMD:LED_0603_1608Metric" H 3800 6600 50  0001 C CNN
F 3 "~" H 3800 6600 50  0001 C CNN
	1    3800 6600
	0    1    -1   0   
$EndComp
$Comp
L Device:R R5
U 1 1 60BD37ED
P 3800 6300
F 0 "R5" H 3870 6346 50  0000 L CNN
F 1 "1k" H 3870 6255 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 3730 6300 50  0001 C CNN
F 3 "~" H 3800 6300 50  0001 C CNN
	1    3800 6300
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR041
U 1 1 60BD37F3
P 3800 6750
F 0 "#PWR041" H 3800 6500 50  0001 C CNN
F 1 "GND" H 3805 6577 50  0000 C CNN
F 2 "" H 3800 6750 50  0001 C CNN
F 3 "" H 3800 6750 50  0001 C CNN
	1    3800 6750
	-1   0    0    -1  
$EndComp
Wire Wire Line
	4100 6300 4100 6250
Wire Wire Line
	4100 6250 4300 6250
Wire Wire Line
	4400 6150 3800 6150
$EndSCHEMATC
