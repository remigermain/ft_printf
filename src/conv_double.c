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

static void put_double(t_pf *lst, ulong_t nb[BUFF_FLOAT], size_t i)
{
	wuchar_t	*new;
	size_t 		max;
	int				ret;
	char 			c;

	put_itoa(lst, nb[i++]);
	if (lst->preci > 0)
		put_buff(lst, ".", 1, 0);
	while ((i - 1) < (size_t)lst->preci)
		put_itoa(lst, nb[i++]);
	if (lst->conv != 'f' && lst->conv != 'F' &&
			lst->conv != 'g' && lst->conv != 'G')
	{
		c = (lst->maj == 1 ? 'E' : 'e');
		max = ((lst->conv == 'a' || lst->conv == 'A') ? 1 : 2);
		ret = ft_sprintf(&new, "%c%+.*d", c, max,lst->exponent);
		put_buff(lst, new, ret, 1);
	}
}

static void roundup_double(t_pf *lst, ulong_t nb[BUFF_FLOAT], int i, int max)
{
	i = lst->preci + 2;
	max = lst->preci + 2;
	while (i > 0)
	{
		if ((nb[i] >= (lst->base / 2) && (i == max || i == (max - 1))) ||
			(nb[i] >= lst->base && i > 0))
		{
			nb[i - 1] += 1;
			nb[i] = nb[i] % lst->base;
		}
		i--;
	}
	if (lst->conv == 'g' || lst->conv == 'G')
	{
		i = lst->preci;
		while (i > 1)
		{
			if (nb[i] == 0)
				lst->preci--;
			else
				break;
			i--;
		}
	}
	put_double(lst, nb, 0);
}

static void 	assign_double(t_pf *lst, size_t i, int j)
{
	ulong_t nb[BUFF_FLOAT];
	size_t 				preci;

	preci = lst->preci + 2;
	nb[i++] = lst->ul_nb;
	j = (lst->ful_nb != 0 ? ulen_base(lst->ful_nb, lst->base) : 0);
	i += j;
	while (j > 0)
	{
		nb[j--] = lst->ful_nb % lst->base;
		lst->ful_nb /= lst->base;
	}
	while (preci > 0)
	{
		lst->fl_nb *= lst->base;
		nb[i++] = (int)lst->fl_nb;
		lst->fl_nb -= (int)lst->fl_nb;
		preci--;
	}
	roundup_double(lst, nb, 0, 0);
}

static int max_calc(t_pf *lst, int max)
{
	if (lst->space == 1 && lst->sign != '+' && lst->psign == 0)
	{
		put_prefix(lst, 0, 1, 0);
		if (lst->field > 0)
			lst->field--;
		else if (lst->field < 0)
			lst->field++;
	}
	if (lst->ul_nb > 9223372036854775807)
		max = 3;
	else
	{
		if ((lst->conv == 'g' || lst->conv == 'G') && lst->ul_nb != 0)
			lst->preci--;
		max = ulen_base(lst->ul_nb, lst->base) + lst->preci;
		max += (lst->psign != 0 ? 1 : 0);
		max += ((lst->point == 0 || lst->preci > 0) ? 1 : 0);
		if (lst->conv != 'f' && lst->conv != 'F' &&
			lst->conv != 'g' && lst->conv != 'G')
			max += 2 + MAX(ulen_base(ABS(lst->exponent), lst->base), 2);
	}
	return (max);
}


int	conv_double(t_pf *lst, char *str, int index)
{
	int 	max;

	lst_putoption(lst, str, index);
	lst_putdouble(lst);
	max = max_calc(lst, 0);
	if (lst->zero == 1)
		put_sign(lst);
	put_prefix(lst, max, lst->field, lst->zero);
	if (lst->zero == 0)
		put_sign(lst);
	if (lst->ul_nb > 9223372036854775807)
		put_buff(lst, ft_ustrdup((wuchar_t*)("nan")), 3, 1);
	else
		assign_double(lst, 0, 0);
	put_prefix(lst, max, -lst->field, 0);
	return (index + 1);
}
