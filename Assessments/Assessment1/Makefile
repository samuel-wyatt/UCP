CC = gcc
EXEC = snake
OBJ = main.o array.o random.o
CFLAGS = -Wall -Werror -ansi -pedantic

$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

main.o : main.c array.h random.h terminal.h
	$(CC) -c main.c $(CFLAGS)

array.o : array.c array.h random.h
	$(CC) -c array.c $(CFLAGS)

random.o : random.h
	$(CC) -c random.c $(CFLAGS)

terminal.o : terminal.h
	$(CC) -c terminal.c $(CFLAGS)

clean :
	rm -f $(EXEC) *.o