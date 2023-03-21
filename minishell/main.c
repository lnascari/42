/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaoline <gpaoline@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 10:21:22 by gpaoline          #+#    #+#             */
/*   Updated: 2023/03/20 14:41:38 by gpaoline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_var	*g_var;

void	free_split(char **s)
{
	int	i;

	i = -1;
	while (s[++i])
		free(s[i]);
	free(s);
}

void	space_in_quote(char *str)
{
	int	i;
	int	squote;
	int	dquote;

	i = -1;
	squote = 0;
	dquote = 0;
	while (str[++i])
	{
		if (!squote && str[i] == '"')
			dquote = !dquote;
		if (!dquote && str[i] == '\'')
			squote = !squote;
		if (dquote && str[i] == ' ')
			str[i] = 17;
		if (squote && str[i] == ' ')
			str[i] = 17;
	}
}

void	del_quote(char *str)
{
	int	i;
	int	squote;
	int	dquote;

	i = -1;
	squote = 0;
	dquote = 0;
	while (str[++i])
	{
		if (squote && str[i] == '$')
			str[i] = 18;
		if (!squote && str[i] == '"')
		{
			dquote = !dquote;
			if (!dquote && str[i] == '"')
				str[i] = 127;
		}
		if (!dquote && str[i] == '\'')
		{
			squote = !squote;
			if (!squote && str[i] == '\'')
				str[i] = 127;
		}
		if (dquote && str[i] == '"')
			str[i] = 127;
		if (squote && str[i] == '\'')
			str[i] = 127;
	}
}

int	count_127(char *s)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == 127)
			count++;
		i++;
	}
	return (count);
}

char	*shorten_list(char *s)
{
	int		i;
	int		j;
	int		count;
	char	*s2;

	count = count_127(s);
	s2 = (char *)malloc(ft_strlen(s) - count);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == 127)
			i++;
		else
		{
			s2[j] = s[i];
			i++;
			j++;
		}
	}
	s2[j] = 0;
	free(s);
	return (s2);
}

void	spaces(char **s)
{
	int	i;
	int	j;

	i = -1;
	while (s[++i])
	{
		j = -1;
		while (s[i][++j])
		{
			if (s[i][j] == 17)
				s[i][j] = ' ';
		}
		s[i] = shorten_list(s[i]);
	}
}

void	handler(int x)
{
	(void) x;
	printf("\n");
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

void	handler2(int x)
{
	(void) x;
}

char	**ft_environ(void)
{
	extern char	**environ;
	char		**env;
	char		*tmp;
	t_var		*v;
	int			i;

	i = 0;
	v = g_var;
	while (environ[i])
		i++;
	while (v)
	{
		if (v->export)
			i++;
		v = v->next;
	}
	env = (char **)malloc(i + 1);
	i = -1;
	while (environ[++i])
		env[i] = ft_strcpy(environ[i]);
	v = g_var;
	while (v)
	{
		if (v->export)
		{
			tmp = ft_strjoin(v->name, "=");
			env[i++] = ft_strjoin(tmp, v->value);
			free(tmp);
		}
		v = v->next;
	}
	env[i] = 0;
	return (env);
}

int	exe_path(char **s, char **p, int i)
{
	char	*pa;
	char	*temp;
	int		stat;

	temp = ft_strjoin(p[i], "/");
	pa = ft_strjoin(temp, s[0]);
	free(temp);
	if (!access(pa, X_OK))
	{
		if (!fork())
			execve(pa, s, ft_environ());
		waitpid(-1, &stat, 0);
		ft_varedit(&g_var, ft_strcpy("?"), ft_itoa(WEXITSTATUS(stat)), 0);
		free(pa);
		return (1);
	}
	free(pa);
	return (0);
}

void	programs(char **s)
{
	char	**p;
	int		stat;
	int		i;

	if (!access(s[0], X_OK))
	{
		if (!fork())
			execve(s[0], s, ft_environ());
		waitpid(-1, &stat, 0);
		ft_varedit(&g_var, ft_strcpy("?"), ft_itoa(WEXITSTATUS(stat)), 0);
	}
	else
	{
		p = ft_split(getenv("PATH"), ':');
		i = -1;
		while (p[++i])
		{
			if (exe_path(s, p, i))
				break ;
		}
		free_split(p);
	}
}

void	new_str(char **str, char *value, int start, int end)
{
	int		i;
	int		j;
	char	*new;

	new = malloc((ft_strlen(*str) - (end - start)) + ft_strlen(value) + 1);
	i = -1;
	j = -1;
	while (++i < start)
		new[++j] = (*str)[i];
	i = -1;
	while (value[++i])
		new[++j] = value[i];
	i = end - 1;
	while ((*str)[++i])
		new[++j] = (*str)[i];
	new[++j] = 0;
	free(*str);
	*str = new;
}

void	sub_var(char **str, int start)
{
	int		i;
	int		end;
	char	*name;
	t_var	*v;

	i = start + 1;
	if ((*str)[i] == '?' || (*str)[i] == '_'
		|| ((*str)[i] >= '0' && (*str)[i] <= '9')
		|| ((*str)[i] >= 'a' && (*str)[i] <= 'z')
		|| ((*str)[i] >= 'A' && (*str)[i] <= 'Z'))
	{
		if ((*str)[i] == '?')
		{
			v = ft_varsearch(g_var, "?");
			new_str(str, v->value, start, start + 2);
		}
		else
		{
			while ((*str)[i] == '_' || ((*str)[i] >= '0' && (*str)[i] <= '9')
				|| ((*str)[i] >= 'a' && (*str)[i] <= 'z')
				|| ((*str)[i] >= 'A' && (*str)[i] <= 'Z'))
				i++;
			end = i;
			name = ft_substr(*str, start + 1, end - (start + 1));
			if (getenv(name))
				new_str(str, getenv(name), start, end);
			else
			{
				v = ft_varsearch(g_var, name);
				if (v)
					new_str(str, v->value, start, end);
				else
					new_str(str, "", start, end);
			}
			free(name);
		}
	}
}

void	check_var(char **s)
{
	int	i;
	int	j;

	i = -1;
	while (s[++i])
	{
		j = 0;
		while (s[i][j])
		{
			if (s[i][j] == '$')
				sub_var(&s[i], j);
			else if (s[i][j] == 18)
				s[i][j] = '$';
			j++;
		}
	}
}

int	var_value(char *str, int export)
{
	int		i;
	char	*name;
	char	*value;

	i = 0;
	while (str[i] == '_' || (str[i] >= '0' && str[i] <= '9')
		|| (str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
		i++;
	if (i && str[i] == '=')
	{
		name = malloc(i + 1);
		ft_strlcpy(name, str, i + 1);
		value = malloc(ft_strlen(str) - i);
		ft_strlcpy(value, str + i + 1, ft_strlen(str) - i);
		ft_varedit(&g_var, name, value, export);
		return (1);
	}
	return (0);
}

void	ft_env(void)
{
	extern char	**environ;
	t_var		*v;
	int			i;

	i = 0;
	while (environ[i])
		printf("%s\n", environ[i++]);
	v = g_var;
	while (v)
	{
		if (v->export)
			printf("%s=%s\n", v->name, v->value);
		v = v->next;
	}
}

void	ft_export(char **s)
{
	t_var	*v;
	int		i;

	i = 0;
	if (!s[1])
		ft_env();
	else
	{
		while (s[++i])
		{
			if (!var_value(s[i], 1) && s[i][0] != '?')
			{
				v = ft_varsearch(g_var, s[i]);
				if (v)
					v->export = 1;
			}
		}
	}
}

void	cases(char **s)
{
	int	i;

	i = -1;
	while (s[++i] && var_value(s[i], 0))
		;
	if (!ft_strcmp(s[0], "env"))
		ft_env();
	else if (!ft_strcmp(s[0], "export"))
		ft_export(s);
	else
		programs(s);
}

int	main(void)
{
	char	*str;
	char	**s;

	signal(SIGINT, handler);
	signal(SIGQUIT, handler2);
	g_var = 0;
	ft_varadd_front(&g_var, ft_strcpy("?"), ft_strcpy("0"), 0);
	while (1)
	{
		str = readline("minishell> ");
		if (!str || !ft_strcmp(str, "exit"))
		{
			printf("exit\n");
			exit(0);
		}
		add_history(str);
		if (str[0])
		{
			space_in_quote(str);
			del_quote(str);
			s = ft_split(str, ' ');
			spaces(s);
			check_var(s);
			cases(s);
			free_split(s);
		}
		free(str);
	}
}
