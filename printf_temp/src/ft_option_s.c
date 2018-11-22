/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_option_d.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/12 12:38:05 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/20 22:05:37 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_prefix(int len, int nb, int point)
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

static int	ft_option_neg(t_option *lst, char *new, int count)
{
	int len;

	len = ft_strlen(new);
	if (lst->point == 0)
		count += ft_putstr(new);
	else
		count += ft_putnstr(new, lst->af_nb);
	len = ft_strlen(new);
	if (lst->point == 1)
		count += ft_prefix(ft_nbmin(lst->af_nb, len), lst->bf_nb, 0);
	else
		count += ft_prefix(ft_nbmax(lst->af_nb, len), lst->bf_nb, 0);
	return (count);
}

static int	ft_option_pos(t_option *lst, char *new, int count)
{
	int len;

	len = ft_strlen(new);
	if (lst->point == 1)
		count += ft_prefix(ft_nbmin(lst->af_nb, len), lst->bf_nb, lst->bf_zero);
	else
		count += ft_prefix(ft_nbmax(lst->af_nb, len), lst->bf_nb, lst->bf_zero);
	if (lst->point == 0)
		count += ft_putstr(new);
	else
		count += ft_putnstr(new, lst->af_nb);
	return (count);
}

int			ft_option_s(t_valst *lst_va, char *str, int count, int index)
{
	t_option	*lst;
	char		*new;
	int			nb;

	lst = ft_put_option(str, count, index);
	count = 0;
	if (lst->dollar == 1)
		lst_va = ft_lst_init2(lst_va, lst->dollar_nb, 0);
	if (lst->space == 1 && lst->sign == 0
			&& lst->af_nb == 0 && lst->bf_nb == 0)
		count += ft_prefix(0, 1, 0);
	if (lst->star == 1)
	{
		nb = va_arg(lst_va->lst_copy, int);
		if (nb > lst->bf_nb && nb != 0)
			lst->bf_nb = nb;
	}
	new = va_arg(lst_va->lst_copy, char*);
	if (new == NULL)
		new = "(null)";
	if (lst->sign != '-')
		count += ft_option_pos(lst, new, 0);
	else
		count += ft_option_neg(lst, new, 0);
	return (count);
}
