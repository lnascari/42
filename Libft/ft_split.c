#include "libft.h"

static char	ft_splitsize(char const *s, char c)
{
	int	size;

	if (!*s)
		return (0);
	size = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			size++;
		while (*s && *s != c)
			s++;
	}
	return (size);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		i;

	split = ft_calloc(ft_splitsize(s, c) + 1, sizeof(char));
	if (!split || !s)
		return (0);
	i = -1;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			if (!ft_strchr(s, c))
				split[++i] = ft_substr(s, 0, ft_strlen(s));
			else
				split[++i] = ft_substr(s, 0, ft_strchr(s, c) - s);
		}
		while (*s && *s != c)
			s++;
	}
	return (split);
}
