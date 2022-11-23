/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnascari <lnascari@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:18:03 by lnascari          #+#    #+#             */
/*   Updated: 2022/11/23 14:09:11 by lnascari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static void	ft_bzero(void *s, size_t n)
{
	char	*str;
	int		i;

	i = 0;
	str = s;
	while ((long unsigned int) i < n)
	{
		str[i] = 0;
		i++;
	}
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != 0)
	{
		i++;
	}
	return (i);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;

	if (!nmemb || !size)
	{
		nmemb = 1;
		size = 1;
	}
	p = malloc(nmemb * size);
	if (!p)
		return (0);
	ft_bzero(p, nmemb * size);
	return (p);
}

char	*ft_strjoin(char *s1, char *s2)
{
	unsigned int	i;
	char			*p;
	int				l;
	int				j;

	l = ft_strlen(s1) + ft_strlen(s2) + 1;
	p = ft_calloc(l, 1);
	if (!p)
		return (0);
	j = 0;
	i = 0;
	while (s1[i] != 0)
		p[j++] = s1[i++];
	i = 0;
	while (s2[i] != 0)
		p[j++] = s2[i++];
	free(s1);
	free(s2);
	return (p);
}

char	*ft_strlcpy(char *src, int size, void *clean)
{
	int		i;
	char	*dst;

	dst = ft_calloc(size, 1);
	if (size != 0)
	{
		i = 0;
		while (i < size - 1 && src[i] != 0)
		{
			dst[i] = src [i];
			i++;
		}
		dst[i] = 0;
	}
	if (clean)
		free(clean);
	return (dst);
}
