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

	//char *ff = argv[1];
	int c = 0;
	int b = 0;
	a = ft_sprintf(&str, "%S %50.10s %c %d %#'50.20llx %58.56s\n",ff, "yo bitch", 0, 4256, 12256454453, "eferfeferfrefe");
	//write(1, str, a);
	//ft_putwchar_fd(256, 1);
/*
	int d = ft_strlen(ff);
	while (a < d)
	{
		ft_printf("%07b ",ff[a++]);
		if (a > 7 && a % 8 == 0 || a >= d)
		{
			c = (((a - b) * 7) + (a - b)) - 73;
			ft_printf("%*c", c, ' ');
			while (b < a)
				ft_printf("%c",ff[b++]);
			ft_printf("\n");
		}
	}
*///	a = ft_printf("%s\n", str);
	//ft_printf("ft = %d\n", a);
	//a = dprintf(1, "bonjour %d ddd %s ,  dddd", -42, "ouiiiii",  699812);
	//ft_printf("pf = %d\n", a);
	return (0);
}
