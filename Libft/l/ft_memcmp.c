/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnascari <lnascari@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 11:52:29 by lnascari          #+#    #+#             */
/*   Updated: 2022/10/21 13:25:35 by lnascari         ###   ########.fr       */
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
	char s1[] = "abcddf";
	char s2[] = "abcdef";
	printf("%d\n", ft_memcmp(s1, s2, 5));
} */