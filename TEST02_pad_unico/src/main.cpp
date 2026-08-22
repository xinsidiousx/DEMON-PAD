#include <Arduino.h>

const int PAD_PIN = 2;

bool padPressed = false;  // guarda si el pad estaba presionado la última vez que revisamos

void setup() {
  pinMode(PAD_PIN, INPUT_PULLUP);
}

void loop() {
  bool currentlyPressed = (digitalRead(PAD_PIN) == LOW); // LOW = presionado, por el pull-up

  if (currentlyPressed && !padPressed) {
    // acaba de pasar de suelto a presionado
    usbMIDI.sendNoteOn(60, 100, 1);
  }

  if (!currentlyPressed && padPressed) {
    // acaba de pasar de presionado a suelto
    usbMIDI.sendNoteOff(60, 0, 1);
  }

  padPressed = currentlyPressed; // actualizamos el "recuerdo" para la próxima vuelta
}