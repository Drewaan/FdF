
CC = cc
CFLAGS = -Wall -Wextra -Werror -std=c99
SRC_DIR = sources
OBJ_DIR = objs
INCLUDE_DIR = include
LIBFT_DIR = ./libft

# Detect the operating system
UNAME_S := $(shell uname -s)


MLX_INCLUDE_DIR = ./mlx
MLX_LIB_FLAGS = -L$(MLX_INCLUDE_DIR) -lmlx -lm -lX11 -lXext

# List of source files
SRCS = $(wildcard $(SRC_DIR)/*.c)
# List of object files
OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

# Main target
NAME = fdf

all: $(NAME)

$(NAME): $(LIBFT_DIR)/libft.a $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ $(MLX_LIB_FLAGS) -L$(LIBFT_DIR) -lft

# Rule to compile object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INCLUDE_DIR) -I$(MLX_INCLUDE_DIR) -I$(LIBFT_DIR)

# Create the objects directory if it does not exist
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Compile libft
$(LIBFT_DIR)/libft.a:
	$(MAKE) -C $(LIBFT_DIR)


# Rule to compile bonus object files
$(OBJ_DIR)/%.o: | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INCLUDE_DIR) -I$(MLX_INCLUDE_DIR) -I$(LIBFT_DIR)

# Clean target
clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

# Distclean target
distclean: clean
	rm -f $(NAME)

fclean: clean
	rm -f $(NAME)
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) fclean

# Rebuild target
re: fclean all

# Phony targets
.PHONY: all clean distclean fclean re
