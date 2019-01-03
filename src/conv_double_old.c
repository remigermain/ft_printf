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

static  void zero(t_pf *lst, ulong_t nb[BUFF_FLOAT])
{
	size_t i;

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

static void put_double(t_pf *lst, ulong_t nb[BUFF_FLOAT])
{
	size_t i;

	i = 0;
	put_itoa(lst, nb[i++]);
	if (lst->conv == 'g' || lst->conv == 'G')
		zero(lst, nb);
	if (lst->preci > 0)
	{
		lst->psign = 4;
		put_sign(lst);
	}
	while ((i - 1) < (size_t)lst->preci)
		put_itoa(lst, nb[i++]);
}

static void roundup_double(t_pf *lst, ulong_t nb[BUFF_FLOAT])
{
	size_t i;
	size_t max;

	i = lst->preci + 1;
	max = lst->preci + 1;
	while (i > 0)
	{
		if ((nb[i] >= (lst->base / 2) && i == max) ||
			(nb[i] >= lst->base && i > 0))
		{
			nb[i - 1] += 1;
			nb[i] = nb[i] % lst->base;
		}
		i--;
	}
}

static void 	ft_assign_double(t_pf *lst, size_t i, size_t j, size_t k)
{
	ulong_t nb[BUFF_FLOAT];
	size_t preci;

	preci = lst->preci + 1;
	nb[i++] = lst->ul_nb;
	if (lst->exponent > 0)
		j = ulen_base(lst->ful_nb, lst->base);
	while (k < j)
	{
		nb[i + ulen_base(lst->ful_nb, lst->base) - 1] = lst->ful_nb % lst->base;
		lst->ful_nb /= lst->base;
		k++;
	}
	preci = MAX(preci - j, 0);
	i += j;
	while (preci > 0)
	{
		lst->fl_nb *= lst->base;
		nb[i++] = (int)lst->fl_nb % lst->base;
		lst->fl_nb -= (int)lst->fl_nb;
		preci--;
	}
	if ((ft_abs(lst->exponent) >= lst->preci) || lst->conv == 'f' || lst->conv == 'F' ||
lst->conv == 'g' || lst->conv == 'G')
		roundup_double(lst, nb);
	put_double(lst, nb);
}

static void double_sufix(t_pf *lst)
{
	wuchar_t	*new;
	int				ret;
	char 			c;

	c = (lst->maj == 1 ? 'E' : 'e');
	if ((lst->conv == 'e' || lst->conv == 'E' ||
			lst->conv == 'g' || lst->conv == 'G') && lst->preci <= ft_abs(lst->exponent))
	{
		ret = ft_sprintf(&new, "%c% .2d", c, lst->exponent);
		put_buff(lst, new, ret, 0);
	}
}

void preci(t_pf *lst)
{
	long double tmp;

	tmp = lst->fl_nb;
	while ((int)(tmp * lst->base) == 0)
	{
		tmp *= lst->base;
		lst->preci++;
	}
}

int	conv_double(t_pf *lst, char *str, int index)
{
	int 	max;
	int 	len;

	lst_putoption(lst, str, index);
	lst_putdouble(lst);
	if (lst->conv != 'f' && lst->conv != 'F')
		preci(lst);
	if (lst->conv == 'g' || lst->conv == 'G')
		len = ulen_base(lst->ul_nb, lst->base);
	else
		len = ulen_base(lst->ul_nb, lst->base);
	if ((lst->conv == 'g' || lst->conv == 'G') && (lst->exponent < -4 || (ft_abs(lst->exponent) >= lst->preci)))
		lst->preci = MIN(ft_abs(lst->exponent), lst->preci);

	max = len + lst->preci;
	if ((lst->conv == 'g' || lst->conv == 'G') && (lst->exponent < -4 || (ft_abs(lst->exponent) >= lst->preci)))
		max += 2 + MAX(ulen_base(ft_abs(lst->exponent), 10), 1);
	else if ((lst->conv == 'e' || lst->conv == 'E') && lst->exponent != 0)
		max += 2 + MAX(ulen_base(ft_abs(lst->exponent), 10), 2);
	if (lst->psign != 0)
		max++;
	if (lst->point == 0 || lst->preci > 0)
		max++;
	if (lst->space == 1 && lst->sign != '+' && lst->psign == 0)
	{
			put_prefix(lst, 0, 1, 0);
			if (lst->field > 0)
				lst->field--;
			else if (lst->field < 0)
				lst->field++;
	}
	if (lst->zero == 1)
		put_sign(lst);
	put_prefix(lst, max, lst->field, lst->zero);
	if (lst->zero == 0)
		put_sign(lst);
	ft_assign_double(lst, 0, 0, 0);
	put_prefix(lst, max, -lst->field, 0);
	double_sufix(lst);
	return (index + 1);
}
