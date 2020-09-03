/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfunc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocathern <ocathern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 14:03:05 by ocathern          #+#    #+#             */
/*   Updated: 2020/09/03 14:14:13 by ocathern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

size_t		ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

void		ft_putnbr(int n)
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

int			ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t		i;

	if (n == 0)
		return (0);
	i = 0;
	while (*s1 == *s2)
	{
		if (i == n - 1 || *s1 == '\0')
			return (0);
		i++;
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

void		ft_putstr(char const *s)
{
	if (s)
	{
		while (*s)
		{
			ft_putchar(*s);
			s++;
		}
	}
}
