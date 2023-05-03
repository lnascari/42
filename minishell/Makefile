FILES = \
	ft_utils.c var_utils.c commands.c handlers.c programs.c quotes.c spaces.c \
<<<<<<< HEAD
	var.c operators.c pipe.c red_struct.c redirections.c check.c environ.c
=======
	var.c operators.c pipe.c red_struct.c redirections.c check.c
>>>>>>> e5fc907b233d9c0130db5a929ee377f265cb5164

OBJ = $(FILES:.c=.o)

NAME = minishell

all: $(NAME)
		$(MAKE) -C ./libft
		cc -Wall -Wextra -Werror main.c $(NAME).a ./libft/libft.a -o $(NAME) -lreadline
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