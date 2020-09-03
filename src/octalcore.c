/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octalcore.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nblackie <nblackie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 18:04:10 by i18316588         #+#    #+#             */
/*   Updated: 2020/08/30 00:20:40 by nblackie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

const static print_abstract g_octal[6] = 
{
	&print_ll_octal,
	&print_hh_octal,
	&print_l_octal,
	&print_h_octal,
	&print_octal,
	&print_octal
};

int		switch_octal(va_list args, t_format format)
{
	t_size size;

	size = ll;
	while (size <= EMPTY_SIZE)
	{
		if (size == format.size)
			return (g_octal[size](args, format));
		size++;
	}
	return (g_octal[size](args, format));
}

void	print_oсtal_val(unsigned long long val, int *count, t_format f, char c)
{
	int	prec;

	++(*count);
	if (val > 7)
		print_oсtal_val(val / 8, count, f, c);
	else
	{
		if (f.flags.zero)
			print_zero_flag(count, f, c);
		else
		{
			prec = ((f.precision - *count) < 0) ? 0
			: f.precision - *count - (c != '\0');
			if (!f.flags.minus)
				*count += nputchar(' ', f.width - prec - *count - (c != '\0'));
			*count += nputchar(c, c != '\0');
			*count += nputchar('0', prec);
		}
	}
	nputchar(val % 8 + '0', 1);
}
