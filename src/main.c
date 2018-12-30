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
	ff[0] = 97;
	ff[1] = 256;
	ff[2] = 256;
	ff[3] = 256;
	ff[4] = 256;
	ff[5] = 256;
	ff[6] = 256;
	ff[7] = 256;
	ff[8] = 256;
	ff[9] = 256;

char *c = "efre \t\n\1\2\3 fffewf wfwe \t\n\r\fwe";
	//ft_printf("%d %d %d, %d, %d, %d %d %d %d %d\n",c, c << 1,  c >> 1, c >> 2 , c >> 3, c >> 4, c >> 5, c >> 6, c >> 7, c >> 8);
	//ft_printf("%d %d\n", c, c & 1);
	//ft_printf(" %s %#50.36llu %c %C %50.20p \n%.1ts\n","feeerfee546", 1661611569, 97, 256, &ft_strlen, argv);
	ft_printf(" d = %d  d = %d d = %1$d  d = %d %0$d\n", 42, 53, 10, 22, 55);
	printf(" d = %d  d = %d d = %$0d  d = %d\n", 42, 53);
	return (0);
}
