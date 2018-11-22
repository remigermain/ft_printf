/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_option_d.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/12 12:38:05 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/16 09:05:54 by rgermain    ###    #+. /#+    ###.fr     */
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

static int	ft_option_neg(t_option *lst, unsigned long int nb, int count)
{
	int pos;
	int len;

	pos = 0;
	len = 0;
	if (lst->sign == '+')
		pos = 1;
	len = ft_ullen(nb) + pos;
	if (lst->af_nb > ft_intlen(nb))
		count += ft_print_prefix(ft_ullen(nb), lst->af_nb, 1);
	ft_putulnbr(nb);
	if (len < lst->af_nb)
		count += ft_print_prefix(lst->af_nb + pos, lst->bf_nb, 0);
	else
		count += ft_print_prefix(len, lst->bf_nb, 0);
	return (count + len);
}

static int	ft_option_pos(t_option *lst, unsigned long int nb, int count)
{
	int pos;
	int len;

	pos = 0;
	len = 0;
	if (lst->sign == '+')
		pos = 1;
	len = ft_ullen(nb) + pos;
	if (len < lst->af_nb)
		count += ft_print_prefix(lst->af_nb + pos, lst->bf_nb, 0);
	else if (lst->bf_zero == 1 && lst->point == 0)
		count += ft_print_prefix(len, lst->bf_nb, 1);
	else
		count += ft_print_prefix(len, lst->bf_nb, 0);
	if (lst->af_nb > ft_ullen(nb))
		count += ft_print_prefix(ft_ullen(nb), lst->af_nb, lst->point);
	ft_putulnbr(nb);
	return (count + len);
}

int		ft_option_u2(t_valst *lst_va, char *str, int count, int index)
{
	t_option		*lst;
	int				*total;
	unsigned long int	nb;

	lst = ft_put_option(str, count, index);
	if (lst->dollar == 1)
		lst_va = ft_lst_init2(lst_va, lst->dollar_nb, 0);
	total = tab_2_init();
   	nb = va_arg(lst_va->lst_copy, unsigned long int);
	if (lst->space == 1 && lst->sign == 0
			&& lst->af_nb == 0 && lst->bf_nb == 0)
		nb += ft_print_prefix(0, 1, 0);
	if (lst->star == 1)
	{
		if (lst->bf_nb == 0)
			lst->bf_nb = nb;
		nb = va_arg(lst_va->lst_copy, long long int);
	}
	if (lst->sign != '-')
		total[1] += ft_option_pos(lst, nb, 0);
	else
		total[1] += ft_option_neg(lst, nb, 0);
	return (total[1]);
}
