CC = gcc
CFLAGS = -Wall -Wextra -O3 -std=c99
LDLIBS = -lm

SRC = $(wildcard *.c)
TARGET = $(SRC:%.c=%.exe)

.PHONY: all run clean

all: $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $^ $(LDLIBS)
