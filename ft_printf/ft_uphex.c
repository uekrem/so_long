/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uphex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekrem <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:05:25 by hekrem            #+#    #+#             */
/*   Updated: 2022/12/08 14:30:19 by hekrem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_uphex(unsigned int nbr, int *index)
{
	char	*base;

	base = "0123456789ABCDEF";
	if (nbr < 16)
	{
		if (nbr < 10)
			*index += ft_putchar(nbr + '0');
		else
			*index += ft_putchar(base[nbr % 16]);
	}
	if (nbr >= 16)
	{
		ft_uphex(nbr / 16, index);
		ft_uphex(nbr % 16, index);
	}
}
