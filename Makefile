CC=cc
CFLAGS= -Wall -Wextra -g 
SRC=$(wildcard src/*.c)
LDFLAGS= -lm
BUILD_DIR=build
OBJ=$(SRC:src/%.c=$(BUILD_DIR)/%.o)
TARGET=$(BUILD_DIR)/Calculator$(EXE)


ifeq ($(DETECTED_OS),Windows)
    EXE = .exe
    RM = del /Q
    MKDIR = mkdir
else
    EXE =
    RM = rm -rf
    MKDIR = mkdir -p
endif



all: $(TARGET)

$(TARGET):$(OBJ)
	$(CC) -o $@ $(OBJ) $(LDFLAGS)

$(BUILD_DIR)/%.o:src/%.c |$(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR):
	$(MKDIR) -p $(BUILD_DIR)


clean:
	$(RM) $(BUILD_DIR)/

.PHONY: all clean

