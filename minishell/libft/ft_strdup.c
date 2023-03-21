/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaoline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:11:30 by gpaoline          #+#    #+#             */
/*   Updated: 2022/10/05 14:11:31 by gpaoline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include <string.h>

char	*ft_strdup(const char *s)
{
	char				*p;
	long unsigned int	lg;
	int					i;

	lg = ft_strlen((char *)s);
	p = (char *)malloc((lg + 1) * sizeof(char));
	if (!p)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		p[i] = s[i];
		i ++;
	}
	p[i] = '\0';
	return (p);
}

/* int main()
{
	const char s[] = "lorem ipsum dolor sit amet";
	printf("%s\n", ft_strdup(s));
} */

/* void	ft_print_result(char const *s)
{
	int		len;

	len = 0;
	while (s[len])
		len++;
	write(1, s, len);
}

int		main()
{
	char	str[] = "lorem ipsum dolor sit amet";
	char	*str_dup;

	alarm(5);
	if (!(str_dup = ft_strdup(str)))
		ft_print_result("NULL");
	else
		ft_print_result(str_dup);
	if (str_dup == str)
		ft_print_result("\nstr_dup's adress == str's adress");
	return (0);
} */