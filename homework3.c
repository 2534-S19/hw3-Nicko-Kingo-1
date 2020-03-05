#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include "homework3.h"
#include "myGPIO.h"
#include "myTimer.h"

int main(void)
{
    // Count variables to control the LEDs.
    unsigned int count0 = 0;
    unsigned int count1 = 0;

    // TODO: Declare the variables that main uses to interact with your state machine.
    unsigned char buttonhistory = UNPRESSED;
    bool debounce = false;

    // Stops the Watchdog timer.
    initBoard();
    // Initialize the GPIO.
    // YOU MUST WRITE THIS FUNCTION IN myGPIO.c
    initGPIO();
    // Initialize Timer0 to provide a one second count interval for updating LED2.
    // YOU MUST WRITE THIS FUNCTION IN myTimer.c
    initTimer(TIMER32_0_BASE, TIMER0_PRESCALER, TIMER0_COUNT);
    // Initialize Timer1 to provide a one millisecond count interval for updating the button history.
    // YOU MUST WRITE THIS FUNCTION IN myTimer.c
    initTimer(TIMER32_1_BASE, TIMER1_PRESCALER, TIMER1_COUNT);

    while(1)
    {
        // Update the color of LED2 using count0 as the index.
        // YOU MUST WRITE THIS FUNCTION BELOW.
        changeLaunchpadLED2(count0);
        // Update the color of the Boosterpack LED using count1 as the index.
        // YOU MUST WRITE THIS FUNCTION BELOW.
        changeBoosterpackLED(count1);

        // TODO: If Timer0 has expired, increment count0.
        // YOU MUST WRITE timer0expired IN myTimer.c
        if(timer0Expired())
        {
            count0++;
            if(count0 >=8) count0 = 0; //resets the LED2 counter
        }


        // TODO: If Timer1 has expired, update the button history from the pushbutton value.
        // YOU MUST WRITE timer1expired IN myTimer.c
        if(timer1Expired())
        {
            buttonhistory <<= 1; //moves the button information to the left
            buttonhistory |= (checkStatus_BoosterpackS1());
        }

        // TODO: Call the button state machine function to check for a completed, debounced button press.
        // YOU MUST WRITE THIS FUNCTION BELOW.
        debounce = fsmBoosterpackButtonS1(buttonhistory);

        // TODO: If a completed, debounced button press has occurred, increment count1.
        if(debounce)
        {
            count1++;
            if(count1 >=8) count1 = 0; //resets the LED count
            while(!checkStatus_BoosterpackS1()); //Makes sure that the color doesn't change as I hold down the button
            buttonhistory = 0xFF; //resets the buttonhistory value
        }
    }
}

void initBoard()
{
    WDT_A_hold(WDT_A_BASE);
}

// TODO: Map the value of a count variable to a color for LED2.
// Since count is an unsigned integer, you can mask the value in some way.
void changeLaunchpadLED2(unsigned int count)
{
    switch(count)
    {
    case 0:
        turnOff_LaunchpadLED2Red();
        turnOff_LaunchpadLED2Green();
        turnOff_LaunchpadLED2Blue();
        break;
    case 1:
        turnOn_LaunchpadLED2Red();
        turnOff_LaunchpadLED2Green();
        turnOff_LaunchpadLED2Blue();
        break;
    case 2:
        turnOff_LaunchpadLED2Red();
        turnOn_LaunchpadLED2Green();
        turnOff_LaunchpadLED2Blue();
        break;
    case 3:
        turnOn_LaunchpadLED2Red();
        turnOn_LaunchpadLED2Green();
        turnOff_LaunchpadLED2Blue();
        break;
    case 4:
        turnOff_LaunchpadLED2Red();
        turnOff_LaunchpadLED2Green();
        turnOn_LaunchpadLED2Blue();
        break;
    case 5:
        turnOn_LaunchpadLED2Red();
        turnOff_LaunchpadLED2Green();
        turnOn_LaunchpadLED2Blue();
        break;
    case 6:
        turnOff_LaunchpadLED2Red();
        turnOn_LaunchpadLED2Green();
        turnOn_LaunchpadLED2Blue();
        break;
    case 7:
        turnOn_LaunchpadLED2Red();
        turnOn_LaunchpadLED2Green();
        turnOn_LaunchpadLED2Blue();
        break;
    default:
        turnOff_LaunchpadLED2Red();
        turnOff_LaunchpadLED2Green();
        turnOff_LaunchpadLED2Blue();
        break;

    }
}

// TODO: Maybe the value of a count variable to a color for the Boosterpack LED
// This is essentially a copy of the previous function, using a different LED
void changeBoosterpackLED(unsigned int count)
{
    switch(count)
        {
        case 0:
            turnOff_BoosterpackLEDRed();
            turnOff_BoosterpackLEDGreen();
            turnOff_BoosterpackLEDBlue();
            break;
        case 1:
            turnOn_BoosterpackLEDRed();
            turnOff_BoosterpackLEDGreen();
            turnOff_BoosterpackLEDBlue();
            break;
        case 2:
            turnOff_BoosterpackLEDRed();
            turnOn_BoosterpackLEDGreen();
            turnOff_BoosterpackLEDBlue();
            break;
        case 3:
            turnOn_BoosterpackLEDRed();
            turnOn_BoosterpackLEDGreen();
            turnOff_BoosterpackLEDBlue();
            break;
        case 4:
            turnOff_BoosterpackLEDRed();
            turnOff_BoosterpackLEDGreen();
            turnOn_BoosterpackLEDBlue();
            break;
        case 5:
            turnOn_BoosterpackLEDRed();
            turnOff_BoosterpackLEDGreen();
            turnOn_BoosterpackLEDBlue();
            break;
        case 6:
            turnOff_BoosterpackLEDRed();
            turnOn_BoosterpackLEDGreen();
            turnOn_BoosterpackLEDBlue();
            break;
        case 7:
            turnOn_BoosterpackLEDRed();
            turnOn_BoosterpackLEDGreen();
            turnOn_BoosterpackLEDBlue();
            break;
        }
}

// TODO: Create a button state machine.
// The button state machine should return true or false to indicate a completed, debounced button press.
bool fsmBoosterpackButtonS1(unsigned char buttonhistory)
{
    //Note, my Boosterpack LED functions similarly to the golden solution,
    //though the led changes on the pull up of the button instead of the push down.

    if(buttonhistory == 0x00)
        return true;
    return false;
}
