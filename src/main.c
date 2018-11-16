/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/09 15:39:07 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/16 09:25:33 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int		main(int argc, char **argv)
{
	int a;

	a = 0;

	char *t = "ceci est une string";
	char *d = "je sai pas";
	int e = 5;
	unsigned int b = 42967296;
	char  *test_simple_mix;
	//argv[1] = NULL;
	if (argc == 2)
	{

		a = printf("%lx, %lx\n", 1992, ULONG_MAX);
		a = ft_printf("%lx, %lx\n", 1992, ULONG_MAX);
//		printf("pf = %d\n", a);
//		a = ft_printf("{% 03d}", 0);
//		printf("pf = %d\n", a);
/*
		a = printf("pf %.5p\n", 0);
		printf("pf = %d\n", a);
		a = ft_printf("ft %.5p\n", 0);
		printf("ft = %d\n", a);
		a = printf("pf2 %2.9p\n", 1234);
		printf("pf2 = %d\n", a);
		a = ft_printf("ff2 %2.9p\n", 1234);
		printf("ft2 = %d\n", a);

*/

	}
	return (0);
}
