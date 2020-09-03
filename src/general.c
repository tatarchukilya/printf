/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: i18316588 <i18316588@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 15:35:03 by i18316588         #+#    #+#             */
/*   Updated: 2020/09/02 18:37:31 by i18316588        ###   ########.fr       */
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
	return (format.type == x ? "0x" : "0X");
}
