CC=gcc
SRC=src
BIN=bin
PARAMS=-Wall

# C files
NORM=normal
MAIN=main

all : $(MAIN).o $(NORM).o
	$(CC) $(PARAMS) $(BIN)/*.o -o out.exe

$(MAIN).o : init
	$(CC) $(PARAMS) -c $(SRC)/$(MAIN).c -o $(BIN)/$(MAIN).o

$(NORM).o : init
	$(CC) $(PARAMS) -c $(SRC)/$(NORM).c -o $(BIN)/$(NORM).o

init:
	mkdir -p $(BIN)

clean:
	rm -rf $(BIN)