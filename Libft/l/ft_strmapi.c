/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnascari <lnascari@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 17:00:24 by lnascari          #+#    #+#             */
/*   Updated: 2022/10/17 13:04:06 by lnascari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

static int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		i++;
	}
	return (i);
}

static char	*ft_strcpy(const char *src)
{
	unsigned int	i;
	char			*dst;

	dst = malloc(ft_strlen(src) + 1);
	if (!dst)
		return (0);
	i = 0;
	while (src[i] != 0)
	{
		dst[i] = src [i];
		i++;
	}
	dst[i] = 0;
	return (dst);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		i;

	str = ft_strcpy(s);
	if (!str)
		return (0);
	i = 0;
	while (str[i] != 0)
	{
		str[i] = f(i, str[i]);
		i++;
	}
	return (str);
}

/* char	f(unsigned int i, char c)
{
	return (c + 1);
}

int	main()
{
	printf("%s\n", ft_strmapi("abcde", f));
} */