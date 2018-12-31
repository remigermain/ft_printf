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
	if (lst->conv == 'g' || lst->conv == 'G')
		lst->conv = 'G';
	while (((coef * lst->base) < (unsigned long)nb) && nb != 0)
	{
		coef *= lst->base;
		lst->exposant += 1;
	}
	lst->ul_nb = (unsigned long)nb / coef;
	lst->fl_nb = ((nb - (lst->ul_nb * coef)) / coef);
}

static void	lst_putdouble_neg(t_pf *lst, long double nb, unsigned long coef)
{
	if (lst->conv == 'g' || lst->conv == 'G')
		lst->conv = 'G';
	while (((unsigned long)(coef * nb) <= 0) && nb != 0)
	{
		coef *= lst->base;
		lst->exposant -= 1;
	}
	lst->ul_nb = (unsigned long)(nb * coef);
	lst->fl_nb = (nb * coef) - lst->ul_nb;

}

void	lst_putdouble(t_pf *lst)
{
	long double nb;

	if (lst->lenght == 100000)
		nb = va_arg(lst->va_copy, long double);
	else
		nb = (long double)va_arg(lst->va_copy, double);
  if ((lst->conv == 'f' || lst->conv == 'F') ||
	((lst->conv == 'g' || lst->conv == 'G') && nb > 0.0001))
  {
		if (lst->conv == 'g' || lst->conv == 'G')
			lst->conv = 'g';
	  lst->ul_nb = (unsigned long)nb;
	  lst->fl_nb = nb - (unsigned long)nb;
  }
  else if ((unsigned long)nb > 0)
    lst_putdouble_pos(lst, nb, 1);
	else
		lst_putdouble_neg(lst, nb, 1);
	if (lst->point == 0)
		lst->preci = 6;
	if ((lst->conv == 'g' || lst->conv == 'G') && lst->ul_nb != 0)
		lst->preci = ft_abs(lst->preci - ulen_base(lst->ul_nb, lst->base));
}
