#ifndef CHIP_8_H
#define CHIP_8_H
#include <stdint.h>
#include <thread>

class Chip8 {
public:
    static constexpr int DISPLAY_HEIGHT = 32;
    static constexpr int DISPLAY_WIDTH = 64;

    uint8_t memory[4096];

    uint8_t display[DISPLAY_HEIGHT][DISPLAY_WIDTH];

    uint8_t V[16];

    uint16_t pc;

    uint16_t I;

    uint16_t stack[16];
    

    uint8_t delay;
    uint8_t sound;

    Chip8();
    ~Chip8();

    void reset();

    bool running;
        
    std::thread timer_thread;

    // to be called at 60hz rate
    void decrement_timers(); 

    void render();
};

#endif