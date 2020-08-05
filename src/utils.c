/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: i18316588 <i18316588@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 14:00:30 by i18316588         #+#    #+#             */
/*   Updated: 2020/07/28 07:45:37 by i18316588        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

// Выводит символ заданное кол-во раз и возвращает это кол-во
// Метод позволяет экономить строки ввиду ананизма с ограничением в 25 штук
int nputchar(char c, int num)
{
    int result;
    
    result = num >= 0 ? num : 0;
    while (num > 0)
    {
        ft_putchar(c);
        --num;
    }
    return (result);
}