/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nblackie <nblackie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 17:19:54 by i18316588         #+#    #+#             */
/*   Updated: 2020/08/30 00:20:08 by nblackie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		handle_flag(char **str, t_format *fomat)
{
	set_flag(**str, &(fomat->flags));
	(*str)++;
}

void		handle_width(char **str, t_format *format)
{
	int	width;

	width = 0;
	while (ft_isdigit(**str))
	{
		width = width * 10 + (**str - '0');
		(*str)++;
	}
	format->width = width;
}

void		handle_precision(char **str, t_format *format)
{
	int	precision;

	precision = 0;
	(*str)++;
	while (ft_isdigit(**str))
	{
		precision = precision * 10 + (**str - '0');
		(*str)++;
	}
	format->precision = precision;
}

void		handle_size(char **str, t_format *format)
{
	t_size		size;
	int			len;

	size = ll;
	while (size != EMPTY_SIZE)
	{
		len = ft_strlen(g_sizes[size]);
		if (!ft_strncmp(*str, g_sizes[size], len))
		{
			format->size = size;
			(*str) = (*str) + len;
			return ;
		}
		size++;
	}
}

t_type		char_to_type(char c)
{
	int i;

	i = 0;
	while (i < NUMBER_OF_TYPES)
	{
		if (g_types[i] == c)
			return (i);
		i++;
	}
	return (EMPTY_TYPE);
}

t_format	handle_format(char **str)
{
	t_format	format;

	setup_format(&format);
	while (true)
	{
		if (is_flag(**str))
			handle_flag(str, &format);
		else if (ft_isdigit(**str))
			handle_width(str, &format);
		else if (**str == '.')
			handle_precision(str, &format);
		else if (is_size(**str))
			handle_size(str, &format);
		else
		{
			format.type = char_to_type(**str);
			if (format.type != EMPTY_TYPE)
				(*str)++;
			break ;
		}
	}
	return (format);
}
