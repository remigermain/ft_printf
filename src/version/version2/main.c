/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/09 15:39:07 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/13 22:14:52 by rgermain    ###    #+. /#+    ###.fr     */
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
	//	a = printf("bonjour %d  %3$d  %1$s  %d pop\n", 90, 42, 48);
	//	printf("%d\n", a);
		//a = ft_printf("bonjour  % d   pop\n", 90);
		a = ft_printf("bonjour %d  %d  %d pop\n", 90, 4, 48);
	//	printf("%d\n", a);
	//	a = ft_printf("bonjour  %- 199.d   pop\n", -4299);
	//	printf("%d\n", a);
//		a = printf("bonjour  %-d   pop\n", -4299);
//		printf("%d\n", a);
	//	a = ft_printf("bonjour  % d   pop\n", 4299);
	//	ft_printf("%d\n", a);
	}
	return (0);
}
