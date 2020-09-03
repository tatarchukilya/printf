/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nblackie <nblackie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 15:50:02 by i18316588         #+#    #+#             */
/*   Updated: 2020/08/30 00:20:12 by nblackie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		print_hex(va_list args, t_format format)
{
	unsigned int	val;
	int				count;
	char			*sign;

	val = (unsigned int)va_arg(args, int);
	sign = (format.flags.sharp && val != 0) ? get_prefix(format) : "";
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

int		print_l_hex(va_list args, t_format format)
{
	unsigned long	val;
	int				count;
	char			*sign;

	val = (unsigned long)va_arg(args, long int);
	sign = (format.flags.sharp && val != 0) ? get_prefix(format) : "";
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

int		print_ll_hex(va_list args, t_format format)
{
	unsigned long long	val;
	int					count;
	char				*sign;

	val = (unsigned long long)va_arg(args, long long int);
	sign = (format.flags.sharp && val != 0) ? get_prefix(format) : "";
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

int		print_h_hex(va_list args, t_format format)
{
	unsigned short int	val;
	int					count;
	char				*sign;

	val = (unsigned short int)va_arg(args, unsigned int);
	sign = (format.flags.sharp && val != 0) ? get_prefix(format) : "";
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

int		print_hh_hex(va_list args, t_format format)
{
	unsigned char		val;
	int					count;
	char				*sign;

	val = (unsigned char)va_arg(args, int);
	sign = (format.flags.sharp && val != 0) ? get_prefix(format) : "";
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
