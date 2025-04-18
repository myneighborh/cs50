CC = clang
CFLAGS = -Wall -Werror -lcs50
SRC_DIRS = $(wildcard pset*)
BIN_DIR = bin

SRC_FILES = $(wildcard $(addsuffix /*.c, $(SRC_DIRS)))

TARGETS = $(basename $(notdir $(SRC_FILES)))

BIN_FILES = $(addprefix $(BIN_DIR)/, $(TARGETS))

all: $(BIN_FILES)

$(BIN_DIR)/%: $(SRC_DIRS)/%.c | $(BIN_DIR)
	$(CC) $< $(CFLAGS) -o $@

$(TARGETS): %: $(BIN_DIR)/%

clean:
	rm -f $(BIN_DIR)/*