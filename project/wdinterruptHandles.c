#include <msp430.h>
#include "buzzer.h"
#include "led.h"
#include "switches.h"

//referenced from demo code
void decisec() //desisecond timer
{
  static char count = 0; //DS freq change

  if (++count > 2)
    {
      buzzer_adv_freq();
      count=0;
    }

}

void
__interrupt_vec(WDT_VECTOR) WDT()
{
  static char sec_count = 0;  //second count
  static char deci_count = 0; //  decisecond count


  if (++sec_count == 250)
    sec_count = 0;
  if (++deci_count == 25)
    {
      switch_interrupt_handler();
      buzzer_adv_freq();
      deci_count = 0;
    }
  led_update();
}
