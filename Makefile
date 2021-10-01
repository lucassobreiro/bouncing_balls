APP="bouncing_balls"

all:
	if [ -e *.o ]; then\
		make clear;\
	fi

	make compile

	if [ -e $(APP) ]; then\
		make run;\
	fi

compile:
	g++ src/*.cpp -I src/ -c -Wall
	g++ *.o -o $(APP) -lsfml-graphics -lsfml-window -lsfml-system
	chmod +x $(APP)

run:
	./$(APP)

clear:
	rm *.o

