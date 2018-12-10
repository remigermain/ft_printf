/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_params_char.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/10 16:21:44 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/10 16:40:22 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_option_char(t_pf *lst, size_t c)
{
	int count;

	count = 0;
	count += ft_print_prefix(1, lst->field, lst->zero, lst->fd);
	count += ft_putchar_fd(c, lst->fd);
	count += ft_print_prefix(1, -lst->field, 0, lst->fd);
	return (count);
}

int		ft_params_char(t_valst *lst_va, char *str, int i, int index)
{
	t_pf	*lst;
	int		count;
	size_t	c;

	count = 0;
	lst = lst_initoption(lst_va, str, i, index);
	c = (char)va_arg(lst_va->copy, int);
	count = ft_option_char(lst, c);
	lst_va->count += count;
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
	count = ft_option_char(lst, c);
	lst_va->count += count;
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
	count = ft_option_char(lst, c);
	lst_va->count += count;
	return (index + 1);
}


