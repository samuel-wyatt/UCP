CC = gcc
EXEC = snake
OBJ = main.o array.o random.o game.o terminal.o
CFLAGS = -Wall -Werror -ansi -pedantic -g

ifdef UNBEATABLE
CFLAGS += -D UNBEATABLE=1
UNBEATABLE : clean $(EXEC)
endif

$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

main.o : main.c array.h random.h game.h
	$(CC) -c main.c $(CFLAGS)

array.o : array.c array.h random.h
	$(CC) -c array.c $(CFLAGS)

game.o : game.c terminal.h game.h
	$(CC) -c game.c $(CFLAGS)

random.o : random.h
	$(CC) -c random.c $(CFLAGS)

terminal.o : terminal.h
	$(CC) -c terminal.c $(CFLAGS)

clean :
	rm -f $(EXEC) *.o