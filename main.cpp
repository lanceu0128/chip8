#include <iostream>
#include "chip8.h"
using namespace std;

int main() {
    Chip8 chip = Chip8();
    chip.reset();

    while (chip.running)  {
        // handle keyboard input here

        // hanlde instructions (fetch decode and execute) here

        chip.render();

        this_thread::sleep_for(chrono::milliseconds(16));
    }

    return 0;
}
