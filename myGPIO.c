/*
 * GPIO.c
 *
 *  Created on: 3/5/2020
 *      Author: Nick King
 */

// For the code you place here, you may use your code that uses register references.
// However, I encourage you to start using the Driver Library as soon as possible.

#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include "myGPIO.h"

// TODO: Create a function to initialize the GPIO.
// Even though this assignment does not use all of the pushbuttons, you should write one function that does a complete GPIO init.
void initGPIO()
{
    //initalizes all of the GPIO peripherals
    GPIO_setAsInputPinWithPullDownResistor (PORT1, LPBUTTON1);

    GPIO_setAsInputPinWithPullDownResistor (PORT1, LPBUTTON2);

    GPIO_setAsInputPinWithPullDownResistor (PORT5, BPBUTTON1);

    GPIO_setAsInputPinWithPullDownResistor (PORT3, BPBUTTON2);

    GPIO_setAsOutputPin (PORT1, LPLED1);

    GPIO_setAsOutputPin (PORT2, LEDR);

    GPIO_setAsOutputPin (PORT2, LEDG);

    GPIO_setAsOutputPin (PORT2, LEDB);

    GPIO_setAsOutputPin (PORT2, BLEDR);

    GPIO_setAsOutputPin (PORT2, BLEDG);

    GPIO_setAsOutputPin (PORT5, BLEDB);

    //makes sure that all outputs are off
    turnOff_LaunchpadLED1();
    turnOff_LaunchpadLED2Red();
    turnOff_LaunchpadLED2Green();
    turnOff_LaunchpadLED2Blue();
    turnOff_BoosterpackLEDRed();
    turnOff_BoosterpackLEDGreen();
    turnOff_BoosterpackLEDBlue();
}

// TODO: Create a function to return the status of Launchpad Pushbutton S1
unsigned char checkStatus_LaunchpadS1()
{
    return GPIO_getInputPinValue(PORT1, LPBUTTON1);
}

// TODO: Create a function to return the status of Launchpad Pushbutton S2
unsigned char checkStatus_LaunchpadS2()
{
    return GPIO_getInputPinValue(PORT1, LPBUTTON2);
}

// TODO: Create a function to return the status of Boosterpack Pushbutton S1
unsigned char checkStatus_BoosterpackS1()
{
    return GPIO_getInputPinValue(PORT5, BPBUTTON1);
}

// TODO: Create a function to return the status of Boosterpack Pushbutton S2
unsigned char checkStatus_BoosterpackS2()
{
    return GPIO_getInputPinValue(PORT3, BPBUTTON2);
}

// TODO: Create a function to turn on Launchpad LED1.
void turnOn_LaunchpadLED1()
{
    GPIO_setOutputHighOnPin (PORT1, LPLED1);
}

// TODO: Create a function to turn off Launchpad LED1.
void turnOff_LaunchpadLED1()
{
    GPIO_setOutputLowOnPin (PORT1, LPLED1);
}

// TODO: Create a function to turn on the Red Launchpad LED2.
void turnOn_LaunchpadLED2Red()
{
    GPIO_setOutputHighOnPin (PORT2, LEDR);
}

// TODO: Create a function to turn off the Red Launchpad LED2.
void turnOff_LaunchpadLED2Red()
{
    GPIO_setOutputLowOnPin (PORT2, LEDR);
}

// TODO: Create a function to turn on the Green Launchpad LED2.
void turnOn_LaunchpadLED2Green()
{
    GPIO_setOutputHighOnPin (PORT2, LEDG);
}

// TODO: Create a function to turn off the Green Launchpad LED2.
void turnOff_LaunchpadLED2Green()
{
    GPIO_setOutputLowOnPin (PORT2, LEDG);
}

// TODO: Create a function to turn on the Blue Launchpad LED2.
void turnOn_LaunchpadLED2Blue()
{
    GPIO_setOutputHighOnPin (PORT2, LEDB);
}

// TODO: Create a function to turn off the Blue Launchpad LED2.
void turnOff_LaunchpadLED2Blue()
{
    GPIO_setOutputLowOnPin (PORT2, LEDB);
}

// TODO: Create a function to turn on the Red Boosterpack LED2.
void turnOn_BoosterpackLEDRed()
{
    GPIO_setOutputHighOnPin (PORT2, BLEDR);
}

// TODO: Create a function to turn off the Red Boosterpack LED2.
void turnOff_BoosterpackLEDRed()
{
    GPIO_setOutputLowOnPin (PORT2, BLEDR);
}

// TODO: Create a function to turn on the Green Boosterpack LED2.
void turnOn_BoosterpackLEDGreen()
{
    GPIO_setOutputHighOnPin (PORT2, BLEDG);
}

// TODO: Create a function to turn off the Green Boosterpack LED2.
void turnOff_BoosterpackLEDGreen()
{
    GPIO_setOutputLowOnPin (PORT2, BLEDG);
}

// TODO: Create a function to turn on the Blue Boosterpack LED2.
void turnOn_BoosterpackLEDBlue()
{
    GPIO_setOutputHighOnPin (PORT5, BLEDB);
}

// TODO: Create a function to turn off the Green Boosterpack LED2.
void turnOff_BoosterpackLEDBlue()
{
    GPIO_setOutputLowOnPin (PORT5, BLEDB);
}
