CC = gcc
CFLAGS = -Wall -g
BIN_DIR = bin
TARGET = $(BIN_DIR)/myprog
OBJS = $(BIN_DIR)/main.o

all: $(TARGET)

# Link step
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Compile step
$(BIN_DIR)/main.o: main.c | $(BIN_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Create bin directory if it doesn't exist
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

.PHONY: clean
clean:
	rm -rf $(BIN_DIR)
