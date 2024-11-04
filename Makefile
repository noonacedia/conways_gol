CC = gcc
CFLAGS = -Ilib/include
LDFLAGS = -Llib -lraylib -lm
BUILD_DIR = build
BIN_DIR = bin
TARGET = $(BIN_DIR)/main

SRC = src/main.c
OBJ = $(SRC:src/%.c=$(BUILD_DIR)/%.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	mkdir -p $(BIN_DIR)
	$(CC) -o $@ $^ $(LDFLAGS)

$(BUILD_DIR)/%.o: src/%.c
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)
