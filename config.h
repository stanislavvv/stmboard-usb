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
 * shell will be echo input chars
 */
#define SHELL_ECHO 1

/**
 * initalization messages to uart
 */
#define BOOT_VERBOSE 0

/// Debug output flag
#define DEBUG 0

/// USB flag
#define USE_USB 0

#if USE_USB==1
  /// MCU clock speed (48MHz for USB)
  #define CLOCK_SPEED RCC_CLOCK_HSI_48MHZ
  
  // Debug log and shell via USB-CDC
#else
  /// MCU clock speed (72MHz without USB)
  #define CLOCK_SPEED RCC_CLOCK_HSE8_72MHZ

  /// debug and shell hardware uart port without usb
  #define UART USART1
  #define UART_RCC RCC_USART1
  #define UART_SPEED 921600 // max speed on some usb-uart converters

#endif

// EOF
