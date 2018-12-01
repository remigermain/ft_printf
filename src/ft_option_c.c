/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_option_d.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/12 12:38:05 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/01 13:30:32 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_c(t_option *lst, unsigned int c, int index)
{
	int count;

	count = 0;
	if (lst->bf_nb < 0 || lst->sign == '-')
	{
		if (index == 0)
			count += ft_putchar_fd(c, lst->fd);
		else
			count += ft_putwchar_fd(c, lst->fd);
		count += ft_print_prefix(1, lst->bf_nb, 0, lst->fd);
	}
	else
	{
		count += ft_print_prefix(1, lst->bf_nb, lst->bf_zero, lst->fd);
		if (index == 0)
			count += ft_putchar_fd(c, lst->fd);
		else
			count += ft_putwchar_fd(c, lst->fd);
	}
	return (count);
}

int		*ft_params_perc(t_valst *lst_va, char *str, int *tab_i, int index)
{
	t_option		*lst;
	unsigned int	c;

	c = '%';
	lst = ft_put_option(lst_va, str, tab_i[0], index);
	tab_i[1] += ft_print_c(lst, c, 1);
	tab_i[0] = ((tab_i[0] + index) + 1);
	return (tab_i);
}

int		*ft_params_cmaj(t_valst *lst_va, char *str, int *tab_i, int index)
{
	t_option		*lst;
	unsigned int	c;

	lst = ft_put_option(lst_va, str, tab_i[0], index);
	c = (unsigned int)va_arg(lst_va->lst_copy, int);
	tab_i[1] += ft_print_c(lst, c, 1);
	tab_i[0] = ((tab_i[0] + index) + 1);
	return (tab_i);
}

int		*ft_params_c(t_valst *lst_va, char *str, int *tab_i, int index)
{
	t_option		*lst;
	unsigned int	c;

	lst = ft_put_option(lst_va, str, tab_i[0], index);
	c = (unsigned int)va_arg(lst_va->lst_copy, int);
	if (lst->flag_l == 0)
		tab_i[1] += ft_print_c(lst, c, 0);
	else
		tab_i[1] += ft_print_c(lst, c, 1);
	tab_i[0] = ((tab_i[0] + index) + 1);
	return (tab_i);
}

int		*ft_params_no(t_valst *lst_va, char *str, int *tab_i, int index)
{
	t_option		*lst;
	unsigned int	c;
	int				count;

	count = 0;
	lst = ft_put_option(lst_va, str, tab_i[0], index);
	c = str[tab_i[0] + index];
	tab_i[1] += ft_print_c(lst, c, 0);
	tab_i[0] = ((tab_i[0] + index) + 1);
	return (tab_i);
}
