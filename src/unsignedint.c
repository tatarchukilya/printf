/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsignedint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocathern <ocathern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 18:14:01 by nblackie          #+#    #+#             */
/*   Updated: 2020/09/04 14:26:22 by ocathern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	print_un_int(va_list args, t_format format)
{
	unsigned int	val;
	int				count;

	val = (unsigned int)va_arg(args, unsigned int);
	if (val == 0 && format.precision == 0)
		return (print_empty(format, '\0'));
	if (format.flags.minus || format.precision != EMPTY)
		format.flags.zero = false;
	count = 0;
	print_int_val(val, &count, format, '\0');
	if (format.flags.minus)
		count += nputchar(' ', format.width - count);
	return (count);
}

int	print_un_h_int(va_list args, t_format format)
{
	unsigned short int	val;
	int					count;

	val = (unsigned short int)va_arg(args, unsigned int);
	if (val == 0 && format.precision == 0)
		return (print_empty(format, '\0'));
	if (format.flags.minus || format.precision != EMPTY)
		format.flags.zero = false;
	count = 0;
	print_int_val(val, &count, format, '\0');
	if (format.flags.minus)
		count += nputchar(' ', format.width - count);
	return (count);
}

int	print_un_hh_int(va_list args, t_format format)
{
	unsigned short int	val;
	int					count;

	val = (unsigned char)va_arg(args, unsigned int);
	if (val == 0 && format.precision == 0)
		return (print_empty(format, '\0'));
	if (format.flags.minus || format.precision != EMPTY)
		format.flags.zero = false;
	count = 0;
	print_int_val(val, &count, format, '\0');
	if (format.flags.minus)
		count += nputchar(' ', format.width - count);
	return (count);
}

int	print_un_l_int(va_list args, t_format format)
{
	unsigned long int	val;
	int					count;

	val = (unsigned long int)va_arg(args, unsigned long int);
	if (val == 0 && format.precision == 0)
		return (print_empty(format, '\0'));
	if (format.flags.minus || format.precision != EMPTY)
		format.flags.zero = false;
	count = 0;
	print_int_val(val, &count, format, '\0');
	if (format.flags.minus)
		count += nputchar(' ', format.width - count);
	return (count);
}

int	print_un_ll_int(va_list args, t_format format)
{
	unsigned long int	val;
	int					count;

	val = (unsigned long int)va_arg(args, unsigned long int);
	if (val == 0 && format.precision == 0)
		return (print_empty(format, '\0'));
	if (format.flags.minus || format.precision != EMPTY)
		format.flags.zero = false;
	count = 0;
	print_int_val(val, &count, format, '\0');
	if (format.flags.minus)
		count += nputchar(' ', format.width - count);
	return (count);
}
