CC = gcc
EXEC = snake
OBJ = main.o array.o
CFLAGS = -Wall -Werror -ansi -pedantic

$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

main.o : main.c array.h
	$(CC) -c main.c $(CFLAGS)

array.o : array.c
	$(CC) -c array.c $(CFLAGS)

clean :
	rm -f $(EXEC) *.o