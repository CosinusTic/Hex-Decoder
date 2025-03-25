CC=gcc
CFLAGS=-Werror -Wall -std=c99
BIN=decoder

all:
	$(CC) $(CFLAGS) *.c -o $(BIN)
