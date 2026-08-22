# TEST02 — 1 pad físico → Note On/Off

## Objetivo
Confirmar la detección de un solo botón físico (sin matriz todavía) y su traducción a mensajes MIDI Note On/Note Off, sin repetir el mensaje mientras se mantiene presionado.

## Conexión
```
Pin 2 (Teensy) ──── Botón ──── GND (Teensy)
```
Usa la resistencia interna de pull-up del Teensy (`INPUT_PULLUP`), sin necesidad de resistencia externa.

## Configuración
- `platform = teensy`
- `board = teensy41`
- `framework = arduino`
- `build_flags = -D USB_MIDI`

## Qué hace el código
Guarda el estado anterior del botón en una variable `bool padPressed`. En cada vuelta del `loop()`, compara el estado actual contra el anterior:
- Si pasó de suelto → presionado: manda `Note On`.
- Si pasó de presionado → suelto: manda `Note Off`.

Esto evita mandar el mismo mensaje cientos de veces por segundo mientras el botón se mantiene presionado (detección de flancos).

## Resultado
- [ ] Compila sin errores
- [ ] Sube correctamente al Teensy
- [ ] Al presionar el botón se recibe un único Note On
- [ ] Al soltar el botón se recibe un único Note Off

## Notas / problemas encontrados
- Pendiente de probar físicamente por falta de cable de datos micro-USB compatible con el Teensy.

## Conceptos aprendidos
- Diferencia entre tipo de dato (`bool`) y estructura de control (`if`).
- Detección de flancos: comparar el estado actual contra el estado anterior para detectar un *cambio*, no un estado constante.
