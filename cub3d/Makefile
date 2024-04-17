FILES = \
	hooks.c wasd_keys.c ray_casting.c image_and_pixels.c player.c map.c \
	get_next_line.c sprite.c free_and_error.c main_checks.c check_map.c \
	check.c

OBJ = $(FILES:.c=.o)

NAME = cub3D

all: $(NAME)
	$(MAKE) -C ./libft
	cd minilibx-linux && make && cd ..
	cc -Wall -Wextra -Werror main.c $(NAME).a ./libft/libft.a minilibx-linux/libmlx.a -lXext -lX11 -lm -lz -o $(NAME)
$(NAME): $(OBJ)
	ar -crs $(NAME).a $?
%.o: %.c
	cc -Wall -Wextra -Werror -c $?
clean:
	rm -f ./*.o
	$(MAKE) -C ./libft clean
fclean: clean
	$(MAKE) -C ./libft fclean
	rm -f ./*.a
	rm -f $(NAME)
re: fclean all