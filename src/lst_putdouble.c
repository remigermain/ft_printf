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

static void	lst_putdouble_pos(t_pf *lst, long double nb, unsigned long coef)
{
	while (((coef * lst->base) < (unsigned long)nb) && nb != 0)
	{
		coef *= lst->base;
		lst->exponent++;
	}
	lst->ul_nb = (unsigned long)nb / coef;
	lst->ful_nb = nb - (lst->ul_nb * coef);
	lst->fl_nb = nb - (unsigned long)nb;
}

static void	lst_putdouble_neg(t_pf *lst, long double nb, unsigned long coef)
{
	while (((unsigned long)(coef * nb) <= 0) && nb != 0)
	{
		coef *= lst->base;
		lst->exponent--;
	}
	lst->ul_nb = (unsigned long)(nb * coef);
	lst->fl_nb = (nb * coef) - lst->ul_nb;
}

static void	lst_putdouble_main(t_pf *lst, long double nb)
{
	if (lst->point == 0)
		lst->preci = 6;
	if ((lst->conv == 'f' || lst->conv == 'F') || (lst->conv == 'g' && lst->preci >= ulen_base(nb, lst->base)))
	{
		lst->ul_nb = (unsigned long)nb;
		lst->fl_nb = nb - (unsigned long)nb;
	}
	else if ((unsigned long)nb > 0)
		lst_putdouble_pos(lst, nb, 1);
	else
		lst_putdouble_neg(lst, nb, 1);
	if (lst->point == 0 && (lst->conv == 'e' || lst->conv == 'E'))
		lst->preci = ft_max2(6, ft_abs(lst->exponent));
}

void	lst_putdouble(t_pf *lst)
{
	long double nb;

	if (lst->lenght == 100000)
		nb = va_arg(lst->va_copy, long double);
	else
		nb = (long double)va_arg(lst->va_copy, double);
	if (nb < 0)
	{
		nb = -nb;
		lst->psign = 1;
	}
	else if (nb >= 0 && lst->sign == '+')
		lst->psign = 2;
	lst_putdouble_main(lst, nb);
}
