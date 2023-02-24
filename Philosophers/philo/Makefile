FILES =  ft_atoi.c

OBJ = $(FILES:.c=.o)

NAME = philo

all: $(NAME)
	gcc -Wall -Wextra -Werror main.c $(NAME).a -o $(NAME) -pthread
$(NAME): $(OBJ)
	ar -crs $(NAME).a $?
%.o: %.c
	gcc -Wall -Wextra -Werror -c $?
clean:
	rm -f ./*.o
fclean: clean
	rm -f ./*.a
	rm $(NAME)
re: fclean all