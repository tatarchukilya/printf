/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocathern <ocathern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 11:42:35 by i18316588         #+#    #+#             */
/*   Updated: 2020/09/04 14:29:39 by ocathern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

const static print_abstract g_un_int[6] =
{
	&print_un_ll_int,
	&print_un_hh_int,
	&print_un_l_int,
	&print_un_h_int,
	&print_un_int,
	&print_un_int
};

const static print_abstract g_int[6] =
{
	&print_ll_int,
	&print_hh_int,
	&print_l_int,
	&print_h_int,
	&print_int,
	&print_int
};

char	get_sign_int(t_format format, long long num)
{
	if (num < 0)
		return ('-');
	if (format.flags.plus)
		return ('+');
	if (format.flags.space)
		return (' ');
	return ('\0');
}

void	print_int_val(unsigned long long val, int *count, t_format f, char c)
{
	int	prec;

	// printf("VAL: %llu\n", val);
	++(*count);
	if (val > 9)
		print_int_val(val / 10, count, f, c);
	else
	{
		if (f.flags.zero)
			print_zero_flag(count, f, c);
		else
		{
			prec = (f.precision - *count) < 0 ? 0 : f.precision - *count;
			if (!f.flags.minus)
				*count += nputchar(' ', f.width - prec - *count - (c != '\0'));
			*count += nputchar(c, c != '\0');
			*count += nputchar('0', prec);
		}
	}
	nputchar(val % 10 + '0', 1);
}

int		switch_int(va_list args, t_format format)
{
	t_size			size;
	print_abstract	fn;

	size = ll;
	while (size <= EMPTY_SIZE)
	{
		if (size == format.size)
			break ;
		size++;
	}
	// printf("FORMAT TYPE: %u\n FORMAT SIZE: %u\n", format.type, format.size);
	fn = format.type == u ? g_un_int[size] : g_int[size];
	return (fn(args, format));
}
