/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils2.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/20 16:06:08 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/30 19:22:14 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init_nb2(t_option *lst, t_valst *lst_va)
{
	if (lst->unb == 0)
	{
		if (lst->nb2 < 0)
		{
			lst->psign = 1;
			lst->nb2 = -lst->nb2;
		}
		else if (lst->nb2 >= 0 && lst->sign == '+')
			lst->psign = 2;
		else
			lst->psign = 0;
		lst->nb = lst->nb2;
	}
	else
		lst->psign = 0;
}

void	ft_init_unb(t_option *lst, t_valst *lst_va)
{
	unsigned long nb;

	nb = 0;
	if (lst->flag_h == 1)
		nb = (unsigned short)va_arg(lst_va->lst_copy, int);
	else if (lst->flag_h == 2)
		nb = (unsigned char)va_arg(lst_va->lst_copy, int);
	else if (lst->flag_l == 1 && lst->conv_u == 0)
		nb = va_arg(lst_va->lst_copy, long);
	else if (lst->flag_l == 2 || lst->conv_u > 0)
		nb = va_arg(lst_va->lst_copy, unsigned long);
	else if (lst->flag_j == 1)
		nb = va_arg(lst_va->lst_copy, intmax_t);
	else if (lst->flag_z == 1)
		nb = va_arg(lst_va->lst_copy, size_t);
	else
		nb = va_arg(lst_va->lst_copy, unsigned long);
	lst->nb = nb;
	lst->unb = 1;
	ft_init_nb2(lst, lst_va);
}

void	ft_init_snb(t_option *lst, t_valst *lst_va)
{
	long nb;

	nb = 0;
	if (lst->flag_h == 1)
		nb = (short)va_arg(lst_va->lst_copy, int);
	else if (lst->flag_h == 2)
		nb = (char)va_arg(lst_va->lst_copy, int);
	else if (lst->flag_l == 1 && lst->conv_u == 0)
		nb = va_arg(lst_va->lst_copy, long);
	else if (lst->flag_l == 2 || lst->conv_u > 0)
		nb = va_arg(lst_va->lst_copy, long);
	else if (lst->flag_j == 1)
		nb = va_arg(lst_va->lst_copy, intmax_t);
	else if (lst->flag_z == 1)
		nb = va_arg(lst_va->lst_copy, size_t);
	else
		nb = va_arg(lst_va->lst_copy, int);
	lst->nb2 = nb;
	ft_init_nb2(lst, lst_va);
}

void	ft_initnb(t_option *lst, t_valst *lst_va)
{
	if (lst->conv_d == 1)
		ft_init_snb(lst, lst_va);
	else
		ft_init_unb(lst, lst_va);
	if (lst->conv_p == 1)
		lst->psign = 3;
}
