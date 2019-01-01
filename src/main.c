/* ************************************************************************** */
/*                                                          Le - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@Le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/19 22:28:54 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/20 14:33:21 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"
#include <math.h>

int	main(int argc, char **argv)
{
	int a = 0;

	if (argc != -1)
		a++;
	if (argv[0][0] == 1)
		a++;
	long double nb =	 1257276.489456516898448716464688766566 ;
	long double nb2 =	 0.0004894565168984 ;
	int b = 10;
		a = 10;
	a = ft_printf("%50.37Lg", nb);
	ft_printf("ft = %d\n", a);
	a = printf("%50.37Lg", nb);
	printf("pf = %d\n", a);

	a = ft_printf("%50.2Lg", nb);
	ft_printf("ft = %d\n", a);
	a = printf("%50.2Lg", nb);
	printf("pf = %d\n", a);

	a = ft_printf("%.37Lg", nb);
	ft_printf("ft = %d\n", a);
	a = printf("%.37Lg", nb);
	printf("pf = %d\n", a);

	a = ft_printf("%Lg", nb);
	ft_printf("ft = %d\n", a);
	a = printf("%Lg", nb);
	printf("pf = %d\n\n\n", a);


//////////
	a = ft_printf("%50.37Lg", nb2);
	ft_printf("ft = %d\n", a);
	a = printf("%50.37Lg", nb2);
	printf("pf = %d\n", a);

	a = ft_printf("%50.1Lg", nb2);
	ft_printf("ft = %d\n", a);
	a = printf("%50.1Lg", nb2);
	printf("pf = %d\n", a);

	a = ft_printf("%.37Lg", nb2);
	ft_printf("ft = %d\n", a);
	a = printf("%.37Lg", nb2);
	printf("pf = %d\n", a);

	a = ft_printf("%Lg", nb2);
	ft_printf("ft = %d\n", a);
	a = printf("%Lg", nb2);
	printf("pf = %d\n", a);
	return (0);
}
