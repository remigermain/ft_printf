

#include "ft_printf.h"

int main()
{
	int a = 0;

	 a = printf("%015s", "");
	printf("pf = %0d\n", a);
	 a = ft_printf("%015s", "");
	printf("ft = %0d\n", a);
	
	 a = printf("%0.-40s", "");
	printf("pf = %0d\n", a);
	 a = ft_printf("%0.-40s", "");
	printf("ft = %0d\n", a);
	
	 a = printf("%0s", "");
	printf("pf = %0d\n", a);
	 a = ft_printf("%0s", "");
	printf("ft = %0d\n", a);
	
	 a = printf("%0-15.-40s", "");
	printf("pf = %0d\n", a);
	 a = ft_printf("%0-15.-40s", "");
	printf("ft = %0d\n", a);
	
	 a = printf("%015.--40s", "dscdscdsc");
	printf("pf = %0d\n", a);
	 a = ft_printf("%015.--40s", "dscdscdsc");
	printf("ft = %0d\n", a);
	
	 a = printf("%015.s", "");
	printf("pf = %0d\n", a);
	 a = ft_printf("%015.s", "");
	printf("ft = %0d\n", a);

	a = printf("% o|%+o", 42, 42);
	printf("pf = %0d\n", a);
	a = ft_printf("% o|%+o", 42, 42);
	printf("ft = %0d\n", a);

	a = printf("{%03.1d}", 0);
	printf("pf = %0d\n", a);
	a = ft_printf("{%03.1d}", 0);
	printf("ft = %0d\n", a);

	a = printf("%D", -1L);
	printf("pf = %0d\n", a);
	a = ft_printf("%D", -1L);
	printf("ft = %0d\n", a);

	a = printf("% x|%+x", 42, 42);
	printf("pf = %0d\n", a);
	a = ft_printf("% x|%+x", 42, 42);
	printf("pf = %0d\n", a);

	a = printf("%hhD, %hhD", 0, USHRT_MAX);
	printf("pf = %0d\n", a);
	a = ft_printf("%hhD, %hhD", 0, USHRT_MAX);
	printf("pf = %0d\n", a);

	a = printf("{%}");
printf("pf %d\n", a);
	a = ft_printf("{%}");
printf("ft %d\n", a);




	a = printf("0!% 018.0i!", 433288652);
printf("pf %d\n", a);
	a = ft_printf("0!% 018.2i!",433288652);
printf("ft %d\n", a);
	return (0);






}
