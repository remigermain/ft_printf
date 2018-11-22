/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/09 15:39:07 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/13 14:37:08 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int		main(int argc, char **argv)
{
	int a;

	a = 0;
	ft_atoi(argv[0]);
	//argv[1] = NULL;
	if (argc == 2)
	{
		printf("%s%s%s%s%s\n", "1", "2", "3", "4", "5");
		ft_printf("%s%s%s%s%s\n", "1", "2", "3", "4", "5");
//		ft_a = printf("[vrai]A %c Z\n", 0);
//		printf("[vrai] %d\n", a);
//		a = ft_printf("[faux]A %c Z\n", 0);
//		ft_printf("[faux] %d\n", a);
//		printf("[vrai] = %d\n\n", a);
//		a = ft_printf("[faux]A %.5s Z\n", );
	//	printf("%d %d %d %d %d\n", 1, -2, 3, -4, 5);
	//	ft_printf("%d %d %d %d %d\n", 1, -2, 3, -4, 5);
//		ft_printf("[faux] = %d\n", a);
	}
	return (0);
}
