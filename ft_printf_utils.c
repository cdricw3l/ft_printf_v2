/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdric.b <cdric.b@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 23:33:19 by cdric.b           #+#    #+#             */
/*   Updated: 2026/03/12 00:07:14 by cdric.b          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putnbr_base(unsigned int nb, char *base, int fd, int *r)
{
	char	c;
	size_t	len;

	len = ft_strlen(base);
	if (nb >= len)
		ft_putnbr_base(nb / len, base, fd, r);
	c = base[nb % len];
	write(1, &c, 1);
	(*r)++;
}

void	ft_putptr_base(unsigned long nb, char *base, int fd, int *r)
{
	char	c;
	size_t	len;

	len = ft_strlen(base);
	if (nb >= len)
		ft_putnbr_base(nb / len, base, fd, r);
	c = base[nb % len];
	write(1, &c, 1);
	(*r)++;
}

void	ft_putstr_fd(char *str, int fd, int *r)
{
	if (!str)
		return ;
	while (*str)
	{
		(*r) += write(fd, &(*str), 1);
		str++;
	}
}

void	ft_putchar_fd(int c, int fd, int *r)
{
	(*r) += write(fd, &c, 1);
}
