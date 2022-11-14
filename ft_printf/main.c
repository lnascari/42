/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnascari <lnascari@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 22:20:33 by lnascari          #+#    #+#             */
/*   Updated: 2022/11/07 14:35:21 by lnascari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_printf(const char *s, ...);

int	main(void)
{
	char	*s;

	s = 0;
	printf("\t%d", printf("a"));
	printf("\n");
	ft_printf("\t%d", ft_printf("a"));
	ft_printf("\n");
	printf("\t%d", printf("%c", 46));
	printf("\n");
	ft_printf("\t%d", ft_printf("%c", 46));
	ft_printf("\n");
	printf("\t%d", printf("%c", 0));
	printf("\n");
	ft_printf("\t%d", ft_printf("%c", 0));
	ft_printf("\n");
	printf("\t%d", printf("%c", 128));
	printf("\n");
	ft_printf("\t%d", ft_printf("%c", 128));
	ft_printf("\n");
	printf("\t%d", printf("%s", "ciao"));
	printf("\n");
	ft_printf("\t%d", ft_printf("%s", "ciao"));
	ft_printf("\n");
	printf("\t%d", printf("%s", s));
	printf("\n");
	ft_printf("\t%d", ft_printf("%s", s));
	ft_printf("\n");
	printf("\t%d", printf("%p", &s));
	printf("\n");
	ft_printf("\t%d", ft_printf("%p", &s));
	ft_printf("\n");
	printf("\t%d", printf("%p", (void *)s));
	printf("\n");
	ft_printf("\t%d", ft_printf("%p", (void *)s));
	ft_printf("\n");
	printf("\t%d", printf("%p", (void *)234));
	printf("\n");
	ft_printf("\t%d", ft_printf("%p", (void *)234));
	ft_printf("\n");
	printf("\t%d", printf("%d", 0));
	printf("\n");
	ft_printf("\t%d", ft_printf("%d", 0));
	ft_printf("\n");
	printf("\t%d", printf("%d", 2147483647));
	printf("\n");
	ft_printf("\t%d", ft_printf("%d", 2147483647));
	ft_printf("\n");
	printf("\t%d", printf("%d", -2147483647));
	printf("\n");
	ft_printf("\t%d", ft_printf("%d", -2147483647));
	ft_printf("\n");
	printf("\t%d", printf("%i", 2147483647));
	printf("\n");
	ft_printf("\t%d", ft_printf("%i", 2147483647));
	ft_printf("\n");
	printf("\t%d", printf("%u", 42));
	printf("\n");
	ft_printf("\t%d", ft_printf("%u", 42));
	ft_printf("\n");
	printf("\t%d", printf("%u", -2147483647));
	printf("\n");
	ft_printf("\t%d", ft_printf("%u", -2147483647));
	ft_printf("\n");
	printf("\t%d", printf("%x", 104683));
	printf("\n");
	ft_printf("\t%d", ft_printf("%x", 104683));
	ft_printf("\n");
	printf("\t%d", printf("%X", 962354));
	printf("\n");
	ft_printf("\t%d", ft_printf("%X", 962354));
	ft_printf("\n");
	printf("\t%d", printf("abcd '%d%%'", 37));
	printf("\n");
	ft_printf("\t%d", ft_printf("abcd '%d%%'", 37));
	ft_printf("\n");
	printf("\t%d", printf("%p", -1));
	printf("\n");
	ft_printf("\t%d", ft_printf("%p", -1));
	ft_printf("\n");
	printf("\t%d", printf("%p", 0xdeadc0de));
	printf("\n");
	ft_printf("\t%d", ft_printf("%p", 0xdeadc0de));
	ft_printf("\n");
}
