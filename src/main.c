/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/09 15:39:07 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/20 22:11:46 by rgermain    ###    #+. /#+    ###.fr     */
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
		a = printf("pf %.4s\n", s);
		printf("pf %d\n", a);
		a = ft_printf("ft %.4s\n", s);
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
