/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/09 15:39:07 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/05 18:37:50 by rgermain    ###    #+. /#+    ###.fr     */
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
		ft_printf("%r\n", "\3");
		ft_printf("%c\n", 3);
	return (0);
}
