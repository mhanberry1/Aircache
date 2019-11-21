CC = gcc
CFLAGS = -Wall

EXE = server

.PHONY: server

all: clean server

server:
	$(CC) -o $(EXE) $(CFLAGS) $(OBJ) $@.c

clean:
	rm -f $(EXE)
