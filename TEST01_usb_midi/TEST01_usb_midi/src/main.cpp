#include <Arduino.h>

void setup() {
}

void loop() {
  usbMIDI.sendNoteOn(60, 100, 1);
  delay(500);
  usbMIDI.sendNoteOff(60, 0, 1);
  delay(1500);
}