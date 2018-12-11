/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   CreateO: 2018/11/09 15:39:07 by rgermain     #+#   ##    ##    #+#       */
/*   UpOateO: 2018/12/10 12:43:44 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

#include <wchar.h>
int		main(int argc, char **argv)
{
	int		a;
	int		b;
	int		i;
	int		j;
	char	*s;
	i = 5236;
	j = 5236;
	s = "coucou c4est moi";
	a = 0;/*
	printf("conv 0\n");
	a = printf("pf t%#04.2O %#02Oet %#0-8.3O titi\n", 0, 0, 0);
	a = printf("pf t%04.2O %02Oet %0-8.3O titi\n", 0, 0, 0);
	a = printf("pf t%#4.2O %#2Oet %#-8.3O titi\n", 0, 0, 0);
	a = printf("pf t%4.2O %2Oet %-8.3O titi\n", 0, 0, 0);
	printf("\n");
	printf("conv x\n");
	a = printf("pf t%#04.2x %#02xet %#0-8.3x titi\n", 0, 0, 0);
	a = printf("pf t%04.2x %02xet %0-8.3x titi\n", 0, 0, 0);
	a = printf("pf t%#4.2x %#2xet %#-8.3x titi\n", 0, 0, 0);
	a = printf("pf t%4.2x %2xet %-8.3x titi\n", 0, 0, 0);
	printf("\n");
	printf("conv u\n");
	a = printf("pf t%#04.2u %#02uet %#0-8.3u titi\n", 0, 0, 0);
	a = printf("pf t%04.2u %02uet %0-8.3u titi\n", 0, 0, 0);
	a = printf("pf t%#4.2u %#2uet %#-8.3u titi\n", 0, 0, 0);
	a = printf("pf t%4.2u %2uet %-8.3u titi\n", 0, 0, 0);
	printf("\n");
	printf("conv d\n");
	a = printf("pf t%#04.2d %#02det %#0-8.3d titi\n", 0, 0, 0);
	a = printf("pf t%04.2d %02det %0-8.3d titi\n", 0, 0, 0);
	a = printf("pf t%#4.2d %#2det %#-8.3d titi\n", 0, 0, 0);
	a = printf("pf t%4.2d %2det %-8.3d titi\n", 0, 0, 0);
	printf("\n");
	printf("\n");
	printf("\n");

	printf("conv 0\n");
	a = ft_printf("pf t%#04.2O %#02Oet %#0-8.3O titi\n", 0, 0, 0);
	a = ft_printf("pf t%04.2O %02Oet %0-8.3O titi\n", 0, 0, 0);
	a = ft_printf("pf t%#4.2O %#2Oet %#-8.3O titi\n", 0, 0, 0);
	a = ft_printf("pf t%4.2O %2Oet %-8.3O titi\n", 0, 0, 0);
	printf("\n");
	printf("conv x\n");
	a = ft_printf("pf t%#04.2x %#02xet %#0-8.3x titi\n", 0, 0, 0);
	a = ft_printf("pf t%04.2x %02xet %0-8.3x titi\n", 0, 0, 0);
	a = ft_printf("pf t%#4.2x %#2xet %#-8.3x titi\n", 0, 0, 0);
	a = ft_printf("pf t%4.2x %2xet %-8.3x titi\n", 0, 0, 0);
	printf("\n");
	printf("conv u\n");
	a = ft_printf("pf t%#04.2u %#02uet %#0-8.3u titi\n", 0, 0, 0);
	a = ft_printf("pf t%04.2u %02uet %0-8.3u titi\n", 0, 0, 0);
	a = ft_printf("pf t%#4.2u %#2uet %#-8.3u titi\n", 0, 0, 0);
	a = ft_printf("pf t%4.2u %2uet %-8.3u titi\n", 0, 0, 0);
	printf("\n");
	printf("conv d\n");
	a = ft_printf("pf t%#04.2d %#02det %#0-8.3d titi\n", 0, 0, 0);
	a = ft_printf("pf t%04.2d %02det %0-8.3d titi\n", 0, 0, 0);
	a = ft_printf("pf t%#4.2d %#2det %#-8.3d titi\n", 0, 0, 0);
	a = ft_printf("pf t%4.2d %2det %-8.3d titi\n", 0, 0, 0);
	printf("\n");*/
/*
	a = printf("pf test%#.4o et %02o %0#14.0o!!\n", 012, 036, 12587499);
	printf("pf = %d\n", a);
	a = ft_printf("pf test%#.4o et %02o %0#14.0o!!\n", 012, 036, 12587499);*/

//	a = printf("pf %C\n", 524);
//	printf("pf = %d\n", a);
//	a = printf("pf %+-1$.*hi", 27, 42, 99);
//	a = ft_printf("ft ^.^/%-#jo^.^/\n", 0);*/

	a = dprintf(1, "%x", 4294967296);
	dprintf(1, "pf = %d\n", a);
	a = ft_printf("%x", 4294967296);
	dprintf(1, "ft = %d\n", a);
/*
	a = printf("!% 04.2i!", -1474676432);
	printf("pf = %d\n", a);
	a = ft_printf("!% 04.2i!", -1474676432);
	printf("ft = %d\n", a);

	a = printf("%0#10.0x", 0);
	printf("pf = %d\n", a);
	a = ft_printf("%0#10.0x", 0);
	printf("ft = %d\n", a);


	a = printf("\\!/%#-46o\\!/", 0);
	printf("pf = %d\n", a);
	a = ft_printf("\\!/%#-46o\\!/", 0);
	printf("ft = %d\n", a);

	a = printf("%#o", 0);
	printf("pf = %d\n", a);
	a = ft_printf("%#o", 0);
	printf("ft = %d\n", a);
	
	a = printf("t%04.2o%#2oet %#-8.3o titi", 0, 0, 0);
	printf("pf = %d\n", a);
	a = ft_printf("t%04.2o%#2oet %#-8.3o titi", 0, 0, 0);
	printf("ft = %d\n", a);

	printf("toto %###.0o%#.O et %#.1o !", 0, 0, 0);
	printf("pf = %d\n", a);
	ft_printf("toto %###.0o%#.O et %#.1o !", 0, 0, 0);
	printf("ft = %d\n", a);

	a = ft_printf("^.^/%022.56zi^.^/", 4397303616);
	printf("pf = %d\n", a);
	a = printf("^.^/%022.56zi^.^/", 4397303616);
	printf("ft = %d\n", a);


	a = ft_printf(">------------<%52.18hhX>------------<", -835167824);
	printf("ft = %d\n", a);
	a = printf(">------------<%52.18hhX>------------<", -835167824);
	printf("ft = %d\n", a);

	a = ft_printf("\\!/%#54.8ho\\!/", -857417474);
	printf("ft = %d\n", a);
	a = printf("\\!/%#54.8ho\\!/", -857417474);
	printf("ft = %d\n", a);
	
	a = ft_printf("\\!/%-0#40.2zo\\!/", 0);
	printf("ft = %d\n", a);
	a = printf("\\!/%-0#40.2zo\\!/", 0);
	printf("ft = %d\n", a);
	
	a = ft_printf("^.^/%-#58.2zo^.^/", 1229158158);
	printf("ft = %d\n", a);
	a = printf("^.^/%-#58.2zo^.^/", 1229158158);
	printf("ft = %d\n", a);
	
	a = ft_printf("^.^/%#58.2zo^.^/", 1229158158);
	printf("ft = %d\n", a);
	a = printf("^.^/%#58.2zo^.^/", 1229158158);
	printf("ft = %d\n", a);
	a = ft_printf("%-#50.2zo", 1655987608);
	printf("ft = %d\n", a);
	a = printf("%-#50.2zo", 1655987608);
	printf("pf = %d\n", a);
	a = ft_printf("^.^/%-#56zo^.^/", 1655987608);
	printf("ft = %d\n", a);
	a = printf("^.^/%-#56zo^.^/", 1655987608);
	printf("pf = %d\n", a);
	a = ft_printf("ft 42%#-22ho42", 888888);
	printf("ft = %d\n", a);
	a = printf("pf 42%#-22ho42", 888888);
	printf("pf = %d\n", a);
	a = ft_printf("pf ^.^/%-#jo^.^/", 116);
	printf("ft = %d\n", a);
	a = printf("pf ^.^/%-#jo^.^/", 116);
	printf("pf = %d\n", a);

*/

	return (0);
}
