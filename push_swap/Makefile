FILES = operations_s.c operations_p.c operations_r.c operations_rr.c ft_atoi.c sort.c

OBJ = $(FILES:.c=.o)

NAME = pushswap.a

all: $(NAME)
	gcc -Wall -Wextra -Werror main.c pushswap.a -o pushswap
$(NAME): $(OBJ)
	ar -crs $(NAME) $?
%.o: %.c
	gcc -Wall -Wextra -Werror -c $?
clean:
	rm -f ./*.o
fclean: clean
	rm -f ./*.a
re: fclean all