/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils2.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/20 16:06:08 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/10 16:20:30 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_signprefix(t_pf *lst)
{
	if (lst->conv == 'p' || ((lst->conv == 'x' || lst->conv == 'X')
				&& lst->hash == 1 && lst->ul_nb != 0))
		lst->psign = 3;
	else if (lst->conv == 'e' || lst->conv == 'E')
		lst->psign = 4;
	else if (lst->conv == 'a' || lst->conv == 'A')
		lst->psign = 5;
}

void	ft_init_unb(t_pf *lst, t_valst *lst_va)
{
	if (lst->lenght == 1 || (lst->lenght == 2 && (lst->conv == 'd'
					|| lst->conv == 'U' || lst->conv == 'D')))
		lst->ul_nb = (unsigned short)va_arg(lst_va->copy, int);
	else if (lst->lenght == 2)
		lst->ul_nb = (unsigned char)va_arg(lst_va->copy, int);
	else if (lst->lenght == 10 && (lst->conv != 'u' || lst->conv != 'U'))
		lst->ul_nb = va_arg(lst_va->copy, long);
	else if (lst->lenght == 20 || (lst->conv == 'u' || lst->conv == 'U'))
		lst->ul_nb = va_arg(lst_va->copy, unsigned long);
	else if (lst->lenght == 100)
		lst->ul_nb = va_arg(lst_va->copy, intmax_t);
	else if (lst->lenght == 1000)
		lst->ul_nb = va_arg(lst_va->copy, size_t);
	else if (lst->conv == 'o')
		lst->ul_nb = va_arg(lst_va->copy, unsigned int);
	else
		lst->ul_nb = va_arg(lst_va->copy, unsigned long);
	lst->psign = (lst->sign == '+' ? 2 : 0);
}

void	ft_init_snb(t_pf *lst, t_valst *lst_va)
{
	if (lst->lenght == 1 || (lst->lenght == 2 && lst->conv == 'd'))
		lst->nb_tmp = (short)va_arg(lst_va->copy, int);
	else if (lst->lenght == 2)
		lst->nb_tmp = (char)va_arg(lst_va->copy, int);
	else if (lst->lenght == 10 && (lst->conv != 'u' || lst->conv != 'U'))
		lst->nb_tmp = va_arg(lst_va->copy, long);
	else if (lst->lenght == 20 && (lst->conv == 'u' || lst->conv == 'U'))
		lst->nb_tmp = va_arg(lst_va->copy, long);
	else if (lst->lenght == 100)
		lst->nb_tmp = va_arg(lst_va->copy, intmax_t);
	else if (lst->lenght == 1000)
		lst->nb_tmp = va_arg(lst_va->copy, size_t);
	else if (lst->conv == 'D' || lst->conv == 'I')
		lst->nb_tmp = va_arg(lst_va->copy, long);
	else
		lst->nb_tmp = va_arg(lst_va->copy, int);
	lst->psign = (lst->nb_tmp < 0 ? 1 : 0);
	if (lst->sign == '+' && lst->nb_tmp >= 0)
		lst->psign = 2;
	lst->ul_nb = (lst->nb_tmp < 0 ? -lst->nb_tmp : lst->nb_tmp);
}

void	ft_initnb(t_pf *lst, t_valst *lst_va)
{
	if (lst->conv == 'd' || lst->conv == 'D' || lst->conv == 'I' ||
			(lst->conv == 'i' && lst->lenght != 20))
		ft_init_snb(lst, lst_va);
	else
		ft_init_unb(lst, lst_va);
	ft_signprefix(lst);
}
