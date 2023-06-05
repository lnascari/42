/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnascari <lnascari@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 11:53:38 by lnascari          #+#    #+#             */
/*   Updated: 2022/10/16 13:50:09 by lnascari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*p;
	t_list	*tmp;

	p = *lst;
	while (p != 0)
	{
		tmp = p;
		p = p->next;
		del(tmp);
	}
	*lst = 0;
}
