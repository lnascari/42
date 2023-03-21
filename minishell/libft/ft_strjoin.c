/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaoline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 15:09:48 by gpaoline          #+#    #+#             */
/*   Updated: 2022/10/05 15:09:49 by gpaoline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

static size_t	ft_strlen(char *str)
{
	long unsigned int	count;

	count = 0;
	while (str[count] != '\0')
	{
		count++;
	}
	return (count);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char				*s3;
	unsigned long int	x;
	unsigned long int	y;
	unsigned long int	lg;

	lg = ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1;
	x = 0;
	y = 0;
	s3 = (char *)malloc(lg * sizeof(char));
	if (s3 == 0)
		return (0);
	while (s1[x] != '\0')
	{
		s3[x] = s1[x];
		x ++;
	}
	while (s2[y] != '\0')
	{
		s3[x] = s2[y];
		x ++;
		y ++;
	}
	s3[x] = '\0';
	return (s3);
}

/* int main()
{
	const char s1[] = "SATOR";
	const char s2[] = "AREPO";
	printf("%s\n", ft_strjoin(s1, s2));
} */