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
	wuchar_t *str;
	long double nb = 1669243656.21556646666;
	wchar_t ff[10];
	ff[0] = 256;
	ff[1] = 256;
	ff[2] = 256;
	ff[3] = 256;
	ff[4] = 256;
	ff[5] = 256;
	ff[6] = 256;
	ff[7] = 256;
	ff[8] = 256;
	ff[9] = 256;
	a = ft_sprintf(&str, "%S\n", ff);
//	a = ft_printf("%s\n", str);
	//ft_printf("ft = %d\n", a);
	//a = dprintf(1, "bonjour %d ddd %s ,  dddd", -42, "ouiiiii",  699812);
	//ft_printf("pf = %d\n", a);
	return (0);
}
