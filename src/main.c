/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/09 15:39:07 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/24 09:31:51 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		main(int argc, char **argv)
{
	int		a;
	int		i;
	int		j;
	char	*s;

	i = 5236;
	j = 5236;
	s = "coucou c4est moi";
	if (argc == 2)
	{

		a = printf("pf %p\n", &ft_strlen);
//		a = printf("pf %.5p\n", 0);
//		a = printf("pf %.0p, %.p\n", 0, 0);
//		a = printf("pf {%3*p}\n", 10, 0);		
//		a = printf("pf %2.9p\n", 123458888);
//		a = printf("pf %9.2p\n", 1234);
		printf("pf %d\n", a);
		a = ft_printf("ft %p\n", &ft_strlen);
//		a = ft_printf("ft %.5p\n", 0);
//		a = ft_printf("ft %.0p, %.p\n", 0, 0);
//		a = ft_printf("ft %2.9p\n", 123458888);
//		a = ft_printf("ft %9.2p\n",1234);
//		a = ft_printf("ft {%3*p}\n", 10, 0);		
		printf("ft %d\n", a);
//		a = printf("pf %-03d, %-08.25d\n", 0, j);
//		a = printf("pf = %d\n", a);
//		a = ft_printf("ft %-03d, %-08.25d\n", 0, j);
//		a = printf("ft = %d\n", a);
	}
	return (0);
}

/*		
a = ft_printf("%.59d, %059d\n", i, j);










*/
