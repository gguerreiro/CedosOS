#include <Arduino.h>

#ifdef SERIAL_DEBUG

#ifndef SERIAL_BAUD
#define SERIAL_BAUD 115200
#endif

#define SETUP_DEBUG() Serial.begin(SERIAL_BAUD)
#define DEBUGLN(message) Serial.println(message)
#define DEBUG(message) Serial.print(message)

#else

#define SETUP_DEBUG /**/
#define DEBUGLN(message) /**/
#define DEBUG(message) /**/

#endif
