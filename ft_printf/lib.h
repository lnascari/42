/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnascari <lnascari@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 22:09:13 by lnascari          #+#    #+#             */
/*   Updated: 2022/11/07 14:28:22 by lnascari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H

int		ft_printf(const char *s, ...);
void	ft_putchar(char c, int *n);
void	ft_putnbr_base(long int nbr, char *base, int *n);
void	ft_putp(unsigned long int nbr, int *n);

#endif