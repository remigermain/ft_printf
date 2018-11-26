/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_option_d.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/12 12:38:05 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/26 19:06:28 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_option_neg(t_option *lst, unsigned int nb, int count)
{
	int len;
	int max;

	len = ft_uintlen_base(nb, 16);
	max = ft_max2(len, lst->af_nb);
	if (lst->point == 1 || lst->af_nb == 0)
		count += ft_print_prefix(len, lst->af_nb, 1);
	else
		count += ft_print_prefix(len, lst->bf_nb, 1);
	ft_putunbr_base_maj(nb, 16, 0);
	if (lst->point == 1 || lst->af_nb == 0)
		count += ft_print_prefix(max, lst->bf_nb, 0);
	return (count + len);
}

static int	ft_option_pos(t_option *lst, unsigned int nb, int count)
{
	int len;
	int max;

	len = ft_uintlen_base(nb, 16);
	max = ft_max2(len, lst->af_nb);
	if (lst->bf_zero != 1 || lst->point == 1)
		count += ft_print_prefix(max, lst->bf_nb, 0);
	if (lst->bf_zero != 1 || lst->point == 1)
		count += ft_print_prefix(len, lst->af_nb, 1);
	else
		count += ft_print_prefix(len, lst->bf_nb, 1);
	ft_putunbr_base_maj(nb, 16, 0);
	return (count + len);
}

int			ft_option_x(t_valst *lst_va, char *str, int count, int index)
{
	t_option		*lst;
	unsigned int	nb;
	int				len;

	len = 0;
	lst = ft_put_option(str, count, index);
	if (lst->dollar == 1)
		lst_va = lst_init2(lst_va, lst->dollar_nb, 0);
	ft_option_star(lst_va, lst);
	nb = va_arg(lst_va->lst_copy, unsigned int);
	if (lst->space == 1 && lst->sign == 0
			&& lst->af_nb == 0 && lst->af_nb == 0)
	{
		lst->bf_nb--;
		len += ft_print_prefix(0, 1, 0);
	}
	if (lst->hash == 1 && nb != 0)
		len += ft_putstr("0x");
	if ((lst->sign != '-') &&
			(!(lst->point == 1 && lst->af_nb == 0 && nb == 0)))
		len += ft_option_pos(lst, nb, 0);
	else if (!(lst->point == 1 && lst->af_nb == 0 && nb == 0))
		len += ft_option_neg(lst, nb, 0);
	return (len);
}

int			*ft_params_x(t_valst *lst_va, char *str, int *tab_i, int index)
{
	tab_i[1] += ft_option_x(lst_va, str, tab_i[0], index);
	tab_i[0] = ((tab_i[0] + index) + 1);
	return (tab_i);
}
