CC = clang
CFLAGS = -Wall -Werror -lcs50
SRC_DIRS = $(wildcard pset*)
BIN_DIR = bin

SRC_FILES = $(wildcard $(addsuffix /*.c, $(SRC_DIRS)))
TARGETS = $(basename $(notdir $(SRC_FILES)))
BIN_FILES = $(addprefix $(BIN_DIR)/, $(TARGETS))

vpath %.c $(SRC_DIRS)

all: $(BIN_FILES)

$(BIN_DIR)/%: %.c | $(BIN_DIR)
	$(CC) $< $(CFLAGS) -o $@

$(TARGETS): %: $(BIN_DIR)/%

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

clean:
	rm -f $(BIN_DIR)/*

.PHONY: all clean $(TARGETS)