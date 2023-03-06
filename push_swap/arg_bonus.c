/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnascari <lnascari@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 13:51:03 by lnascari          #+#    #+#             */
/*   Updated: 2023/03/06 13:56:16 by lnascari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	arg_checker_error(int *arr, char **arg)
{
	int	i;

	write(2, "Error\n", 7);
	free(arr);
	i = -1;
	while (arg[++i])
		free(arg[i]);
	free(arg);
	exit(0);
}

int	arg_checker_check(char *str, int *arr, char **arg)
{
	long	n;
	int		i;

	i = -1;
	while (str[++i])
	{
		if ((str[i] < '0' || str[i] > '9') && (str[i] != '+' && str[i] != '-'))
			arg_checker_error(arr, arg);
	}
	n = ft_atoi(str);
	if (n > 2147483647 || n < -2147483648)
		arg_checker_error(arr, arg);
	return ((int) n);
}

void	arg_checker_duplicates(int *arr, int len, char **arg)
{
	int	i;
	int	j;

	i = -1;
	while (++i < len - 1)
	{
		j = i;
		while (++j < len)
		{
			if (arr[i] == arr[j])
				arg_checker_error(arr, arg);
		}
	}
}

void	arg_checker(char *argv)
{
	char	**arg;
	int		*arr;
	int		len;
	int		i;
	int		j;

	arg = ft_split(argv, ' ');
	len = 0;
	while (arg[len])
		len++;
	arr = malloc(len * sizeof(int));
	i = len;
	j = 0;
	while (--i >= 0)
		arr[j++] = arg_checker_check(arg[i], arr, arg);
	arg_checker_duplicates(arr, len, arg);
	i = -1;
	while (arg[++i])
		free(arg[i]);
	free(arg);
	checker(arr, len);
}
