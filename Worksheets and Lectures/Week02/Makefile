CFLAGS = -Wall -Werror -pedantic -ansi 
CC = gcc
OBJ = bounds.o powers.o
EXEC = program

ifdef DEBUG
CFLAGS += -D DEBUG=1
DEBUG : clean $(EXEC)
endif

$(EXEC) : $(OBJ)
		$(CC) $(OBJ) -o $(EXEC)

bounds.o : bounds.c macros.h powers.h
		$(CC) -c bounds.c $(CFLAGS)

powers.o : powers.c macros.h
		$(CC) -c powers.c $(CFLAGS)

clean : 
		rm -f $(EXEC) $(OBJ)

