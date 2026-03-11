/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdric.b <cdric.b@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 23:02:28 by cdric.b           #+#    #+#             */
/*   Updated: 2026/03/11 23:39:19 by cdric.b          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

static void	case_managment(va_list list, char c, int *r)
{
	if (c == 'c')
		ft_putchar_fd(va_arg(list, int), 1, r);
	if (c == 'd' || c == 'i')
		ft_putnbr_base(va_arg(list, unsigned int), BASE_D, 1, r);
	if (c == 's')
		ft_putstr_fd(va_arg(list, char *), 1, r);
	if (c == 'x')
		ft_putnbr_base(va_arg(list, unsigned int), BASE_HEX_LOW, 1, r);
	if (c == 'X')
		ft_putnbr_base(va_arg(list, unsigned int), BASE_HEX_UP, 1, r);
}

int	ft_printf(const char *format, ...)
{
	int		r;
	va_list	list;

	va_start(list, format);
	r = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			case_managment(list, *format, &r);
			format++;
		}
		else
		{
			write(1, &(*format), 1);
			r++;
			format++;
		}
	}
	va_end(list);
	return (r);
}
