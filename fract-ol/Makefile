FILES = fractal.c utils.c ft_atoi.c

OBJ = $(FILES:.c=.o)

NAME = fractol.a

LIBS = minilibx-linux/libmlx_Linux.a -lXext -lX11 -lm -lz

all: $(NAME)
	gcc -Wall -Wextra -Werror main.c fractol.a minilibx-linux/libmlx.a -lXext -lX11 -lm -lz -o fractol
$(NAME): $(OBJ)
	ar -crs $(NAME) $?
%.o: %.c
	gcc -Wall -Wextra -Werror -c $?
clean:
	rm -f ./*.o
fclean: clean
	rm -f fractol.a
	rm -f fractol
re: fclean all