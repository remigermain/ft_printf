/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_option_d.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/12 12:38:05 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/14 13:54:42 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putnbr_dlm2(t_pf *lst, int count, int base)
{
	while (count < (lst->preci ))
	{
		count++;
		lst->fl_nb *= base;
	}
	lst->fl_nb++;
	ft_putnbr_ulm((unsigned long)lst->fl_nb, base, lst->maj, lst->fd);
	count--;
	return (count);
}

int		ft_putnbr_dlm3(t_pf *lst, int count, int base)
{
	while (count < lst->preci)
	{
		lst->fl_nb = (lst->fl_nb - (long)lst->fl_nb) * base;
		ft_putnbr_ulm((unsigned long)lst->fl_nb, base, lst->maj, lst->fd);
		count++;
	}
	return (count);
}

int		ft_putnbr_dlm(t_pf *lst)
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
