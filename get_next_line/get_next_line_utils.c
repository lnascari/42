/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnascari <lnascari@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:18:03 by lnascari          #+#    #+#             */
/*   Updated: 2022/11/18 15:21:49 by lnascari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_strlcpy(char *dst, char *src, int size)
{
	int	i;

	if (size != 0)
	{
		i = 0;
		while (i < size - 1 && src[i] != 0)
		{
			dst[i] = src [i];
			i++;
		}
		dst[i] = 0;
	}
}