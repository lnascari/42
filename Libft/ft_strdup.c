#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*str;

	str = malloc(ft_strlen(s));
	if (!str)
		return (0);
	i = -1;
	while (s[++i])
		str[i] = s[i];
	str[i] = 0;
	return (str);
}