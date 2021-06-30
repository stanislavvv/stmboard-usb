/** @weakgroup utils
 *  @{
 */
/**
 * @file main.c
 * @brief main procedure of control board experiments
 *
 * Copyright 2020 Stanislav V. Vlasov <stanislav.v.v@gmail.com>
 *
 */
#include "FreeRTOS.h"
#include "task.h"

#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>

#include "config.h"
#include "hw.h"
#include "hw/usb.h"

// tasks
#include "shell/shell.h"
#include "morse.h"
static char s[] = "Hello world!!!";

#if(  configCHECK_FOR_STACK_OVERFLOW > 0 )
/**
 * @addtogroup rtos
 * stuff for freertos - catch stack overflow error and hang
 */
    extern void vApplicationStackOverflowHook( TaskHandle_t xTask, char *pcTaskName );

    void vApplicationStackOverflowHook( TaskHandle_t pxTask, char *pcTaskName )
    {
        /* This function will get called if a task overflows its stack. */
        ( void ) pxTask;
        ( void ) pcTaskName;
        for (;;) { };
    }
#endif

// test morse task
static void task_hello(void *args __attribute((unused)))
{
    for (;;)
    {
        send_string(s);
        lspc();
    }
}

/**
 * @brief main procedure
 * init hardware, create FreeRTOS tasks and run scheduler
 */
int main(void)
{

    init_hw();

    //xTaskCreate(task_hello, "hello", 100, NULL, configMAX_PRIORITIES-1, NULL);
    xTaskCreate(shell_task, "shell", 500, NULL, 1, NULL);
    xTaskCreate(usb_task, "usb", 1000, NULL, 1, NULL);
    vTaskStartScheduler();

    for (;;) { };
    return 0;
}

/**
 * @}
 */
