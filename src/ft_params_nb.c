/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_params_nb.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/06 14:31:36 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/20 19:35:17 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_signcalc(t_pf *lst)
{
	if (lst->psign == 1 || lst->psign == 2)
		return (1);
	else if (lst->psign == 3)
		return (2);
	return (0);
}

static int	ft_hashcalc(t_pf *lst, int index, int len)
{
	if (lst->hash == 1 && (lst->conv == 'u' || lst->conv == 'U'))
		lst->hash = 0;
	if (lst->hash == 1 && (lst->conv == 'o' || lst->conv == 'O'))
	{
		if (lst->ul_nb == 0 && lst->point == 1 && lst->preci > 0)
			return (0);
		if (lst->point == 0 && lst->ul_nb == 0)
			return (0);
		index = 1;
		if ((lst->point == 1 && lst->preci > len))
		{
			if (lst->preci != 0)
				lst->preci--;
		}
		if (lst->field < 0)
			lst->field++;
	}
	return (index);
}

static void	ft_spacecalc(t_pf *lst)
{
	if (lst->point == 1 && lst->preci >= 0)
		lst->zero = 0;
	if (lst->space == 1 && (lst->conv == 'o' || lst->conv == 'O' ||
				lst->conv == 'x' || lst->conv == 'X'))
		lst->space = 0;
	if (lst->space == 1 && lst->sign != '+' && lst->psign == 0
			&& lst->conv != 'u' && lst->conv != 'U')
	{
		ft_putprefix(lst, 0, 1, 0);
		if (lst->field > 0)
			lst->field--;
		else if (lst->field < 0)
			lst->field++;
	}
}

static void	ft_option_nb(t_pf *lst)
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
	ft_spacecalc(lst);
	max = ft_max2(len, lst->preci) + sign;
	if (lst->zero == 1)
		ft_print_sign(lst);
	ft_putprefix(lst, max + index, lst->field, lst->zero);
	if (lst->zero == 0)
		ft_print_sign(lst);
	ft_putprefix(lst, 0, index, 1);
	ft_putprefix(lst, len, lst->preci, 1);
	if (!(lst->point == 1 && lst->preci == 0 && lst->ul_nb == 0))
			pf_itoa(lst, lst->ul_nb);
	ft_putprefix(lst, max, -lst->field, 0);
}

int			ft_params_nb(t_valst *lst_va, char *str, int index)
{
	t_pf	*lst;

	lst = lst_initoption(lst_va, str, index);
	ft_initnb(lst, lst_va);
	ft_option_nb(lst);
	pf_finaljoin(lst_va, lst->str, lst->count);
	free(lst->str);
	free(lst);
	return (index + 1);
}
