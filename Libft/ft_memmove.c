/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnascari <lnascari@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 13:40:37 by lnascari          #+#    #+#             */
/*   Updated: 2023/06/06 14:23:46 by lnascari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	tmp[1024];

	i = -1;
	while (++i < n)
		tmp[i] = ((char *) src)[i];
	i = -1;
	while (++i < n)
		((char *) dest)[i] = tmp[i];
	return (dest);
}
