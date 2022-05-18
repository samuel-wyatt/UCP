CC = gcc
EXEC = snake
OBJ = main.o array.o random.o game.o terminal.o LinkedList.o input.o
CFLAGS = -Wall -Werror -ansi -pedantic -g


$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

main.o : main.c array.h random.h game.h main.h LinkedList.h input.h
	$(CC) -c main.c $(CFLAGS)

array.o : array.c array.h random.h
	$(CC) -c array.c $(CFLAGS)

game.o : game.c terminal.h game.h
	$(CC) -c game.c $(CFLAGS)

random.o : random.h
	$(CC) -c random.c $(CFLAGS)

terminal.o : terminal.h
	$(CC) -c terminal.c $(CFLAGS)

LinkedList.o : LinkedList.c LinkedList.h
	$(CC) -c LinkedList.c $(CFLAGS)

input.o : input.c LinkedList.h main.h
	$(CC) -c input.c $(CFLAGS)

clean :
	rm -f $(EXEC) *.o