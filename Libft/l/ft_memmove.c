/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnascari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:12:19 by lnascari          #+#    #+#             */
/*   Updated: 2022/10/04 14:12:29 by lnascari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	s[1024];
	char	*d;
	int		i;

	d = dest;
	i = 0;
	while ((long unsigned int) i < n)
	{
		s[i] = *(char *)(src + i);
		i++;
	}
	i = 0;
	while ((long unsigned int) i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

/* int main () {
   const char src[50] = "abcdefghijk";
   char dest[50] = "0123456789";
   printf("Before memmove dest = %s\n", dest);
   ft_memmove(&dest, &src, sizeof(char) * 9);
   printf("After memmove dest = %s\n", dest);
} */