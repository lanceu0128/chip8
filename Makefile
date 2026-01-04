all: main

main: main.cpp chip8.cpp chip8.h 
	g++ main.cpp chip8.cpp -o main

clean:
	rm main