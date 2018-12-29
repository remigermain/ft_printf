/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_params_f.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/11 20:46:44 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/20 19:33:33 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static void 		ft_printdouble(t_pf *lst, unsigned long nb[PF_BUFF])
{
	int a;

	a = 0;
	pf_itoa(lst, nb[a++]);
	while (lst->preci-- > 0)
	{
		if (a == 1)
			pf_stringjoin(lst, ".", 1, 0);
		pf_itoa(lst, nb[a++]);
	}
}

static void ft_double_roundup(t_pf *lst, unsigned long nb[PF_BUFF])
{
	int a;

	a = lst->preci + 1;
	if (a != 0 && nb[a] >= (lst->base / 2))
		nb[a - 1]++;
	a--;
	while ((a + 1) != 0)
	{
		if (a > 0 && ft_ulen_base(nb[a], lst->base) > 1)
		{
			nb[a - 1]++;
			nb[a] %= lst->base;
		}
		a--;
	}
}

static void 	ft_assign_double(t_pf *lst, int count)
{
	unsigned long nb[PF_BUFF];
	int						a;
	int 					preci;

	a = 0;
	preci = lst->preci;
	nb[a++] = lst->ul_nb;
	while (lst->preci-- > 0)
	{
		lst->fl_nb *= lst->base;
		if (lst->preci == 0 &&
			((long)(lst->fl_nb * lst->base) % lst->base) > 5)
			nb[a++] = (long)(lst->fl_nb) + 1;
		else
			nb[a++] = (long)lst->fl_nb;
		lst->fl_nb -= (long)lst->fl_nb;
	}
	lst->preci = preci;
  ft_double_roundup(lst, nb);
	ft_printdouble(lst, nb);
}

static void	ft_initdouble(t_pf *lst)
{
	long double nb;

	if (lst->lenght == 100000)
		nb = va_arg(lst->va_copy, long double);
	else
		nb = (long double)va_arg(lst->va_copy, double);
	if (lst->point == 0)
		lst->preci = 6;
	lst->ul_nb = (unsigned long)nb;
	lst->fl_nb = nb - (unsigned long)nb;
	if (lst->preci == 0 && (int)(lst->fl_nb * lst->base) > 5)
		lst->ul_nb++;
}

int	ft_params_double(t_pf *lst, char *str, int index)
{
	int 	max;
	int 	len;

	lst_putoption(lst, str, index);
	ft_initdouble(lst);
	len = ft_ulen_base(lst->ul_nb, lst->base);
	max = len + lst->preci;
	if (lst->point == 0 || lst->preci > 0)
		max++;
	pf_putprefix(lst, max, lst->field, lst->zero);
	ft_assign_double(lst, 0);
	return (index + 1);
}
