/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaoline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 09:55:10 by gpaoline          #+#    #+#             */
/*   Updated: 2022/10/05 09:55:11 by gpaoline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
// #include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	long unsigned int	i;

	i = 0;
	while (i < n)
	{
		if (s1[i] == '\0')
			return (-1);
		if (s2[i] == '\0')
			return (1);
		if (s1[i] > s2[i])
			return (s1[i] - s2[i]);
		else if (s1[i] < s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

/* int main()
{
	char s1[] = "AbCDEF";
	char s2[] = "ABCDEF";
	unsigned int n = 7;
	printf("%d ", ft_strncmp(s1, s2, n));
	printf("%d\n", strncmp(s1, s2, n));
} */