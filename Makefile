CPP=g++
RM=rm -f
CFLAGS=-g

SRC = playboard.cpp keyboard-event.cpp game.cpp main.cpp
OBJ = $(SRC:.cpp=.o)

snake : $(OBJ)
	$(CPP) $^ -o $@

# les dépendances
playboard.o : playboard.cpp playboard.h keyboard-event.h
keyboard-event.o : keyboard-event.cpp keyboard-event.h
game.o : game.cpp game.h playboard.h
main.o : main.cpp game.h

%.o:%.cpp
	$(CPP) $(CFLAGS) -o $@ -c $<

clean:
	$(RM) *.o snake

.PHONY: clean
