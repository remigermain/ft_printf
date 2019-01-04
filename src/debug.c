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

static void	debug2(t_pf *lst)
{
	printf("lst->local = %zu\n", lst->local);
	printf("lst->field = %d\n", lst->field);
	printf("lst->point = %zu\n", lst->point);
	printf("PRECI = %d\n", PRECI);
	printf("lst->maj = %zu\n", lst->maj);
	printf("lst->psign = %zu\n", lst->psign);
	printf("lst->base = %zu\n", lst->base);
	printf("lst->lenght = %zu\n", lst->lenght);
	printf("lst->conv = %c\n", (char)lst->conv);
	printf("\n[end printf list]\n\n");
}

void		debug(t_pf *lst)
{
	printf("\n [printf list]\n");
	printf("\n[buff]\nlst->buff_count = %d\n", lst->buff_count);
	printf("lst->buff = %s\n", lst->buff);
	printf("\n[str]\nlst->count = %d\n", lst->count);
	printf("lst->str = %s\n\n", lst->str);
	printf("lst->ul_nb = %lu\n", lst->ul_nb);
	printf("lst->fl_nb = %lu\n", lst->ful_nb);
	printf("lst->fl_nb = %.*Lf\n", PRECI, lst->fl_nb);
	printf("lst->exponent = %d\n", lst->exponent);
	printf("lst->hash = %zu\n", lst->hash);
	printf("lst->space = %zu\n", lst->space);
	printf("lst->zero = %zu\n", lst->zero);
	if (lst->sign == 0)
		printf("lst->sign = %d\n", 0);
	else
		printf("lst->sign = %c\n", (char)lst->sign);
	debug2(lst);
}
