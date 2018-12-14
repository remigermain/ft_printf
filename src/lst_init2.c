/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_params_nb.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/06 14:31:36 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/14 10:10:42 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_signcalc(t_pf *lst)
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

int	ft_hashcalc(t_pf *lst, int index, int len)
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

int	ft_spacecalc(t_pf *lst, int len, int i)
{
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
