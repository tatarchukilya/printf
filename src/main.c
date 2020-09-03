/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: i18316588 <i18316588@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 08:22:00 by i18316588         #+#    #+#             */
/*   Updated: 2020/09/02 19:30:38 by i18316588        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

size_t	print_str(char **str)
{
	char	*temp;
	size_t	len;

	len = 0;
	temp = *str;
	while (**str != '%')
	{
		if (**str == '\0')
			break ;
		(*str)++;
		len++;
	}
	write(1, temp, len);
	return (len);
}

size_t	handele_format_print_value(char **str, va_list args)
{
	t_format	format;

	(*str)++;
	if (**str == '%')
	{
		ft_putchar('%');
		(*str)++;
		return (1);
	}
	format = handle_format(str);
	return (g_fn[format.type](args, format));
}

int		ft_printf(char *fmt, ...)
{
	va_list	args;
	size_t	count;

	count = 0;
	va_start(args, fmt);
	while (true)
	{
		count += print_str(&fmt);
		if (*fmt == '\0')
			break ;
		count += handele_format_print_value(&fmt, args);
		if (*fmt == '\0')
			break ;
	}
	va_end(args);
	ft_putstr(fmt);
	return (count);
}
