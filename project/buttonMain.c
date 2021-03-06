#include <msp430.h>
#include "libTimer.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"
#include "state_machine.h"

void main(void)
{

  configureClocks();
  switch_init();

  
  led_init();
  led_update(); //For button press

  buzzer_init(); //For button press

  enableWDTInterrupts();
  or_sr(0x18); //CPU off, GIE on
}
