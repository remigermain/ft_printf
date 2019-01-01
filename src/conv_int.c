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

static int	ft_hashcalc(t_pf *lst, int index, int len)
{
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
	if (lst->space == 1 && (lst->conv == 'o' || lst->conv == 'O' ||
				lst->conv == 'x' || lst->conv == 'X'))
		lst->space = 0;
	if (lst->space == 1 && lst->sign != '+' && lst->psign == 0
			&& lst->conv != 'u' && lst->conv != 'U')
	{
		put_prefix(lst, 0, 1, 0);
		if (lst->field > 0)
			lst->field--;
		else if (lst->field < 0)
			lst->field++;
	}
}

int			conv_int(t_pf *lst, char *str, int index)
{
	int len;
	int max;
	int sign;

	lst_putoption(lst, str, index);
	lst_putint(lst);
	len = ulen_base(lst->ul_nb, lst->base);
	sign = ((lst->sign == 3) ? 2 : (lst->sign == 0 ? 0 : 1));
	if (lst->ul_nb == 0 && lst->point == 1 && lst->preci == 0)
		len = 0;
	lst->hash = ft_hashcalc(lst, 0, len);
	ft_spacecalc(lst);
	max = ft_max2(len, lst->preci) + sign;
	if (lst->zero == 1)
		put_sign(lst);
	put_prefix(lst, max + lst->hash, lst->field, lst->zero);
	if (lst->zero == 0)
		put_sign(lst);
	put_prefix(lst, 0, lst->hash, 1);
	put_prefix(lst, len, lst->preci, 1);
	if (!(lst->point == 1 && lst->preci == 0 && lst->ul_nb == 0))
			put_itoa(lst, lst->ul_nb);
	put_prefix(lst, max, -lst->field, 0);
	return (index + 1);
}
