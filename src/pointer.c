/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocathern <ocathern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 20:33:28 by ocathern          #+#    #+#             */
/*   Updated: 2020/09/04 14:02:38 by ocathern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	print_pointer(va_list args, t_format format)
{
	unsigned long long	val;
	int					count;
	char				*sign;

	val = (unsigned long long)va_arg(args, long long int);
	sign = "0x";
	if (val == 0 && format.precision == 0)
		return (print_empty_hex(format, sign));
	if (format.flags.minus || format.precision != EMPTY)
		format.flags.zero = false;
	count = 0;
	print_hex_val(val, &count, format, sign);
	if (format.flags.minus)
		count += nputchar(' ', format.width - count);
	return (count);
}