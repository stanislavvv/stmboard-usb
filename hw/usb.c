/** @weakgroup hardware
 *  @{
 */
/**
 * @file usb.h
 * @brief usb functions
 *
 * based on libopencm3 usb-cdcexample
 *
 * Copyright 2021 Stanislav V. Vlasov <stanislav.v.v@gmail.com>
 */

#include <stdlib.h>
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/usb/usbd.h>
#include <libopencm3/usb/cdc.h>
#include "hw.h"
#include "config.h"
#include "usb.h"

int led_stat = 0;

usbd_device *usbd_dev_g; // 'g' for 'global'

/// @internal Buffer to be used for control requests.
uint8_t usbd_control_buffer[128];

/**
 * @brief init usb hardware
 */
void usb_init(void)
{
    //AFIO_MAPR |= AFIO_MAPR_SWJ_CFG_JTAG_OFF_SW_ON;

    gpio_set_mode(LED_PORT, GPIO_MODE_INPUT, 0, LED_PIN);

    usbd_dev_g = usbd_init(
                &st_usbfs_v1_usb_driver, &dev, &config, usb_strings,
                3, usbd_control_buffer, sizeof(usbd_control_buffer));
    usbd_register_set_config_callback(usbd_dev_g, cdcacm_set_config);

    gpio_set(LED_PORT, LED_PIN);
    gpio_set_mode(LED_PORT, GPIO_MODE_OUTPUT_2_MHZ,
                  GPIO_CNF_OUTPUT_PUSHPULL, LED_PIN);
}

/**
 * @brief usb rtos task
 */
void usb_task(void *args __attribute((unused)))
{

    while (1)
    {
        usbd_poll(usbd_dev_g);
        delay_ms(1); // switch to another task
    }
}
///@}
