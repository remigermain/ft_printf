/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils4.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/27 20:49:03 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/06 18:14:07 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_ulm(unsigned long nb, size_t base, size_t maj, size_t fd)
{
	if (nb >= base)
	{
		ft_putnbr_ulm((nb / base), base, maj, fd);
		ft_putnbr_ulm((nb % base), base, maj, fd);
	}
	else if (nb < 10)
		ft_putchar_fd(nb + '0', fd);
	else if (maj == 1)
		ft_putchar_fd(nb + 55, fd);
	else
		ft_putchar_fd(nb + 87, fd);
}

void	ft_putnbr_ul(unsigned long nb, size_t fd)
{
	ft_putnbr_ulm(nb, 10, 1, fd);
}

int		ft_ulen_base(unsigned long nb, size_t base)
{
	int count;

	count = 0;
	while (nb >= base)
	{
		nb /= base;
		count++;
	}
	return (count + 1);
}

int		ft_ulen(unsigned long nb)
{
	return (ft_ulen_base(nb, 10));
}
