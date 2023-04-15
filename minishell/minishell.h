/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaoline <gpaoline@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 10:47:06 by gpaoline          #+#    #+#             */
/*   Updated: 2023/04/14 12:25:48 by gpaoline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <termios.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "./libft/libft.h"

typedef struct s_var
{
	char			*name;
	char			*value;
	int				export;
	struct s_var	*next;
}	t_var;

typedef struct s_red
{
	int		input;
	char	*input_file;
	int		output;
	char	*output_file;
	char	**s;
}	t_red;

extern t_var	*g_var;

int		ft_strcmp(char *s1, char *s2);
char	*ft_strcpy(char *src);
void	ft_free_split(char **s, int all);
void	ft_free_struct(t_red *orders, int pipes);
void	ft_free_and_exit(t_red *orders, char *str, int pipes);

void	ft_varclear(t_var **var);
void	ft_vardelone(t_var **var, t_var *v);
void	ft_varedit(t_var **var, char *name, char *value, int export);
void	ft_varadd_front(t_var **var, char *name, char *value, int export);
t_var	*ft_varsearch(t_var *var, char *name);

void	space_in_quote(char *str);
void	del_quote(char *str);

void	spaces(char **s);

int		var_value(char *str, int export);
void	check_var(char **s);

void	ft_env(void);
void	ft_export(char **s);
void	ft_unset(char **s);
void	ft_exit(char **s, char *str);
void	ft_cd(char **s);

int		programs(char **s, int exe);

void	handler_int(int x);
void	handler_int_programs(int x);
void	handler_quit(int x);

void	exec_op(t_red *orders, int pipes, char *str);

int		op_pipe_check(char **s);
void	open_and_exec(t_red orders);

int		operators(char *str);
void	redirections(char **s, t_red *order);

int		struct_error(t_red *orders, int pipes);
void	red_struct_init(t_red *order);
void	orders_arr(char **s, char *str);

int		cases_control(char **s);
void	ft_error(int *error, char *s, int p);

#endif