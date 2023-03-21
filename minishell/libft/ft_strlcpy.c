/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaoline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:56:45 by gpaoline          #+#    #+#             */
/*   Updated: 2022/10/04 14:56:47 by gpaoline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
// #include <unistd.h>

static size_t	ft_lenght(const char *str)
{
	unsigned long int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	unsigned long int	i;
	unsigned long int	x;

	x = ft_lenght(src);
	i = 0;
	if (size != 0)
	{
		while (src[i] != '\0' && i < size - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (x);
}

/*int main()
{
	char str1[10] = "SASAS";
	char str2[15] = "SOSOS";
	unsigned int size = 10;
	printf("%ld\n", ft_strlcpy(str2, str1, size));
	printf("%s\n", str2);
}*/
