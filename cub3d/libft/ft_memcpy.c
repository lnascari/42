/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaoline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 11:27:04 by gpaoline          #+#    #+#             */
/*   Updated: 2022/10/04 11:27:05 by gpaoline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
// #include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t length)
{
	long unsigned int	count;
	char				*ptr;

	ptr = dst;
	count = 0;
	while (count < length)
	{
		*ptr = *(char *)src;
		ptr ++;
		src ++;
		count ++;
	}
	return (dst);
}

/*int main()
{
	char src[] = "sooo";
	char dst[] = "saaa";
	char dst2[] = "saaa";
	ft_memcpy(dst, src, 6);
	printf("%s\n", dst);
	memcpy(dst2, src, 6);
	printf("%s\n", dst2);
}*/
