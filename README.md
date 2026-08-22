# 😈 DEMON PAD

Controlador MIDI modular para producción y performance musical — proyecto de Ingeniería Electrónica.

Basado conceptualmente en un controlador 4×4 construido en el colegio, pero desarrollado desde cero como una plataforma de hardware y firmware propia.

## Estado actual: V1.0 — en desarrollo

## Hardware (V1.0)
| Elemento | Detalle |
|---|---|
| MCU | Teensy 4.1 |
| Pads | 16 (matriz 4×4), mecánicos + diodo por switch |
| LEDs | 16 RGB, WS2812B (provisional) |
| Potenciómetros | 4, para MIDI CC |
| Pantalla | OLED SSD1306 128×64, I2C (provisional) |
| Encoder | Rotativo con pulsador |
| Comunicación | USB-MIDI nativo |

## Mapa de pines (Teensy 4.1)
| Función | Pin |
|---|---|
| Matriz — Filas | 0, 1, 2, 3 |
| Matriz — Columnas | 4, 5, 6, 7 |
| LED data | 8 |
| Encoder A / B / SW | 9 / 10 / 11 |
| Potenciómetros 1-4 | A0, A1, A2, A3 (14-17) |
| OLED SDA / SCL | 18 / 19 |

## Decisiones MIDI
- Canal: 1
- Nota base (pad 1): 36 (C1), mapeo fila por fila (36-51)
- Potenciómetros → CC 20-23
- Sin velocity en V1

## Plan de pruebas

| Test | Objetivo | Estado |
|---|---|---|
| [TEST01](./tests/TEST01_usb_midi/) | Teensy reconocido como dispositivo USB-MIDI | 🟡 En progreso |
| TEST02 | 1 pad físico → Note On/Off | ⬜ Pendiente |
| TEST03 | Matriz 4×4 completa (16 pads) | ⬜ Pendiente |
| TEST04 | 16 LEDs RGB | ⬜ Pendiente |
| TEST05 | 4 potenciómetros → MIDI CC | ⬜ Pendiente |
| TEST06 | OLED + encoder | ⬜ Pendiente |
| TEST07 | Sistema completo + medición de latencia | ⬜ Pendiente |

## Estructura del repositorio
```
DEMON-PAD/
├── README.md                  <- este archivo
├── tests/
│   ├── TEST01_usb_midi/
│   │   ├── src/main.cpp
│   │   ├── platformio.ini
│   │   └── README.md          <- qué se probó, qué se aprendió, resultado
│   ├── TEST02_pad_unico/
│   ├── TEST03_matriz_4x4/
│   └── ...
├── firmware/                  <- versión modular final (cuando lleguemos a TEST07)
│   ├── src/
│   └── include/
└── docs/
    ├── mapa_de_pines.md
    └── decisiones_de_diseno.md
```

## Roadmap post-V1.0
V1.1 interfaz → V1.2 configuración → V1.3 presets → V1.4 Drum Mode → V1.5 secuenciador experimental → V1.X optimización → V2.0 (8×8, 64 pads) → V3.0 (funciones avanzadas / velocity)
