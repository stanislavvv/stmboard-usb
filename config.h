/**
 * @file config.h
 * @brief project configuration definitions
 *
 * Copyright 2020 Stanislav V. Vlasov <stanislav.v.v@gmail.com>
 *
 */

/* hardware definitions for STM32F103 now */

/**
 * onboard blue pill led port
 */
#define LED_PORT            GPIOC

/**
 * onboard blue pill led pin
 */
#define LED_PIN             GPIO13

/**
 * onboard blue pill led pin number
 */
#define LED_PIN_NUM         13

/**
 * rotary encoder with button pins
 * @{
 */
#define ENCODER_BUTTON_PORT GPIOA
#define ENCODER_BUTTON_PIN  GPIO15
#define ENCODER_QUAD_PORT   GPIOB
#define ENCODER_QUAD_PIN1   GPIO3
#define ENCODER_QUAD_PIN2   GPIO4
/**
 * @}
 */

/**
 * uart port
 */
#define UART USART1
#define UART_RCC RCC_USART1
#define UART_SPEED 921600 // max speed on some usb-uart converters

/**
 * shell will be echo input chars
 */
#define SHELL_ECHO 1

/**
 * initalization messages to uart
 */
#define BOOT_VERBOSE 1

#define DEBUG 1
