NAME = so_long
CC = cc
HEADER = so_long.h
SRC = so_long.c \
	  src/ft_check_ext.c \
	  gnl/get_next_line.c \
	  gnl/get_next_line_utils.c
LIBFT = libft.a
FT_PRINTF = libftprintf.a
FT_PRINTF_DIR = ft_printf
LIBFT_DIR = libft
CFLAGS = -Werror -Wextra -Wall
OBJ = $(SRC:.c=.o)

all: $(FT_PRINTF) $(LIBFT) $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(FT_PRINTF):
	@make -C $(FT_PRINTF_DIR)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) -L$(LIBFT_DIR) -lft -L$(FT_PRINTF_DIR) -lftprintf -o $(NAME)

clean:
	@rm -f $(OBJ)
	@make -C $(LIBFT_DIR) clean
	@make -C $(FT_PRINTF_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@make -C $(FT_PRINTF_DIR) fclean
re: fclean all

.PHONY: clean
