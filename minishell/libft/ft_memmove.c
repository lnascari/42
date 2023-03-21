/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaoline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 13:51:43 by gpaoline          #+#    #+#             */
/*   Updated: 2022/10/04 13:51:44 by gpaoline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
// #include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t length)
{
	long unsigned int	i;
	char				*ptrd;
	char				*ptrs;

	ptrs = (char *)src;
	ptrd = (char *)dst;
	i = 0;
	if (ptrd > ptrs)
	{
		while (length-- > 0)
			ptrd[length] = ptrs[length];
	}
	else
	{
		while (i < length)
		{
			ptrd[i] = ptrs[i];
			i ++;
		}
	}
	return (dst);
}

/*int main()
{
	char src[] = "sooo";
	char dst[] = "saaa";
	char dst2[] = "saaa";
	ft_memmove(dst, src, 3);
	printf("%s\n", dst);
	memmove(dst2, src, 3);
	printf("%s\n", dst2);
}*/
