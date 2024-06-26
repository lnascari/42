/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnascari <lnascari@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:02:07 by lnascari          #+#    #+#             */
/*   Updated: 2023/03/06 13:57:28 by lnascari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	error(int *arr)
{
	write(2, "Error\n", 7);
	free(arr);
	exit(0);
}

int	check(char *str, int *arr)
{
	long	n;
	int		i;

	i = -1;
	while (str[++i])
	{
		if ((str[i] < '0' || str[i] > '9') && (str[i] != '+' && str[i] != '-'))
			error(arr);
	}
	n = ft_atoi(str);
	if (n > 2147483647 || n < -2147483648)
		error(arr);
	return ((int) n);
}

void	duplicates(int *arr, int len)
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
				error(arr);
		}
	}
}

int	main(int argc, char **argv)
{
	int	*arr;
	int	i;
	int	j;

	if (argc > 1)
	{
		if (argc == 2)
			arg_checker(argv[1]);
		else
		{
			arr = malloc((argc - 1) * sizeof(int));
			i = argc;
			j = 0;
			while (--i > 0)
				arr[j++] = check(argv[i], arr);
			duplicates(arr, argc - 1);
			checker(arr, argc - 1);
		}
	}
}
