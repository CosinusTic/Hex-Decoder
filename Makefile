CC=gcc
CFLAGS=-Werror -Wall -std=c99
BIN=decoder
SRC=src/*.c *.c

all:
	$(CC) $(CFLAGS) $(SRC) -o $(BIN)

clean:
	rm -rf $(BIN)
