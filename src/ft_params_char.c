/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_params_char.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/10 16:21:44 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/19 23:37:10 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static wuchar_t *pf_convwchar(wchar_t wc)
{
	wuchar_t	*new;
	size_t		a;

	if (!(new = (wuchar_t*)malloc(sizeof(wuchar_t) * lenwchar(wc) + 1)))
		return (NULL);
	a = 0;
	convert_wchar(&new, wc, &a);
	return (new);
}

static	int	ft_print_char(t_pf *lst, char c, wuchar_t *wc, int index)
{
	int max;

	if (index == 1)
		max = ft_strlen(wc);
	else
		max = 1;
	ft_putprefix(lst, max, lst->field, lst->zero);
	if (index == 1)
		pf_tmpjoin(lst, wc, max, 1);
	else
		pf_tmpjoin(lst, &c, max, 0);
	ft_putprefix(lst, max, -lst->field, 0);
	return (1);
}

int			ft_params_char(t_va *lst_va, char *str, int index)
{
	t_pf	*lst;
	int		count;
	char	c;
	wuchar_t	*wc;

	lst = lst_initoption(lst_va, str, index);
	if ((lst->lenght >= 10 && lst->lenght <= 20) || lst->conv == 'C')
	{
		wc = pf_convwchar(va_arg(lst_va->copy, wchar_t));
		count = ft_print_char(lst, 0, wc, 1);
	}
	else
	{
		c = (char)va_arg(lst_va->copy, int);
		count = ft_print_char(lst, c, 0, 0);
	}
	pf_finaljoin(lst_va, lst->str, lst->count);
	free(lst->str);
	free(lst);
	return (index + 1);
}

int			ft_params_perc(t_va *lst_va, char *str, int index)
{
	t_pf	*lst;

	lst = lst_initoption(lst_va, str, index);
	ft_print_char(lst, '%', 0, 0);
	pf_finaljoin(lst_va, lst->str, lst->count);
	free(lst->str);
	free(lst);
	return (index + 1);
}

int			ft_params_no(t_va *lst_va, char *str, int index)
{
	t_pf	*lst;

	lst = lst_initoption(lst_va, str, index);
	ft_print_char(lst, str[index], 0, 0);
	pf_finaljoin(lst_va, lst->str, lst->count);
	free(lst->str);
	free(lst);
	return (index + 1);
}
