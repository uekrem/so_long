/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekrem <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:07:15 by hekrem            #+#    #+#             */
/*   Updated: 2022/12/08 15:20:59 by hekrem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int		ft_printf(const char *s, ...);
void	ft_putnbr(long nbr, int *index);
int		ft_putchar(char c);
void	ft_putstr(char *s, int *index);
void	ft_pointer(unsigned long nbr, int *index);
void	ft_uns(unsigned long nbr, int *index);
void	ft_uphex(unsigned int nbr, int *index);
void	ft_hex(unsigned int nbr, int *index);

#endif
