all: main

main: 
	g++ main.cpp chip8.cpp -o main

clean:
	rm main