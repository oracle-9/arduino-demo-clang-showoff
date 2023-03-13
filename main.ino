#include "include/config.h"
#include "include/melody.h"

static void play();
static void nop();
static void button_interrupt_handler();

typedef void job_fn_t();
static volatile job_fn_t* work = play;

static size_t note_iter = 0;

void setup() {
    pinMode(LED_PIN, OUTPUT);
    attachInterrupt(
        digitalPinToInterrupt(BUTTON_PIN),
        button_interrupt_handler,
        FALLING
    );
}

void loop() {
    work();
}

static void play() {
    struct Note note;
    memcpy_P(&note, MELODY + note_iter, sizeof(note));
    digitalWrite(LED_PIN, HIGH);
    tone(PIEZO_PIN, note.freq, note.dur);
    digitalWrite(LED_PIN, LOW);
    delay(note.pause);
    note_iter = (note_iter + 1) % MELODY_LEN;
}

static void nop() {}

static void button_interrupt_handler() {
    if (work == play) {
        work = nop;
    } else {
        work = play;
    }
}
