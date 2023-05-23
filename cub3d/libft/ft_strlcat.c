/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaoline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 11:49:58 by gpaoline          #+#    #+#             */
/*   Updated: 2022/05/23 15:08:18 by gpaoline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

static size_t	ft_strlen(char const *str)
{
	long unsigned int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	long unsigned int	i;
	long unsigned int	dlen;
	long unsigned int	j;
	long unsigned int	slen;

	j = 0;
	while (dest[j] != '\0' && j < size)
		j++;
	dlen = j;
	slen = ft_strlen(src);
	if (size == 0 || size <= dlen)
		return (size + slen);
	i = 0;
	while (src[i] != '\0' && i < size - dlen - 1)
	{
		dest[j] = src[i];
		j++;
		i++;
	}
	dest[j] = '\0';
	return (dlen + slen);
}

/* int main()
{
	char src[100] = "SAAAAS";
	char dest[] = "rrrrrrrrrrrrrrr";
	unsigned int size = 5;
	printf("%ld\n", ft_strlcat(dest, "lorem ipsum dolor sit amet", size));
	printf("%s\n", dest);
} */