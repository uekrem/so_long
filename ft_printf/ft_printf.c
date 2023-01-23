/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekrem <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:02:37 by hekrem            #+#    #+#             */
/*   Updated: 2022/12/08 15:22:43 by hekrem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check(char s, va_list list, int *tmp)
{
	if (s == 'c')
		*tmp += ft_putchar(va_arg(list, int));
	else if (s == 's')
		ft_putstr(va_arg(list, char *), tmp);
	else if (s == 'p')
	{
		ft_putstr("0x", tmp);
		ft_pointer(va_arg(list, unsigned long), tmp);
	}
	else if (s == 'd')
		ft_putnbr(va_arg(list, int), tmp);
	else if (s == 'i')
		ft_putnbr(va_arg(list, int), tmp);
	else if (s == 'u')
		ft_uns(va_arg(list, unsigned int), tmp);
	else if (s == 'x')
		ft_hex(va_arg(list, int), tmp);
	else if (s == 'X')
		ft_uphex(va_arg(list, int), tmp);
	else if (s == '%')
		*tmp += ft_putchar('%');
}

int	ft_printf(const char *str, ...)
{
	va_list	list;
	int		i;
	int		tmp;

	i = 0;
	tmp = 0;
	va_start(list, str);
	while (str[i])
	{
		if (str[i] == '%')
		{	
			i++;
			ft_check(str[i], list, &tmp);
		}
		else
			tmp += ft_putchar(str[i]);
		i++;
	}
	va_end(list);
	return (tmp);
}
