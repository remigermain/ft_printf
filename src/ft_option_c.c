/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_option_d.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/12 12:38:05 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/24 09:27:45 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_option_c(t_valst *lst_va, char *str, int count, int index)
{
	t_option		*lst;
	unsigned int	nb;

	lst = ft_put_option(str, count, index);
	count = 0;
	if (lst->dollar == 1)
		lst_va = lst_init2(lst_va, lst->dollar_nb, 0);
	ft_option_star(lst_va, lst);
	nb = (unsigned int)va_arg(lst_va->lst_copy, int);
	if (lst->space == 1 && lst->sign == 0
			&& lst->af_nb == 0 && lst->bf_nb == 0)
		count += ft_print_prefix(0, 1, 0);
	if (lst->bf_nb < 0 || lst->sign == '-')
	{
		ft_putchar(nb);
		count += ft_print_prefix(1, lst->bf_nb, 0);
	}
	else
	{
		count += ft_print_prefix(1, lst->bf_nb, 0);
		ft_putchar(nb);
	}
	return (count + 1);
}

int	*ft_params_c(t_valst *lst_va, char *str, int *tab_i, int index)
{
	tab_i[1] += ft_option_c(lst_va, str, tab_i[0], index);
	tab_i[0] = ((tab_i[0] + index) + 1);
	return (tab_i);
}

int	*ft_params_perc(t_valst *lst_va, char *str, int *tab_i, int index)
{
	ft_putchar('%');
	tab_i[1] += 1;
	tab_i[0] = ((tab_i[0] + index) + 1);
	return (tab_i);
}
