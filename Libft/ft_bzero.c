/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnascari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 12:05:05 by lnascari          #+#    #+#             */
/*   Updated: 2022/10/04 12:05:17 by lnascari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

void	ft_bzero(void *s, size_t n)
{
	char	*str;
	int		i;

	i = 0;
	str = s;
	while ((long unsigned int) i < n)
	{
		str[i] = 0;
		i++;
	}
}

/* int main(){
	char x[] = "aaaaaaa";
	ft_bzero(&x, 5);
	printf("\n%s", x);
} */