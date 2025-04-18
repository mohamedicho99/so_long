NAME = so_long
CC = cc
HEADER = so_long.h
SRC = so_long.c \
	  src/init_program.c \
	  src/movement.c \
	  src/rendering.c \
	  src/normal_exit.c \
	  src/handle_textures.c \
	  src/ft_check_ext.c \
	  src/ft_check_shape.c \
	  src/ft_exit.c \
	  src/ft_flood_fill.c \
	  src/ft_path.c \
	  src/ft_check_count.c \
	  src/ft_wall.c \
	  src/ft_check_resources.c \
	  src/parsing.c \
	  gnl/get_next_line.c \
	  gnl/get_next_line_utils.c
LIBFT = libft.a
FT_PRINTF = libftprintf.a
FT_PRINTF_DIR = ft_printf
LIBFT_DIR = libft
# Added MLX variables
MLX_DIR = mlx_linux
MLX = $(MLX_DIR)/libmlx.a
CFLAGS = -Werror -Wextra -Wall
OBJ = $(SRC:.c=.o)

.SECONDARY: $(OBJ)

all: $(FT_PRINTF) $(LIBFT) $(MLX) $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(FT_PRINTF):
	@make -C $(FT_PRINTF_DIR)

# Added MLX build target
$(MLX):
	@make -C $(MLX_DIR)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) -L$(LIBFT_DIR) -lft -L$(FT_PRINTF_DIR) -lftprintf -L$(MLX_DIR) -lmlx -L/usr/lib -I$(MLX_DIR) -lXext -lX11 -lm -lz -o $(NAME)

clean:
	@rm -f $(OBJ)
	@make -C $(LIBFT_DIR) clean
	@make -C $(FT_PRINTF_DIR) clean
	@make -C $(MLX_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@make -C $(FT_PRINTF_DIR) fclean
re: fclean all

.PHONY: clean