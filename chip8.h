#ifndef CHIP_8_H
#define CHIP_8_H

class Chip8 {
    const int mem = 4096
    uint8_t memory[mem];

    uint8_t display[64*32];

    uint8_t V[16];

    uint16_t pc;

    uint16_t I;

    uint16_t stack[16];

    uint8_t delay;
    uint8_t sound;

}

#endif