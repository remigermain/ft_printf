/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils4.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/27 20:49:03 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/20 14:33:42 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_ulm(t_pf *lst, unsigned long nb, int i, int first)
{
	unsigned long	j;
	int				len;

	j = 1;
	while (j < nb)
		j *= lst->base;
	len = ft_ulen_base(nb, lst->base);
	while (len > 0)
	{
		nb %= j;
		j /= lst->base;
		if (((len % 3) == 0) && first == 1)
			i += ft_putchar_fd('\'', lst->fd);
		if ((nb / j) < 10)
			i += ft_putchar_fd((nb / j) + '0', lst->fd);
		else if (lst->maj == 1)
			i += ft_putchar_fd((nb / j) + 55, lst->fd);
		else
			i += ft_putchar_fd((nb / j) + 87, lst->fd);
		first = lst->local;
		len--;
	}
	return (i);
}

int	ft_putnbr_ul(t_pf *lst, unsigned long nb)
{
	return (ft_putnbr_ulm(lst, nb, 0, 0));
}

int	ft_ulen_base(unsigned long nb, size_t base)
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

int	ft_ulen(unsigned long nb)
{
	return (ft_ulen_base(nb, 10));
}
