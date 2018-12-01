/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils2.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/20 16:06:08 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/01 15:49:25 by rgermain    ###    #+. /#+    ###.fr     */
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
			lst->nb = -lst->nb2;
		}
		else
			lst->nb = lst->nb2;
		if (lst->nb2 >= 0 && lst->sign == '+')
			lst->psign = 2;
	}
	else
		lst->psign = 0;
}

void	ft_init_unb(t_option *lst, t_valst *lst_va)
{
	if (lst->flag_h == 1 || ( lst->flag_h == 2 && (lst->conv_o == 2 || lst->conv_u == 2
			|| lst->conv_d == 2)))
		lst->nb = (unsigned short)va_arg(lst_va->lst_copy, int);
	else if (lst->flag_h == 2)
		lst->nb = (unsigned char)va_arg(lst_va->lst_copy, int);
	else if (lst->flag_l == 1 && lst->conv_u == 0)
		lst->nb = va_arg(lst_va->lst_copy, long);
	else if (lst->flag_l == 2 || lst->conv_u > 0)
		lst->nb = va_arg(lst_va->lst_copy, unsigned long);
	else if (lst->flag_j == 1)
		lst->nb = va_arg(lst_va->lst_copy, intmax_t);
	else if (lst->flag_z == 1)
		lst->nb = va_arg(lst_va->lst_copy, size_t);
	else if (lst->conv_o == 1)
		lst->nb = va_arg(lst_va->lst_copy, unsigned int);
	else
		lst->nb = va_arg(lst_va->lst_copy, unsigned long);
	lst->unb = 1;
}

void	ft_init_snb(t_option *lst, t_valst *lst_va)
{
	if (lst->flag_h == 1)
	{
		if (lst->conv_d == 2)
			lst->nb2 = (unsigned short)va_arg(lst_va->lst_copy, int);
		else
			lst->nb2 = (short)va_arg(lst_va->lst_copy, int);
	}
	else if (lst->flag_h == 2)
	{
		if (lst->conv_d == 2)
			lst->nb2 = (unsigned short)va_arg(lst_va->lst_copy, int);
		else
			lst->nb2 = (char)va_arg(lst_va->lst_copy, int);
	}
	else if (lst->flag_l == 1 && lst->conv_u == 0)
		lst->nb2 = va_arg(lst_va->lst_copy, long);
	else if (lst->flag_l == 2 || lst->conv_u > 0)
		lst->nb2 = va_arg(lst_va->lst_copy, long);
	else if (lst->flag_j == 1)
		lst->nb2 = va_arg(lst_va->lst_copy, intmax_t);
	else if (lst->flag_z == 1)
		lst->nb2 = va_arg(lst_va->lst_copy, size_t);
	else if (lst->conv_d == 2)
		lst->nb2 = va_arg(lst_va->lst_copy, long);
	else
		lst->nb2 = va_arg(lst_va->lst_copy, int);
}

void	ft_initnb(t_option *lst, t_valst *lst_va)
{
	if (lst->conv_d >= 1)
		ft_init_snb(lst, lst_va);
	else
		ft_init_unb(lst, lst_va);
	ft_init_nb2(lst, lst_va);
	ft_modspec(lst);
	if (lst->conv_p == 1)
		lst->psign = 3;
}
