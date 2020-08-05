/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: i18316588 <i18316588@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 15:56:16 by i18316588         #+#    #+#             */
/*   Updated: 2020/08/05 18:18:35 by i18316588        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_H
#define READ_H

#include <stdarg.h>
#include "../includes/libft/libft.h"

# define PI 3.141592653589793238462643383279
# define EMPTY -1
# define NUMBER_OF_TYPES 21
# define ABS 

typedef enum s_bool
{
	false,
	true  
}           t_bool;

/*  Для параметров используестя две сущности:
		1. Массив символов или строк с перечнем возможных ваниантов
		2. Множество возсожных вариантов в таком же порядке
	Таким образом при чтении, к примеру, типа, сравнивается символ типа из
	строки с каждым символов массива. Если находится совпадение, в t_format
	в поле type записывается значение из t_type, которое дергается по индексу
	нацденного совпадения в массиве.
*/

// Вожможные варианты обозначений длинны
const static char *g_sizes[] = {"ll", "hh", "l", "h", "L"};

// Вожможные варианты обозначений типа
const static char g_types[] = {'c', 'C', 'd', 'i', 'o', 'u', 'x', 'X', 'n',
'p', 's', 'S', 'z', 'e', 'E', 'f', 'F', 'g', 'G', 'a', 'A', '\0'};

// Вожможные варианты флагов
const static char g_flags[] = {'-', '+', '0', '#', ' ', '\0'};

// Счетчик выводимых символов
size_t g_count;

/// Флаги. Если 1 - установлен, 0 - нет
typedef struct  s_flags
{
	t_bool minus;
	t_bool plus;
	t_bool zero;
	t_bool sharp;
	t_bool space;
}               t_flags;

// Множество вариантов длинны
typedef enum s_size
{
	ll,
	hh,
	l,
	h,
	L,
	EMPTY_SIZE
}           t_size;

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
	n,
	p,
	s,
	S,
	z,
	e,
	E,
	f,
	F,
	g,
	G,
	a,
	A,
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

typedef int (* print_abstract)(va_list, t_format);

typedef void (* print_step)(int val, int *count, t_format f);

int         print_int(va_list args, t_format format);

int         print_stub(va_list args, t_format format);

// Массив функций печати для каждого типа
const static print_abstract g_fn[21] = {
	&print_stub,			//c
	&print_stub, 			//C
	&print_int,				//d
	&print_int, 			//i
	&print_stub,			//o
	&print_stub, 			//u
	&print_stub,			//x
	&print_stub,			//X
	&print_stub,			//e
	&print_stub,			//E
	&print_stub,			//f
	&print_stub,			//F
	&print_stub,			//g
	&print_stub,			//G
	&print_stub,			//a
	&print_stub,			//A
	&print_stub,			//n
	&print_stub,			//p
	&print_stub, 			//s
	&print_stub,			//S
	&print_stub,			//z
}; 

void        log_flags(t_flags flag);

void        log_format(t_format *format);

void        set_flag(char flag, t_flags *flags);

void        setup_format(t_format *format);

int         is_flag(char c);

int         is_size(char c);

int			nputchar(char c, int num);

t_format    handle_format(char **str);

int			print_num(int val, int prec);

int			print_un_int_w(unsigned int val, int *c, t_format f, char sign);

#endif