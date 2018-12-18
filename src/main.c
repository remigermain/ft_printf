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
	a = 0;
/*	printf("conv 0\n");
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
	printf("\n");

	a = printf("pf test%#.4o et %02o %0#14.0o!!\n", 012, 036, 12587499);
	printf("pf = %d\n", a);
	a = ft_printf("pf test%#.4o et %02o %0#14.0o!!\n", 012, 036, 12587499);

//	a = printf("pf %C\n", 524);
//	printf("pf = %d\n", a);
//	a = printf("pf %+-1$.*hi", 27, 42, 99);
//	a = ft_printf("ft ^.^/%-#jo^.^/\n", 0);

	a = dprintf(1, "%x", 4294967296);
	dprintf(1, "pf = %d\n", a);
	a = ft_printf("%x", 4294967296);
	dprintf(1, "ft = %d\n", a);

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



a = printf("%x", -42);                         
	printf("pf = %d\n", a);
a = ft_printf("%x", -42);                         
	printf("ft = %d\n", a);

a = printf("%X", -42);                         
	printf("pf = %d\n", a);
a = ft_printf("%X", -42);                         
	printf("ft = %d\n", a);

a =printf("%x", 4294967296);                  
	printf("pf = %d\n", a);
a =ft_printf("%x", 4294967296);                  
	printf("ft = %d\n", a);

a = printf("%X", 4294967296);                  
	printf("pf = %d\n", a);
a = ft_printf("%X", 4294967296);                  
	printf("ft = %d\n", a);

a = printf("@moulitest: %5.xT%5.0x", 0, 0);    
	printf("pf = %d\n", a);
a = ft_printf("@moulitest: %5.xT%5.0x", 0, 0);    
	printf("ft = %d\n", a);

a = printf("%5.2s is a string", "");          
	printf("pf = %d\n", a);
a = ft_printf("%5.2s is a string", "");          
	printf("ft = %d\n", a);

a  = printf("@moulitest: %5.oT%5.0o", 0, 0);    
	printf("pf = %d\n", a);
a = ft_printf("@moulitest: %5.oT%5.0o", 0, 0);    
	printf("ft = %d\n", a);

a = printf("@moulitest: %5.dT%5.0d", 0, 0);    
	printf("pf = %d\n", a);
a = ft_printf("@moulitest: %5.dT%5.0d", 0, 0);    
	printf("ft = %d\n", a);

a = printf("%u", -1);                          
	printf("pf = %d\n", a);
a = ft_printf("%u", -1);                          
	printf("ft = %d\n", a);

a = printf("%u", 4294967296);                  
	printf("pf = %d\n", a);
a = ft_printf("%u", 4294967296);                  
	printf("ft = %d\n", a);

a = printf("%+u", 4294967295);   
	printf("pf = %d\n", a);
a = ft_printf("%+u", 4294967295);   
	printf("ft = %d\n", a);

a = printf("toto%.0d et %+.i et  %   .0D !!!", 0, 0, 0);
	printf("pf = %d\n", a);
a = ft_printf("toto%.0d et %+.i et  %   .0D !!!", 0, 0, 0);
	printf("ft = %d\n", a);

a = printf("% u", 4294967295);
	printf("pf = %d\n", a);
a = ft_printf("% u", 4294967295);
	printf("ft = %d\n", a);

a = printf("@main_ftprintf: %###-#0000 33...12..#0+0d", 256);
//a = printf("@main_ftprintf: %###-#0000 33.12+d", 256);
	printf("pf = %d\n", a);
a = ft_printf("@main_ftprintf: %###-#0000 33...12..#0+0d", 256);
	printf("ft = %d\n", a);

a = printf("% U", 4294967295);
	printf("pf = %d\n", a);
a = ft_printf("% u", 4294967295);
	printf("ft = %d\n", a);

	a = printf("%hhjd", 128);
	printf("pf = %d\n", a);
	a = ft_printf("%hhld", 128);
	printf("ft = %d\n", a);

	a = printf("@main_ftprintf: %####0000 33..1d", 256);
	printf("pf = %d\n", a);
	a = ft_printf("@main_ftprintf: %####0000 33..1d", 256);
	printf("pf = %d\n", a);

	a  = printf("@main_ftprintf: %####0000 33..1..#00d\\n", 256);
	printf("pf = %d\n", a);
	a = ft_printf("@main_ftprintf: %####0000 33..1..#00d\\n", 256);
	printf("pf = %d\n", a);

	a = printf("%0d", -579);
	printf("pf = %d\n", a);
	a = ft_printf("%0d", -579);
	printf("ft = %d\n\n", a);

	a =printf("%zhd", 4294967296);
	printf("pf = %d\n", a);
	a = ft_printf("%zhd", 4294967296);
	printf("ft = %d\n", a);

	a = printf("%jzd", 9223372036854775807);
	printf("pf = %d\n", a);
	a = ft_printf("%jzd", 9223372036854775807);
	printf("ft = %d\n", a);

	a = printf("%jhd", 9223372036854775807);
	printf("pf = %d\n", a);
	a = ft_printf("%jhd", 9223372036854775807);
	printf("ft = %d\n", a);

*/
long double flo2 = 16665165;
//double flo = 45893.1561165656;
double flo = 45893.551566;

printf("double\n");
	a = printf("%f", flo);
	printf("ft = %d\n", a);
	a = ft_printf("%f", flo);
	printf("pf = %d\n", a);
	
	a = printf("%.f", flo);
	printf("ft = %d\n", a);
	a = ft_printf("%.f", flo);
	printf("pf = %d\n", a);
	
	a = printf("%.10f", flo);
	printf("ft = %d\n", a);
	a = ft_printf("%.10f", flo);
	printf("pf = %d\n", a);

	a = printf("%10f", flo);
	printf("ft = %d\n", a);
	a = ft_printf("%10f", flo);
	printf("pf = %d\n", a);

	a = printf("%10.10f", flo);
	printf("ft = %d\n", a);
	a = ft_printf("%10.10f", flo);
	printf("pf = %d\n", a);

printf("\nlong double\n");
	a = printf("%Lf", flo2);
	printf("ft = %d\n", a);
	a = ft_printf("%Lf", flo2);
	printf("pf = %d\n", a);
	
	a = printf("%.Lf", flo2);
	printf("ft = %d\n", a);
	a = ft_printf("%.Lf", flo2);
	printf("pf = %d\n", a);
	
	a = printf("%.10Lf", flo2);
	printf("ft = %d\n", a);
	a = ft_printf("%.10Lf", flo2);
	printf("pf = %d\n", a);

	a = printf("%10Lf", flo2);
	printf("ft = %d\n", a);
	a = ft_printf("%10Lf", flo2);
	printf("pf = %d\n", a);

	a = printf("%10.10Lf", flo2);
	printf("ft = %d\n", a);
	a = ft_printf("%10.10Lf", flo2);
	printf("pf = %d\n", a);

printf("\nlong double a\n");
	a = printf("%La", flo2);
	printf("ft = %d\n", a);
	a = ft_printf("%La", flo2);
	printf("pf = %d\n", a);
	
	a = printf("%.La", flo2);
	printf("ft = %d\n", a);
	a = ft_printf("%.La", flo2);
	printf("pf = %d\n", a);
	
	a = printf("%.10La", flo2);
	printf("ft = %d\n", a);
	a = ft_printf("%.10La", flo2);
	printf("pf = %d\n", a);

	a = printf("%10La", flo2);
	printf("ft = %d\n", a);
	a = ft_printf("%10La", flo2);
	printf("pf = %d\n", a);

	a = printf("%10.10La", flo2);
	printf("ft = %d\n", a);
	a = ft_printf("%10.10La", flo2);
	printf("pf = %d\n", a);

printf("\ndouble 'a'\n");
	a = printf("%a", flo);
	printf("ft = %d\n", a);
	a = ft_printf("%a", flo);
	printf("pf = %d\n", a);
	
	a = printf("%.a", flo);
	printf("ft = %d\n", a);
	a = ft_printf("%.a", flo);
	printf("pf = %d\n", a);
	
	a = printf("%.10a", flo);
	printf("ft = %d\n", a);
	a = ft_printf("%.10a", flo);
	printf("pf = %d\n", a);

	a = printf("%10a", flo);
	printf("ft = %d\n", a);
	a = ft_printf("%10a", flo);
	printf("pf = %d\n", a);

	a = printf("%10.18a", flo);
	printf("ft = %d\n", a);
	a = ft_printf("%10.18a", flo);
	printf("pf = %d\n", a);


	

printf("\nlong double e\n");
	a = printf("%Lef", flo2);
	printf("ft = %d\n", a);
//	a = ft_printf("%Lef", flo2);
//	printf("pf = %d\n", a);
	
	a = printf("%.Lef", flo2);
	printf("ft = %d\n", a);
//	a = ft_printf("%.Lef", flo2);
//	printf("pf = %d\n", a);
	
	a = printf("%.10Lef", flo2);
	printf("ft = %d\n", a);
//	a = ft_printf("%.10Lef", flo2);
//	printf("pf = %d\n", a);

	a = printf("%10Lef", flo2);
	printf("ft = %d\n", a);
//	a = ft_printf("%10Lef", flo2);
//	printf("pf = %d\n", a);

	a = printf("%10.10Lef", flo2);
	printf("ft = %d\n", a);
//	a = ft_printf("%10.10Lef", flo2);
//	printf("pf = %d\n", a);

printf("\nlong double g\n");
	a = printf("%Lgf", flo2);
	printf("ft = %d\n", a);
//	a = ft_printf("%Lgf", flo2);
//	printf("pf = %d\n", a);
	
	a = printf("%.Lgf", flo2);
	printf("ft = %d\n", a);
//	a = ft_printf("%.Lgf", flo2);
//	printf("pf = %d\n", a);
	
	a = printf("%.10Lgf", flo2);
	printf("ft = %d\n", a);
//	a = ft_printf("%.10Lgf", flo2);
//	printf("pf = %d\n", a);

	a = printf("%10Lgf", flo2);
	printf("ft = %d\n", a);
//	a = ft_printf("%10Lgf", flo2);
//	printf("pf = %d\n", a);

	a = printf("%10.10Lgf", flo2);
	printf("ft = %d\n", a);
//	a = ft_printf("%10.10Lgf", flo2);
//	printf("pf = %d\n", a);



return (0);
}
