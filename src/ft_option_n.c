/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_option_d.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/12 12:38:05 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/02 17:23:41 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		*ft_params_n(t_valst *lst_va, char *str, int *tab_i, int index)
{
	int	*nb;

	nb = va_arg(lst_va->lst_copy, int*);
	*nb = tab_i[1];
	tab_i[0] = ((tab_i[0] + index) + 1);
	return (tab_i);
}
