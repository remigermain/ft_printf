

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


	a = printf("42%56lc42", (char)9876);
	printf("pf = %0d\n", a);
	a = ft_printf("42%56lc42", (char)9876);
	printf("ft = %0d\n", a);

	a = printf("%6C et coco %C titi %C tyty", 3250, 0xd800, 'u');
	printf("pf = %0d\n", a);
	a = ft_printf("%6C et coco %C titi %C tyty", 3250, 0xd800, 'u');

	a = printf("%ls, %ls", L"ÊM-^ZM-^VÁM-^BM-^I", L"ŸM-^Dÿ≠ŸM-^E ÿÆŸM-^Fÿ≤ŸM-ÿ±");
	printf(" pf = %d\n", a);
	a  = ft_printf("%ls, %ls", L"ÊM-^ZM-^VÁM-^BM-^I", L"ŸM-^Dÿ≠ŸM-^E ÿÆŸM-^Fÿ≤ŸM-ÿ±");
	printf(" ft = %d\n", a);

	a = printf("%-2.4ls", L"最終的なフラッシュ");
	printf("pf %d\n", a);
	a = ft_printf("%-2.4ls", L"最終的なフラッシュ");
	printf("ft %d\n", a);

a = printf("%S", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
	printf("pf %d\n", a);
a = ft_printf("%S", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
	printf("ft %d\n", a);



	ft_printf("%C", L'ÁM-^L´');

	a = printf("%C", L'ÁM-^L´');
	printf("pf = %0d\n", a);
	a = ft_printf("%C", L'ÁM-^L´');
	printf("ft = %0d\n", a);

	a = printf("% x|%+x", 42, 42);
	printf("pf = %0d\n", a);
	a = ft_printf("% x|%+x", 42, 42);
	printf("pf = %0d\n", a);

	a = printf("%hhD, %hhD", 0, USHRT_MAX);
	printf("pf = %0d\n", a);
	a = ft_printf("%hhD, %hhD", 0, USHRT_MAX);
	printf("pf = %0d\n", a);


	a = printf("0!% 018.0i!", 433288652);
printf("pf %d\n", a);
	a = ft_printf("0!% 018.2i!",433288652);
printf("ft %d\n", a);
	return (0);





}
