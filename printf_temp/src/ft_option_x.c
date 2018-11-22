/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_option_d.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/12 12:38:05 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/16 07:30:54 by rgermain    ###    #+. /#+    ###.fr     */
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

static int	ft_option_neg(t_option *lst, long nb, int count, int maj)
{
	int len;

	len = 0;
	len = ft_llen_base(nb, 16);
	if (lst->af_nb > len)
		count += ft_print_prefix(len, lst->af_nb, 1);
	ft_putnbr_base_lmaj(nb, 16, maj);
	if (len < lst->af_nb)
		count += ft_print_prefix(lst->af_nb, lst->bf_nb, 0);
	else
		count += ft_print_prefix(len, lst->bf_nb, 0);
	return (count + len);
}

static int	ft_option_pos(t_option *lst, long nb, int count, int maj)
{
	int len;

	len = ft_llen_base(nb, 16);
	if (len < lst->af_nb)
		count += ft_print_prefix(lst->af_nb, lst->bf_nb, 0);
	else if (lst->bf_zero == 1 && lst->point == 0)
		count += ft_print_prefix(len, lst->bf_nb, 1);
	else
		count += ft_print_prefix(len, lst->bf_nb, 0);
	if (lst->af_nb > len)
		count += ft_print_prefix(len, lst->af_nb, lst->point);
	ft_putnbr_base_lmaj(nb, 16, maj);
	return (count + len);
}

int		ft_option_x(t_valst *lst_va, char *str, int count, int index)
{
	t_option	*lst;
	int			*total;
	int			maj;
	long		nb;

	lst = ft_put_option(str, count, index);
	maj = 0;
	if (str[count + index] == 'X')
			maj = 1;
	if (lst->dollar == 1)
		lst_va = ft_lst_init2(lst_va, lst->dollar_nb, 0);
	total = tab_2_init();
	nb = va_arg(lst_va->lst_copy, long);
	if (lst->space == 1 && nb >= 0 && lst->sign == 0
			&& lst->af_nb == 0 && lst->bf_nb == 0)
		total[1] += ft_print_prefix(0, 1, 0);
	if ((lst->point == 1 || lst->hash == 1) && nb == 0)
	{
		return (total[1]);
	}
	if (lst->hash == 1)
	{
		ft_putstr("0x");
		total[1] += 2;
	}	
	if (lst->star == 1)
	{
		if (lst->bf_nb == 0)
			lst->bf_nb = ft_abs(nb);
		nb = va_arg(lst_va->lst_copy, long);
	}
	if (lst->sign != '-')
		total[1] += ft_option_pos(lst, nb, 0, maj);
	else
		total[1] += ft_option_neg(lst, nb, 0, maj);
	return (total[1]);
}
