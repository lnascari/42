FILES = operations_s.c operations_p.c operations_r.c operations_rr.c ft_atoi.c ft_split.c sort.c complex_sort_a.c complex_sort_b.c sort_utils.c arg.c checker_bonus.c get_next_line_bonus.c get_next_line_utils_bonus.c arg_bonus.c

OBJ = $(FILES:.c=.o)

NAME = push_swap.a

all: $(NAME)
	gcc -Wall -Wextra -Werror main.c push_swap.a -o push_swap
bonus: $(NAME)
	gcc -Wall -Wextra -Werror main_bonus.c push_swap.a -o checker
$(NAME): $(OBJ)
	ar -crs $(NAME) $?
%.o: %.c
	gcc -Wall -Wextra -Werror -c $?
clean:
	rm -f ./*.o
fclean: clean
	rm -f ./*.a
	rm -f push_swap
	rm -f checker
re: fclean all