CC = gcc
CFLAGS = -Wall -Werror -ansi -pedantic
EXEC = display
OBJ = display.o plot.o

$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

display.o : display.c plot.h
	$(CC) -c display.c $(CFLAGS)

plot.o : plot.c plot.h
	$(CC) -c plot.c $(CFLAGS)

clean :
	rm -rf *.o $(EXEC)