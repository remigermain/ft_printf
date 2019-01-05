/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   debug.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/04 16:24:14 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/04 16:28:26 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
static void	debug2(t_pf *lst)
{
	dprintf(1, "lst->local = %zu\n", lst->local);
	dprintf(1, "lst->field = %d\n", lst->field);
	dprintf(1, "lst->point = %zu\n", lst->point);
	dprintf(1, "lst->preci = %d\n", lst->preci);
	dprintf(1, "lst->maj = %zu\n", lst->maj);
	dprintf(1, "lst->psign = %zu\n", lst->psign);
	dprintf(1, "lst->base = %zu\n", lst->base);
	dprintf(1, "lst->lenght = %zu\n", lst->lenght);
	dprintf(1, "lst->conv = %c\n", (char)lst->conv);
	dprintf(1, "\n[end printf list]\n\n");
}

void		debug(t_pf *lst)
{
	dprintf(1, "\n [printf list]\n");
	dprintf(1, "\n[buff]\nlst->buff_count = %d\n", lst->buff_count);
	dprintf(1, "lst->buff = %s\n", lst->buff);
	dprintf(1, "\n[str]\nlst->count = %d\n", lst->count);
	dprintf(1, "lst->str = %s\n\n", lst->str);
	dprintf(1, "lst->ul_nb = %lu\n", lst->ul_nb);
	dprintf(1, "lst->fl_nb = %lu\n", lst->ful_nb);
	dprintf(1, "lst->fl_nb = %.*Lf\n", PRECI, lst->fl_nb);
	dprintf(1, "lst->exponent = %d\n", lst->exponent);
	dprintf(1, "lst->hash = %zu\n", lst->hash);
	dprintf(1, "lst->space = %zu\n", lst->space);
	dprintf(1, "lst->zero = %zu\n", lst->zero);
	if (lst->sign == 0)
		dprintf(1, "lst->sign = %d\n", 0);
	else
		dprintf(1, "lst->sign = %c\n", (char)lst->sign);
	debug2(lst);
}
