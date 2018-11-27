/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putchar.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 14:24:30 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/27 18:12:02 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"


int		ft_min2(int nb1, int nb2)
{
	if (nb1 > nb2)
		return (nb2);
	return (nb1);
}

int		ft_max2(int nb1, int nb2)
{
	if (nb1 < nb2)
		return (nb2);
	return (nb1);
}

void	ft_putwchar(unsigned int c)
{
	char new[4];
	int a;

	a = 0;
	if (c <= 0x7F)
		new[a++] = c;
	else if (c > 0xFFFF)
	{
		if (c > 0x10FFFF)
		{
			new[a++] = (240 + c) / 262144;
			new[a++] = ((128 + c) / 4096) % 64;
		}
		else if (c < 0xFFFF)
			new[a++] = (224 + c) / 4096;
		new[a++] = ((128 + c) / 64) % 64;
	}
	if (c > 0x7F)
		new[a++] = (128 + c) % 64;
	write(1, new, a);
}

void	ft_putchar(char c)
{
	write(1, &c, sizeof(c));
}
