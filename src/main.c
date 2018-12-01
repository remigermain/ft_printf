/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/09 15:39:07 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/01 16:49:43 by rgermain    ###    #+. /#+    ###.fr     */
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

		a = printf("pf test%#.4o et %02o %0#14.o!!\n", 012, 036, 12587499);
		a = ft_printf("ft test%#.4o et %02o %0#14.o!!\n", 012, 036, 12587499);
		a = ft_printf("ft {blue}%C{eoc} {red}%s{eoc}\n", 0xbffe, "c'est rouge");
		a = printf("ft %d\n", a);
	}
	return (0);
}
