/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
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
	char *str;
	long double nb = 1669243656.21556646666;
	a = ft_printf("%Lf\n", nb);
	a = printf("%Lf\n", nb);
	//ft_printf("ft = %d\n", a);
	//a = dprintf(1, "bonjour %d ddd %s ,  dddd", -42, "ouiiiii",  699812);
	//ft_printf("pf = %d\n", a);
	return (0);
}
