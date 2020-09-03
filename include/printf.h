/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocathern <ocathern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 15:56:16 by i18316588         #+#    #+#             */
/*   Updated: 2020/09/03 14:14:30 by ocathern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
#define PRINTF_H

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdarg.h>
#include "./libft/libft.h"

# define PI 3.141592653589793238462643383279
# define EMPTY -1
# define NUMBER_OF_TYPES 13
# define ABS 

const static char *g_low_hex = "0123456789abcdef";

const static char *g_up_hex = "0123456789ABCDEF";

typedef enum s_bool
{
	false,
	true
}           t_bool;

const static char *g_sizes[] = {"ll", "hh", "l", "h", "L"};

typedef enum s_size
{
	ll, hh, l, h, L, EMPTY_SIZE
}           t_size;

const static char g_flags[] = {'-', '+', '0', '#', ' ', '\0'};

/// Флаги. Если 1 - установлен, 0 - нет
typedef struct  s_flags
{
	t_bool minus;
	t_bool plus;
	t_bool zero;
	t_bool sharp;
	t_bool space;
}               t_flags;

// Вожможные варианты обозначений типа
const static char g_types[] = {'c', 'C', 'd', 'i', 'o', 'u', 'x', 'X',
'f', 'F', 'p', 's', 'S', '\0'};

// Множество вариантов типов, по сути тип - это индекс, по которому дергается 
// функция из массива g_fn
typedef enum s_type
{
	c,
	C,
	d,
	i,
	o,
	u,
	x,
	X,
	f,
	F,
	p,
	s,
	S,
	EMPTY_TYPE
}           t_type;

// Все данные о том, в каком формате выводить данные
typedef struct      s_format
{
	t_flags			flags;
	int				width;
	int             precision;
	t_size          size;
	t_type          type;
}                   t_format;

// Прототип всех функций выода
typedef int (* print_abstract)(va_list, t_format);

// Перечень функций вывода по типам данных (упакованы в g_fn)
// Под капотом у каждой должен быть выбор функции типа print_abstract
// С поправкой на параметр size

void		print_str_num(char *str, int num, t_bool is_line_break);

int			print_empty(t_format format, char sign);

int			switch_int(va_list args, t_format format);

int			switch_octal(va_list args, t_format format);

int			switch_hex(va_list args, t_format format);

int         print_stub(va_list args, t_format format);

void		print_hex_val(unsigned long long val, int *cn, t_format f, char *c);

void		print_int_val(unsigned long long val, int *cn, t_format f, char c);

void    	print_oсtal_val(unsigned long long val, int *count, t_format f, char c);

char		get_sign_int(t_format format, long long num);

char		*get_prefix(t_format format);

int			print_char(va_list args, t_format format);

int			print_string(va_list args, t_format format);

int     	print_float(va_list args, t_format format);

// Массив функций печати для каждого типа
const static print_abstract g_fn[NUMBER_OF_TYPES] = {
	&print_char,			//c
	&print_char, 			//C
	&switch_int,			//d
	&switch_int, 			//i
	&switch_octal,			//o
	&switch_int, 			//u
	&switch_hex,			//x
	&switch_hex,			//X
	&print_float,			//f
	&print_stub,			//F
	&print_stub,			//p
	&print_string, 			//s
	&print_string,			//S
};

// Фекции вывода значения пипа INT с поправкой на параметр size
// Упакованы в g_int
int			print_h_int(va_list args, t_format format);

int			print_hh_int(va_list args, t_format format);

int			print_l_int(va_list args, t_format format);

int			print_ll_int(va_list args, t_format format);

int			print_int( va_list args, t_format format);

// Фекции вывода значения пипа UNSIGNED INT с поправкой на параметр size
// Упакованы в g_un_int
int			print_un_ll_int(va_list args, t_format format);

int			print_un_l_int(va_list args, t_format format);

int			print_un_h_int(va_list args, t_format format);

int			print_un_hh_int(va_list args, t_format format);

int			print_un_int( va_list args, t_format format);

// Функции для вывода значений octal с поправкой на параметр size
// Упакованы в g_octal

int     	print_h_octal(va_list args, t_format format);

int			print_hh_octal(va_list args, t_format format);

int			print_l_octal(va_list args, t_format format);

int			print_ll_octal(va_list args, t_format format);

int 		print_octal(va_list args, t_format format);

int     	print_h_hex(va_list args, t_format format);

int			print_hh_hex(va_list args, t_format format);

int			print_l_hex(va_list args, t_format format);

int			print_ll_hex(va_list args, t_format format);

int 		print_hex(va_list args, t_format format);

void		print_zero_flag(int *count, t_format format, char sign);

void        log_flags(t_flags flag);

void        log_format(t_format *format);

void        set_flag(char flag, t_flags *flags);

void        setup_format(t_format *format);

int         is_flag(char c);

int         is_size(char c);

int			nputchar(char c, int num);

int			nputstr(char *str, int num);

t_format    handle_format(char **str);

int			print_num(int val, int prec);

int			is_int_empty(unsigned long long val, t_format format);

int			print_empty_hex(t_format format, char *sign);

void		print_zero_flag_hex(int *count, t_format format, char *sign);

int			ft_isdigit(int ch);

size_t		ft_strlen(const char *s);

void		ft_putnbr(int n);

void		ft_putchar(char c);

int			ft_strncmp(const char *s1, const char *s2, size_t n);

void		ft_putstr(char const *s);

#endif