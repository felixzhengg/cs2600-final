CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Wpedantic
TARGET = bank
SOURCES = src/uiMenu.c src/accounts.c src/input.c src/transactions.c src/file_management.c src/history.c
HEADERS = $(wildcard src/*.h)

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(SOURCES) $(HEADERS)
	$(CC) $(CFLAGS) $(SOURCES) -o $(TARGET)

clean:
	rm -f $(TARGET) $(TARGET).exe
