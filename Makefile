# **************************************************************************** #
#                                MAKEFILE                                     #
# **************************************************************************** #

# Name of the final executable
NAME = push_swap

# ==============================================================================
#                                DIRECTORIES
# ==============================================================================

# Your source files (for push_swap logic)
SRC_DIR = src
OBJ_DIR = obj

# Your libft folder
LIBFT_DIR = libft
LIBFT_MAKE = make -C $(LIBFT_DIR)
LIBFT_CLEAN = make clean -C $(LIBFT_DIR)
LIBFT_FCLEAN = make fclean -C $(LIBFT_DIR)
LIBFT = $(LIBFT_DIR)/libft.a

# Header files location
INCLUDES = -Iinclude -I$(LIBFT_DIR)/includes

# ==============================================================================
#                                FILES
# ==============================================================================

# Source files for push_swap
SRC =	main.c \
		error_exit.c \
		free_args.c \
		parse_args.c \
		stack.c \
		ft_atoi_safe.c

# Object files (same names, just different extension and folder)
OBJS = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# ==============================================================================
#                                RULES
# ==============================================================================

# Default rule when you run `make`
all: $(NAME)

# Rule to build push_swap
$(NAME): $(LIBFT) $(OBJS)
	@echo "Compiling $(NAME)..."
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

# Compile object files from .c files
# $< = source file (.c)
# $@ = target file (.o)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Build libft first using its own Makefile
$(LIBFT):
	@$(LIBFT_MAKE)

# Clean only this project’s object files
clean:
	@echo "Cleaning object files..."
	@rm -rf $(OBJ_DIR)

# Clean this project AND libft’s build files
fclean: clean
	@echo "Cleaning $(NAME) and libft..."
	@rm -f $(NAME)
	@$(LIBFT_FCLEAN)

# Full rebuild from scratch
re: fclean all

# ==============================================================================

.PHONY: all clean fclean re
