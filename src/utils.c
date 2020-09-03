/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nblackie <nblackie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 14:00:30 by i18316588         #+#    #+#             */
/*   Updated: 2020/08/30 00:19:47 by nblackie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	nputchar(char c, int num)
{
	int	result;

	result = num >= 0 ? num : 0;
	while (num > 0)
	{
		ft_putchar(c);
		--num;
	}
	return (result);
}

int	nputstr(char *str, int num)
{
	int		len;
	int		i;

	len = ft_strlen(str);
	if (len < num)
		num = len;
	i = 0;
	while (i < num)
	{
		ft_putchar(*str);
		str++;
		i++;
	}
	return (num);
}
