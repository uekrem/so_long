/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekrem <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:01:24 by hekrem            #+#    #+#             */
/*   Updated: 2022/12/08 14:32:58 by hekrem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hex(unsigned int nbr, int *index)
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
		ft_hex(nbr / 16, index);
		ft_hex(nbr % 16, index);
	}
}
