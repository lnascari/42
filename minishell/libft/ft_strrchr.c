/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaoline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 16:42:52 by gpaoline          #+#    #+#             */
/*   Updated: 2022/10/04 16:42:55 by gpaoline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	x;

	i = 0;
	x = -1;
	while (s[i] != 0)
	{
		if (s[i] == c)
			x = i;
		i++;
	}
	if (c == 0)
		return ((char *)s + i);
	if (x != -1)
		return ((char *)s + x);
	return (0);
}

/* int main () {
   const char s[50] = "abcdabcd";
   printf("%s\n", ft_strrchr(s, 'a'));
} */