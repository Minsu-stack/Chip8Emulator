#ifndef CHIP8EMULATOR_CHIP8_H
#define CHIP8EMULATOR_CHIP8_H
#include <stdint.h>
#include <stdbool.h>
#include "stack.h"
struct Chip8 {
    uint8_t memory[4096];
    bool display[64][32];
    uint16_t programCounter;
    uint16_t i;
    Stack stack;
    //uint8_t stackPointer;
    uint8_t delayTimer;
    uint8_t soundTimer;
    uint8_t V[16];
};

extern struct Chip8 chip8;

#endif //CHIP8EMULATOR_CHIP8_H
