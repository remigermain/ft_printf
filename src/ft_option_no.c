/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_option_d.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/12 12:38:05 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/26 18:54:30 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_option_no(t_valst *lst_va, char *str, int count, int index)
{
	t_option		*lst;
	unsigned	int nb;

	nb = str[count + index];
	lst = ft_put_option(str, count, index);
	count = 0;
	ft_option_star(lst_va, lst);
	if (lst->bf_nb < 0 || lst->sign == '-')
	{
		ft_putchar(nb);
		count += ft_print_prefix(1, lst->bf_nb, 0);
	}
	else
	{
		count += ft_print_prefix(1, lst->bf_nb, lst->bf_zero);
		ft_putchar(nb);
	}
	return (count + 1);
}

int	*ft_params_no(t_valst *lst_va, char *str, int *tab_i, int index)
{
	tab_i[1] += ft_option_no(lst_va, str, tab_i[0], index);
	tab_i[0] = ((tab_i[0] + index) + 1);
	return (tab_i);
}
