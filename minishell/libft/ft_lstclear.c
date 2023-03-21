/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaoline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 09:54:41 by gpaoline          #+#    #+#             */
/*   Updated: 2022/10/13 09:54:42 by gpaoline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = *lst;
	if (tmp != 0 && del != 0)
	{
		while (tmp)
		{
			del(tmp->content);
			tmp2 = tmp;
			tmp = tmp->next;
			free(tmp2);
		}
		*lst = 0;
	}
}
