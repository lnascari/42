FILES = ft_printf.c ft_putnbr_base.c

OBJ = $(FILES:.c=.o)

NAME = libftprintf.a

all: $(NAME)
$(NAME): $(OBJ)
	ar -crs $(NAME) $?
%.o: %.c
	gcc -Wall -Wextra -Werror -c $?
clean:
	rm -f ./*.o
fclean: clean
	rm -f libftprintf.a
re: fclean all