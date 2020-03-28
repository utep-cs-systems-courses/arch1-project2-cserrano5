#include <msp430.h>
#include "state_machine.h"
#include "led.h"

void led_state(int state)
{

  char flags = 0;

  //switch cases
  switch(state)
    {
      //Button 1, GREEN
    case 0:
      flags |= LED_GREEN; 
      P1OUT &= (0xff ^ LEDS) | flags;
      P1OUT |= flags;
      break;

      //Button 2, RED
    case 1:
      flags |= LED_RED; 
      P1OUT &= (0xff ^ LEDS) | flags;
      P1OUT |= flags;
      break;

      //Button 3, BOTH LED
    case 2: 
      flags |= LEDS;
      P1OUT &= (0xff ^ LEDS) | flags;
      P1OUT |= flags;
      break;

      //Button 4, NO LED
    case 3: //Button 4, NO LED
      P1OUT &= ~LEDS;
      break;
    default:
      break;
    }
}
