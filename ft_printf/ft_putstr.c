/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekrem <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:04:27 by hekrem            #+#    #+#             */
/*   Updated: 2022/12/08 15:00:21 by hekrem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *s, int *index)
{
	int	i;

	i = 0;
	if (s == NULL)
		ft_putstr("(null)", index);
	else
	{
		while (s[i])
		{
			*index += ft_putchar(s[i]);
			i++;
		}	
	}
}
