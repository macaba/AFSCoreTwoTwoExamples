#include "Audio.h"
#include "Audio_AFS.h"
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "driver/gpio.h"
#include "driver/i2c.h"
#include "esp_wifi.h"
#include "xi2c.h"
#include "fonts.h"
#include "ssd1306.h"
#include "nvs_flash.h"

AudioControlAFSCoreTwoTwo    afs22;

xSemaphoreHandle print_mux;

static void i2c_test(void * parameter )
{
    SSD1306_GotoXY(40, 4);
    SSD1306_Puts("ESP32", &Font_7x10, SSD1306_COLOR_WHITE);
    
    /* Go to location X = 20, Y = 25 */
    SSD1306_GotoXY(8, 25);
    SSD1306_Puts("I2C SSD1306 OLED", &Font_7x10, SSD1306_COLOR_WHITE);
    
    /* Go to location X = 15, Y = 45 */
    SSD1306_GotoXY(20, 45);
    SSD1306_Puts("Akbar Hashim", &Font_7x10, SSD1306_COLOR_WHITE);
    
    /* Update screen, send changes to LCD */
    SSD1306_UpdateScreen();

    while (1) {
        /* Invert pixels */
        SSD1306_ToggleInvert();
        
        /* Update screen */
        SSD1306_UpdateScreen();
        
        /* Make a little delay */
        vTaskDelay(50);
    }

}

extern "C" {
   void app_main();
}

void app_main()
{
    print_mux = xSemaphoreCreateMutex();
    afs22.init();
    vTaskDelay(50/portTICK_RATE_MS);   
    SSD1306_Init();

    xTaskCreatePinnedToCore(i2c_test, "i2c_test", 1024, NULL, 1, NULL, 1);
}
