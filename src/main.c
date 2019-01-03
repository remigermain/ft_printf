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
	long double nb =	-6464666165.56 ;
	long double nb2 =	 -0.544 ;
	long double nb3 =	 -5.555555555555555;
		a = 10;
	a = ft_printf("%-'50.34Lf", nb);
	ft_printf("ft = %-d\n", a);
	a = printf("%-'50.34Lf", nb);
	printf("pf = %-d\n", a);

	a = ft_printf("%-'50.1Lf", nb);
	ft_printf("ft = %-d\n", a);
	a = printf("%-'50.1Lf", nb);
	printf("pf = %-d\n", a);

	a = ft_printf("%-'.34Lf", nb);
	ft_printf("ft = %-d\n", a);
	a = printf("%-'.34Lf", nb);
	printf("pf = %-d\n", a);

	a = ft_printf("%''-Lf", nb);
	ft_printf("ft = %-d\n", a);
	a = printf("%-'Lf", nb);
	printf("pf = %-d\n\n\n", a);


//////////
	a = ft_printf("%-50.34Lf", nb2);
	ft_printf("ft = %-d\n", a);
	a = printf("%-50.34Lf", nb2);
	printf("pf = %-d\n", a);

	a = ft_printf("%-50.1Lf", nb2);
	ft_printf("ft = %-d\n", a);
	a = printf("%-50.1Lf", nb2);
	printf("pf = %-d\n", a);

	a = ft_printf("%-Lf", nb2);
	ft_printf("ft = %-d\n", a);
	a = printf("%-Lf", nb2);
	printf("pf = %-d\n\n", a);

////
	a = ft_printf("%-50.34Lf", nb3);
	ft_printf("ft = %-d\n", a);
	a = printf("%-50.34Lf", nb3);
	printf("pf = %-d\n", a);

	a = ft_printf("%-50.1Lf", nb3);
	ft_printf("ft = %-d\n", a);
	a = printf("%-50.1Lf", nb3);
	printf("pf = %-d\n", a);

	a = ft_printf("%-.34Lf", nb3);
	ft_printf("ft = %-d\n", a);
	a = printf("%-.34Lf", nb3);
	printf("pf = %-d\n", a);

	a = ft_printf("%-Lf", nb3);
	ft_printf("ft = %-d\n", a);
	a = printf("%-Lf", nb3);
	printf("pf = %-d\n", a);
	return (0);
}
