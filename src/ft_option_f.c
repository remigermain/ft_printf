/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_option_d.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/12 12:38:05 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/05 17:44:29 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_calcul_len2(t_option *lst, int len, int index)
{
	int sign;
	int max;

	sign = 0;
	max = 0;
	if (index == 1)
	{
		if (lst->point == 1)
			max = len + lst->af_nb;
		else
			max = len + 6;
		return (max);
	}
	else
	{
		if ((lst->point == 1 && lst->af_nb > 0) || lst->point == 0)
			sign++;
		if (lst->sign != 0)
			sign++;
		return (sign);
	}
}

static int	ft_option_neg(t_option *lst, int count)
{
	int len;
	int sign;
	int max;

	sign = 0;
	len = ft_ulen_base(lst->nb, lst->base);
	max = ft_calcul_len2(lst, len, 1);
	sign = ft_calcul_len2(lst, len, 0);
	count += ft_print_sign(lst);
	if (lst->zero == 1)
		count += ft_print_prefix(max + sign, lst->bf_nb, 1, lst->fd);
	ft_putnbr_ulm(lst->nb, lst->base, lst->maj, lst->fd);
	if (lst->af_nb > 0 || lst->point == 0)
	{
		lst->bf_nb--;
		count += ft_putchar_fd('.', lst->fd);
	}
	if (lst->point == 0 || lst->flag_l == 1)
		count += ft_print_prefix(0, lst->af_nb, 1, lst->fd);
	else if (lst->af_nb > 0)
		count += ft_putnbr_dlm(lst);
	if ((lst->point == 1 || lst->point == 0) && lst->zero == 0)
		count += ft_print_prefix(max, lst->bf_nb, 0, lst->fd);
	return (count + len);
}

static int	ft_option_pos(t_option *lst, int count)
{
	int len;
	int sign;
	int max;

	sign = 0;
	len = ft_ulen_base(lst->nb, lst->base);
	max = ft_calcul_len2(lst, len, 1);
	sign = ft_calcul_len2(lst, len, 0);
	if ((lst->point == 1 || lst->point == 0) && lst->zero == 0)
		count += ft_print_prefix(max + sign, lst->bf_nb, 0, lst->fd);
	count += ft_print_sign(lst);
	if (lst->zero == 1)
		count += ft_print_prefix(max + sign, lst->bf_nb, 1, lst->fd);
	ft_putnbr_ulm(lst->nb, lst->base, lst->maj, lst->fd);
	if (lst->af_nb > 0 || lst->point == 0)
		count += ft_putchar_fd('.', lst->fd);
	count += ft_putnbr_dlm(lst);
	return (count + len);
}

void		ft_init_double(t_option *lst, t_valst *lst_va)
{
	int			a;
	long double nb;

	a = 6;
	if (lst->flag_l == 1)
		nb = va_arg(lst_va->lst_copy, long double);
	else
		nb = (long double)va_arg(lst_va->lst_copy, double);
	if (lst->sign == '+' && (long)nb > 0)
		lst->psign = 2;
	else if (nb < 0)
	{
		lst->psign = 1;
		nb = -nb;
	}
	if (lst->point == 0)
		lst->af_nb = 6;
	lst->nb = (unsigned long)nb;
	lst->nb3 = (nb - (long)nb);
}

int			*ft_params_f(t_valst *lst_va, char *str, int *tab_i, int index)
{
	t_option	*lst;
	int			count;

	lst = ft_put_option(lst_va, str, tab_i[0], index);
	count = 0;
	ft_init_double(lst, lst_va);
	if (lst->base == 16)
		lst->psign = 3;
	if (lst->sign != '-')
		count = ft_option_pos(lst, count);
	else
		count = ft_option_neg(lst, count);
	count += ft_print_end(lst);
	tab_i[1] += count;
	tab_i[0] += (index + 1);
	return (tab_i);
}
