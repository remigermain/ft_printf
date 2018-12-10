/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_params_nb.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/06 14:31:36 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/10 16:17:38 by rgermain    ###    #+. /#+    ###.fr     */
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
	if (lst->hash == 1 && lst->conv == 'u')
		lst->hash = 0;
	if (lst->hash == 1 && lst->conv != 'd' && lst->conv != 'x'
			&& lst->conv != 'X')
	{
		lst->zero = 0;
		if (lst->preci <= len || lst->ul_nb != 0)
		{
			index = 1;
			if (lst->point == 1 && lst->preci != 0)
				lst->preci--;
			else if (lst->point != 1)
			{
				if (lst->ul_nb == 0)
					index = 0;
				else if (lst->field > 0)
					lst->field--;
				else if (lst->field < 0)
					lst->field++;
			}
		}
	}
	return (index);
}

int	ft_spacecalc(t_pf *lst, int len, int i)
{
	if (lst->space == 1 && lst->psign != 1)
	{
		i += ft_print_prefix(0, 1, 0, lst->fd);
		if (lst->field > 0)
			lst->field--;
		else
			lst->field++;
	}
	return (i);
}
