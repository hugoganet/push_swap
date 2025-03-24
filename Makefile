# **************************************************************************** #
#                                MAKEFILE                                      #
# **************************************************************************** #

NAME		= push_swap

# Directories
SRC_DIR		= src
OBJ_DIR		= obj
LIBFT_DIR	= libft

# Compiler & Flags
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -Iinclude -I$(LIBFT_DIR)/includes

# Source files
SRC_FILES	= \
		main.c \
		memory_and_errors/error_exit.c \
		memory_and_errors/free.c \
		parsing/ft_atoi_safe.c \
		parsing/parse_args.c \
		sorting_operations/helper_functions.c \
		sorting_operations/sort_2_to_5_elements.c \
		stack_operations/push_operations.c \
		stack_operations/rotate_operations.c \
		stack_operations/stack.c \
		stack_operations/swap_operations.c \

SRCS		= $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJS		= $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

# Libft
LIBFT		= $(LIBFT_DIR)/libft.a

# Default rule
all: $(NAME)

# Executable rule
$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

# Libft rule
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# Create .o from .c with matching folder structure
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean object files
clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -rf $(OBJ_DIR)

# Clean everything
fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re