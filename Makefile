CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c99

SRC_DIR = sources
OBJ_DIR = objs
INCLUDE_DIR = include
LIBFT_DIR = ./libft
MLX_DIR = ./mlx

NAME = fdf

# Lista completa de archivos fuente (con ruta)
SRCS = $(addprefix $(SRC_DIR)/, \
	altitude_bonus.c \
	bresenham.c \
	colors_bonus.c \
	data.c \
	design.c \
	error.c \
	free.c \
	isometric_view.c \
	key_handling_bonus.c \
	main.c \
	mlx_main.c \
	parsing_map_utils.c \
	parsing_map.c \
	rotation_bonus.c \
	transformation_points_bonus.c \
	translation_bonus.c \
	zoom_bonus.c)

# Archivos objeto
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

# MLX
MLX_INCLUDE_DIR = $(MLX_DIR)
MLX_LIB = $(MLX_DIR)/libmlx.a
MLX_LIB_FLAGS = -L$(MLX_DIR) -lmlx -lm -lX11 -lXext

# Compilación principal
all: $(NAME)

$(NAME): $(LIBFT_DIR)/libft.a $(MLX_LIB) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(MLX_LIB_FLAGS) -L$(LIBFT_DIR) -lft

# Regla para compilar objetos
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INCLUDE_DIR) -I$(MLX_INCLUDE_DIR) -I$(LIBFT_DIR)

# Crear carpeta de objetos si no existe
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Compilar libft
$(LIBFT_DIR)/libft.a:
	$(MAKE) -C $(LIBFT_DIR)

# Compilar MiniLibX
$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)

# Limpiar objetos
clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean

# Limpiar todo
fclean: clean
	rm -f $(NAME)
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(MLX_DIR) clean

# Recompilar todo
re: fclean all
