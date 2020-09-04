/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocathern <ocathern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 18:49:55 by nblackie          #+#    #+#             */
/*   Updated: 2020/09/04 18:42:12 by ocathern         ###   ########.fr       */
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

void	print_fzero_flag(int *count, t_format format, char sign) {
	*count += nputchar(sign, sign != '\0');
	*count += nputchar('0', format.width - *count - format.precision - 
														(format.precision > 0));
	//*count += nputchar('0', format.precision - *count);
}

void	print_lng(unsigned long long num)
{
	// printf("\nnum: %llu\n", num);
	if (num > 10)
		print_lng(num / 10);
	ft_putchar(num % 10 + '0');
}

unsigned long long powerten(int power)
{
	unsigned long long result;
    
    result = 1;
	while (power > 0)
	{
        result *= 10; 
		power--;
	}
	return (result);
}

long double	roundff(long double val, int prec)
{
	unsigned long long	coef;
	// long double temp;
	
	coef = powerten(prec);
	val *= coef;
	if ((val - (int) val) >= 0.5)
		val++;
	val /= coef;
	return (val);
}

void print_fract(long double val, t_format format, int *count)
{
	long long whole;

	val = roundff(val, 20);
	val = roundff(val, format.precision);
	ft_putchar('.');
	whole = val;
	val -= whole;
	val *= powerten(format.precision);
	whole = val;
	print_lng(whole);
	*count += format.precision + 1;
}

void    print_whole(long double val, t_format format, int *count, char c)
{
    long long	num;
    
    ++(*count);
    num = (long long) val;
    if (val > 10)
        print_whole(val / 10, format, count, c);
    else 
	{
		if (format.flags.zero)
			print_fzero_flag(count, format, c);
		else
		{
			if (!format.flags.minus)
				*count += nputchar(' ', format.width - format.precision - 
								*count - (c != '\0') - (format.precision > 0));
			*count += nputchar(c, c != '\0');
		}
	}
    ft_putchar(num % 10 + '0');
}

int		print_float(va_list args, t_format format)
{
    long double				val;
	// int 					num;
    int						count;
	char					sign;

	count = 0;
	val = format.size == L	? va_arg(args, long double) 
							: va_arg(args, double);
	sign = get_sign_double(format, val);
	val = fabsl(val);
	// printf()
	val = roundff(val, format.precision);
    format.precision = format.precision != EMPTY ? format.precision : 6;
	if (val == 0 && format.precision == 0)
		return print_empty(format, sign);
	if (format.flags.minus || format.precision != EMPTY)
		format.flags.zero = false;		
    print_whole(val, format, &count, sign);
	if (format.precision > 0)
		print_fract(val, format, &count);
	if (format.flags.minus)
		count += nputchar(' ', format.width - count);
    return(count);
}
