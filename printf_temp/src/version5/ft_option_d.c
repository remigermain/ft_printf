/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_option_d.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/12 12:38:05 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/15 16:58:33 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_prefix(int len, int nb, int point)
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

int		ft_option_neg(t_option *lst, int nb, int count)
{
	int neg;
	int pos;
	int len;

	neg = 0;
	pos = 0;
	len = 0;
	if (nb < 0)
		neg = 1;
	nb = ft_abs(nb);
	if (lst->sign == '+' && neg == 0)
		pos = 1;
	len = ft_intlen(nb) + pos + neg;
	if (neg == 1)
		ft_putchar('-');
	else if (pos == 1)
		ft_putchar('+');
	if (lst->af_nb > ft_intlen(nb))
		count += ft_print_prefix(ft_intlen(nb), lst->af_nb, lst->point);
	ft_putnbr(nb);
	if (len < lst->af_nb)
		count += ft_print_prefix(lst->af_nb + pos + neg, lst->bf_nb, 0);
	else
		count += ft_print_prefix(len, lst->bf_nb, 0);
	return (count + len);
}

int		ft_option_pos(t_option *lst, int nb, int count)
{
	int neg;
	int pos;
	int len;

	neg = 0;
	pos = 0;
	len = 0;
	if (nb < 0)
		neg = 1;
	nb = ft_abs(nb);
	if (lst->sign == '+' && neg == 0)
		pos = 1;
	len = ft_intlen(nb) + pos + neg;
	if (len < lst->af_nb)
		count += ft_print_prefix(lst->af_nb + pos + neg, lst->bf_nb, 0);
	else
		count += ft_print_prefix(len, lst->bf_nb, 0);
	if (neg == 1)
		ft_putchar('-');
	else if (pos == 1)
		ft_putchar('+');
	if (lst->af_nb > ft_intlen(nb))
		count += ft_print_prefix(ft_intlen(nb), lst->af_nb, lst->point);
	ft_putnbr(nb);
	return (count + len);
}

int		ft_option_d(t_valst *lst_va, char *str, int count, int index)
{
	t_option	*lst;
	int			*total;

	lst = ft_put_option(str, count, index);
	if (lst->dollar == 1)
		lst_va = ft_lst_init2(lst_va, lst->dollar_nb, 0);
//	total = tab_2_init();
	total[0] = va_arg(lst_va->lst_copy, int);
	if (lst->space == 1 && total[0] >= 0 && lst->sign == 0
			&& lst->af_nb == 0 && lst->bf_nb == 0)
	{
		total[1]++;
		ft_putchar(' ');
	}
	if (lst->star == 1)
	{
		if (lst->bf_nb == 0)
			lst->bf_nb = ft_abs(total[0]);
		total[0] = va_arg(lst_va->lst_copy, int);
		lst->point = 1;
		total[1] += ft_option_neg(lst, total[0], 0);
	}
	else if (lst->sign != '-')
		total[1] += ft_option_pos(lst, total[0], 0);
	else
		total[1] += ft_option_neg(lst, total[0], 0);
	return (total[1]);
}
