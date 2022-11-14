/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnascari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 12:15:28 by lnascari          #+#    #+#             */
/*   Updated: 2022/10/04 12:15:31 by lnascari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*d;
	int		i;

	d = dest;
	i = 0;
	while ((long unsigned int) i < n)
	{
		d[i] = *(char *)(src + i);
		i++;
	}
	return (dest);
}

/* int main () {
   const char src[50] = "abcdefghijk";
   char dest[50] = "0123456789";
   printf("Before memcpy dest = %s\n", dest);
   ft_memcpy(&dest, &src, sizeof(char) * 9);
   printf("After memcpy dest = %s\n", dest);
} */