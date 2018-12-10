/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_params_char.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/10 16:21:44 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/10 16:51:00 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_option_string(t_pf *lst, char *str)
{
	int count;
	int max;
	int len;

	count = 0;
	len = ft_strlen(str);
	if (lst->point == 0)
		max = len;
	else
		max = lst->preci;
	count += ft_print_prefix(max, lst->field, lst->zero, lst->fd);
	if (lst->point == 0)
		count += ft_putstr_fd(str, lst->fd);
	else
		count += ft_putnstr_fd(str, lst->preci, lst->fd);
	count += ft_print_prefix(count, -lst->field, 0, lst->fd);
	return (count);
}

int		ft_params_string(t_valst *lst_va, char *str, int i, int index)
{
	t_pf	*lst;
	int		count;
	char	*str2;

	count = 0;
	lst = lst_initoption(lst_va, str, i, index);
	str2 = va_arg(lst_va->copy, char*);
	if (str2 == NULL)
		str2 = "(null)";
	count = ft_option_string(lst, str2);
	lst_va->count += count;
	return (index + 1);
}


