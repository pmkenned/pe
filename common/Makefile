CC = gcc
CFLAGS = -Wall -Wextra -O3 -std=c99
LDLIBS = -lm

SRC = $(wildcard *.c)
OBJ = $(SRC:%.c=%.o)
DEP = $(SRC:%.c=%.d)

.PHONY: all clean

all: $(OBJ)

clean:
	rm -f $(OBJ) $(DEP)

-include $(DEP)

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c -MMD -o $@ $< $(LDLIBS)
