/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnascari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 11:30:48 by lnascari          #+#    #+#             */
/*   Updated: 2022/10/05 11:30:52 by lnascari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		if (*((char *) s + i) == c)
			return (((char *) s + i));
		i++;
	}
	return (0);
}

/* int main () {
   const char s[50] = "abcdedcba";
   printf("%s\n", (char *)ft_memchr(s, 'f', 9));
} */