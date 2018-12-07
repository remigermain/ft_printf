/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_params_nb.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/06 14:31:36 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/07 16:31:23 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_op(t_pf *lst)
{
	int len;
	int max;
	int sign;
	int i;

	len = ft_ulen_base(lst->ul_nb, lst->base);
	sign = 0;
	i = 0;
	if (lst->psign == 1 || lst->psign == 2)
		sign = 1;
	if (lst->psign == 3 || lst->psign == 5)
		sign = 2;
	if (lst->psign == 4)
		sign = 3;
	if (lst->space == 1)
	{
		i += ft_print_prefix(0, 1, 0, lst->fd);
		lst->preci--;
	}
	max = ft_max2(len, lst->preci) + sign;
	if (lst->hash == 1 && lst->point == 1 && lst->field > max)
	{
		if ((lst->preci - 1) > len)
		;//	lst->preci--;
		else if (lst->field > max)
			lst->field--;
	}
	else if (lst->hash == 1 && lst->point == 0)
		lst->field--;
	i += ft_print_prefix(max, lst->field, 0, lst->fd);
	i += ft_print_sign(lst);
	if ((lst->hash == 1 && lst->point == 1 && lst->field > 0) || 
		(lst->hash == 1 && lst->point == 0))
		i += ft_print_prefix(0, 1, 1, lst->fd);
	i += ft_print_prefix(len, lst->preci, 1, lst->fd);
	ft_putnbr_ulm(lst->ul_nb, lst->base, lst->maj, lst->fd);
	i += ft_print_prefix(max, -lst->field, 0, lst->fd);
	return (i + len);
}

int		ft_params_nb(t_valst *lst_va, char *str, int i, int index)
{
	t_pf 	*lst;
	int count;

	count = 0;
	lst = lst_initoption(lst_va, str, i, index);
	ft_initnb(lst, lst_va);
	ft_signprefix(lst);
//	debug(lst);
//	sleep(2);
	count = ft_print_op(lst);
	lst_va->count += count;
	return (index + 1);
}
