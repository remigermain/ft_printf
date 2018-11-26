/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/09 15:39:07 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/26 18:35:56 by rgermain    ###    #+. /#+    ###.fr     */
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
	j = 5236;
	s = "coucou c4est moi";
	if (argc == 2)
	{
		a = printf("pf Le fichier {cyan}%s{eoc} contient : {red}%s{eoc}\n", "coucou", "salut");
//		a = printf("pf {%05.Z}\n", 0);
//		a = printf("pf %lc, %lc\n", L'ÊM-^ZM-^V', L'ÿ≠');
//		a = printf("pf %llD, %llD\n", 0, USHRT_MAX);
//		a = printf("pf %llx ffff\n", ULLONG_MAX);
//		a = printf("pf %lc, %lc\n", L'ÊM-^ZM-^V', L'ÿ≠');
//		a = printf("pf %lx, %lx\n", 0, ULONG_MAX);
//		a = printf("pf %S\n", L"Á±≥");
//		a = printf("pf %C\n", L'ÁM-^L´');
//		a = printf("pf {%05.%}\n", 0);
//		a = printf("pf %#x\n", 42);
//		a = printf("pf %#x\n", 0);
//		a = printf("pf %#.x, %#.0x\n", 0, 0);
//		a = printf("pf % S\n", L"(null)");
//		a = printf("pf % s\n", NULL);
//		a = printf("pf %03c\n", 0);
//		a = printf("pf %.x, %.0x\n", 0, 0);
//		a = printf("pf %#.O\n", 0);
//		a = printf("pf % u\n", 9999);
//		a = printf("pf %.u, %.0u\n", 0, 0);
//		a = printf("pf %.o, %.0O\n", 0, 0);
//		a = printf("pf %X %X\n", 0, UINT_MAX);
//		a = printf("pf %o\n", LONG_MAX);
//		a = printf("pf %.5p\n", 0);
//		a = printf("pf %.0p, %.p\n", 0, 0);
//		a = printf("pf {%3*p}\n", 10, 0);		
//		a = printf("pf %2.9p\n", 123458888);
//		a = printf("pf %9.2p\n", 1234);
		printf("pf %d\n", a);
/////////////////////////////
		a = ft_printf("ft Le fichier {jaune}%s{eoc} {blue}c'est bleu{eoc} {green} cest vert{eoc} {purple} c'est violet {eoc}  {yellow} cest jaune {eoc} contient : {red}%s{eoc}\n", "coucou", "salut");
//		a = ft_printf("ft {%05.Z}\n", 0)eoc;
//		a = ft_printf("ft %lc, %lc\n", L'ÊM-^ZM-^V', L'ÿ≠');
//		a = ft_printf("ft %llD, %llD\n", 0, USHRT_MAX);
//		a = ft_printf("ft %llx ffff\n", ULLONG_MAX);
//		a = ft_printf("ft %lc, %lc\n", L'ÊM-^ZM-^V', L'ÿ≠');
//		a = ft_printf("ft %lx, %lx\n", 0, ULONG_MAX);
//		a = ft_printf("ft %S\n", L"Á±≥");
//		a = ft_printf("ft {%05.%}\n", 0);
//		a = ft_printf("ft %#x\n", 42);
//		a = ft_printf("ft %C\n", L'ÁM-^L´');
//		a = ft_printf("ft %#x\n", 0);
//		a = ft_printf("ft %#.x, %#.0x\n", 0, 0);
//		a = ft_printf("ft % s\n", L"(null)");
//		a = ft_printf("ft % s\n", NULL);
//		a = ft_printf("ft %03c\n", 0);
//		a = ft_printf("ft %.x, %.0x\n", 0, 0);
//		a = ft_printf("ft %#.O\n", 0);
//		a = ft_printf("ft % u\n", 9999);
//		a = ft_printf("ft %.u, %.0u\n", 0, 0);
//		a = ft_printf("ft %.o, %.0O\n", 0, 0);
//		a = ft_printf("ft %X %X\n", 0, UINT_MAX);
//		a = ft_printf("ft %.o\n", LONG_MAX);
//		a = ft_printf("ft %.5p\n", 0);
//		a = ft_printf("ft %.0p, %.p\n", 0, 0);
//		a = ft_printf("ft %2.9p\n", 123458888);
//		a = ft_printf("ft %9.2p\n",1234);
//		a = ft_printf("ft {%3*p}\n", 10, 0);		
		printf("ft %d\n", a);
//		a = printf("pf %-03d, %-08.25d\n", 0, j);
//		a = printf("pf = %d\n", a);
//		a = ft_printf("ft %-03d, %-08.25d\n", 0, j);
//		a = printf("ft = %d\n", a);
	}
	return (0);
}

/*		
a = ft_printf("%.59d, %059d\n", i, j);










*/
