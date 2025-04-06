# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -Werror -Iincludes

# Directories
SRC_DIR = srcs
OBJ_DIR = objs

# Output file
OUTPUT = ft_printf

# Find all the .c files in the srcs directory
SRCS = $(wildcard $(SRC_DIR)/*.c)

# Convert .c files to .o object files
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Default target to build the program
all: $(OUTPUT)

# Link the object files to create the final executable
$(OUTPUT): $(OBJS)
	$(CC) $(OBJS) -o $(OUTPUT)

# Create the objects directory
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Compile the source files into object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up object files and the executable
clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(OUTPUT)

re: fclean all

# Phony targets
.PHONY: all clean fclean re

