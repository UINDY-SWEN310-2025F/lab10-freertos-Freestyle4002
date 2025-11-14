#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"


void taskFirst(void *p) {
    int count = 0;
    while (count < 3) {
        printf("hello task1: count %d\n", count);
        count++;
        vTaskDelay(500 / portTICK_PERIOD_MS);
    }
    vTaskDelete(NULL);
}

void taskSecond(void *p) {
    int count = 0;
    while (count < 3) {
        printf("hello task2: count %d\n", count);
        count++;
        vTaskDelay(600 / portTICK_PERIOD_MS);
    }
    vTaskDelete(NULL);
}

void taskThird(void *p) {
    int count = 0;
    while (count < 3) {
        printf("hello task3: count %d\n", count);
        count++;
        vTaskDelay(700 / portTICK_PERIOD_MS);
    }
    vTaskDelete(NULL);
}


void app_main(void)
{
    xTaskCreate(taskFirst, "task1", 2048, NULL, 3, NULL);
    xTaskCreate(taskSecond, "task2", 2048, NULL, 3, NULL);
    xTaskCreate(taskThird, "task3", 2048, NULL, 3, NULL);
    
    return;
}