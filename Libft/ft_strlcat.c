/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnascari <lnascari@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:01:21 by lnascari          #+#    #+#             */
/*   Updated: 2023/06/06 11:33:54 by lnascari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dstlen;

	dstlen = 0;
	while (dstlen < size && dst[dstlen])
		dstlen++;
	if (size == dstlen)
		return (size + ft_strlen(src));
	i = -1;
	j = dstlen;
	while (size && ++i < size - dstlen - 1 && src[i])
		dst[j++] = src[i];
	dst[j] = 0;
	return (ft_strlen(src) + dstlen);
}
