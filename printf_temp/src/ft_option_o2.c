/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_option_d.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/12 12:38:05 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/16 09:04:09 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_prefix(int len, int nb, int point)
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

static int	ft_option_neg(t_option *lst, unsigned long nb, int count)
{
	int len;

	len = 0;
	len = ft_ullen_base(nb, 8);
	if (lst->af_nb > ft_ullen_base(nb, 8))
		count += ft_print_prefix(ft_ullen_base(nb, 8), lst->af_nb, lst->point);
	ft_putulnbr_base(nb, 8);
	if (len < lst->af_nb)
		count += ft_print_prefix(lst->af_nb, lst->bf_nb, 0);
	else
		count += ft_print_prefix(len, lst->bf_nb, 0);
	return (count + len);
}

static int	ft_option_pos(t_option *lst, unsigned long nb, int count)
{
	int len;

	len = ft_ullen_base(nb, 8);
	if (len < lst->af_nb)
		count += ft_print_prefix(lst->af_nb, lst->bf_nb, 0);
	else
		count += ft_print_prefix(len, lst->bf_nb, 0);
	if (lst->af_nb > ft_ullen_base(nb, 8))
		count += ft_print_prefix(ft_ullen_base(nb, 8), lst->af_nb, lst->point);
	ft_putulnbr_base(nb, 8);
	return (count + len);
}

int			ft_option_o2(t_valst *lst_va, char *str, int count, int index)
{
	t_option	*lst;
	unsigned long		nb;

	lst = ft_put_option(str, count, index);
	count = 0;
	if (lst->dollar == 1)
		lst_va = ft_lst_init2(lst_va, lst->dollar_nb, 0);
	nb = va_arg(lst_va->lst_copy, unsigned long);
	if (lst->space == 1 && lst->sign == 0
			&& lst->af_nb == 0 && lst->bf_nb == 0)
		count += ft_print_prefix(0, 1, 0);
	if (lst->hash == 1 && nb != 0)
		count += ft_print_prefix(0, 1, 1);
	if (lst->point == 1 && nb == 0)
	{
		if (lst->hash == 1)
		{
			ft_putchar('0');
			return (count + 1);
		}
		else
			return (count);
	}
	if (lst->star == 1)
	{
		if (lst->bf_nb == 0)
			lst->bf_nb = ft_abs(nb);
		nb = va_arg(lst_va->lst_copy, unsigned long);
		lst->point = 1;
		count += ft_option_neg(lst, nb, 0);
	}
	else if (lst->sign != '-')
		count += ft_option_pos(lst, nb, 0);
	else
		count += ft_option_neg(lst, nb, 0);
	return (count);
}
