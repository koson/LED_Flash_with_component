#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "LED.h"

LED led1(5); 
LED led2(17); 
LED led3(18); 


void ALL_LED_OFF()
{
    led1.OFF();
    led2.OFF();
    led3.OFF();
}

extern "C" void app_main(void)
{
    int i = 0;
    while(1)
    {        
        switch(i)
        {
            case 0:
            led1.ON();
            break;
            case 1:
            led2.ON();
            break;
            case 2:
            led3.ON();
            break;
        }
        vTaskDelay(100/portTICK_PERIOD_MS);
        ALL_LED_OFF();
        if(i++ >= 2) i = 0;
    }
}