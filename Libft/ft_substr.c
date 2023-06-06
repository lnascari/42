#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
    char	*str;

	str = malloc(len + 1);
	if (!str)
		return (0);
	i = -1;
	while (++i < len && s[start + i])
		str[i] = s[start + i];
	str[i] = 0;
	return (str);
}
