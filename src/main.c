/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/09 15:39:07 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/06 21:06:33 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		main(int argc, char **argv)
{
	int		a;
	int		b;
	int		i;
	int		j;
	char	*s;
	long double	ff = 81256.99;
	float	ff2 = 5934.166161;
	double  dd = 1.42;
	i = 5236;
	j = 5236;
	s = "coucou c4est moi";
	//if (argc >= 2)
	a = 0;
//	while (a < 128)
	a= ft_printf("ft %20.ld et %.4hhi !\n", 0x11ffaa147, (signed char)-8);
	a = printf("ft = %d\n", a);
	a= printf("ft %20.ld et %.4hhi !\n", 0x11ffaa147, (signed char)-8);
	a = printf("pf = %d\n", a);
//	a= printf("ft % #+-58.*hhD   \n", 42, 51, 23);
//	printf("ft = %d\n", a);
//	printf("ft = %d\n", a);
//	printf("ft = %d\n", a);
//	a = printf("pf %+-15d\n", -2004662592);
//	printf("pf = %d\n", a);
	return (0);
}
