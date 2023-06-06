/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnascari <lnascari@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 12:04:57 by lnascari          #+#    #+#             */
/*   Updated: 2023/06/06 14:28:35 by lnascari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*p;

	if (!c)
		return ((char *) s + ft_strlen(s));
	p = 0;
	while (*s)
	{
		if (*s == c)
			p = (char *) s;
		s++;
	}
	return (p);
}
