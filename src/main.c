#include <stdio.h>
#include "ft_printf.h"
#include <math.h>

int main()
{
	long double nb = pow(1024, 1024);
	long double nb1 = sqrt(-1);
	long double nb2 = 1556818.164894984;

	printf("   %Lg\n", nb);
	ft_printf("   %Lg\n\n", nb);
	printf("   %Lg\n", nb1);
	ft_printf("   %Lg\n\n", nb1);
	printf("   %Lg\n", nb2);
	ft_printf("   %Lg\n\n", nb2);
	
	return (0);
}
