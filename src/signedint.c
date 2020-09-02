/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signedint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nblackie <nblackie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 18:11:43 by nblackie          #+#    #+#             */
/*   Updated: 2020/09/01 19:36:49 by nblackie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		print_int(va_list args, t_format format)
{
	int				val;
	int				count;
	char			sign;
	unsigned int	num;

	val = (int) va_arg(args, int);
	sign = get_sign_int(format, val);
	if (val == 0 && format.precision == 0)
		return print_empty(format, sign);
	if (format.flags.minus || format.precision != EMPTY)
		format.flags.zero = false;
	num = abs(val);
	count = 0;
	print_int_val(num, &count, format, sign);
	if (format.flags.minus)
		count += nputchar(' ', format.width - count);
	return (count);
}

int		print_h_int(va_list args, t_format format)
{
    short int 			val;
    int					count;
    char				sign;
    unsigned short int	num;

    val = (short int) va_arg(args, int);
    sign = get_sign_int(format, val);
    if (val == 0 && format.precision == 0)
        return print_empty(format, sign);
    if (format.flags.minus || format.precision != EMPTY)
        format.flags.zero = false;
    num = abs(val);
    count = 0;
    print_int_val(num, &count, format, sign);
    if (format.flags.minus)
        count += nputchar(' ', format.width - count);
    return count;
}

int		print_hh_int( va_list args, t_format format)
{
    char    			    val;
	int					    count;
	char				    sign;
	unsigned char   		num;
	
	val = (char) va_arg(args, int);
    
	sign = get_sign_int(format, val);
	if (val == 0 && format.precision == 0)
		return print_empty(format, sign);
	if (format.flags.minus || format.precision != EMPTY)
		format.flags.zero = false;
	num = abs(val);
	count = 0;
	print_int_val(num, &count, format, sign);
	if (format.flags.minus)
		count += nputchar(' ', format.width - count);
	return count;
}

int		print_l_int( va_list args, t_format format)
{
    long int	        val;
	int			        count;
	char		        sign;
	unsigned long int   num;
	
	val = va_arg(args, long int);
    
	sign = get_sign_int(format, val);
	if (val == 0 && format.precision == 0)
		return print_empty(format, sign);
	if (format.flags.minus || format.precision != EMPTY)
		format.flags.zero = false;
	num = labs(val);
	count = 0;
	print_int_val(num, &count, format, sign);
	if (format.flags.minus)
		count += nputchar(' ', format.width - count);
	return count;
}

int print_ll_int( va_list args, t_format format)
{
    long long int           val;
	int			          	count;
	char		           	sign;
	unsigned long long int  num;
	
	val = va_arg(args, int);
    
	sign = get_sign_int(format, val);
	if (val == 0 && format.precision == 0)
		return print_empty(format, sign);
	if (format.flags.minus || format.precision != EMPTY)
		format.flags.zero = false;
	num = labs(val);
	count = 0;
	print_int_val(num, &count, format, sign);
	if (format.flags.minus)
		count += nputchar(' ', format.width - count);
	return count;
}