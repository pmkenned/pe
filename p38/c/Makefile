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
	make clean -C ../../common/
	rm -f $(TARGET)

$(TARGET): $(SRC) ../../common/common.o
	make -C ../../common/
	$(CC) $(CFLAGS) -o $(TARGET) $^ $(LDLIBS)
