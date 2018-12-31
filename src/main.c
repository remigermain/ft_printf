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

int	main(int argc, char **argv)
{
	int a = 0;

	if (argc != -1)
		a++;
	if (argv[0][0] == 1)
		a++;
	long double nb =	5115525227.0252172700100006316;
	int b = 10;
		a = 10;
	ft_printf("%'.*Lf\n", a++,nb);
	printf("%'.*Lf\n\n", b++,nb);
	ft_printf("%'.*Lf\n", a++,nb);
	printf("%'.*Lf\n\n", b++,nb);
	ft_printf("%'.*Lf\n", a++,nb);
	printf("%'.*Lf\n\n", b++,nb);
	ft_printf("%'.*Lf\n", a++,nb);
	printf("%'.*Lf\n\n", b++,nb);
	ft_printf("%'.*Lf\n", a++,nb);
	printf("%'.*Lf\n\n", b++,nb);
	ft_printf("%'.*Lf\n", a++,nb);
	printf("%'.*Lf\n\n", b++,nb);
	ft_printf("%'.*Lf\n", a++,nb);
	printf("%'.*Lf\n\n", b++,nb);
	ft_printf("%'.*Lf\n", a++,nb);
	printf("%'.*Lf\n\n", b++,nb);
	ft_printf("%'.*Lf\n", a++,nb);
	printf("%'.*Lf\n\n", b++,nb);
	return (0);
}
