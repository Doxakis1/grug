# Created by doxakis 1
# Grug chess engine


LIB_DIR := ./lib/
SRC_DIR := ./src/
NAME := grug_engine
COMPILER := gcc
COMPILER_FLAGS := -O3
INCLUDES := -I./src 
LINKER_FLAGS := -O3

# Source files and object files wildcarded to include all c files in src/
SOURCE_FILES := $(wildcard src/*.c)
OBJECT_FILES := $(SOURCE_FILES:.c=.o)

# all depends on executable (~/!)existing
all=$(NAME)

# Rule to do .c to .o
.c.o:
	$(COMPILER) -c $(COMPILER_FLAGS) $(INCLUDES) $< -o $@

# Linking
$(NAME):$(OBJECT_FILES) Makefile
	mkdir -p ./bin/
	$(COMPILER) $(OBJECT_FILES) $(LINKER_FLAGS) -o ./bin/$(NAME)

# Lazy clean
clean:
	rm -rf $(OBJECT_FILES)

# Lazy clean
fclean:
	rm -rf $(OBJECT_FILES) ./bin/$(NAME)

test:$(NAME)
	./bin/$(NAME)
