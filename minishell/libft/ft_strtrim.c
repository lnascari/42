/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaoline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 15:43:52 by gpaoline          #+#    #+#             */
/*   Updated: 2022/10/05 15:43:54 by gpaoline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

static int	ft_start(const char *s1, const char *set)
{
	size_t	i;
	size_t	lgs;

	i = 0;
	lgs = ft_strlen((char *)s1);
	while (i < lgs)
	{
		if (ft_strchr(set, s1[i]) == 0)
			break ;
		i ++;
	}
	return (i);
}

static int	ft_end(const char *s1, const char *set)
{
	size_t	i;
	size_t	lgs;

	i = 0;
	lgs = ft_strlen((char *)s1);
	while (i < lgs)
	{
		if (ft_strchr(set, s1[lgs - i - 1]) == 0)
			break ;
		i ++;
	}
	return (lgs - i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*s2;

	if (s1 == 0)
		return (0);
	if (set == 0)
		return (ft_strdup(s1));
	start = ft_start(s1, set);
	end = ft_end(s1, set);
	if (start >= end)
		return (ft_strdup(""));
	s2 = (char *)malloc((end - start + 1) * sizeof(char));
	if (s2 == 0)
		return (0);
	ft_strlcpy(s2, (char *)s1 + start, end - start + 1);
	return (s2);
}

/* int main()
{
	char s1[] = "abcaaaas asdasd saaaabc";
	char set[] = "abc";
	printf("%s\n", ft_strtrim(s1, set));
} */