FILES = \
	ft_utils.c var_utils.c commands.c handlers.c programs.c quotes.c spaces.c \
	var.c operators.c pipe.c red_struct.c redirections.c op_pipe.c

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