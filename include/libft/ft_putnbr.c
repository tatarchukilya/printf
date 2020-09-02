/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nblackie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 19:24:43 by nblackie          #+#    #+#             */
/*   Updated: 2019/09/07 15:15:32 by nblackie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	unsigned int num;

	if (n > 2147483647 || n < -2147483648)
		return ;
	if (n < 0)
	{
		ft_putchar('-');
		num = -n;
	}
	else
		num = n;
	if (num > 9)
		ft_putnbr(num / 10);
	ft_putchar(num % 10 + '0');
}
