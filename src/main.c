/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/09 15:39:07 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/07 16:07:34 by rgermain    ###    #+. /#+    ###.fr     */
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
	a = ft_printf("ft t%#04.2O %#2Oet %#-8.3O titi\n", 40, 23, 24);
	a = ft_printf("ft t%#04.2O %#2Oet %#-8.3O titi\n", 5, 1, 1);
	a = ft_printf("ft t%4.2O %2Oet %-8.3O titi\n", 40, 23, 24);
	a = ft_printf("ft t%4.2O %2Oet %-8.3O titi\n", 1, 1, 1);
	a = printf("ft = %d\n", a);
	a = printf("pf t%#04.2O %#2Oet %#-8.3O titi\n", 40, 23, 24);
	a = printf("pf t%#04.2O %#2Oet %#-8.3O titi\n", 1, 1, 1);
	a = printf("pf t%4.2O %2Oet %-8.3O titi\n", 40, 23, 24);
	a = printf("pf t%4.2O %2Oet %-8.3O titi\n", 1, 1, 1);
	a = printf("pf = %d\n", a);
//	a= printf("ft % #+-58.*hhD   \n", 42, 51, 23);
//	printf("ft = %d\n", a);
//	printf("ft = %d\n", a);
//	printf("ft = %d\n", a);
//	a = printf("pf %+-15d\n", -2004662592);
//	printf("pf = %d\n", a);
	return (0);
}
