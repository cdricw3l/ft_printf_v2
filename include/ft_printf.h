/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdric.b <cdric.b@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 23:37:21 by cdric.b           #+#    #+#             */
/*   Updated: 2026/04/03 05:21:53 by cdric.b          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <assert.h>
#include <limits.h>


# define BASE_D          "0123456789"
# define BASE_HEX_UP     "0123456789ABCDEF"
# define BASE_HEX_LOW    "0123456789abcdef"

int		ft_printf(const char *format, ...);
void	ft_putnbr_base(int nb, char *base, int fd, int *r);
void	ft_putptr_base(unsigned long nb, char *base, int fd, int *r);
void	ft_putstr_fd(char *str, int fd, int *r);
void	ft_putchar_fd(int c, int fd, int *r);
size_t	ft_strlen(char *str);

#endif