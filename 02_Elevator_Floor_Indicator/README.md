# STM32 Bare-Metal Elevator Floor Indicator

A bare-metal STM32 project that uses a push button to select elevator floors and two LEDs to indicate the current floor.

## Functionality

- Initially, the elevator is at Floor 1.
- 1 button press → Floor 1 → LED 1 ON
- 2 button presses → Floor 2 → LED 2 ON
- 3 button presses → Floor 1 → LED 1 ON
- 4 button presses → Floor 2 → LED 2 ON
- The pattern continues alternately.

## Hardware

- STM32 Microcontroller
- Push Button
- 2 LEDs
- Current-limiting resistors

## Programming

- Language: C
- Programming approach: Bare-metal STM32
