/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_option_d.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/12 12:38:05 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/13 22:13:01 by rgermain    ###    #+. /#+    ###.fr     */
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
	
void	ft_option_d1(t_option *lst, va_list lst_va, int nb)
{
	int	tmp_nb;

	tmp_nb = lst->nb;
	if (lst->sign == '-' && (ft_intlen(nb) < lst->nb) && lst->point == 1)
	{
		nb = -nb;
		ft_putchar('-');
	}
	else if (lst->nb > ft_intlen(nb))
		ft_putnbr(nb);
	ft_option_d3(ft_intlen(nb), lst->nb, lst->point);
	if (tmp_nb < ft_intlen(nb)) 
		ft_putnbr(nb);
}

void	ft_option_d2(t_option *lst, va_list lst_va, int nb)
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
	
int		ft_option_d(va_list lst_va, char *str, int count, int index)
{
	t_option	*lst;
	int			nb;
	int			total;

	nb = va_arg(lst_va, int);
	lst = ft_put_option(str, count, index);
	total = ft_calcul_lst(lst, nb);
	ft_option_nb_init(lst, nb);
	if (lst->space == 1 && nb >= 0 
			&& lst->nb <= ft_intlen(nb) && lst->sign == 0)
		ft_putchar(' ');
	if (lst->star == 1)
	{
		ft_option_d3(0, nb, 0);
		nb = va_arg(lst_va, int);
	}
	if (lst->sign == '-')
		ft_option_d1(lst, lst_va, nb);
	else
		ft_option_d2(lst, lst_va, nb);
	return (total);
}
