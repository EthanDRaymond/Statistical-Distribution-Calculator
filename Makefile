CC=gcc
SRC=src/
BIN=bin/
NORM=normal

all : $(NORM).exe

$(NORM).exe : init
	$(CC) $(SRC)$(NORM).c -o $(BIN)$(NORM).exe

init:
	mkdir -p $(BIN)

clean:
	rm -rf *.o *.exe