/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnascari <lnascari@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 13:27:54 by lnascari          #+#    #+#             */
/*   Updated: 2023/06/06 13:50:48 by lnascari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (!*little)
		return ((char *) big);
	i = -1;
	while (++i < len && big[i])
	{
		if (big[i] == little[0])
		{
			j = 0;
			while (j + i < len && big[j + i] == little[i] && little[i])
				j++;
			if (!little[j])
				return ((char *) big + i);
		}
	}
	return (0);
}
