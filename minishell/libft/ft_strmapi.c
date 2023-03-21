/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaoline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 12:03:38 by gpaoline          #+#    #+#             */
/*   Updated: 2022/10/07 12:03:39 by gpaoline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char					*s1;
	long unsigned int		len;
	long unsigned int		i;

	i = 0;
	len = ft_strlen((char *)s);
	s1 = (char *)malloc((len + 1) * sizeof(char));
	if (s1 == 0)
		return (0);
	while (i < len)
	{
		s1[i] = f(i, s[i]);
		i ++;
	}
	s1[i] = '\0';
	return (s1);
}

/* int main()
{
	char s[] = "abcd";
	char (*fp)(unsigned int, char);
	fp = fa;
	printf("%s\n", ft_strmapi(s, fp));
} */