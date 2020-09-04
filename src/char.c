/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocathern <ocathern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 21:24:53 by nblackie          #+#    #+#             */
/*   Updated: 2020/09/04 14:07:35 by ocathern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	print_char(va_list args, t_format format)
{
	char	val;
	int		count;

	val = (char)va_arg(args, int);
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

int	print_string(va_list args, t_format format)
{
	char	*val;
	int		count;
	int		len;

	val = va_arg(args, char *);
	val = (val == NULL) ? "(null)" : val;
	len = ft_strlen(val);
	if (format.precision != EMPTY)
		len = format.precision > len ? len : format.precision;
	if (format.flags.minus)
		format.flags.zero = false;
	count = 0;
	if (format.flags.zero)
		count += nputchar('0', format.width - len);
	else if (!format.flags.minus)
		count += nputchar(' ', format.width - len);
	count += nputstr(val, len);
	if (format.flags.minus)
		count += nputchar(' ', format.width - len);
	return (count);
}
