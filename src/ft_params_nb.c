/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_params_nb.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/06 14:31:36 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/20 19:28:32 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_signcalc(t_pf *lst)
{
	int sign;

	sign = 0;
	if (lst->psign == 1 || lst->psign == 2)
		sign = 1;
	if (lst->psign == 3 || lst->psign == 5)
		sign = 2;
	if (lst->psign == 4)
		sign = 3;
	return (sign);
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

static int	ft_spacecalc(t_pf *lst, int i)
{
	if (lst->point == 1 && lst->preci >= 0)
		lst->zero = 0;
	if (lst->space == 1 && (lst->conv == 'o' || lst->conv == 'O' ||
				lst->conv == 'x' || lst->conv == 'X'))
		lst->space = 0;
	if (lst->space == 1 && lst->sign != '+' && lst->psign == 0
			&& lst->conv != 'u' && lst->conv != 'U')
	{
		i += ft_print_prefix(0, 1, 0, lst->fd);
		if (lst->field > 0)
			lst->field--;
		else if (lst->field < 0)
			lst->field++;
	}
	return (i);
}

static int	ft_option_nb(t_pf *lst, int i)
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
	i = ft_spacecalc(lst, i);
	max = ft_max2(len, lst->preci) + sign;
	if (lst->zero == 1)
		i += ft_print_sign(lst);
	i += ft_print_prefix(max + index, lst->field, lst->zero, lst->fd);
	if (lst->zero == 0)
		i += ft_print_sign(lst);
	i += ft_print_prefix(0, index, 1, lst->fd);
	i += ft_print_prefix(len, lst->preci, 1, lst->fd);
	if ((!(lst->point == 1 && lst->preci == 0 && lst->ul_nb == 0)) &&
			lst->local == 1)
		i += ft_putnbr_ulm(lst->ul_nb, lst->base, lst->maj, lst->fd);
	else if ((!(lst->point == 1 && lst->preci == 0 && lst->ul_nb == 0)))
		i += ft_putnbr_ulm3(lst, lst->ul_nb, 0, 0);
	i += ft_print_prefix(max, -lst->field, 0, lst->fd);
	return (i);
}

int			ft_params_nb(t_valst *lst_va, char *str, int i, int index)
{
	t_pf	*lst;

	lst = lst_initoption(lst_va, str, i, index);
	ft_initnb(lst, lst_va);
	lst_va->count += ft_option_nb(lst, 0);
	free(lst);
	return (index + 1);
}
