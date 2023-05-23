/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaoline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 13:53:44 by gpaoline          #+#    #+#             */
/*   Updated: 2022/10/10 13:53:45 by gpaoline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

/* void	f(unsigned int i, char * c)
{
	*c += 1;
} */

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	long unsigned int		i;

	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i ++;
	}
}

/* int main()
{
	char s[] = "abcd";
	void (*fp)(unsigned int, char *);
	fp = f;
	ft_striteri(s, fp);
	printf("%s\n", s);
} */