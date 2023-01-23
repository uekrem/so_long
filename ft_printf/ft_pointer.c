/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekrem <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:01:48 by hekrem            #+#    #+#             */
/*   Updated: 2022/12/08 14:01:49 by hekrem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_pointer(unsigned long nbr, int *index)
{
	char	*base;

	base = "0123456789abcdef";
	if (nbr < 16)
	{
		if (nbr < 10)
			*index += ft_putchar(nbr + '0');
		else
			*index += ft_putchar(base[nbr % 16]);
	}
	if (nbr >= 16)
	{
		ft_pointer(nbr / 16, index);
		ft_pointer(nbr % 16, index);
	}
}
