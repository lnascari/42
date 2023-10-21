#include "get_next_line.h"

char	*read_line(char *str, int fd)
{
	char	*tmp;
	int 	size;

	size = BUFFER_SIZE;
	if (!str)
		str = ft_calloc(1, sizeof(char));
	tmp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	while (size == BUFFER_SIZE && !ft_strchr(str, '\n'))
	{
		size = read(fd, tmp, BUFFER_SIZE);
		tmp[size] = 0;
		str = ft_strjoin(str, tmp);
	}
	free(tmp);
	return (str);
}

size_t	line_len(char *s)
{
	size_t	i;

	i = -1;
	while (s[++i])
	{
		if(s[i] == '\n')
			return (i + 1);
	}
	return (i);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;
	char		*tmp;

	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, 0, 0) < 0)
		return (0);
	str = read_line(str, fd);
	if (!str || !str[0])
	{
		free(str);
		str = 0;
		return (0);
	}
	line = ft_substr(str, 0, line_len(str));
	tmp = ft_strchr(str, '\n');
	if (tmp)
		tmp = ft_substr(str, line_len(str), ft_strlen(tmp + 1));
	free(str);
	str = tmp;
	return line;
}
