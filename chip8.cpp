#include "chip8.h"

using namespace std;

Chip8::Chip8() {
    for (int i = 0; i < sizeof(fonts); i++) {
        memory[i] = fonts[i];
    }
}

int main() {}