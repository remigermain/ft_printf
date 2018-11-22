/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_option_d.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/12 12:38:05 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/16 06:22:49 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_prefix(int len, int nb)
{
	int count;

	count = 0;
	while (len < nb)
	{
		ft_putchar(' ');
		count++;
		nb--;
	}
	return (count);
}

int			ft_option_c(t_valst *lst_va, char *str, int count, int index)
{
	t_option		*lst;
	unsigned int	nb;

	lst = ft_put_option(str, count, index);
	count = 0;
	if (lst->dollar == 1)
		lst_va = ft_lst_init2(lst_va, lst->dollar_nb, 0);
	nb = (unsigned int)va_arg(lst_va->lst_copy, int);
	if (lst->space == 1 && lst->sign == 0
			&& lst->af_nb == 0 && lst->bf_nb == 0)
		count += ft_print_prefix(0, 1);
	if (lst->star == 1)
	{
		if (lst->bf_nb == 0)
			lst->bf_nb = ft_abs(nb);
		nb = va_arg(lst_va->lst_copy, int);
	}
	count += ft_print_prefix(1, lst->bf_nb);
	ft_putchar(nb);
	return (count + 1);
}
