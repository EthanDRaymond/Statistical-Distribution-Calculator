CC=gcc
SRC=src
BIN=bin
PARAMS=-Wall

all : bin/main.o bin/normal.o bin/poisson.o init
	$(CC) $(PARAMS) $(BIN)/*.o -o out.exe

bin/main.o : init
	$(CC) $(PARAMS) -c src/main.c -o $(BIN)/main.o

bin/normal.o : init
	$(CC) $(PARAMS) -c src/normal.c -o $(BIN)/normal.o
	
bin/poisson.o : init
	$(CC) $(PARAMS) -c src/poisson.c -o $(BIN)/poisson.o

init:
	mkdir -p $(BIN)

clean:
	rm -rf $(BIN)