/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_option_d.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/12 12:38:05 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/01 15:43:00 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_option_neg(t_option *lst, char *new, int count)
{
	int len;
	int max;
	int min;

	len = ft_strlen(new);
	max = ft_max2(len, lst->af_nb);
	min = ft_min2(len, lst->af_nb);
	if (lst->point == 1)
	{
		count += ft_putnstrw_fd(new, lst->af_nb, lst->fd);
		count += ft_print_prefix(min, lst->bf_nb, 0, lst->fd);
	}
	else
	{
		count += ft_putstrw_fd(new, lst->fd);
		count += ft_print_prefix(max, lst->bf_nb, 0, lst->fd);
	}
	return (count);
}

static int	ft_option_pos(t_option *lst, char *new, int count)
{
	int len;
	int max;
	int min;

	len = ft_strlen(new);
	max = ft_max2(len, lst->af_nb);
	min = ft_min2(len, lst->af_nb);
	if (lst->point == 1)
	{
		count += ft_print_prefix(min, lst->bf_nb, lst->bf_zero, lst->fd);
		count += ft_putnstrw_fd(new, lst->af_nb, lst->fd);
	}
	else
	{
		count += ft_print_prefix(max, lst->bf_nb, lst->bf_zero, lst->fd);
		count += ft_putstrw_fd(new, lst->fd);
	}
	return (count);
}

int			*ft_params_s(t_valst *lst_va, char *str, int *tab_i, int index)
{
	t_option	*lst;
	char		*new;

	lst = ft_put_option(lst_va, str, tab_i[0], index);
	new = va_arg(lst_va->lst_copy, char*);
	lst->af_nb = ft_abs(lst->af_nb);
	if (new == NULL)
		new = "(null)";
	if (lst->sign != '-')
		tab_i[1] += ft_option_pos(lst, new, 0);
	else
		tab_i[1] += ft_option_neg(lst, new, 0);
	tab_i[0] = ((tab_i[0] + index) + 1);
	return (tab_i);
}

int			*ft_params_smaj(t_valst *lst_va, char *str, int *tab_i, int index)
{
	t_option	*lst;
	char		*new;

	lst = ft_put_option(lst_va, str, tab_i[0], index);
	new = (long)va_arg(lst_va->lst_copy, char*);
	lst->af_nb = ft_abs(lst->af_nb);
	if (new == NULL)
		new = "(null)";
	if (lst->sign != '-')
		tab_i[1] += ft_option_pos(lst, new, 0);
	else
		tab_i[1] += ft_option_neg(lst, new, 0);
	tab_i[0] = ((tab_i[0] + index) + 1);
	return (tab_i);
}
