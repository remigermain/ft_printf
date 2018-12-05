/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils2.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/20 16:06:08 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/05 16:28:06 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_modspec(t_option *lst)
{
	if (lst->hash == 1 && lst->point == 1 && lst->af_nb == 0
			&& lst->bf_nb == 0 && lst->conv_o >= 1 && lst->nb == 0)
		lst->point = 0;
}

void	ft_nbflag(t_option *lst)
{
	if (lst->flag_h == 0 && lst->flag_l == 0
			&& lst->flag_j == 0 && lst->flag_z == 0)
		lst->nbflag = 0;
	else
		lst->nbflag = 1;
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
	lst->fd = lst_va->fd;
	if (lst->dollar == 1)
		lst_va = lst_initva(lst_va, lst->dollar_nb, 0);
	if (lst->star != 0)
	{
		nb = va_arg(lst_va->lst_copy, int);
		if (lst->point == 1 && lst->af_nb == 0 && lst->bf_nb == 0 && nb != 0)
			lst->point = 0;
		if (lst->star == 1)
			ft_option_star2(lst, nb);
		else
		{
			lst->bf_nb = nb;
			lst->af_nb = ft_abs(va_arg(lst_va->lst_copy, int));
		}
		if (nb < 0 && lst->point == 0)
			lst->sign = '-';
		if (nb < 0 && lst->point == 1 && lst->zero == 0 && lst->bf_nb == 0)
			lst->af_nb = 0;
	}
	ft_nbflag(lst);
}
