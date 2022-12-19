FILES = ft_printf.c ft_putnbr_base.c

OBJ = $(FILES:.c=.o)

NAME = libftprintf.a

LIBS = minilibx-linux/libmlx_Linux.a -lXext -lX11 -lm -lz

all: #$(NAME)
	gcc -Wall -Wextra -Werror main.c fractal.o minilibx-linux/libmlx.a -lXext -lX11 -lm -lz
$(NAME): $(OBJ)
	ar -crs $(NAME) $?
%.o: %.c
	gcc -Wall -Wextra -Werror -c $?
clean:
	rm -f ./*.o
fclean: clean
	rm -f libftprintf.a
re: fclean all