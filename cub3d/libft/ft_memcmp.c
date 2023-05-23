/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaoline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:56:36 by gpaoline          #+#    #+#             */
/*   Updated: 2022/10/05 10:56:37 by gpaoline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const char			*ptr1;
	const char			*ptr2;
	long unsigned int	count;

	if (n == 0)
		return (0);
	count = 0;
	ptr1 = s1;
	ptr2 = s2;
	while (count < n)
	{
		if (ptr1[count] != ptr2[count])
		{
			if (ptr2[count] == '\0')
				return (1);
			if (ptr1[count] == '\0')
				return (-1);
			return (ptr1[count] - ptr2[count]);
		}
		count ++;
	}
	return (0);
}

/* int main()
{
	const char s1[] = "abcdefg";
	const char s2[] = "AbcDefg";
	printf("%d\n", ft_memcmp("t\200", "t\0", 2));
	printf("%d\n", memcmp("t\200", "t\0", 2));
} */