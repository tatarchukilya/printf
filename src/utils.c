/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocathern <ocathern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 14:00:30 by i18316588         #+#    #+#             */
/*   Updated: 2020/09/04 14:32:45 by ocathern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		nputchar(char c, int num)
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

int		nputstr(char *str, int num)
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

int		ft_isdigit(int ch)
{
	return (ch >= '0' && ch <= '9');
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
