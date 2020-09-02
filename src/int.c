/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: i18316588 <i18316588@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 11:42:35 by i18316588         #+#    #+#             */
/*   Updated: 2020/09/02 18:28:28 by i18316588        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

const static print_abstract g_un_int[6] = 
{
	&print_un_ll_int,
	&print_un_hh_int,
	&print_un_l_int,
	&print_un_h_int,
	&print_un_int, //Флаг L Реализовать общий метод для случая, если тип не указан
	&print_un_int
};

const static print_abstract g_int[6] =
{
	&print_ll_int,
	&print_hh_int,
	&print_l_int,
	&print_h_int,
	&print_int,		// Реализовать общий метод для случая, если тип не указан
	&print_int
};

// Возвращает знак '-', '+' или ' ' для типа int
char get_sign_int(t_format format, long long num)
{
	if (num < 0)
		return ('-');
	if (format.flags.plus)
		return ('+');
	if (format.flags.space)
		return (' ');
	return ('\0');
}

// Функция выводит значение, точность и знак. Если флаг минус не указан,
// то выводится еще и ширина, если указан, то ширина добивается пробелами
// после вывода значения в функции print_int файла int.c
// Функция рекурсивная, каждый вызов означает, что будет напечатан еще один
// символ, поэтому счетчик инкрементируется на входе
void	print_int_val(unsigned long long val, int *count, t_format f, char c)
{
	int prec;

	++(*count);
	if (val > 10)
		print_int_val(val / 10, count, f, c);
	else
	{
		if (f.flags.zero)
			print_zero_flag(count, f, c);
		else
		{
			prec = (f.precision - *count) < 0 ? 0 : f.precision - *count;
			if (!f.flags.minus)
				*count += nputchar(' ', f.width - prec - *count - (c != '\0'));
			*count += nputchar(c, c != '\0');
			*count += nputchar('0', prec);
		}
	}
	nputchar(val % 10 + '0', 1);
}

int		switch_int(va_list args, t_format format)
{
	t_size			size;
	print_abstract	fn;

	size = ll;
	
	while (size <= EMPTY_SIZE)
	{
		if (size == format.size)
			break;
		size++;
	}
	fn = format.type == u ? g_un_int[size] : g_int[size];
	return (fn(args, format)); 
}
