/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_params.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/13 20:25:54 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/13 22:12:53 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int	*ft_params_d(va_list lst_va, char *str, int *tab_i, int index)
{
	tab_i[1] += ft_option_d(lst_va, str, tab_i[0], index);
	tab_i[0] = ((tab_i[0] + index) + 1);
	return (tab_i);
}
