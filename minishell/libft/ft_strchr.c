/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaoline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:59:41 by gpaoline          #+#    #+#             */
/*   Updated: 2022/10/04 15:59:42 by gpaoline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	int		count;
	char	*t;

	t = (char *)s;
	count = 0;
	if (c == '\0')
	{
		while (s[count] != '\0')
			count ++;
		t = (char *)&s[count];
		return (t);
	}
	else
	{
		while (s[count] != '\0')
		{
			if (s[count] == c)
			{
				t = (char *)&s[count];
				return (t);
			}
			count ++;
		}
	}
	return (0);
}

/* int main ()
{
	const char s[] = "bonjour";
	char c = 's';
	// ft_strchr(s, c);
	printf("%s\n", ft_strchr(s, c));
} */