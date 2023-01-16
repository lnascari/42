FILES = ft_putnbr.c ft_atoi.c

OBJ = $(FILES:.c=.o)

NAME = minitalk.a

all: $(NAME)
	gcc -Wall -Wextra -Werror server.c minitalk.a -o server
	gcc -Wall -Wextra -Werror client.c minitalk.a -o client
$(NAME): $(OBJ)
	ar -crs $(NAME) $?
%.o: %.c
	gcc -Wall -Wextra -Werror -c $?
clean:
	rm -f ./*.o
fclean: clean
	rm -f ./*.a
re: fclean all