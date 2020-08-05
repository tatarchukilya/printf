/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: i18316588 <i18316588@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 17:19:54 by i18316588         #+#    #+#             */
/*   Updated: 2020/07/25 06:16:33 by i18316588        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void    handle_flag(char **str, t_format *fomat)
{
    set_flag(**str, &(fomat->flags));
    (*str)++;
}

void	handle_width(char **str, t_format *format)
{
	int width;

	width = 0;
	while (ft_isdigit(**str))
	{
		width = width * 10 + (**str - '0');
		(*str)++;
	}
	format->width = width;
}

void	handle_precision(char **str, t_format *format)
{
	int precision;

	precision = 0;
	(*str)++; // Не понятно зачем это сдесь
    /*if (**str == '0')
	{
		type->precision = 0;
		return ;
	}*/
	while (ft_isdigit(**str))
	{	
		/*if (**str == '0' && precision == 0)
		{
			type->precision = 0;
			return ;
		} */
		precision = precision * 10 + (**str - '0');
		(*str)++;
	}
	format->precision = precision;
}

void	handle_size(char **str, t_format *format)
{
	t_size		size;
	int			len;

	size = ll;  // index = 0
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

t_type    char_to_type(char c)
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

t_format    handle_format(char **str)
{
    t_format format;
    
    setup_format(&format);
    while (true)
    {
        if (is_flag(**str))
            handle_flag(str, &format);
        else if (ft_isdigit(**str))
            handle_width(str, &format);
        else if(**str == '.')
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