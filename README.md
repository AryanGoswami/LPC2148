### **LPC2148 Microcontroller Key Points:**

The LPC2148 microcontroller is based on the ARM7 family and is available in a small LQFP64 package. It has an on-chip static RAM of 8 kB-40 kB and an on-chip flash memory of 32 kB-512 kB. The wide interface is 128 bit, or accelerator allows 60 MHz high-speed operation. It takes 400 milliseconds time for erasing the data in full chip and 1 millisecond time for 256 bytes of programming. Embedded Trace interfaces and Embedded ICE RT offers real-time debugging with high-speed tracing of instruction execution and on-chip Real Monitor software. It has 2 kB of endpoint RAM and USB 2.0 full speed device controller.

### Description:
This repository contains a collection of code examples demonstrating various functionalities of 
the LPC2148 microcontroller. Each example includes a C code file (.c) illustrating a specific use 
case.

### Contents:
DAC.c: Code for Digital-to-Analog Converter (DAC) operation
DHT11(Temperature_Humidity_Sensor).c: Code for interfacing with a DHT11 temperature and humidity 
sensor
INTERFACING_SERVO_MOTOR_USING_PWM.c: Code for controlling a servo motor using Pulse-Width 
Modulation (PWM)
KEYPAD.c: Code for interfacing with a keypad
LCD.c: Code for interfacing with a Liquid Crystal Display (LCD)
LED BLINK_FLASH.c: Code for blinking and flashing LED
LED_CHASE.c: Code for creating a LED chase effect
LED_RELAY_BUZZER.pdf: This is a PDF file, containing information related to LED, relay, 
and buzzer control

### Usage:
Set Up Development Environment: Ensure you have a suitable development environment set up for 
NXP LPC2148 microcontrollers, such as Keil uVision.
Import Projects: Import the individual C files into your development environment and configure 
the project settings accordingly.
Build and Run: Compile and run the code to observe the desired functionality.
