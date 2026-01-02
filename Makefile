all: main chip8

main: 
	g++ main.cpp -o main

chip8:
	g++ chip8.cpp -o chip8
	