

#include "ft_printf.h"

int main()
{
	int a = 0;
/*	a = printf("{%s}", 0);
	printf("pf = %d\n", a);
	a = ft_printf("{%s}", 0);
	printf("ft = %d\n", a);
*/
/*
	printf("{%03.2d}", 0);
	printf("pf = %d\n", a);
	ft_printf("{%03.2d}", 0);
	printf("ft = %d\n", a);
	*/
	 a = printf("%15.4s", "42");
	printf("pf = %d\n", a);
	 a = ft_printf("%15.4s", "42");
	printf("ft = %d\n", a);
	return (0);
}
