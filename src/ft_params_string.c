/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_params_char.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/10 16:21:44 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/19 23:02:29 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static int	wchar_verif(wchar_t *wstr)
{
	int a;
	int count;

	a = 0;
	count = 0;
	while (wstr[a] != '\0')
	{
		if (wstr[a] > 0x10FFFF)
			return (-1);
		a++;
	}
	return (count);
}

static	int	ft_print_string(t_pf *lst, char *str, wchar_t *wstr, int index)
{
	int count;

	count = 0;
	if (lst->point == 0 && index == 1)
		count += ft_putstr_fd(str, lst->fd);
	else if (index == 1)
		count += ft_putnstr_fd(str, lst->preci, lst->fd);
	else if (lst->point == 0 && index == 0)
		count += ft_putpstr_fd(str, lst->fd);
	else if (index == 0)
		count += ft_putpnstr_fd(str, lst->preci, lst->fd);
	else if (lst->point == 0 && index == 2)
		count += ft_putstrw_fd(wstr, lst->fd);
	else if (index == 2)
		count += ft_putnstrw_fd(wstr, lst->preci, lst->fd);
	return (count);
}

static int	ft_option_string(t_pf *lst, char *str, wchar_t *wstr, int index)
{
	int count;
	int max;
	int len;

	count = 0;
	if (index == 2)
	{
		len = ft_countwchars(wstr);
		if (wchar_verif(wstr) == -1)
			return (-1);
	}
	else
		len = ft_strlen(str);
	if (lst->point == 1)
		max = ft_min2(lst->preci, len);
	else
		max = len;
	count += ft_print_prefix(max, lst->field, lst->zero, lst->fd);
	count += ft_print_string(lst, str, wstr, index);
	count += ft_print_prefix(count, -lst->field, 0, lst->fd);
	return (count);
}

static void	initstring(t_valst *lst_va, char **cstr, wchar_t **wstr, int index)
{
	if (index == 1)
	{
		*wstr = va_arg(lst_va->copy, wchar_t*);
		if (*wstr == NULL)
			*wstr = L"(null)";
	}
	else
	{
		*cstr = va_arg(lst_va->copy, char*);
		if (*cstr == NULL)
			*cstr = "(null)";
	}
}

int			ft_params_string(t_valst *lst_va, char *str, int i, int index)
{
	t_pf	*lst;
	int		count;
	char	*cstr;
	wchar_t	*wstr;

	count = 0;
	lst = lst_initoption(lst_va, str, i, index);
	if ((lst->lenght >= 10 && lst->lenght <= 20) || lst->conv == 'S')
	{
		initstring(lst_va, &cstr, &wstr, 1);
		count = ft_option_string(lst, cstr, wstr, 2);
	}
	else
	{
		lst->preci = ft_abs(lst->preci);
		initstring(lst_va, &cstr, &wstr, 0);
		if (lst->conv == 'r')
			count = ft_option_string(lst, cstr, wstr, 0);
		else
			count = ft_option_string(lst, cstr, wstr, 1);
	}
	lst_va->count = (count == -1 ? count : lst_va->count + count);
	free(lst);
	return (index + 1);
}
