CC = gcc
CFLAGS = -Wall

EXE = server sample_server

.PHONY: server

all: clean sample_server server

server:
	$(CC) -o $@ $(CFLAGS) $(OBJ) $@.c

sample_server:
	$(CC) -o $@ $(CFLAGS) $(OBJ) $@.c

clean:
	rm -f $(EXE)
