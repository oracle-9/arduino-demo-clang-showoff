#ifndef DEMO_NOTE_H
#define DEMO_NOTE_H

#include <stdint.h>

struct Note {
    uint16_t freq;
    uint16_t dur;
    uint16_t pause;
};

#endif // DEMO_NOTE_H
