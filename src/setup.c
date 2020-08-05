/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: i18316588 <i18316588@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 08:48:44 by i18316588         #+#    #+#             */
/*   Updated: 2020/07/04 14:41:03 by i18316588        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void setup_flags(t_flags *flags)
{
    flags->minus = false;
	flags->plus = false;
	flags->sharp = false;
	flags->space = false;
	flags->zero = false;
}

void setup_format(t_format *format)
{
    setup_flags(&(format->flags));
    format->width = EMPTY;
    format->precision = EMPTY;
    format->size = EMPTY_SIZE;
    format->type = EMPTY_TYPE;
}