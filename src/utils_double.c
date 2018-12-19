/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_option_d.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/12 12:38:05 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/19 22:09:20 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_calcul_len2(t_pf *lst, int len, int index)
{
	int sign;
	int max;

	sign = 0;
	max = 0;
	if (index == 1)
	{
		if (lst->point == 1)
			max = len + lst->preci;
		else
			max = len + 6;
		return (max);
	}
	else
	{
		if ((lst->point == 1 && lst->preci > 0) || lst->point == 0)
			sign++;
		if (lst->sign != 0)
			sign++;
		return (sign);
	}
}

static int	ft_putnbr_dlm2(t_pf *lst, int count, int base)
{
	int len;

	len = 0;
	while (count < (lst->preci))
	{
		count++;
		lst->fl_nb *= base;
		if ((long)(lst->fl_nb * base) == 0 && count < (lst->preci))
			len += ft_putchar_fd('0', lst->fd);
	}
	if (((long)lst->fl_nb % lst->base) >= (lst->base / 2))
		lst->fl_nb++;
	if (lst->lenght != 0 && lst->conv != 'a')
		lst->fl_nb /= base;
	if (len < count)
		ft_putnbr_ulm((unsigned long)lst->fl_nb, base, lst->maj, lst->fd);
	return (count);
}

static int	ft_putnbr_dlm3(t_pf *lst, int count, int base)
{
	while (count < lst->preci)
	{
		lst->fl_nb = (lst->fl_nb - (long)lst->fl_nb) * base;
		ft_putnbr_ulm((unsigned long)lst->fl_nb, base, lst->maj, lst->fd);
		count++;
	}
	return (count);
}

int			ft_putnbr_dlm(t_pf *lst)
{
	int	count;
	int base;

	count = 0;
	base = lst->base;
	if (lst->preci > 18)
		count = ft_putnbr_dlm3(lst, count, base);
	else
		count = ft_putnbr_dlm2(lst, count, base);
	return (count);
}
