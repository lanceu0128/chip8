#ifndef CHIP_8_H
#define CHIP_8_H
#include <stdint.h>

class Chip8 {
public:
    uint8_t memory[4096];

    uint8_t display[64*32];

    uint8_t V[16];

    uint16_t pc;

    uint16_t I;

    uint16_t stack[16];
    

    uint8_t delay;
    uint8_t sound;

    Chip8();
    void reset();
};

#endif