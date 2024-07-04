main.o: main.cpp
	g++ -c main.cpp
sistema.o: sistema.cpp
	g++ -c sistema.cpp
astronauta.o: astronauta.cpp
	g++ -c astronauta.cpp
voo.o: voo.cpp
	g++ -c voo.cpp
gerenciadorAstronauta.o: gerenciadorAstronauta.cpp
	g++ -c gerenciadorAstronauta.cpp
gerenciadorVoo.o: gerenciadorVoo.cpp
	g++ -c gerenciadorVoo.cpp
prog: main.o sistema.o astronauta.o voo.o gerenciadorAstronauta.o gerenciadorVoo.o
	g++ -o prog main.o sistema.o astronauta.o voo.o gerenciadorAstronauta.o gerenciadorVoo.o -Wall -fsanitize=address
debug: main.cpp sistema.cpp astronauta.cpp voo.cpp gerenciadorAstronauta.cpp gerenciadorVoo.cpp
	g++ -O0 -g -o debug main.cpp sistema.cpp astronauta.cpp voo.cpp gerenciadorAstronauta.cpp gerenciadorVoo.cpp
all: prog
	./prog
clear:
	rm *.o prog debug