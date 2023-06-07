/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnascari <lnascari@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 10:53:42 by lnascari          #+#    #+#             */
/*   Updated: 2023/06/07 11:39:09 by lnascari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	str = malloc(len + 1);
	if (!str)
		return (0);
	i = -1;
	while (++i < len && start + i < ft_strlen(s))
		str[i] = s[start + i];
	str[i] = 0;
	return (str);
}
