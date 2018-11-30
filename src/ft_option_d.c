/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_option_d.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/12 12:38:05 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/30 22:19:17 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_option_neg(t_option *lst, int count)
{
	int len;
	int sign;
	int max;

	sign = 0;
	len = ft_ulen_base(lst->nb, lst->base);
	max = ft_prefmax(lst);
	if (lst->psign == 1)
		sign = 1;
	if (lst->conv_p)
		sign = 2;
	ft_print_sign(lst);
	if (lst->point == 1 || lst->af_nb == 0)
		count += ft_print_prefix(len, lst->af_nb, 1, lst->fd);
	else
		count += ft_print_prefix(len, lst->bf_nb, 1, lst->fd);
	ft_putnbr_ulm(lst->nb, lst->base, lst->maj, lst->fd);
	if (lst->point == 1 || lst->af_nb == 0)
		count += ft_print_prefix(max + sign, lst->bf_nb, 0, lst->fd);
	return (count + len + sign);
}

static int	ft_option_pos(t_option *lst, int count)
{
	int len;
	int sign;
	int max;

	sign = 0;
	len = ft_ulen_base(lst->nb, lst->base);
	max = ft_prefmax(lst);
	if (lst->psign == 1 || (lst->sign == '+' && lst->psign != 1))
		sign++;
	if (lst->conv_p)
		sign = 2;
	if (lst->bf_zero != 1 || lst->point == 1)
		count += ft_print_prefix(max + sign, lst->bf_nb, 0, lst->fd);
	ft_print_sign(lst);
	if (lst->bf_zero != 1 || lst->point == 1)
		count += ft_print_prefix(len, lst->af_nb, 1, lst->fd);
	else
		count += ft_print_prefix(len + sign, lst->bf_nb, 1, lst->fd);
	ft_putnbr_ulm(lst->nb, lst->base, lst->maj, lst->fd);
	return (count + len + sign);
}

static int	ft_option_pref(t_option *lst, int len, int index)
{
	if (lst->space == 1 && lst->psign != 1 && lst->sign == 0)
	{
		lst->bf_nb--;
		len += ft_print_prefix(0, 1, 0, lst->fd);
	}
	if (lst->hash == 1 && (index > 2 || lst->nb != 0) && lst->conv_d == 0)
	{
		if (lst->af_nb > 0)
			lst->af_nb--;
		else if (lst->bf_nb > 0)
			lst->bf_nb--;
		if (lst->base != 16)
			len += ft_putstr("0");
		else if (lst->maj == 1)
			len += ft_putstr("0X");
		else
			len += ft_putstr("0x");
	}
	return (len);
}

static int	ft_option_d(t_option *lst, int index)
{
	int len;

	len = ft_option_pref(lst, 0, index);
	if ((lst->sign != '-') &&
			(!(lst->point == 1 && lst->af_nb == 0 && lst->nb == 0)))
		len += ft_option_pos(lst, 0);
	else if (!(lst->point == 1 && lst->af_nb == 0 && lst->nb == 0))
		len += ft_option_neg(lst, 0);
	else
		len += ft_print_sign(lst);
	return (len);
}

int			*ft_params_d(t_valst *lst_va, char *str, int *tab_i, int index)
{
	t_option	*lst;
	int			nb;
	int			len;

	len = 0;
	lst = ft_put_option(lst_va, str, tab_i[0], index);
	ft_initnb(lst, lst_va);
	tab_i[1] += ft_option_d(lst, index);
	tab_i[0] = ((tab_i[0] + index) + 1);
	return (tab_i);
}
