CC = gcc
CFLAGS = -Wall -Werror -ansi -pedantic
EXEC = program
OBJ = cmdLine.o functions.o

$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

cmdLine.o : cmdLine.c 
	$(CC) -c cmdLine.c $(CFLAGS)

functions.o : functions.c
	$(CC) -c functions.c $(CFLAGS)

clean : 
	rm -f $(EXEC) *.o
