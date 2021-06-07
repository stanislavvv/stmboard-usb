/* copyright string for vera++ */
/* morse functions */
/* not for production use */

#define DIT_LENGTH 200 /* length of dot in ms */
#define DAH_LENGTH DIT_LENGTH * 3 /* length of dash in ms */

/* long pause */
#define lspc() vTaskDelay(pdMS_TO_TICKS(DAH_LENGTH));

/* short pause */
#define sspc() vTaskDelay(pdMS_TO_TICKS(DIT_LENGTH));

/* send morse character */
void send_morse_letter(char c);
/* send string */
void send_morse_string(char s[]);
