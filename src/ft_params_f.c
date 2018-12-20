/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_params_f.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/11 20:46:44 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/20 19:33:33 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_params_f(t_valst *lst_va, char *str, int i, int index)
{
	t_pf	*lst;
	int		count;

	lst = lst_initoption(lst_va, str, i, index);
	count = 0;
	lst_va->count += count;
	free(lst);
	return (index) + 1;
}
