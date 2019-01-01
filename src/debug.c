/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   debug.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/11 20:48:22 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/19 14:20:22 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	debug(t_pf *lst)
{
	printf("\n [printf list]\n");
	printf("\n[buff]\nlst->buff_count = %d\n", lst->buff_count);
	printf("lst->buff = %s\n", lst->buff);
	printf("\n[str]\nlst->count = %d\n", lst->count);
	printf("lst->str = %s\n\n", lst->str);
	printf("lst->ul_nb = %lu\n", lst->ul_nb);
	printf("lst->fl_nb = %lu\n", lst->ful_nb);
	printf("lst->fl_nb = %.*Lf\n", lst->preci, lst->fl_nb);
	printf("lst->exponent = %d\n", lst->exponent);
	printf("lst->hash = %zu\n", lst->hash);
	printf("lst->space = %zu\n", lst->space);
	printf("lst->zero = %zu\n", lst->zero);
	if (lst->sign == 0)
		printf("lst->sign = %d\n", 0);
	else
		printf("lst->sign = %c\n", (char)lst->sign);
	printf("lst->local = %zu\n", lst->local);
	printf("lst->field = %d\n", lst->field);
	printf("lst->point = %zu\n", lst->point);
	printf("lst->preci = %d\n", lst->preci);
	printf("lst->maj = %zu\n", lst->maj);
	printf("lst->psign = %zu\n", lst->psign);
	printf("lst->base = %zu\n", lst->base);
	printf("lst->lenght = %zu\n", lst->lenght);
	printf("lst->conv = %c\n", (char)lst->conv);
	printf("\n[end printf list]\n\n");
}
