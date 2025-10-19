# Makefile simple pour compiler tsp.c
CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Wpedantic -O2
LDLIBS = -lm

SRC = P1_fonctions.c
OBJ = $(SRC:.c=.o)
BIN = tsp

.PHONY: all clean

all: $(BIN)

$(BIN): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDLIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(BIN)
