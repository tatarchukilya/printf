/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   istrue.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nblackie <nblackie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 21:02:21 by nblackie          #+#    #+#             */
/*   Updated: 2020/08/30 00:20:30 by nblackie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int 	is_flag(char c)
{
	return (c == '-' || c == '+' || c == '0' || c == '#' || c == ' ');
}

int 	is_type(char c)
{
	int i;

	i = 0;
	while (g_types[i] != '\0')
	{
	if (g_types[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int		is_size(char c)
{
	return (c == 'l' || c == 'h' || c == 'L');
}

int		is_flag_empty(t_flags flags) 
{
	return (flags.minus == 0 && flags.minus == 0 && flags.sharp == 0 && 
			flags.space == 0 && flags.zero == 0);
}

int		is_int_empty(unsigned long long val, t_format format)
{
	return (!val && !format.precision);
}