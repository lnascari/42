/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnascari <lnascari@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 12:24:49 by lnascari          #+#    #+#             */
/*   Updated: 2022/11/22 12:29:44 by lnascari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(void)
{
	int	i;
	int	fd;

	fd = open("file.txt", O_RDONLY);
	i = 0;
	while (i++ < 10)
		printf("%s", get_next_line(fd));
}
