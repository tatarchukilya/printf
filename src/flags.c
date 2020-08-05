/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: i18316588 <i18316588@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 20:13:02 by nblackie          #+#    #+#             */
/*   Updated: 2020/07/28 12:02:52 by i18316588        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	set_flag(char flag, t_flags *flags)
{
	if (flag == ' ')
		flags->space = true;
	if (flag == '-')
		flags->minus = true;
	if (flag == '+')
		flags->plus = true;
	if (flag == '0')
		flags->zero = true;
	if (flag == '#')
		flags->sharp = true;
}
