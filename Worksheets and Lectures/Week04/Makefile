CC = gcc
CFLAGS = -Wall -Werror -ansi -pedantic
EXEC = program
OBJ = cmdLine.o question2.o

$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

cmdLine.o : cmdLine.c
	$(CC) -c cmdLine.c $(CFLAGS)

question2.o : question2.c
	$(CC) -c question2.c $(CFLAGS)

clean : 
	rm -f $(EXEC) *.o
