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

	if (argc != -1)
		a++;
	if (argv[0][0] == 1)
		a++;


char *c = "efre \t\n\1\2\3 fffewf wfwe \t\n\r\fwe";
	//ft_printf("%d %d %d, %d, %d, %d %d %d %d %d\n",c, c << 1,  c >> 1, c >> 2 , c >> 3, c >> 4, c >> 5, c >> 6, c >> 7, c >> 8);
	//ft_printf("%d %d\n", c, c & 1);
	ft_printf(" %s  %r %#50.36llu %c %C %50.20p \n%.1ts\n","feeerfee546", c, 1661611569, 97, 256, &ft_strlen, argv);
//	ft_printf("nb = %'50.20llX\n", 16498646316);
//	printf(" d = %d  d = %d d = %$0d  d = %d\n", 42, 53);
	return (0);
}
