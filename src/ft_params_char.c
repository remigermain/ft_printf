/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_params_char.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/10 16:21:44 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/19 22:59:37 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_print_char(t_pf *lst, char c, wchar_t wc, int index)
{
	int count;
	int max;

	count = 0;
	if (index == 1)
	{
		max = ft_countwchar(wc);
		if (max == -1)
			return (-1);
	}
	else
		max = 1;
	count += ft_print_prefix(max, lst->field, lst->zero, lst->fd);
	if (index == 1)
		count += ft_putwchar_fd(wc, lst->fd);
	else
		count += ft_putchar_fd(c, lst->fd);
	count += ft_print_prefix(max, -lst->field, 0, lst->fd);
	return (count);
}

int			ft_params_char(t_valst *lst_va, char *str, int i, int index)
{
	t_pf	*lst;
	int		count;
	char	c;
	wchar_t	wc;

	count = 0;
	lst = lst_initoption(lst_va, str, i, index);
	if ((lst->lenght >= 10 && lst->lenght <= 20) || lst->conv == 'C')
	{
		wc = (wchar_t)va_arg(lst_va->copy, wchar_t);
		count += ft_print_char(lst, 0, wc, 1);
	}
	else
	{
		c = (char)va_arg(lst_va->copy, int);
		count += ft_print_char(lst, c, 0, 0);
	}
	lst_va->count = (count == -1 ? count : lst_va->count + count);
	free(lst);
	return (index + 1);
}

int			ft_params_perc(t_valst *lst_va, char *str, int i, int index)
{
	t_pf	*lst;

	lst = lst_initoption(lst_va, str, i, index);
	lst_va->count += ft_print_char(lst, '%', 0, 0);
	free(lst);
	return (index + 1);
}

int			ft_params_no(t_valst *lst_va, char *str, int i, int index)
{
	t_pf	*lst;

	lst = lst_initoption(lst_va, str, i, index);
	lst_va->count += ft_print_char(lst, str[i + index], 0, 0);
	free(lst);
	return (index + 1);
}
