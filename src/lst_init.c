/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/12 12:39:33 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/19 22:23:23 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void  lst_zero(t_pf *lst)
{
	lst->ul_nb = 0;
	lst->fl_nb = 0;
	lst->exposant = 0;
	lst->nb_tmp = 1;
	lst->hash = 0;
	lst->space = 0;
	lst->zero = 0;
	lst->sign = 0;
	lst->local = 0;
	lst->field = 0;
	lst->point = 0;
	lst->preci = 0;
	lst->maj = 0;
	lst->psign = 0;
	lst->base = 0;
	lst->lenght = 0;
	lst->conv = 0;
	lst->tmp_count = 0;
	lst->tmp_str = NULL;
}

t_pf	*lst_init(void)
{
	t_pf *lst;

	if (!(lst = (t_pf*)malloc(sizeof(t_pf))))
		ftprintf_error(lst, "lst_init", 1);
	lst->count = 0;
	lst->str = NULL;
	return (lst);
}

void	lst_putdollar(t_pf *lst, int len)
{
	va_end(lst->va_copy);
	va_copy(lst->va_copy, lst->va_lst);
	while (--len > 0)
		va_arg(lst->va_copy, int);
}
