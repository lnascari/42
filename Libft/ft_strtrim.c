/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnascari <lnascari@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 15:28:29 by lnascari          #+#    #+#             */
/*   Updated: 2022/10/17 13:07:21 by lnascari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

static int	ft_inset(const char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != 0)
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*p;
	int		l;
	int		i;
	int		s;
	int		e;

	l = ft_strlen(s1);
	i = 0;
	while (i < l && ft_inset(s1[i], set))
		i++;
	if (i == l)
		return (ft_calloc(1, 1));
	s = i;
	i = l - 1;
	while (i >= 0 && ft_inset(s1[i], set))
		i--;
	e = i;
	p = ft_calloc(l - s - (l - e) + 2, 1);
	if (!p)
		return (0);
	i = -1;
	while (s + (++i) <= e)
		p[i] = s1[s + i];
	return (p);
}

/* int	main()
{
	const char s[] = "12915231uoh";
	const char set[] = "abc";
	printf("%s\n", ft_strtrim(s, set));
} */