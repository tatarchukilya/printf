/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: i18316588 <i18316588@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 18:49:55 by nblackie          #+#    #+#             */
/*   Updated: 2020/09/02 18:32:09 by i18316588        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char get_sign_double(t_format format, long double num)
{
	if (num < 0)
		return ('-');
	if (format.flags.plus)
		return ('+');
	if (format.flags.space)
		return (' ');
	return ('\0');
}

int powerten(int power)
{
	int result;
    
    result = 1;
	while (power > 0)
	{
		if (result == 1)
            result = 10;
        else
            result *= 10;   
		power--;
	}
	return (result);
}

double	roundff(double val, int prec)
{
	int	coef;

	coef = powerten(prec);
	val *= coef;
	if ((val - (int) val) >= 0.5)
		val++;
	val /= coef;
	return (val);
}

void print_frac(long double frac, int prec)
{
	int temp;

	frac *= powerten(prec);
	temp = (frac);
	ft_putnbr(temp);
}

void    print_whole(float val, t_format format, int *count, char c)
{
    int		num;
    
    ++(*count);
    num = (int) val;
    if (val > 10)
        print_whole(val / 10, format, count, c);
    else 
	{
		if (format.flags.zero)
			print_zero_flag(count, format, c);
		else
		{
			if (!format.flags.minus)
				*count += nputchar(' ', format.width - format.precision - *count - (c != '\0'));
			*count += nputchar(c, c != '\0');	
		}
	}
    nputchar(' ', format.width - *count -format.precision);
    ft_putchar(num % 10 + '0');
}

int     print_float(va_list args, t_format format)
{
    long double				val;
	int 					num;
    int						count;
	char					sign;

	count = 0;
    val = va_arg(args, double);
	sign = get_sign_double(format, val);
	val = fabsl(val);
    format.precision = format.precision != EMPTY ? format.precision : 6;
	if (val == 0 && format.precision == 0)
		return print_empty(format, sign);
    print_whole(val, format, &count, sign);
	if (format.precision > 0)
	{
		val = roundff(val, format.precision);
		ft_putchar('.');
		num = (int) val;
		val -= num;
		print_frac(val, format.precision);
		count += format.precision + 1;
	}
    return(count);
}
