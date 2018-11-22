/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_option_d.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/12 12:38:05 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/16 07:43:59 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_prefix(int len, long nb, int point)
{
	int count;

	count = 0;
	while (len < nb)
	{
		if (point == 1)
			ft_putchar('0');
		else
			ft_putchar(' ');
		count++;
		nb--;
	}
	return (count);
}

static int	ft_option_neg(t_option *lst, long nb, int count)
{
	int len;

	len = 0;
	len = ft_llen_base(nb, 16);
	ft_putstr("0x");
	if (lst->af_nb > len + 2)
		count += ft_print_prefix(len + 2, lst->af_nb, 1);
	ft_putnbr_base_lmaj(nb, 16, 0);
	if (len < lst->af_nb)
		count += ft_print_prefix(lst->af_nb, lst->bf_nb, 0);
	else
		count += ft_print_prefix(len + 2, lst->bf_nb, 0);
	return (count + len + 2);
}

static int	ft_option_pos(t_option *lst, long nb, int count)
{
	int len;

	len = ft_llen_base(nb, 16);
	if (len < lst->af_nb)
		count += ft_print_prefix(lst->af_nb, lst->bf_nb, 0);
	else if (lst->bf_zero == 1 && lst->point == 0)
	{
		ft_putstr("0x");
		count += ft_print_prefix(len, lst->bf_nb, 1);
	}
	else
		count += ft_print_prefix(len, lst->bf_nb, 0);
	if (lst->bf_zero != 1)
		ft_putstr("0x");
	if (lst->af_nb > len)
		count += ft_print_prefix(len, lst->af_nb, lst->point);
	ft_putnbr_base_lmaj(nb, 16, 0);
	return (count + len + 2);
}

int		ft_option_p(t_valst *lst_va, char *str, int count, int index)
{
	t_option	*lst;
	int			*total;
	long		nb;

	lst = ft_put_option(str, count, index);
	if (lst->dollar == 1)
		lst_va = ft_lst_init2(lst_va, lst->dollar_nb, 0);
	total = tab_2_init();
	nb = va_arg(lst_va->lst_copy, long);
	if (lst->point == 1 && nb == 0 && lst->af_nb == 0)
	{
		ft_putstr("0x");
		return (total[1] += 2);
	}
	if (nb == 0)
		lst->af_nb += 2;
	if (lst->space == 1 && nb >= 0 && lst->sign == 0
			&& lst->af_nb == 0 && lst->bf_nb == 0)
		total[1] += ft_print_prefix(0, 1, 0);
	if (lst->star == 1)
	{
		if (lst->bf_nb == 0)
			lst->bf_nb = ft_abs(nb);
		nb = va_arg(lst_va->lst_copy, long);
	}
	if (lst->sign != '-')
		total[1] += ft_option_pos(lst, nb, 0);
	else
		total[1] += ft_option_neg(lst, nb, 0);
	return (total[1]);
}
