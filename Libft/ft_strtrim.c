#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*p;
	int		l;
	int		i;
	int		s;
	int		e;

	l = ft_strlen(s1);
	i = 0;
	while (i < l && ft_strchr(set, s1[i]))
		i++;
	if (i == l)
		return (ft_calloc(1, 1));
	s = i;
	i = l - 1;
	while (i >= 0 && ft_strchr(set, s1[i]))
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
