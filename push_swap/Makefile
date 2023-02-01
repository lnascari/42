FILES = operations_s.c operations_p.c operations_r.c operations_rr.c ft_atoi.c sort.c complex_sort.c sort_utils.c

OBJ = $(FILES:.c=.o)

NAME = push_swap.a

all: $(NAME)
	gcc -Wall -Wextra -Werror main.c push_swap.a -o push_swap
$(NAME): $(OBJ)
	ar -crs $(NAME) $?
%.o: %.c
	gcc -Wall -Wextra -Werror -c $?
clean:
	rm -f ./*.o
fclean: clean
	rm -f ./*.a
re: fclean all