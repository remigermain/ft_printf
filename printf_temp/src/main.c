/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/09 15:39:07 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/20 17:00:12 by rgermain    ###    #+. /#+    ###.fr     */
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
	j = -5236;
	s = "coucou c4est moi";
	if (argc == 2)
	{
		a = printf("%.59d, %059d\n", i, j);
		a = ft_printf("%.59d, %059d\n", i, j);
	}
	return (0);
}
