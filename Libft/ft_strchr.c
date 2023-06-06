/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnascari <lnascari@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:57:34 by lnascari          #+#    #+#             */
/*   Updated: 2023/06/06 12:04:28 by lnascari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	if (!c)
		return ((char *) s + ft_strlen(s));
	while (*s)
	{
		if (*s++ == c)
			return ((char *) s);
	}
	return (0);
}
