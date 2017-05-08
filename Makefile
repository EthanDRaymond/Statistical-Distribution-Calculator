CC=gcc
SRC=src
BIN=bin
PARAMS=-Wall

all : bin/main.o init
	$(CC) $(PARAMS) $(BIN)/*.o -o out.exe

bin/main.o : init
	$(CC) $(PARAMS) -c src/main.c -o $(BIN)/main.o

init:
	mkdir -p $(BIN)

clean:
	rm -rf $(BIN)