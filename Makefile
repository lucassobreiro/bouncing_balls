APP="bouncing_balls"

all:
	make clear
	make compile
	make run

compile:
	g++ src/*.cpp -I src/ -c -Wall
	g++ *.o -o $(APP) -lsfml-graphics -lsfml-window -lsfml-system

run:
	./$(APP)

clear:
	rm *.o

