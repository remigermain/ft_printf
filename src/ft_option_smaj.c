/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_option_d.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/12 12:38:05 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/27 20:08:43 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_option_neg(t_option *lst, char *new, int count)
{
	int len;
	int max;
	int min;

	len = ft_strlen(new);
	max = ft_max2(len, lst->af_nb);
	min = ft_min2(len, lst->af_nb);
	if (lst->point == 1)
	{
		count += ft_putnstr_w(new, lst->af_nb);
		count += ft_print_prefix(min, lst->bf_nb, 0);
	}
	else
	{
		count += ft_putstr_w(new);
		count += ft_print_prefix(max, lst->bf_nb, 0);
	}
	return (count);
}

static int	ft_option_pos(t_option *lst, char *new, int count)
{
	int len;
	int max;
	int min;

	len = ft_strlen(new);
	max = ft_max2(len, lst->af_nb);
	min = ft_min2(len, lst->af_nb);
	if (lst->point == 1)
	{
		count += ft_print_prefix(min, lst->bf_nb, lst->bf_zero);
		count += ft_putnstr_w(new, lst->af_nb);
	}
	else
	{
		count += ft_print_prefix(max, lst->bf_nb, lst->bf_zero);
		count += ft_putstr_w(new);
	}
	return (count);
}

int			ft_option_smaj(t_valst *lst_va, char *str, int count, int index)
{
	t_option	*lst;
	char		*new;
	int			len;

	len = 0;
	lst = ft_put_option(str, count, index);
	if (lst->dollar == 1)
		lst_va = lst_init2(lst_va, lst->dollar_nb, 0);
	ft_option_star(lst_va, lst);
	new = va_arg(lst_va->lst_copy, char*);
	lst->af_nb = ft_abs(lst->af_nb);
	if (new == NULL)
		new = "(null)";
	if (lst->sign != '-')
		len += ft_option_pos(lst, new, 0);
	else
		len += ft_option_neg(lst, new, 0);
	return (len);
}

int			*ft_params_smaj(t_valst *lst_va, char *str, int *tab_i, int index)
{
	tab_i[1] += ft_option_smaj(lst_va, str, tab_i[0], index);
	tab_i[0] = ((tab_i[0] + index) + 1);
	return (tab_i);
}
