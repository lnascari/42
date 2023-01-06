FILES = fractal.c

OBJ = $(FILES:.c=.o)

NAME = fractol.a

LIBS = minilibx-linux/libmlx_Linux.a -lXext -lX11 -lm -lz

all: $(NAME)
	gcc -Wall -Wextra -Werror main.c fractol.a minilibx-linux/libmlx.a -lXext -lX11 -lm -lz
$(NAME): $(OBJ)
	ar -crs $(NAME) $?
%.o: %.c
	gcc -Wall -Wextra -Werror -c $?
clean:
	rm -f ./*.o
fclean: clean
	rm -f fractol.a
re: fclean all