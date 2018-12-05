/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_option_d.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/12 12:38:05 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/05 17:50:00 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putnbr_dlm2(t_option *lst, int count, int base)
{
	while (count < (lst->af_nb + 1))
	{
		count++;
		lst->nb3 *= base;
	}
	lst->nb3++;
	lst->nb3 /= base;
	ft_putnbr_ulm((unsigned long)lst->nb3, base, lst->maj, lst->fd);
	count--;
	return (count);
}

int		ft_putnbr_dlm3(t_option *lst, int count, int base)
{
	while (count < lst->af_nb)
	{
		lst->nb3 = (lst->nb3 - (long)lst->nb3) * base;
		ft_putnbr_ulm((unsigned long)lst->nb3, base, lst->maj, lst->fd);
		count++;
	}
	return (count);
}

int		ft_putnbr_dlm(t_option *lst)
{
	int	count;
	int base;

	count = 0;
	base = lst->base;
	if (lst->af_nb > 18)
		count = ft_putnbr_dlm3(lst, count, base);
	else
		count = ft_putnbr_dlm2(lst, count, base);
	return (count);
}

int		ft_print_end(t_option *lst)
{
	int	count;

	count = 0;
	if (lst->conv_o == 1)
	{
		if (lst->maj == 1)
			count += ft_putstr_fd("E+00", lst->fd);
		else
			count += ft_putstr_fd("e+00", lst->fd);
	}
	else if (lst->base == 16)
	{
		if (lst->maj == 1)
			count += ft_putstr_fd("P+0", lst->fd);
		else
			count += ft_putstr_fd("p+0", lst->fd);
	}
	return (count);
}
