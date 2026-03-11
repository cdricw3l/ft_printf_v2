/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdric.b <cdric.b@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 21:51:07 by cdric.b           #+#    #+#             */
/*   Updated: 2026/03/11 23:38:49 by cdric.b          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

/*

	format: 
			•%c Prints a single character.
			•%s Prints a string (as defined by the common C convention).
			•%p The void * pointer argument has to be printed in hexadecimal format.
			•%d Prints a decimal (base 10) number.
			•%i Prints an integer in base 10.
			•%u Prints an unsigned decimal (base 10) number.
			•%x Prints a number in hexadecimal (base 16) lowercase format.
			•%X Prints a number in hexadecimal (base 16) uppercase format.
			•%% Prints a percent sign.

*/

int	main(void)
{
	int	r;

	assert(printf("hello\n")
		== ft_printf("hello\n"));
	return (0);
}
