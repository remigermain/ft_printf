/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/09 15:39:07 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/27 20:24:39 by rgermain    ###    #+. /#+    ###.fr     */
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
		a = printf("pf %#7.5X%0006.2x et %lX!\n", 0xab, 0x876, 0xff11ff11ff1);
//		a = printf("pf test%#.4o et %02o %#14.o!!\n", 012, 036, 12587499);
//		a = printf("ft %C, 0x6f\n");
//		a = printf("pf %lc\n", 0x4e6);
//		a = printf("%C", 0x6f);
//		a = printf("pf titi%#012o\n", -874);
//		a = printf("pf coco et %-#-#--24O titi%#012o\n", 12, -874);
//		a = printf("pf %lld\n", LLONG_MIN);
//		a = printf("pf s: %s, p: d:%d\n", "a string", 42);
//		a = printf("pf s: %s, p: %p, d:%d\n", "a string", &ft_strlen, 42);
//		a = printf("pf {%0-3d}\n", 0);
//		a = printf("pf %-2d\n", -7);
//		a = printf("pf %o, %ho, %hho\n", -42, -42, -42);
//		a = printf("pf %#.o, %#.0o\n", 0, 0);
//		a = printf("pf %#.3o\n", 1);
//		a = printf("pf %#x\n", 42);
//		a = printf("pf {%#.5x}\n", 1);
//		a = printf("%");
//		a = printf("pf {%-15Z}\n", 123);
//		a = printf("pf Le fichier {cyan}%s{eoc} contient : {red}%s{eoc}\n", "coucou", "salut");
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

		a = ft_printf("ft %#7.5X%0006.2x et %lX!\n", 0xab, 0x876, 0xff11ff11ff1);

//a = ft_printf("ft test%#.4o et %02o %#14.o!!\n", 012, 036, 12587499);
//		a = ft_printf("ft %C, 0x6f\n");
//		a = ft_printf("ft %lc\n", 0x4e6);
//		a = ft_printf("ft coco et %-#-#--240 \n", 12);
//		a = ft_printf("ft titi%#012o\n", -874);
//		a = ft_printf("ft coco et %-#-#--24O titi%#012o\n", 12, -874);
//		a = ft_printf("ft %lld\n", LLONG_MIN);
//		a = ft_printf("ft %D\n", LONG_MIN);
//		a = ft_printf("ft s: %s, p: %p, d:%d\n", "a string", &ft_strlen, 42);
//		a = ft_printf("ft {%0-3d}\n", 0);
//		a = ft_printf("ft %-2d\n", -7);
//		a = ft_printf("ft %o, %ho, %hho\n", -42, -42, -42);
//		a = ft_printf("ft %#.o, %#.0o\n", 0, 0);
//		a = ft_printf("ft %#.3o\n", 1);
//		a = ft_printf("ft %#x\n", 42);
//		a = ft_printf("ft {%#.5x}\n", 1);
//		a = ft_printf("%");
//		a = ft_printf("ft {%-15Z}\n", 123);
//		a = ft_printf("ft Le fichier {yellow}%s{eoc} {blue}c'est bleu{eoc} {green} cest vert{eoc} {purple} c'est violet {eoc}  {yellow} cest jaune {eoc} contient : {red}%s{eoc}\n", "coucou", "salut");
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
