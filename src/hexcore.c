/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexcore.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nblackie <nblackie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 18:52:00 by nblackie          #+#    #+#             */
/*   Updated: 2020/08/30 00:20:16 by nblackie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

const static print_abstract g_hex[6] = 
{
	&print_ll_hex,
	&print_hh_hex,
	&print_l_hex,
	&print_h_hex,
	&print_hex,
	&print_hex
};

int	print_empty_hex(t_format format, char *sign)
{
	int	count;
	
	if (format.flags.minus)
	{
		ft_putstr(sign);
		count += ft_strlen(sign);
		count += nputchar(' ', format.width - ft_strlen(sign));
	} else
	{
		count = nputchar(' ', format.width - ft_strlen(sign));
		ft_putstr(sign);
		count += ft_strlen(sign);
	}
	return (count);
}

void	print_zero_flag_hex(int *count, t_format format, char *sign)
{
	ft_putstr(sign);
	*count += ft_strlen(sign);
	*count += nputchar('0', format.width - *count);
	*count += nputchar('0', format.precision - *count);
}

void	print_hex_val(unsigned long long val, int *count, t_format f, char *c)
{
    int		prec;
	
	++(*count);
	if (val > 15)
		print_hex_val(val/16, count, f, c);
	else 
	{
		if (f.flags.zero)
            print_zero_flag_hex(count, f, c);
		else
		{	
			prec = ((f.precision - *count) < 0) ? 0
				: f.precision - *count;
			if (!f.flags.minus)
				*count += nputchar(' ', f.width - prec - *count - ft_strlen(c));
			ft_putstr(c);
			*count += ft_strlen(c);
			*count += nputchar('0', prec);
		}
	}
	nputchar(f.type == x ? g_low_hex[val % 16] : g_up_hex[val % 16], 1);
}

int		switch_hex(va_list args, t_format format)
{
	t_size			size;
	print_abstract	fn;

	size = ll;
	
	while (size <= EMPTY_SIZE)
	{
		if (size == format.size)
			break;
		size++;
	}
	fn = g_hex[size];
	return (fn(args, format)); 
}