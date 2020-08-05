/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: i18316588 <i18316588@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 11:42:35 by i18316588         #+#    #+#             */
/*   Updated: 2020/08/05 18:34:18 by i18316588        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "printf.h"

// Удалить?
char get_sign(t_format format, int num)
{
	if (num < 0)
		return ('-');
	if (format.flags.plus)
		return ('+');
	if (format.flags.space)
		return (' ');
	return ('\0');
}



int	print_int(va_list args, t_format format)
{
	int val;
	int count;
	char sign;
	
	val = va_arg(args, int);
	sign = get_sign(format, val);
	if (val == 0 && format.precision == 0)
	{
		count += nputchar(sign, sign != '\0');
		count += nputchar(' ', format.width - sign != '\0');
		return (count);
	}
	if (format.flags.minus || format.precision != EMPTY)
		format.flags.zero = false;
	unsigned int num = val < 0 ? abs(val) : val;
	count = 0;
	print_un_int_w(num, &count, format, get_sign(format, val));
	if (format.flags.minus)
		count += nputchar(' ', format.width - count);
	printf(" lenght: %d", count);
	return count;
}
