/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_params_nb.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/06 14:31:36 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/19 15:25:55 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_option_nb(t_pf *lst, int i)
{
	int len;
	int max;
	int sign;
	int index;

	len = ft_ulen_base(lst->ul_nb, lst->base);
	sign = ft_signcalc(lst);
	if (lst->ul_nb == 0 && lst->point == 1 && lst->preci == 0)
		len = 0;
	index = ft_hashcalc(lst, 0, len);
	i = ft_spacecalc(lst, len, i);
	max = ft_max2(len, lst->preci) + sign;
	if (lst->zero == 1)
		i += ft_print_sign(lst);
	i += ft_print_prefix(max + index, lst->field, lst->zero, lst->fd);
	if (lst->zero == 0)
		i += ft_print_sign(lst);
	i += ft_print_prefix(0, index, 1, lst->fd);
	i += ft_print_prefix(len, lst->preci, 1, lst->fd);
	if ((!(lst->point == 1 && lst->preci == 0 && lst->ul_nb == 0)))
		i += ft_putnbr_ulm(lst->ul_nb, lst->base, lst->maj, lst->fd);
	i += ft_print_prefix(max, -lst->field, 0, lst->fd);
	return (i);
}

int		ft_params_nb(t_valst *lst_va, char *str, int i, int index)
{
	t_pf	*lst;
	int		count;

	count = 0;
	lst = lst_initoption(lst_va, str, i, index);
	ft_initnb(lst, lst_va);
	ft_signprefix(lst);
	count = ft_option_nb(lst, 0);
	lst_va->count += count;
	free(lst);
	return (index + 1);
}
