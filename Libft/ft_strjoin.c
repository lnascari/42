/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnascari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 15:16:38 by lnascari          #+#    #+#             */
/*   Updated: 2022/10/05 15:16:39 by lnascari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

static size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != 0)
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	i;
	char			*p;
	int				l;
	int				j;

	l = ft_strlen(s1) + ft_strlen(s2) + 1;
	p = malloc(l);
	if (!p)
		return (0);
	j = 0;
	i = 0;
	while (s1[i] != 0)
		p[j++] = s1[i++];
	i = 0;
	while (s2[i] != 0)
		p[j++] = s2[i++];
	p[j] = 0;
	return (p);
}

/* int main()
{
	const char *s1 = "abcd";
	const char *s2 = "efgh";
	printf("%s\n", ft_strjoin(s1, s2));
} */