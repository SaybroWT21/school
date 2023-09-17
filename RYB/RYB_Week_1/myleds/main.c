#include <libpynq.h>
#include <stdio.h>

int main(void) {
    pynq_init();
    leds_init_onoff();

    printf("Wait for how many milliseconds? \n"); // There's a space for some reason accoriding to the homework description even tho I don't come across it when CTRL C = CTRL V'ing the exact line from said homework description.
    int duration;
    scanf(" %d", &duration);

    if (duration < 0) {
        printf("The number of milliseconds should be at least 0. \n"); // Space at the end just for consistency with previous print statement.
        leds_destroy();
        pynq_destroy();
        return EXIT_SUCCESS;
    }

    for (int i = 0; i < 20; i++) {

        for (int j = 0; i < NUM_GREEN_LEDS; i++) {
            green_led_onoff(j, LED_ON);
            sleep_msec(duration);
            green_led_onoff(j, LED_OFF);
        }

        for (int j = NUM_GREEN_LEDS - 1; j > 0; j--) {
            green_led_onoff(j, LED_ON);
            sleep_msec(duration);
            green_led_onoff(j, LED_OFF); 
        }
    }

    leds_destroy();
    pynq_destroy();
    return EXIT_SUCCESS;
}