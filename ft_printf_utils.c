/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdric.b <cdric.b@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 23:33:19 by cdric.b           #+#    #+#             */
/*   Updated: 2026/04/05 04:46:25 by cdric.b          ###   ########.fr       */
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

void	ft_putnbr_base(int nb, char *base, int fd, int *r)
{
	char	c;
	long	n;
	size_t	len;

	n = nb;
	if (n < 0)
	{
		(*r) += write(fd, "-", 1);
		n = n * -1;
	}
	len = ft_strlen(base);
	if (n >= (int)len)
		ft_putnbr_base(n / len, base, fd, r);
	c = base[n % len];
	write(1, &c, 1);
	(*r)++;
}

void	ft_putptr_base(unsigned long nb, char *base, int fd, int *r)
{
	char	c;
	size_t	len;

	printf("voici la size de l'arg: %lu\n", sizeof(nb));

	len = ft_strlen(base);
	if (nb >= len)
		ft_putptr_base(nb / len, base, fd, r);
	c = base[nb % len];
	write(1, &c, 1);
	(*r)++;
}

void	ft_putstr_fd(char *str, int fd, int *r)
{
	if (!str)
	{
		(*r) += write(fd, "(null)", 6);
		return ;
	}
	while (*str)
	{
		(*r) += write(fd, &(*str), 1);
		str++;
	}
}

void	ft_putchar_fd(int c, int fd, int *r)
{
	char	c1;

	c1 = c;
	(*r) += write(fd, &c1, 1);
}
