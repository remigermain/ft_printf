/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils2.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/20 16:06:08 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/19 22:17:14 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static void	lst_putnb_unb(t_pf *lst)
{
	if (lst->lenght == 1 && lst->conv != 'O' && lst->conv != 'U'
			&& lst->conv != 'D')
		lst->ul_nb = (unsigned short)va_arg(lst->va_copy, ulong_t);
	else if (lst->lenght == 2 && lst->conv != 'O' && lst->conv != 'U'
			&& lst->conv != 'D')
		lst->ul_nb = (unsigned char)va_arg(lst->va_copy, ulong_t);
	else if (lst->lenght == 10)
		lst->ul_nb = va_arg(lst->va_copy, long);
	else if (lst->lenght == 20)
		lst->ul_nb = va_arg(lst->va_copy, ulong_t);
	else if (lst->lenght == 100)
		lst->ul_nb = va_arg(lst->va_copy, intmax_t);
	else if (lst->lenght == 1000)
		lst->ul_nb = va_arg(lst->va_copy, size_t);
	else if (lst->conv == 'o' || lst->conv == 'x' || lst->conv == 'X' ||
			lst->conv == 'u' || lst->conv == 'X')
		lst->ul_nb = va_arg(lst->va_copy, unsigned int);
	else
		lst->ul_nb = va_arg(lst->va_copy, ulong_t);
	if (lst->sign == '+' && (lst->conv == 'd' || lst->conv == 'D' ||
				lst->conv == 'I' || lst->conv == 'i'))
		lst->psign = 2;
}

static void	lst_putnb_snb(t_pf *lst)
{
	long nb_tmp;

	if (lst->lenght == 1)
		nb_tmp = (short)va_arg(lst->va_copy, int);
	else if (lst->lenght == 2)
		nb_tmp = (char)va_arg(lst->va_copy, int);
	else if (lst->lenght == 10)
		nb_tmp = va_arg(lst->va_copy, long);
	else if (lst->lenght == 20)
		nb_tmp = va_arg(lst->va_copy, long);
	else if (lst->lenght == 100)
		nb_tmp = va_arg(lst->va_copy, intmax_t);
	else if (lst->lenght == 1000)
		nb_tmp = va_arg(lst->va_copy, size_t);
	else if (lst->conv == 'D' || lst->conv == 'I' || lst->lenght != 0)
		nb_tmp = va_arg(lst->va_copy, long);
	else
		nb_tmp = va_arg(lst->va_copy, int);
	lst->psign = (nb_tmp < 0 ? 1 : 0);
	if (lst->sign == '+' && nb_tmp >= 0 && (lst->conv == 'd' ||
				lst->conv == 'D' || lst->conv == 'I' || lst->conv == 'i'))
		lst->psign = 2;
	lst->ul_nb = (nb_tmp < 0 ? -nb_tmp : nb_tmp);
}

void		lst_putint(t_pf *lst)
{
	if (lst->conv == 'd' || (lst->conv == 'i') ||
			(lst->conv == 'D' && lst->lenght == 0))
		lst_putnb_snb(lst);
	else
		lst_putnb_unb(lst);
	if (lst->conv == 'p' || ((lst->conv == 'x' || lst->conv == 'X')
				&& lst->hash == 1 && lst->ul_nb != 0))
	lst->psign = 3;
}