/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnascari <lnascari@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 11:15:04 by lnascari          #+#    #+#             */
/*   Updated: 2022/10/16 14:07:12 by lnascari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*p;

	if (!*lst)
		*lst = new;
	else
	{
		p = *lst;
		while (p->next != 0)
		{
			p = p->next;
		}
		p->next = new;
	}
}
