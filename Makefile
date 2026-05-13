CC=cc
CFLAGS= -Wall -Wextra -g 
SRC=$(wildcard src/*.c)
LDFLAGS= -lm
BUILD_DIR=build
OBJ=$(SRC:src/%.c=$(BUILD_DIR)/%.o)
TARGET=$(BUILD_DIR)/Calculator



all: $(TARGET)

$(TARGET):$(OBJ)
	$(CC) -o $@ $(OBJ) $(LDFLAGS)

$(BUILD_DIR)/%.o:src/%.c |$(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)


clean:
	rm -rf $(BUILD_DIR)/

.PHONY: all clean

