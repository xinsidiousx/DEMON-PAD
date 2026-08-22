#include <Arduino.h>

const uint8_t ROW_PINS[4] = {0, 1, 2, 3};
const uint8_t COL_PINS[4] = {4, 5, 6, 7};
const unsigned long DEBOUNCE_MS = 5;

bool stableState[16] = {false};
bool lastRawState[16] = {false};
unsigned long lastChangeTime[16] = {0};

void setup() {
  for (uint8_t r = 0; r < 4; r++) {
    pinMode(ROW_PINS[r], OUTPUT);
    digitalWrite(ROW_PINS[r], HIGH); // filas inactivas en HIGH
  }
  for (uint8_t c = 0; c < 4; c++) {
    pinMode(COL_PINS[c], INPUT_PULLUP);
  }
}

void loop() {
  unsigned long now = millis();

  for (uint8_t r = 0; r < 4; r++) {
    digitalWrite(ROW_PINS[r], LOW); // activamos solo esta fila
    delayMicroseconds(5);           // pequeño tiempo de asentamiento (microsegundos, no bloquea nada relevante)

    for (uint8_t c = 0; c < 4; c++) {
      uint8_t padIndex = r * 4 + c; // convierte (fila, columna) en un número de pad 0-15
      bool rawPressed = (digitalRead(COL_PINS[c]) == LOW);

      if (rawPressed != lastRawState[padIndex]) {
        // la lectura cruda cambió: reiniciamos el conteo de debounce
        lastRawState[padIndex] = rawPressed;
        lastChangeTime[padIndex] = now;
      } else if (rawPressed != stableState[padIndex] &&
                 (now - lastChangeTime[padIndex]) >= DEBOUNCE_MS) {
        // se mantuvo estable el tiempo suficiente: confirmamos el cambio
        stableState[padIndex] = rawPressed;

        uint8_t note = 36 + padIndex; // nota base 36, mapeo fila por fila
        if (rawPressed) {
          usbMIDI.sendNoteOn(note, 100, 1);
        } else {
          usbMIDI.sendNoteOff(note, 0, 1);
        }
      }
    }

    digitalWrite(ROW_PINS[r], HIGH); // apagamos la fila antes de pasar a la siguiente
  }
}