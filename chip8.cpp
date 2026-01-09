#include "chip8.h"
#include <iostream>
#include <stdint.h>
#include <thread>
#include <string.h>

using namespace std;

uint8_t fonts[80] = {
    0xF0, 0x90, 0x90, 0x90, 0xF0, // 0
    0x20, 0x60, 0x20, 0x20, 0x70, // 1
    0xF0, 0x10, 0xF0, 0x80, 0xF0, // 2
    0xF0, 0x10, 0xF0, 0x10, 0xF0, // 3
    0x90, 0x90, 0xF0, 0x10, 0x10, // 4
    0xF0, 0x80, 0xF0, 0x10, 0xF0, // 5
    0xF0, 0x80, 0xF0, 0x90, 0xF0, // 6
    0xF0, 0x10, 0x20, 0x40, 0x40, // 7
    0xF0, 0x90, 0xF0, 0x90, 0xF0, // 8
    0xF0, 0x90, 0xF0, 0x10, 0xF0, // 9
    0xF0, 0x90, 0xF0, 0x90, 0x90, // A
    0xE0, 0x90, 0xE0, 0x90, 0xE0, // B
    0xF0, 0x80, 0x80, 0x80, 0xF0, // C
    0xE0, 0x90, 0x90, 0x90, 0xE0, // D
    0xF0, 0x80, 0xF0, 0x80, 0xF0, // E
    0xF0, 0x80, 0xF0, 0x80, 0x80  // F
};

Chip8::Chip8() {}

void Chip8::reset() {
    pc = 0;
    I = 0;

    // reset variable registers
    for (int i = 0; i < 16; i++) {
        V[i] = 0;
    }

    // reset stack
    for (int i = 0; i < 16; i++) {
        stack[i] = 0;
    }

    // reset display
    for (int r = 0; r < DISPLAY_HEIGHT; r++) {
        for (int c = 0; c < DISPLAY_WIDTH; c++) {
            display[r][c] = 1;
        }
    }

    // reset memory
    for (int i = 0; i < 4096; i++) {
        memory[i] = 0;
    }

    // add fonts to memory
    for (int i = 0; i < 80; i++) {
        memory[i] = fonts[i];
    }

    running = true;

    timer_thread = thread(&Chip8::decrement_timers, this);
}

void Chip8::decrement_timers() {
    while (true) {
        if (!running) return;

        if (delay > 0) delay -= 1;
    
        if (sound > 0) sound -= 1;
    
        // approx for 16.67 ms; if timing becomes an issue its probably this
        this_thread::sleep_for(chrono::milliseconds(16));
    }
}

Chip8::~Chip8() {
    running = false;
    if (timer_thread.joinable()) {
        timer_thread.join();
    }
}

void Chip8::render() {
    cout << "\033[H"; // reset cursor

    string frame = "";

    for (int r = 0; r < DISPLAY_HEIGHT; r++) {
        for (int c = 0; c < DISPLAY_WIDTH; c++) {
            if (display[r][c] == 1) {
                frame += "█";
            } else {
                frame += ' ';
            }
        }
        frame += '\n';
    }

    cout << frame;
}