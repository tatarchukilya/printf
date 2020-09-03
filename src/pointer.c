/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocathern <ocathern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 20:33:28 by ocathern          #+#    #+#             */
/*   Updated: 2020/09/03 20:38:17 by ocathern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	print_pointer(va_list args, t_format format)
{
	int	count;

	ft_putstr("0x");
	count = 2 + switch_hex(args, format);
	return (count);
}