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
	long double nb =	 -M_PI ;
	int b = 10;
		a = 10;
	ft_printf("%+40.20Lf\n", a++,nb);
	printf("%+40.20Lf\n\n", b++,nb);
	ft_printf("%+40.20Lf\n", a++,nb);
	printf("%+40.20Lf\n\n", b++,nb);
	ft_printf("%+40.20Lf\n", a++,nb);
	printf("%+40.20Lf\n\n", b++,nb);
	ft_printf("%+40.20Lf\n", a++,nb);
	printf("%+40.20Lf\n\n", b++,nb);
	ft_printf("%+40.20Lf\n", a++,nb);
	printf("%+40.20Lf\n\n", b++,nb);
	ft_printf("%+40.20Lf\n", a++,nb);
	printf("%+40.20Lf\n\n", b++,nb);
	ft_printf("%+40.20Lf\n", a++,nb);
	printf("%+40.20Lf\n\n", b++,nb);
	ft_printf("%+40.20Lf\n", a++,nb);
	printf("%+40.20Lf\n\n", b++,nb);
	ft_printf("%+40.20Lf\n", a++,nb);
	printf("%+40.20Lf\n\n", b++,nb);
	return (0);
}
