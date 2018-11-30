/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putchar.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 14:24:30 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/30 17:45:53 by rgermain    ###    #+. /#+    ###.fr     */
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

int		ft_putwchar2(unsigned int c)
{
	char new[4];
	int a;

	a = 0;
	if (c <= 0x7F)
		new[a++] = c;
	else if (c <= 0x7FF)
		new[a++] = 192 + (c / 64);
	else
		exit (0);
	if (c > 0x7F)
		new[a++] = 128 + (c % 64);
	write(1, new, a);
	return (a);
}
int		ft_putwchar(unsigned int c)
{
	return (ft_putwchar_fd(c, 1));
}

int		ft_putwchar_fd(unsigned int c, int fd)
{
	char new[4];
	int a;

	a = 0;
	if (c <= 0x7F)
		new[a++] = c;
	else if (c <= 0x7FF)
		new[a++] = 192 + (c / 64);
	else
	{
		if (c > 0xFFFF)
		{
			new[a++] = 240 + (c / 262144);
			new[a++] = 128 + ((c / 4096) % 64);
		}
		else
			new[a++] = 224 + (c / 4096);
		new[a++] = 128 + ((c / 64) % 64);
	}
	if (c > 0x7F)
		new[a++] = 128 + (c % 64);
	write(fd, new, a);
	return (a);
}

int	ft_putchar(char c)
{
	write(1, &c, sizeof(c));
	return (1);
}
