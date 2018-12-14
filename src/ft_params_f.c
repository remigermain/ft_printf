/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_params_f.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/11 20:46:44 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/14 10:22:39 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_calcul_len2(t_pf *lst, int len, int index)
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

static int	ft_pf_pos(t_pf *lst, int count)
{
	int len;
	int sign;
	int max;

	sign = 0;
	len = ft_ulen_base(lst->ul_nb, lst->base);
	max = ft_calcul_len2(lst, len, 1);
	sign = ft_calcul_len2(lst, len, 0);
	if (lst->zero == 1)
		count += ft_print_sign(lst);
	count += ft_print_prefix(max + sign, lst->field, lst->zero, lst->fd);
	if (lst->zero == 0)
		count += ft_print_sign(lst);
	ft_putnbr_ulm(lst->ul_nb, lst->base, lst->maj, lst->fd);
	if (lst->preci > 0 || lst->point == 0)
	{
		count += ft_putchar_fd('.', lst->fd);
		count += ft_putnbr_dlm(lst);
	}
	count += ft_print_prefix(max + sign, -lst->field, 1, lst->fd);
	return (count + len);
}

void		ft_init_double(t_pf *lst, t_valst *lst_va)
{
	int			a;
	long double nb;

	a = 6;
	if (lst->lenght == 10)
		nb = va_arg(lst_va->copy, long double);
	else
		nb = (long double)va_arg(lst_va->copy, double);
	if (lst->sign == '+' && (long)nb > 0)
		lst->psign = 2;
	else if (nb < 0)
	{
		lst->psign = 1;
		nb = -nb;
	}
	if (lst->point == 0)
		lst->preci = 6;
	lst->ul_nb = (unsigned long)nb;
	lst->fl_nb = (nb - (long)nb);
}

int			ft_params_f(t_valst *lst_va, char *str, int i, int index)
{
	t_pf	*lst;
	int		count;

	lst = lst_initoption(lst_va, str, i, index);
	count = 0;
	ft_init_double(lst, lst_va);
	if (lst->base == 16)
		lst->psign = 3;
	count += ft_pf_pos(lst, count);
	lst_va->count += count;
	return (index) + 1;
}
