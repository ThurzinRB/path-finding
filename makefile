build-main: Obstacle.o
	g++ -o main main.cpp Obstacle.o -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
	make clear

build-setup: Obstacle.o
	g++ -o setup setup.cpp Obstacle.o -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
	make clear

Obstacle.o:
	g++ -c Obstacle.cpp

run-setup:
	./setup

run-main:
	./main

clear:
	rm -f *.o