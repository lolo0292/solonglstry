NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3

SRCS = src/main.c \
       src/free.c \
       src/map.c \
       src/map_utils.c \
       src/player.c \
       src/render.c \
       src/floodfill.c \
	   src/utils.c \
	   src/utils2.c

OBJS = $(SRCS:.c=.o)

HEADER = include/so_long.h

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX_PATH = ./minilibx-linux
MLX_LIB = $(MLX_PATH)/libmlx.a
MLX_FLAGS = -L$(MLX_PATH) -lmlx -lXext -lX11

INCLUDES =  -I $(shell pwd) -Iinclude -I$(LIBFT_DIR) -I$(MLX_PATH)

CFLAGS += $(INCLUDES)
all: $(LIBFT) mlx $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

mlx:
	@make -sC $(MLX_PATH)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_FLAGS) $(INCLUDES) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)
	make clean -C $(LIBFT_DIR)
	make clean -sC $(MLX_PATH)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)
	make clean -sC $(MLX_PATH)

re: fclean all

.PHONY: all clean fclean re mlx
 