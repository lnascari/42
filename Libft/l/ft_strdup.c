/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnascari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:06:19 by lnascari          #+#    #+#             */
/*   Updated: 2022/10/05 14:06:26 by lnascari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

char	*ft_strdup(const char *s)
{
	char	*p;
	int		l;
	int		i;

	l = ft_strlen(s);
	p = (char *)malloc((l + 1) * sizeof(char));
	if (!p)
		return (0);
	i = 0;
	while (i < l)
	{
		p[i] = s[i];
		i++;
	}
	p[l] = 0;
	return (p);
}

/* int main()
{
	const char s[] = "lorem ipsum dolor sit amet";
	printf("%s\n", ft_strdup(s));
} */