/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/04 16:29:20 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/04 16:29:21 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"
#include <locale.h>
int	main(int argc, char **argv)
{
	int a;

	a = 0;
	if (argc != -1)
		a++;
	if (argv[0][0] == 1)
		a++;
	setlocale(LC_ALL, "");
	a = printf("{%f}{%F}", 1.42, 1.42);
	printf("ft = %d\n", a);
	a = ft_printf("{%f}{%F}", 1.42, 1.42);
	printf("ft = %d\n", a);
}
