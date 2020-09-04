#include <stdio.h>
#include "./include/printf.h"

static char	a01;
static unsigned char a02;
static short a03;
static unsigned short a04;
static int a05;
static unsigned int a06;
static long a07;
static unsigned long a08;
static long long a09;
static unsigned long long a10;
static char *a11;
static void *a12;

int	main(void)
{

	//  j = 1.42 % 1.0;
	// printf("%i\n", j);
	int a = printf("{%f}{%lf}{%Lf}\n", 1.42, 1.42, 1.42l);
	// int a = printf("{%f}{%lf}{%Lf}\n", 1444565444646.6465424242242, 1444565444646.6465424242242, 1444565444646.6465424242242l);
	int b = ft_printf("{%f}{%lf}{%Lf}\n", 1.42, 1.42, 1.42l);
	// int b = ft_printf("{%f}{%lf}{%Lf}\n", 1444565444646.6465424242242, 1444565444646.6465424242242, 1444565444646.6465424242242l);
	printf("%i\n", a);
	printf("%i\n", b);
	return (1);
}