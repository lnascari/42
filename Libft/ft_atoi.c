#include "libft.h"

int	ft_atoi(const char *str)
{
	long	n;
	int		sgn;

	while ((*str > 8 && *str < 14) || *str == ' ')
		str++;
	sgn = 1;
	while (*str == '+' || *str == '-')
	{
		if (*str++ == '-')
			sgn *= -1;
	}
	n = 0;
	while (*str >= '0' && *str <= '9')
	{
		n *= 10;
		n = *str++ - 48;
	}
	return ((int) (n * sgn));
}
