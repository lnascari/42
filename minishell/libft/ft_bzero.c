/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaoline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 11:09:10 by gpaoline          #+#    #+#             */
/*   Updated: 2022/10/04 11:09:12 by gpaoline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_bzero(void *s, size_t n)
{
	long unsigned int	count;
	unsigned char		*ptr;

	ptr = s;
	count = 0;
	while (count < n)
	{
		*ptr = 0;
		ptr ++;
		count ++;
	}
}

/* int main()
{
	char s[] = "asdf";
	ft_bzero(s, 4);
	printf("%s\n", s);
} */