/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaoline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:19:30 by gpaoline          #+#    #+#             */
/*   Updated: 2022/10/03 15:19:32 by gpaoline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memset(void *str, int c, size_t n)
{
	long unsigned int	count;
	char				*ptr;

	ptr = str;
	count = 0;
	while (count < n)
	{
		*ptr = c;
		ptr ++;
		count ++;
	}
	return (str);
}

/*int main()
{
	int i = 0;
	int str[] = {1, 2, 3, 4, 5};
	while (i < 5)
	{
		printf("%d ", str[i]);
		i++;
	}
	ft_memset(str, 0, 8);
	printf("\n");
	i = 0;
	while (i < 5)
	{
		printf("%d ", str[i]);
		i++;
	}
	printf("\n");
}*/
