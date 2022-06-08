CC = gcc
EXEC = life
OBJ = main.o input.o game.o
CFLAGS = -Wall -Werror -ansi -pedantic -g

$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

main.o : main.c input.h game.h
	$(CC) -c main.c $(CFLAGS)

input.o : input.c
	$(CC) -c input.c $(CFLAGS)

game.o : game.c
	$(CC) -c game.c $(CFLAGS)

clean :
	rm -f $(EXEC) *.o