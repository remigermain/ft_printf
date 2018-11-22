/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_option_d.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/12 12:38:05 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/20 22:05:32 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_option_neg(t_option *lst, int nb, int count)
{
	int len;
	int sign;
	int max;

	sign = 0;
	len = ft_intlen(nb);
	max = ft_max2(len, lst->af_nb);
	if (nb < 0)
		sign = 1;
	ft_print_sign(nb, lst->sign);
	if (lst->point == 1 || lst->af_nb == 0)
		count += ft_print_prefix(len, lst->af_nb, 1);
	else
		count += ft_print_prefix(len, lst->bf_nb, 1);
	ft_putnbr2(nb);
	if (lst->point == 1 || lst->af_nb == 0)
		count += ft_print_prefix(max + sign, lst->bf_nb, 0);
	return (count + len + sign);
}

static int	ft_option_pos(t_option *lst, int nb, int count)
{
	int len;
	int sign;
	int max;

	sign = 0;
	len = ft_intlen2(nb);
	max = ft_max2(len, lst->af_nb);
	if (nb < 0 || (lst->sign == '+' && nb >= 0))
		sign++;
	if (lst->bf_zero != 1 || lst->point == 1)
		count += ft_print_prefix(max + sign, lst->bf_nb, 0);
	ft_print_sign(nb, lst->sign);
	if (lst->bf_zero != 1 || lst->point == 1)
		count += ft_print_prefix(len, lst->af_nb, 1);
	else
		count += ft_print_prefix(len + sign, lst->bf_nb, 1);
	ft_putnbr2(nb);
	return (count + len + sign);
}

int		ft_option_d(t_valst *lst_va, char *str, int count, int index)
{
	t_option	*lst;
	int			nb;
	int			len;

	len = 0;
	lst = ft_put_option(str, count, index);
	if (lst->dollar == 1)
		lst_va = lst_init2(lst_va, lst->dollar_nb, 0);
	ft_option_star(lst_va, lst);
	nb = va_arg(lst_va->lst_copy, int);
	if (lst->space == 1 && nb >= 0 && lst->sign == 0
			&& lst->af_nb == 0 && lst->af_nb == 0)
	{
		lst->bf_nb--;
		len += ft_print_prefix(0, 1, 0);
	}
	if ((lst->sign != '-') &&
			(!(lst->point == 1 && lst->af_nb == 0 && nb == 0)))
		len += ft_option_pos(lst, nb, 0);
	else if (!(lst->point == 1 && lst->af_nb == 0 && nb == 0))
		len += ft_option_neg(lst, nb, 0);
	return (len);
}

int		*ft_params_d(t_valst *lst_va, char *str, int *tab_i, int index)
{
	tab_i[1] += ft_option_d(lst_va, str, tab_i[0], index);
	tab_i[0] = ((tab_i[0] + index) + 1);
	return (tab_i);
}
