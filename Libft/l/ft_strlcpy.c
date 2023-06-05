/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnascari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:54:37 by lnascari          #+#    #+#             */
/*   Updated: 2022/10/04 14:54:40 by lnascari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		i++;
	}
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int	i;

	if (size != 0)
	{
		i = 0;
		while (i < size - 1 && src[i] != 0)
		{
			dst[i] = src [i];
			i++;
		}
		dst[i] = 0;
	}
	return (ft_strlen((char *)src));
}

/* int main () {
   const char src[50] = "abcdefghijkl";
   char dest[50] = "0123456789";
   printf("size = %ld\n%s\n", ft_strlcpy(dest, src, sizeof(char) * 10), dest);
} */