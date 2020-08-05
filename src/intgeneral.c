/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intgeneral.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: i18316588 <i18316588@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 09:04:47 by i18316588         #+#    #+#             */
/*   Updated: 2020/08/05 18:29:47 by i18316588        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

// Функция выводит значение, точность и знак. Если флаг минус не указан, 
// то выводится еще и ширина, если уазан, то ширина добивается пробелами
// после вывода значения в функции print_int файла int.c
// Функция рекурсивная, каждый вызов означает, что будет напечатан еще один 
// символ, поэтому счетчик сразу инкрементируется
int print_un_int_w(unsigned int val, int *count, t_format f, char sign) {
    int prec;
	
	++(*count);
	if (val > 10)
		print_un_int_w(val / 10, count, f, sign);
	else
    {
		if (f.flags.zero)
		{
			*count += nputchar(sign, sign != '\0');
			*count += nputchar('0', f.width - *count);
		}
		
        prec = f.precision - *count; // Сколько нулей добить в точность
		if (!f.flags.minus)
			*count += nputchar(' ', f.width - *count - prec - (sign != '\0'));
		*count += nputchar(sign, sign != '\0');
		*count += nputchar('0', prec);
    }
	nputchar(val % 10 + '0', 1);
	return (*count);
}
