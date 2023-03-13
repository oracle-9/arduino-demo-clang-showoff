#ifndef DEMO_MELODY_H
#define DEMO_MELODY_H

#include "note.h"

#include <avr/pgmspace.h>
#include <stddef.h>

extern struct Note const MELODY[] PROGMEM;
extern size_t const MELODY_LEN;

#endif // DEMO_MELODY_H
