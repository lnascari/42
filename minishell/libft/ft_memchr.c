/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaoline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:03:25 by gpaoline          #+#    #+#             */
/*   Updated: 2022/10/05 10:03:26 by gpaoline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
// #include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char			*ptr;
	const char			*ptr2;
	long unsigned int	count;

	count = 0;
	ptr = s;
	ptr2 = s;
	while (count < n)
	{
		if (ptr[count] == c)
			return ((char *)ptr2);
		count ++;
		ptr2 ++;
	}
	return (0);
}

/* int main()
{
	char s[] = "abcdefg";
	char c = 'h';
	printf("%p\n", ft_memchr(s, c, 9));
	printf("%p\n", memchr(s, c, 9));
} */