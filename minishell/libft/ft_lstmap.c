/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaoline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 10:51:08 by gpaoline          #+#    #+#             */
/*   Updated: 2022/10/13 10:51:09 by gpaoline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*new1;

	new1 = 0;
	if (lst != 0 && f != 0 && del != 0)
	{
		while (lst)
		{
			new = ft_lstnew(f(lst->content));
			if (!new)
			{
				ft_lstclear(&new1, del);
				return (0);
			}	
			ft_lstadd_back(&new1, new);
			lst = lst->next;
		}
	}
	return (new1);
}
