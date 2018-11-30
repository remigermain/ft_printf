/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/12 12:39:33 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/30 19:31:27 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int			*init_tab2(void)
{
	int	*total;

	if (!(total = (int*)malloc(sizeof(int) * 2)))
		exit(0);
	total[0] = 0;
	total[1] = 0;
	return (total);
}

t_valst		*lst_initva(t_valst *lst_va, int nb, int index)
{
	int		count;

	count = 0;
	if (index == 0)
		va_copy(lst_va->lst_copy, lst_va->lst_va);
	while (count < (nb - 1))
	{
		va_arg(lst_va->lst_copy, int);
		count++;
	}
	return (lst_va);
}
