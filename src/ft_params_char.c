/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_params_char.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/10 16:21:44 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/19 19:37:41 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_countchar(wchar_t c)
{
	if (c <= 0x7F)
		return (1);
	if (c <= 0x7FF)
		return (2);
	if (c <= 0xFFFF)
		return (3);
	if (c <= 0x10FFFF)
		return (4);
	return (-1);
}

int		ft_params_charmaj(t_valst *lst_va, t_pf *lst)
{
	int		count;
	int		max;
	wchar_t	c;

	count = 0;
	c = (wchar_t)va_arg(lst_va->copy, wchar_t);
	max = ft_countchar(c);
	if (max == -1)
		return (-1);
	count += ft_print_prefix(max, lst->field, lst->zero, lst->fd);
	count += ft_putwchar_fd(c, lst->fd);
	count += ft_print_prefix(max, -lst->field, 0, lst->fd);
	return (count);
}

int		ft_params_char(t_valst *lst_va, char *str, int i, int index)
{
	t_pf	*lst;
	int		count;
	char	c;

	count = 0;
	lst = lst_initoption(lst_va, str, i, index);
	if ((lst->lenght >= 10 && lst->lenght <= 20) || lst->conv == 'C')
		count = ft_params_charmaj(lst_va, lst);
	else
	{
		c = (char)va_arg(lst_va->copy, int);
		count += ft_print_prefix(1, lst->field, lst->zero, lst->fd);
		count += ft_putchar_fd(c, lst->fd);
		count += ft_print_prefix(1, -lst->field, 0, lst->fd);
	}
	if (count == -1)
		lst_va->count = -1;
	else
		lst_va->count += count;
	free(lst);
	return (index + 1);
}

int		ft_params_perc(t_valst *lst_va, char *str, int i, int index)
{
	t_pf	*lst;
	int		count;
	size_t	c;

	count = 0;
	lst = lst_initoption(lst_va, str, i, index);
	c = '%';
	count = ft_option_char(lst, c, 0);
	lst_va->count += count;
	free(lst);
	return (index + 1);
}

int		ft_params_no(t_valst *lst_va, char *str, int i, int index)
{
	t_pf	*lst;
	int		count;
	size_t	c;

	count = 0;
	lst = lst_initoption(lst_va, str, i, index);
	c = str[i + index];
	count = ft_option_char(lst, c, 0);
	lst_va->count += count;
	free(lst);
	return (index + 1);
}
