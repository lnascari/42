/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaoline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 13:47:38 by gpaoline          #+#    #+#             */
/*   Updated: 2022/10/05 13:47:40 by gpaoline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	nb;
	char	*p;

	if (!nmemb || !size)
	{
		nmemb = 1;
		size = 1;
	}
	nb = nmemb * size;
	p = malloc(nb);
	if (!p)
		return (0);
	else
		ft_bzero(p, nb);
	return (p);
}
