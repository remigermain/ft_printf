/* ************************************************************************** */
/*                                                          Le - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@Le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/19 22:28:54 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/20 14:33:21 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static void 	put_double(t_pf *lst, unsigned long nb[PF_BUFF])
{
	size_t a;

	a = 0;
	pf_itoa(lst, nb[a++]);
	if (lst->conv == 'g' || lst->conv == 'G')
	{
		while (lst->preci > 0)
		{
			if (nb[lst->preci] == 0)
					lst->preci--;
			else
				break;
		}
	}
	if (lst->preci > 0)
	{
		lst->psign = 4;
		pf_putsign(lst);
	}
	while ((a - 1) < (size_t)lst->preci)
		pf_itoa(lst, nb[a++]);
}

static void roundup_double(t_pf *lst, unsigned long nb[PF_BUFF])
{
	int a;

	a = lst->preci + 1;
	while (a > 0)
	{
		if ((nb[a] >= (lst->base / 2) && a == (lst->preci + 1)) ||
			(nb[a] >= lst->base && a > 0))
		{
			nb[a - 1] += 1;
			nb[a] = nb[a] % lst->base;
		}
		a--;
	}
}

static void 	ft_assign_double(t_pf *lst)
{
	unsigned long nb[PF_BUFF];
	size_t				a;
	int 					preci;

	a = 0;
	preci = lst->preci + 1;
	nb[a++] = lst->ul_nb;
	while (lst->preci >= 0)
	{
		lst->fl_nb *= lst->base;
		nb[a++] = (long)lst->fl_nb;
		lst->fl_nb -= (long)lst->fl_nb;
		lst->preci--;
	}
	lst->preci = preci - 1;
  roundup_double(lst, nb);
	put_double(lst, nb);
}

static void double_sufix(t_pf *lst)
{
	wuchar_t	*new;
	int				ret;
	char 			c;

	if (lst->conv == 'a' || lst->conv == 'A')
		c = (lst->maj == 1 ? 'P' : 'p');
	else
		c = (lst->maj == 1 ? 'E' : 'e');
	if ((lst->conv == 'e' || lst->conv == 'E' ||
			lst->conv == 'G') && lst->ul_nb != 0)
	{
		ret = ft_sprintf(&new, "%c%+.2d", c, lst->exposant);
		pf_stringjoin(lst, new, ret, 1);
	}
	else if (lst->conv == 'a' || lst->conv == 'A')
	{
		ret = ft_sprintf(&new, "%c%+d", c, lst->exposant);
		pf_stringjoin(lst, new, ret, 1);
	}
}

int	conv_double(t_pf *lst, char *str, int index)
{
	int 	max;
	int 	len;

	lst_putoption(lst, str, index);
	lst_putdouble(lst);
	len = ulen_base(lst->ul_nb, lst->base);
	max = len + lst->preci;
	if (lst->point == 0 || lst->preci > 0)
		max++;
	if (lst->psign != 0)
		max++;
	if (lst->zero == 1)
		pf_putsign(lst);
	pf_putprefix(lst, max, lst->field, lst->zero);
	if (lst->zero == 0)
		pf_putsign(lst);
	ft_assign_double(lst);
	pf_putprefix(lst, max, -lst->field, lst->zero);
	pf_stringjoin(lst, lst->tmp_str, lst->tmp_count, 1);
	double_sufix(lst);
	return (index + 1);
}
