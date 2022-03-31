CC = gcc
CFLAGS = -Wall -ansi -pedantic
OBJ = order.o numbers.o user_input.o
EXEC = program

$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

order.o : order.c
	$(CC) -c order.c $(CFLAGS)

numbers.o : numbers.c order.h user_input.h
	$(CC) -c numbers.c $(CFLAGS)

user_input.o : user_input.c
	$(CC) -c user_input.c $(CFLAGS)

clean :
	rm -f $(EXEC) $(OBJ)