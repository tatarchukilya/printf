/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: i18316588 <i18316588@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 08:22:00 by i18316588         #+#    #+#             */
/*   Updated: 2020/08/05 18:34:53 by i18316588        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

/**
 * Принмает указатель на местоо в строке
 * Считает кол-во символов до знака % (начинается описание типа) или до '\0'
 * Выводит на консоль полученное кол-во символов
*/
size_t	print_str(char **str)
{
	char	*temp;
	size_t	len;
	
	len = 0;
	temp = *str;
	while (**str != '%')
	{
		if (**str == '\0')
			break ;
		(*str)++;
		len++;
	}
	write(1, temp, len);
	return (len);
}

/** 
 * Заполняет структуру t_format данными из стороки *str (fmt). Затем вызывает 
 * функцию для форматированного вывода значения из va_list на консоль согласно 
 * формату t_format. t_format.type - это элемент множества, т.е. int - 
 * индекс по которому дергается функция из массива g_fn (printf.h)
*/
size_t handele_format_print_value(char **str, va_list args)
{
	t_format	format;
	char 	*temp;
	
	(*str)++;
	if (**str == '%')
	{
		ft_putchar('%');
		(*str)++;
		return (1);
	}
	format = handle_format(str);
	//log_format(&format);
	size_t i = (g_fn[format.type](args, format));
	return (0);
}

/**
 * Непосредственно основная функция. Запускает цикл, который прерывается на символе 
 * конца строки. Чередует две функции выше: печатает строку до знака "%", затем 
 * выводит на печать отформатированное значение из аргументов. Результат работы каждой функции 
 * добавляет к счетчику. После засершения цикла выводит на консоль остаток строки, 
 * завершает va_list и возвращает количество напечатанных символов (count).
*/
int		ft_printf(char *fmt, ...)
{
	va_list	args;
	size_t	count;
	
	count = 0;
	va_start(args, fmt);
	while (1)
	{
		count += print_str(&fmt);
		if (*fmt == '\0')
			break ;
		count += handele_format_print_value(&fmt, args);
		if (*fmt == '\0')
			break ;
	}
	va_end(args);
	ft_putstr(fmt);
	return (count);
}

int		main(void)
{
	//ft_printf("first %-+21.07hc second %% fird % s", '0', "1");
	//printf("\nfirst%-+5.10d", 5);
	int c = -2147483648;
	//int i = pr2(-2147483648, 0);
	int i = ft_printf("ft_printf:%.d", 0);
	int l = printf("\n   printf:%.d", 0);
	printf(" lenght: %d", l - 11);
}