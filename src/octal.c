/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octal.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nblackie <nblackie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 10:36:47 by i18316588         #+#    #+#             */
/*   Updated: 2020/08/30 00:20:37 by nblackie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int     print_octal(va_list args, t_format format)
{
    unsigned int 	val;
	int				count;
    char            sign;

    val = va_arg(args, unsigned int);
    sign = (format.flags.sharp && val != 0) ? '0' : '\0';
    if (val == 0 && format.precision == 0)
		return print_empty(format, sign);
    if (format.flags.minus || format.precision != EMPTY)
		format.flags.zero = false;
    count = 0;
    print_oсtal_val(val, &count, format, sign);
    if (format.flags.minus)
        count += nputchar(' ', format.width - count);
    return (count);
}

int     print_h_octal(va_list args, t_format format)
{
    unsigned short int	val;
	int					count;
    char				sign;

    val = (unsigned short int) va_arg(args, unsigned int);
    sign = (format.flags.sharp && val != 0) ? '0' : '\0';
    if (val == 0 && format.precision == 0)
		return 	print_empty(format, sign);
    if (format.flags.minus || format.precision != EMPTY)
		format.flags.zero = false;
    count = 0;
    print_oсtal_val(val, &count, format, sign);
    if (format.flags.minus)
        count += nputchar(' ', format.width - count);
    return (count);
}

int     print_hh_octal(va_list args, t_format format)
{
    unsigned long long	val;
	int					count;
    char				sign;

    val = (unsigned char) va_arg(args, int);
    sign = (format.flags.sharp && val != 0) ? '0' : '\0';
    if (val == 0 && format.precision == 0)
		return print_empty(format, sign);
    if (format.flags.minus || format.precision != EMPTY)
		format.flags.zero = false;
    count = 0;
    print_oсtal_val(val, &count, format, sign);
    if (format.flags.minus)
        count += nputchar(' ', format.width - count);
    return (count);
}

int     print_l_octal(va_list args, t_format format)
{
    unsigned long   	val;
	int					count;
    char				sign;

    val = (unsigned long) va_arg(args, unsigned long);
    sign = (format.flags.sharp && val != 0) ? '0' : '\0';
    if (val == 0 && format.precision == 0)
		return print_empty(format, sign);
    if (format.flags.minus || format.precision != EMPTY)
		format.flags.zero = false;
    count = 0;
    print_oсtal_val(val, &count, format, sign);
    if (format.flags.minus)
        count += nputchar(' ', format.width - count);
    return (count);
}

int     print_ll_octal(va_list args, t_format format)
{
    unsigned long int	val;
	int					count;
    char				sign;

    val = (unsigned long int) va_arg(args, unsigned long int);
    sign = (format.flags.sharp && val != 0) ? '0' : '\0';
    if (val == 0 && format.precision == 0)
		return print_empty(format, sign);
    if (format.flags.minus || format.precision != EMPTY)
		format.flags.zero = false;
    count = 0;
    print_oсtal_val(val, &count, format, sign);
    if (format.flags.minus)
        count += nputchar(' ', format.width - count);
    return (count);
}
