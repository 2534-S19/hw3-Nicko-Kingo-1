/*
 * myGPIO.h
 *
 *  Created on: 3/5/2020
 *      Author: Nick King
 *
 */

#ifndef MYGPIO_H_
#define MYGPIO_H_

// This function initializes the peripherals used in the program.
void initGPIO();
// This function returns the value of Launchpad S1.
unsigned char checkStatus_LaunchpadS1();
// This function returns the value of Launchpad S2.
unsigned char checkStatus_LaunchpadS2();
// This function returns the value of Boosterpack S1.
unsigned char checkStatus_BoosterpackS1();
// This function returns the value of Boosterpack S2.
unsigned char checkStatus_BoosterpackS2();
// This function turns on Launchpad LED1.
void turnOn_LaunchpadLED1();
// This function turns off Launchpad LED1.
void turnOff_LaunchpadLED1();
// This function turns on Launchpad Red LED2.
void turnOn_LaunchpadLED2Red();
// This function turns off Launchpad Red LED2.
void turnOff_LaunchpadLED2Red();
// This function turns on Launchpad Blue LED2.
void turnOn_LaunchpadLED2Blue();
// This function turns off Launchpad Blue LED2.
void turnOff_LaunchpadLED2Blue();
// This function turns on Launchpad Green LED2.
void turnOn_LaunchpadLED2Green();
// This function turns off Launchpad Green LED2.
void turnOff_LaunchpadLED2Green();
// This function turns on Boosterpack Red LED.
void turnOn_BoosterpackLEDRed();
// This function turns off Boosterpack Red LED.
void turnOff_BoosterpackLEDRed();
// This function turns on Boosterpack Green LED.
void turnOn_BoosterpackLEDGreen();
// This function turns off Boosterpack Green LED.
void turnOff_BoosterpackLEDGreen();
// This function turns on Boosterpack Blue LED.
void turnOn_BoosterpackLEDBlue();
// This function turns off Boosterpack Blue LED.
void turnOff_BoosterpackLEDBlue();

// TODO: Define any constants that are local to myGPIO.c using #define
//Macros I have defined to make the initial function calls easier
#define LPBUTTON1           BIT1
#define LPBUTTON2           BIT4
#define BPBUTTON1           BIT1
#define BPBUTTON2           BIT5

#define LPLED1              BIT0

#define LEDR                BIT0
#define LEDG                BIT1
#define LEDB                BIT2

#define BLEDR               BIT6
#define BLEDG               BIT4
#define BLEDB               BIT6

#define PORT1               GPIO_PORT_P1
#define PORT2               GPIO_PORT_P2
#define PORT3               GPIO_PORT_P3
#define PORT5               GPIO_PORT_P5

#endif /* MYGPIO_H_ */
