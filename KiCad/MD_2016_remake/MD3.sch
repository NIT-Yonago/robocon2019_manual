EESchema Schematic File Version 4
LIBS:MD_2016_remake_v2-cache
EELAYER 29 0
EELAYER END
$Descr User 5906 4724
encoding utf-8
Sheet 4 6
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L MD_2016_remake_v2-rescue:EP2-3L3SAb-SamacSys_Parts K?
U 1 1 5CF12E97
P 2500 1250
AR Path="/5CF12E97" Ref="K?"  Part="1" 
AR Path="/5CEF8497/5CF12E97" Ref="K3"  Part="1" 
F 0 "K3" H 2900 800 50  0000 C CNN
F 1 "EP2-3L3SAb" H 2900 1400 50  0000 C CNN
F 2 "SamacSys_Parts:EP2_H-BRIDGE" H 3150 1350 50  0001 L CNN
F 3 "http://akizukidenshi.com/download/ds/nec/EP1_EP2_datasheet.pdf" H 3150 1250 50  0001 L CNN
F 4 "Twin automotive relay" H 3150 1150 50  0001 L CNN "Description"
F 5 "NEC" H 3150 950 50  0001 L CNN "Manufacturer_Name"
F 6 "EP2-3L3SAb" H 3150 850 50  0001 L CNN "Manufacturer_Part_Number"
	1    2500 1250
	1    0    0    -1  
$EndComp
$Comp
L Isolator:TLP627 U?
U 1 1 5CF12E9D
P 1250 1450
AR Path="/5CF12E9D" Ref="U?"  Part="1" 
AR Path="/5CEF8497/5CF12E9D" Ref="U10"  Part="1" 
F 0 "U10" H 1450 1650 50  0000 C CNN
F 1 "TLP627" H 1100 1650 50  0000 C CNN
F 2 "Package_DIP:DIP-4_W7.62mm" H 950 1250 50  0001 L CIN
F 3 "https://toshiba.semicon-storage.com/info/docget.jsp?did=16914&prodName=TLP627" H 1250 1450 50  0001 L CNN
	1    1250 1450
	1    0    0    -1  
$EndComp
$Comp
L power:+12V #PWR?
U 1 1 5CF12EA3
P 3650 1350
AR Path="/5CF12EA3" Ref="#PWR?"  Part="1" 
AR Path="/5CEF8497/5CF12EA3" Ref="#PWR062"  Part="1" 
F 0 "#PWR062" H 3650 1200 50  0001 C CNN
F 1 "+12V" H 3665 1523 50  0000 C CNN
F 2 "" H 3650 1350 50  0001 C CNN
F 3 "" H 3650 1350 50  0001 C CNN
	1    3650 1350
	1    0    0    -1  
$EndComp
Wire Wire Line
	3650 1350 3300 1350
$Comp
L power:+12V #PWR?
U 1 1 5CF12EAA
P 2400 1450
AR Path="/5CF12EAA" Ref="#PWR?"  Part="1" 
AR Path="/5CEF8497/5CF12EAA" Ref="#PWR063"  Part="1" 
F 0 "#PWR063" H 2400 1300 50  0001 C CNN
F 1 "+12V" H 2250 1500 50  0000 C CNN
F 2 "" H 2400 1450 50  0001 C CNN
F 3 "" H 2400 1450 50  0001 C CNN
	1    2400 1450
	1    0    0    -1  
$EndComp
Wire Wire Line
	2500 1450 2400 1450
$Comp
L Motor:Motor_DC M?
U 1 1 5CF12EB1
P 4150 1350
AR Path="/5CF12EB1" Ref="M?"  Part="1" 
AR Path="/5CEF8497/5CF12EB1" Ref="M3"  Part="1" 
F 0 "M3" H 4308 1346 50  0000 L CNN
F 1 "xt60" H 4308 1255 50  0000 L CNN
F 2 "Morita:XT60PT-F" H 4150 1260 50  0001 C CNN
F 3 "~" H 4150 1260 50  0001 C CNN
	1    4150 1350
	1    0    0    1   
$EndComp
Wire Wire Line
	4150 1550 3300 1550
Wire Wire Line
	2500 1250 2500 1050
Wire Wire Line
	2500 1050 4150 1050
Wire Wire Line
	2500 1350 1900 1350
Wire Wire Line
	3300 1450 3400 1450
Wire Wire Line
	3400 1450 3400 1750
Wire Wire Line
	3400 1750 2150 1750
$Comp
L Isolator:TLP627 U?
U 1 1 5CF12EBE
P 1250 1850
AR Path="/5CF12EBE" Ref="U?"  Part="1" 
AR Path="/5CEF8497/5CF12EBE" Ref="U11"  Part="1" 
F 0 "U11" H 1450 2050 50  0000 C CNN
F 1 "TLP627" H 1100 2050 50  0000 C CNN
F 2 "Package_DIP:DIP-4_W7.62mm" H 950 1650 50  0001 L CIN
F 3 "https://toshiba.semicon-storage.com/info/docget.jsp?did=16914&prodName=TLP627" H 1250 1850 50  0001 L CNN
	1    1250 1850
	1    0    0    -1  
$EndComp
$Comp
L power:GNDPWR #PWR?
U 1 1 5CF12EC4
P 1900 1550
AR Path="/5CF12EC4" Ref="#PWR?"  Part="1" 
AR Path="/5CEF8497/5CF12EC4" Ref="#PWR065"  Part="1" 
F 0 "#PWR065" H 1900 1350 50  0001 C CNN
F 1 "GNDPWR" H 1800 1600 50  0000 C CNN
F 2 "" H 1900 1500 50  0001 C CNN
F 3 "" H 1900 1500 50  0001 C CNN
	1    1900 1550
	1    0    0    -1  
$EndComp
$Comp
L power:GNDPWR #PWR?
U 1 1 5CF12ECA
P 1900 1950
AR Path="/5CF12ECA" Ref="#PWR?"  Part="1" 
AR Path="/5CEF8497/5CF12ECA" Ref="#PWR067"  Part="1" 
F 0 "#PWR067" H 1900 1750 50  0001 C CNN
F 1 "GNDPWR" H 2100 1900 50  0000 C CNN
F 2 "" H 1900 1900 50  0001 C CNN
F 3 "" H 1900 1900 50  0001 C CNN
	1    1900 1950
	1    0    0    -1  
$EndComp
Wire Wire Line
	1900 1950 1650 1950
Wire Wire Line
	1650 1550 1900 1550
Wire Wire Line
	3300 1250 3500 1250
Wire Wire Line
	3500 1250 3500 1700
$Comp
L Device:Q_NMOS_GDS Q?
U 1 1 5CF12ED4
P 3400 2250
AR Path="/5CF12ED4" Ref="Q?"  Part="1" 
AR Path="/5CEF8497/5CF12ED4" Ref="Q3"  Part="1" 
F 0 "Q3" H 3606 2296 50  0000 L CNN
F 1 "Q_NMOS_GDS" H 3606 2205 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-247-3_Vertical" H 3600 2350 50  0001 C CNN
F 3 "~" H 3400 2250 50  0001 C CNN
	1    3400 2250
	1    0    0    -1  
$EndComp
Wire Wire Line
	2400 1550 2500 1550
$Comp
L MD_2016_remake_v2-rescue:TLP152(E(T-SamacSys_Parts IC?
U 1 1 5CF12EE7
P 850 2150
AR Path="/5CF12EE7" Ref="IC?"  Part="1" 
AR Path="/5CEF8497/5CF12EE7" Ref="IC3"  Part="1" 
F 0 "IC3" H 1150 1800 50  0000 C CNN
F 1 "TLP152" H 1500 1800 50  0000 C CNN
F 2 "Package_SO:SO-5_4.4x3.6mm_P1.27mm" H 1900 2250 50  0001 L CNN
F 3 "http://uk.rs-online.com/web/p/products/8851275P" H 1900 2150 50  0001 L CNN
F 4 "Toshiba TLP152(E(T Photo IC Output Optocoupler, Surface Mount, 5-Pin SO6" H 1900 2050 50  0001 L CNN "Description"
F 5 "2.2" H 1900 1950 50  0001 L CNN "Height"
F 6 "8851275P" H 1900 1850 50  0001 L CNN "RS Part Number"
F 7 "http://uk.rs-online.com/web/p/products/8851275P" H 1900 1750 50  0001 L CNN "RS Price/Stock"
F 8 "Toshiba" H 1900 1650 50  0001 L CNN "Manufacturer_Name"
F 9 "TLP152(E(T" H 1900 1550 50  0001 L CNN "Manufacturer_Part_Number"
	1    850  2150
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5CF12EED
P 3350 2450
AR Path="/5CF12EED" Ref="R?"  Part="1" 
AR Path="/5CEF8497/5CF12EED" Ref="R21"  Part="1" 
F 0 "R21" V 3250 2450 50  0000 C CNN
F 1 "N/A" V 3350 2450 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 3280 2450 50  0001 C CNN
F 3 "~" H 3350 2450 50  0001 C CNN
	1    3350 2450
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R?
U 1 1 5CF12EF3
P 2650 2250
AR Path="/5CF12EF3" Ref="R?"  Part="1" 
AR Path="/5CEF8497/5CF12EF3" Ref="R20"  Part="1" 
F 0 "R20" V 2550 2250 50  0000 C CNN
F 1 "Rg" V 2650 2250 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 2580 2250 50  0001 C CNN
F 3 "~" H 2650 2250 50  0001 C CNN
	1    2650 2250
	0    -1   -1   0   
$EndComp
Wire Wire Line
	2500 2250 2050 2250
Wire Wire Line
	2800 2250 3200 2250
Wire Wire Line
	3200 2250 3200 2450
Connection ~ 3200 2250
$Comp
L power:GNDPWR #PWR?
U 1 1 5CF12EFD
P 3500 2550
AR Path="/5CF12EFD" Ref="#PWR?"  Part="1" 
AR Path="/5CEF8497/5CF12EFD" Ref="#PWR071"  Part="1" 
F 0 "#PWR071" H 3500 2350 50  0001 C CNN
F 1 "GNDPWR" H 3700 2500 50  0000 C CNN
F 2 "" H 3500 2500 50  0001 C CNN
F 3 "" H 3500 2500 50  0001 C CNN
	1    3500 2550
	1    0    0    -1  
$EndComp
Wire Wire Line
	3500 2550 3500 2450
Connection ~ 3500 2450
$Comp
L power:GND #PWR?
U 1 1 5CF12F05
P 850 1550
AR Path="/5CF12F05" Ref="#PWR?"  Part="1" 
AR Path="/5CEF8497/5CF12F05" Ref="#PWR064"  Part="1" 
F 0 "#PWR064" H 850 1300 50  0001 C CNN
F 1 "GND" H 750 1450 50  0000 C CNN
F 2 "" H 850 1550 50  0001 C CNN
F 3 "" H 850 1550 50  0001 C CNN
	1    850  1550
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5CF12F0B
P 850 1950
AR Path="/5CF12F0B" Ref="#PWR?"  Part="1" 
AR Path="/5CEF8497/5CF12F0B" Ref="#PWR066"  Part="1" 
F 0 "#PWR066" H 850 1700 50  0001 C CNN
F 1 "GND" H 750 1850 50  0000 C CNN
F 2 "" H 850 1950 50  0001 C CNN
F 3 "" H 850 1950 50  0001 C CNN
	1    850  1950
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5CF12F11
P 850 2350
AR Path="/5CF12F11" Ref="#PWR?"  Part="1" 
AR Path="/5CEF8497/5CF12F11" Ref="#PWR069"  Part="1" 
F 0 "#PWR069" H 850 2100 50  0001 C CNN
F 1 "GND" H 750 2250 50  0000 C CNN
F 2 "" H 850 2350 50  0001 C CNN
F 3 "" H 850 2350 50  0001 C CNN
	1    850  2350
	1    0    0    -1  
$EndComp
NoConn ~ 850  2250
$Comp
L power:+12V #PWR?
U 1 1 5CF12F18
P 2200 2150
AR Path="/5CF12F18" Ref="#PWR?"  Part="1" 
AR Path="/5CEF8497/5CF12F18" Ref="#PWR068"  Part="1" 
F 0 "#PWR068" H 2200 2000 50  0001 C CNN
F 1 "+12V" H 2350 2200 50  0000 C CNN
F 2 "" H 2200 2150 50  0001 C CNN
F 3 "" H 2200 2150 50  0001 C CNN
	1    2200 2150
	1    0    0    -1  
$EndComp
Wire Wire Line
	2200 2150 2050 2150
$Comp
L power:GNDPWR #PWR?
U 1 1 5CF12F1F
P 2200 2350
AR Path="/5CF12F1F" Ref="#PWR?"  Part="1" 
AR Path="/5CEF8497/5CF12F1F" Ref="#PWR070"  Part="1" 
F 0 "#PWR070" H 2200 2150 50  0001 C CNN
F 1 "GNDPWR" H 2400 2300 50  0000 C CNN
F 2 "" H 2200 2300 50  0001 C CNN
F 3 "" H 2200 2300 50  0001 C CNN
	1    2200 2350
	1    0    0    -1  
$EndComp
Wire Wire Line
	2200 2350 2050 2350
$Comp
L Device:C_Small C?
U 1 1 5CF12F26
P 2200 2250
AR Path="/5CF12F26" Ref="C?"  Part="1" 
AR Path="/5CEF8497/5CF12F26" Ref="C8"  Part="1" 
F 0 "C8" H 2292 2296 50  0000 L CNN
F 1 "0.1u" H 2292 2205 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 2200 2250 50  0001 C CNN
F 3 "~" H 2200 2250 50  0001 C CNN
	1    2200 2250
	1    0    0    -1  
$EndComp
Connection ~ 2200 2150
Connection ~ 2200 2350
Text HLabel 850  1350 0    50   Input ~ 0
A
Text HLabel 850  1750 0    50   Input ~ 0
B
Text HLabel 850  2150 0    50   Input ~ 0
PWM
Wire Wire Line
	2400 1450 2400 1550
Connection ~ 2400 1450
$Comp
L Diode:1N4148W D19
U 1 1 5D9BC971
P 1900 1200
F 0 "D19" V 1854 1280 50  0000 L CNN
F 1 "1N4148W" V 1945 1280 50  0000 L CNN
F 2 "Diode_SMD:D_SOD-123" H 1900 1025 50  0001 C CNN
F 3 "https://www.vishay.com/docs/85748/1n4148w.pdf" H 1900 1200 50  0001 C CNN
	1    1900 1200
	0    1    1    0   
$EndComp
Connection ~ 1900 1350
Wire Wire Line
	1900 1350 1650 1350
$Comp
L Diode:1N4148W D21
U 1 1 5D9BD136
P 2150 1600
F 0 "D21" V 2104 1680 50  0000 L CNN
F 1 "1N4148W" V 2195 1680 50  0000 L CNN
F 2 "Diode_SMD:D_SOD-123" H 2150 1425 50  0001 C CNN
F 3 "https://www.vishay.com/docs/85748/1n4148w.pdf" H 2150 1600 50  0001 C CNN
	1    2150 1600
	0    1    1    0   
$EndComp
Connection ~ 2150 1750
Wire Wire Line
	2150 1750 1650 1750
Wire Wire Line
	2400 1450 2150 1450
$Comp
L power:+12V #PWR061
U 1 1 5D9BDE0F
P 1900 1050
F 0 "#PWR061" H 1900 900 50  0001 C CNN
F 1 "+12V" H 1915 1223 50  0000 C CNN
F 2 "" H 1900 1050 50  0001 C CNN
F 3 "" H 1900 1050 50  0001 C CNN
	1    1900 1050
	1    0    0    -1  
$EndComp
Wire Wire Line
	3650 1700 3500 1700
$Comp
L Device:D_Schottky D?
U 1 1 5D9C88A5
P 3650 1550
AR Path="/5CEF7914/5D9C88A5" Ref="D?"  Part="1" 
AR Path="/5CEF8497/5D9C88A5" Ref="D20"  Part="1" 
F 0 "D20" V 3604 1629 50  0000 L CNN
F 1 "SK54" V 3695 1629 50  0000 L CNN
F 2 "Diode_SMD:D_SMC" H 3650 1550 50  0001 C CNN
F 3 "~" H 3650 1550 50  0001 C CNN
	1    3650 1550
	0    1    1    0   
$EndComp
Wire Wire Line
	3650 1400 3650 1350
Connection ~ 3650 1350
Connection ~ 3500 1700
Wire Wire Line
	3500 1700 3500 2050
$EndSCHEMATC
