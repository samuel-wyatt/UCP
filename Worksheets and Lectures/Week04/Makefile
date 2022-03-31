CC = gcc
CFLAGS = -Wall -Werror -ansi -pedantic
EXEC = program
OBJ = question2.o q2Main.o 

$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

question2.o : question2.c
	$(CC) -c question2.c $(CFLAGS)

q2Main.o : q2Main.c question2.h
	$(CC) -c q2Main.c $(CFLAGS)

clean :
	rm -f $(EXEC) $(OBJ)