/* copyright string for vera++ */
#include "FreeRTOS.h"
#include "task.h"
#include <libopencm3/stm32/gpio.h>
#include "morse.h"
#include "hw.h"

/* send dot */
static inline void dit(void)
{
  LED_on();
  sspc();
  LED_off();
  sspc();
}

/* send dash */
static inline void dah(void)
{
  LED_on();
  lspc();
  LED_off();
  sspc();
}

/* send morse character */
void send_morse_letter(char c)
{
  switch (c)
  {
    case 'A':
    case 'a':
      dit(); dah();
      lspc();
      break;
    case 'B':
    case 'b':
      dah(); dit(); dit(); dit();
      lspc();
      break;
    case 'C':
    case 'c':
      dah(); dit(); dah(); dit();
      lspc();
      break;
    case 'D':
    case 'd':
      dah(); dit(); dit();
      lspc();
      break;
    case 'E':
    case 'e':
      dit();
      lspc();
      break;
    case 'F':
    case 'f':
      dit(); dit(); dah(); dit();
      lspc();
      break;
    case 'G':
    case 'g':
      dah(); dah(); dit();
      lspc();
      break;
    case 'H':
    case 'h':
      dit(); dit(); dit(); dit();
      lspc();
      break;
    case 'I':
    case 'i':
      dit(); dit();
      lspc();
      break;
    case 'J':
    case 'j':
      dit(); dah(); dah(); dah();
      lspc();
      break;
    case 'K':
    case 'k':
      dah(); dit(); dah();
      lspc();
      break;
    case 'L':
    case 'l':
      dit(); dah(); dit(); dit();
      lspc();
      break;
    case 'M':
    case 'm':
      dah(); dah();
      lspc();
      break;
    case 'N':
    case 'n':
      dah(); dit();
      lspc();
      break;
    case 'O':
    case 'o':
      dah(); dah(); dah();
      lspc();
      break;
    case 'P':
    case 'p':
      dit(); dah(); dah(); dit();
      lspc();
      break;
    case 'Q':
    case 'q':
      dah(); dit(); dah(); dah();
      lspc();
      break;
    case 'R':
    case 'r':
      dit(); dah(); dit();
      lspc();
      break;
    case 'S':
    case 's':
      dit(); dit(); dit();
      lspc();
      break;
    case 'T':
    case 't':
      dah();
      lspc();
      break;
    case 'U':
    case 'u':
      dit(); dit(); dah();
      lspc();
      break;
    case 'V':
    case 'v':
      dit(); dit(); dit(); dah();
      lspc();
      break;
    case 'W':
    case 'w':
      dit(); dah(); dah();
      lspc();
      break;
    case 'X':
    case 'x':
      dah(); dit(); dit(); dah();
      lspc();
      break;
    case 'Y':
    case 'y':
      dah(); dit(); dah(); dah();
      lspc();
      break;
    case 'Z':
    case 'z':
      dah(); dah(); dit(); dit();
      lspc();
      break;
    case '0':
      dah(); dah(); dah(); dah(); dah();
      lspc();
      break;
    case '1':
      dit(); dah(); dah(); dah(); dah();
      lspc();
      break;
    case '2':
      dit(); dit(); dah(); dah(); dah();
      lspc();
      break;
    case '3':
      dit(); dit(); dit(); dah(); dah();
      lspc();
      break;
    case '4':
      dit(); dit(); dit(); dit(); dah();
      lspc();
      break;
    case '5':
      dit(); dit(); dit(); dit(); dit();
      lspc();
      break;
    case '6':
      dah(); dit(); dit(); dit(); dit();
      lspc();
      break;
    case '7':
      dah(); dah(); dit(); dit(); dit();
      lspc();
      break;
    case '8':
      dah(); dah(); dah(); dit(); dit();
      lspc();
      break;
    case '9':
      dah(); dah(); dah(); dah(); dit();
      lspc();
      break;
    default:  /* any other character */
      lspc();
  }
}

/* send zero-terminated string */
void send_morse_string(char s[])
{
  for (uint8_t i = 0; s[i] != '\0'; i++)
  {
    send_morse_letter(s[i]);
    if (i == 255) { break; } /* strlen(s) <= 256 */
  }
}
