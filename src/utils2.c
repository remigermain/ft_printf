/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils2.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/20 16:06:08 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/20 22:05:06 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_prefix(int len, int nb, int point)
{
	int count;

	count = 0;
	while (len < nb)
	{
		if (point == 1)
			ft_putchar('0');
		else
			ft_putchar(' ');
		count++;
		nb--;
	}
	return (count);
}

void	ft_print_sign(int nb, int sign)
{
	if (nb < 0)
		ft_putchar('-');
	else if (nb >= 0 && sign == '+')
		ft_putchar('+');
}

void	ft_option_star2(t_option *lst, int nb)
{
	if (lst->star_pos == 1)
		lst->af_nb = ft_max2(lst->bf_nb, nb);
	else if (lst->star_bf == 0)
	{
		if ((ft_abs(nb) > 0 && lst->bf_nb == 0) || nb == 0)
			lst->bf_nb = ft_max2(lst->bf_nb, ft_abs(nb));
		else
			lst->bf_nb = ft_min2(lst->bf_nb, ft_abs(nb));
	}
	else if (nb >= 0)
		lst->bf_nb = ft_abs(nb);
}

void	ft_option_star(t_valst *lst_va, t_option *lst)
{
	int nb;

	nb = 0;
	if (lst->star != 0)
	{
		nb = va_arg(lst_va->lst_copy, int);
		if (lst->star == 1)
			ft_option_star2(lst, nb);
		else
		{
			lst->bf_nb = nb;
			lst->af_nb = ft_abs(va_arg(lst_va->lst_copy, int));
		}
		if (nb < 0)
			lst->sign = '-';
	}
}
