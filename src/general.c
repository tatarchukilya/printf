/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocathern <ocathern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 15:35:03 by i18316588         #+#    #+#             */
/*   Updated: 2020/09/04 15:25:13 by ocathern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	print_zero_flag(int *count, t_format format, char sign)
{
	*count += nputchar(sign, sign != '\0');
	*count += nputchar('0', format.width - *count);
	*count += nputchar('0', format.precision - *count);
}

int		print_empty(t_format format, char sign)
{
	int	count;

	if (format.flags.minus)
	{
		count = nputchar(sign, sign != '\0');
		count += nputchar(' ', format.width - (sign != '\0'));
	}
	else
	{
		count = nputchar(' ', format.width - (sign != '\0'));
		count += nputchar(sign, sign != '\0');
	}
	return (count);
}

char	*get_prefix(t_format format)
{
	return (format.type == X ? "0X" : "0x");
}

int		print_parcent(va_list args, t_format format)
{
	char	val;
	int		count;

	(void) args;
	val = '%';
	if (format.flags.minus)
		format.flags.zero = false;
	count = 0;
	if (format.flags.zero)
		count += nputchar('0', format.width - 1);
	else if (!format.flags.minus)
		count += nputchar(' ', format.width - 1);
	count += nputchar(val, 1);
	if (format.flags.minus)
		count += nputchar(' ', format.width - 1);
	return (count);
}

int		print_empty_type(va_list args, t_format format)
{
	(void) args;
	return print_empty(format, '\0');
}