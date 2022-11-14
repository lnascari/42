/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnascari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:52:28 by lnascari          #+#    #+#             */
/*   Updated: 2022/10/03 15:52:30 by lnascari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

void	*ft_memset(void *s, int c, size_t n)
{
	char	*str;
	int		i;

	i = 0;
	str = s;
	while ((long unsigned int) i < n)
	{
		str[i] = c;
		i++;
	}
	return (s);
}

/* int main(){
	char x[] = "aaaaaaa";
	ft_memset(&x, '@', sizeof(char) * 5);
	printf("%s\n", x);
} */