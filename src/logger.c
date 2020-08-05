/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logger.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: i18316588 <i18316588@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 14:27:29 by i18316588         #+#    #+#             */
/*   Updated: 2020/07/25 09:45:19 by i18316588        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void print_str_num(char *str, int num, t_bool is_line_break)
{
    ft_putstr(str);
    ft_putnbr(num);
    if (is_line_break)
        ft_putchar('\n');
    else
        ft_putchar(' ');
}

void log_flags(t_flags flag)
{
    ft_putstr("flags: ");
    print_str_num("nimus: ", flag.minus, false);
    print_str_num("plus: ", flag.plus, false);
    print_str_num("zero: ", flag.zero, false);
    print_str_num("sharp: ", flag.sharp, false);
    print_str_num("space: ", flag.space, true);
}

void log_flags_compat(t_flags flags)
{
    if (flags.minus)
        ft_putchar('-');
    if (flags.plus)
        ft_putchar('+');
    if (flags.space)
        ft_putchar('_');
    if (flags.zero)
        ft_putchar('0');
    if (flags.sharp)
        ft_putchar('#');
}

void log_format(t_format *format)
{
    log_flags(format->flags);
    print_str_num("width: ", format->width, true);
    print_str_num("precision: ", format->precision, true);
    ft_putstr("size: ");
    ft_putstr((g_sizes[format->size]));
    ft_putchar('\n');
    ft_putstr("type: ");
    ft_putchar(g_types[format->type]);
    ft_putchar('\n');
}

void log_format_compat(t_format *format)
{
    ft_putchar('{');
    log_flags_compat(format->flags);
    ft_putchar('*');
    ft_putnbr(format->width);
    ft_putchar('*');
    ft_putnbr(format->precision);
    ft_putchar('*');
    ft_putstr((g_sizes[format->size]));
    ft_putchar('*');
    ft_putchar(g_types[format->type]);
    ft_putchar('}');
}

int print_stub(va_list args, t_format format)
{
    log_format_compat(&format);
    return args != NULL;
}