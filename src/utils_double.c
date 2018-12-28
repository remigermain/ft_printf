/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_option_d.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/12 12:38:05 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/20 19:35:00 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void 		ft_printdouble(t_pf *lst, unsigned long nb[PF_BUFF])
{
	int a;

	a = 0;
	pf_itoa(lst, nb[a++]);
	while (lst->preci-- > 0)
	{
		if (a == 1)
			pf_tmpjoin(lst, ".", 1);
		pf_itoa(lst, nb[a++]);
	}
}

void ft_double_roundup(t_pf *lst, unsigned long nb[PF_BUFF])
{
	int a;

	a = lst->preci + 1;
	dprintf(1, "preci = %d\n", nb[a - 1]);
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
