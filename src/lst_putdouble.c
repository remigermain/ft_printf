/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lst_putdouble.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/04 16:25:11 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/04 16:25:13 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static void	lst_putdouble_pos(t_pf *lst, long double nb, ulong_t coef)
{
	while (((coef * BASE) < (ulong_t)nb) && nb != 0)
	{
		dprintf(1, "ddd\n");
		coef *= BASE;
		EXPONENT++;
	}
	lst->ul_nb = (ulong_t)nb / coef;
	lst->ful_nb = nb - (lst->ul_nb * coef);
	lst->fl_nb = nb - (ulong_t)nb;
}

static void	lst_putdouble_neg(t_pf *lst, long double nb, ulong_t coef)
{
	while (((ulong_t)(coef * nb) <= 0) && nb != 0)
	{
		dprintf(1, "ddd\n");
		coef *= BASE;
		EXPONENT--;
	}
	lst->ul_nb = (ulong_t)(nb * coef);
	lst->fl_nb = (nb * coef) - lst->ul_nb;
}

static void	lst_putdouble_main(t_pf *lst, long double nb)
{
	if (POINT == 0)
		PRECI = 6;
	if ((CONV == 'f' || CONV == 'F') || (CONV == 'g' &&
			PRECI >= ulen_base(nb, BASE)))
	{
		lst->ul_nb = (ulong_t)nb;
		lst->fl_nb = nb - (ulong_t)nb;
	}
	else if ((ulong_t)nb > 0)
		lst_putdouble_pos(lst, nb, 1);
	else
		lst_putdouble_neg(lst, nb, 1);
	if (POINT == 0 && (CONV == 'e' || CONV == 'E'))
		PRECI = MAX(6, ABS(EXPONENT));
}

void		lst_putdouble(t_pf *lst)
{
	long double nb;

	if (LENGHT == 100000)
		nb = va_arg(lst->va_copy, long double);
	else
		nb = (long double)va_arg(lst->va_copy, double);
	if (nb < 0)
	{
		nb = -nb;
		PSIGN = 1;
	}
	else if (nb >= 0 && SIGN == '+')
		PSIGN = 2;
	if ((ulong_t)nb > 9223372036854775807)
		lst->ul_nb = (ulong_t)nb;
	else
		lst_putdouble_main(lst, nb);
}
