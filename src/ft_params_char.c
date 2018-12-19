/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_params_char.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/10 16:21:44 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/19 14:35:35 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_countchar(char c)
{
	if (c <= 0x7F)
		return (1);
	if (c <= 0x7FF)
		return (2);
	if (c <= 0xFFFF)
		return (3);
	return (4);
}

int		ft_option_char(t_pf *lst, char c, int index)
{
	int count;
	int max;

	count = 0;
	if (c > 0x10FFFF && index == 1)
		return (-1);
	max = 1;
	count += ft_print_prefix(max, lst->field, lst->zero, lst->fd);
	if (index == 0)
		count += ft_putchar_fd(c, lst->fd);
	else
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
	{
		c = va_arg(lst_va->copy, size_t);
		count = ft_option_char(lst, c, 1);
	}
	else
	{
		c = (char)va_arg(lst_va->copy, int);
		count = ft_option_char(lst, c, 0);
	}
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
