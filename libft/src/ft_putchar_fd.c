/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putchar_fd.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 14:07:14 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/30 21:11:36 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

int	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, fd);
	return (1);
}

int	ft_putwchar_fd(unsigned int c, int fd)
{
	char	new[4];
	int		a;

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