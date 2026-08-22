# TEST01 — Teensy reconocido como dispositivo USB-MIDI

## Objetivo
Confirmar que el Teensy 4.1 se presenta ante el computador como un dispositivo USB-MIDI nativo, sin software intermediario (sin Hairless/loopMIDI).

## Configuración
- `platform = teensy`
- `board = teensy41`
- `framework = arduino`
- `build_flags = -D USB_MIDI`

## Qué hace el código
Envía un mensaje `Note On` (nota 60, velocidad 100, canal 1) cada 2 segundos, seguido de su `Note Off`, solo para validar la comunicación — sin pads todavía.

## Resultado
- [ ] Compila sin errores
- [ ] Sube correctamente al Teensy
- [ ] Aparece como dispositivo MIDI en el sistema operativo
- [ ] Se reciben los mensajes Note On/Off en un monitor MIDI o DAW

## Notas / problemas encontrados
- El primer intento de subida falló porque el cable USB usado no transmitía datos (solo carga). Se resolvió cambiando de puerto/cable.
- Error inicial en `platformio.ini`: `platform = teensyduino` no existe; el nombre correcto es `platform = teensy`.

## Conceptos aprendidos
- Diferencia entre plataformas con USB nativo (Teensy) y sin él (ESP32 clásico).
- Qué hace `build_flags` y qué pasa si falta.
- Qué es el modo bootloader (botón de programación) y para qué sirve.
