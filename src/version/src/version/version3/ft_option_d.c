/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_option_d.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/12 12:38:05 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/14 11:08:43 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_option_d3(int nb, int nb_l, int point)
{
	while (nb < nb_l--)
	{
		if (point == 1)
			ft_putchar('0');
		else
			ft_putchar(' ');
	}
}
	
void	ft_option_d1(t_option *lst, int nb)
{
	int	tmp_nb;

	tmp_nb = lst->nb;
	if (lst->sign == '-' && (ft_intlen(nb) < lst->nb) && lst->point == 1 && nb < 0)
	{
		nb = -nb;
		ft_putchar('-');
	}
//	else if (lst->nb > ft_intlen(nb))
//		ft_putnbr(nb);
	ft_option_d3(ft_intlen(nb), lst->nb, lst->point);
	if (tmp_nb > ft_intlen(nb)) 
		ft_putnbr(nb);
}

void	ft_option_d2(t_option *lst, int nb)
{
	if (lst->sign == '+' && nb >= 0 && lst->point == 1)
		ft_putchar('+');
	if (nb < 0 && lst->point == 1)
	{
		nb = -nb;
		ft_putchar('-');
	}
	ft_option_d3(ft_intlen(nb), lst->nb, lst->point);
	if (lst->sign == '+' && nb >= 0 && lst->point == 0)
		ft_putchar('+');
	ft_putnbr(nb);
}

void	ft_option_nb_init(t_option *lst, int nb)
{
	if (lst->sign == '+' && lst->point == 0 && nb >= 0)
		lst->nb--;
	else if (lst->point == 1 && lst->nb < 0)
		lst->nb++;
}
	
int		ft_option_d(t_valst *lst_va, char *str, int count, int index)
{
	t_option	*lst;
	t_valst		*lst2;
	int			nb;
	int			nb2;
	int			total;

	lst = ft_put_option(str, count, index);
	if (lst->dollar == 1)
	{
		lst_va = ft_lst_init2(lst_va, lst->dollar_nb, 0);
		nb = va_arg(lst_va->lst_copy, int);
	}
	else
		nb = va_arg(lst_va->lst_copy, int);
	total = ft_calcul_lst(lst, nb);
	ft_option_nb_init(lst, nb);
	if (lst->space == 1 && nb >= 0 
			&& lst->nb <= ft_intlen(nb) && lst->sign == 0)
		ft_putchar(' ');
	if (lst->star == 1)
	{
		nb2 = nb;
		nb = va_arg(lst_va->lst_copy, int);
		if (lst->star_pos == 0)
		{
			if (ft_intlen(nb) < lst->nb)
				nb2 -= (lst->nb);
			else
				nb2 -= (ft_intlen(nb));
			if (lst->sign == '+')
				nb2--;
			if (lst->sign != '-')
				ft_option_d3(0, nb2 , 0);
			total += (nb2);
		}
		else
			lst->nb = nb2;
	}
	if (lst->sign == '-')
		ft_option_d1(lst, nb);
	else
		ft_option_d2(lst, nb);
	if (lst->star == 1 && lst->star_pos == 0 && lst->sign == '-')
				ft_option_d3(0, nb2 , 0);
	return (total);
}
