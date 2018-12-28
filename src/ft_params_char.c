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
	int				a;

	if (!(new = (wuchar_t*)malloc(sizeof(wuchar_t) * ft_countwchar(wc) + 1)))
		return (NULL);
	a = 0;
	if (wc <= 0x7F)
		new[a++] = wc;
	else if (wc <= 0x7FF)
	new[a++] = 192 + (wc / 64);
	else
	{
		if (wc > 0xFFFF)
		{
			new[a++] = 240 + (wc / 262144);
			new[a++] = 128 + ((wc / 4096) % 64);
		}
		else
			new[a++] = 224 + (wc / 4096);
			new[a++] = 128 + ((wc / 64) % 64);
		}
	if (wc > 0x7F)
		new[a++] = 128 + (wc % 64);
	new[a] = '\0';
	return (new);
}

static	int	ft_print_char(t_pf *lst, char c, wuchar_t *wc, int index)
{
	int max;

	if (index == 1)
	{
		max = ft_strlen(wc);
		if (max == -1)
			return (-1);
	}
	else
		max = 1;
	ft_putprefix(lst, max, lst->field, lst->zero);
	if (index == 1)
		pf_tmpjoin(lst, wc, max);
	else
		pf_tmpjoin(lst, &c, max);
	ft_putprefix(lst, max, -lst->field, 0);
	return (1);
}

int			ft_params_char(t_valst *lst_va, char *str, int index)
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
	if (count == -1)
		lst_va->count = -1;
	else
		pf_finaljoin(lst_va, lst->str, lst->count);
	free(lst->str);
	free(lst);
	return (index + 1);
}

int			ft_params_perc(t_valst *lst_va, char *str, int index)
{
	t_pf	*lst;

	lst = lst_initoption(lst_va, str, index);
	ft_print_char(lst, '%', 0, 0);
	pf_finaljoin(lst_va, lst->str, lst->count);
	free(lst->str);
	free(lst);
	return (index + 1);
}

int			ft_params_no(t_valst *lst_va, char *str, int index)
{
	t_pf	*lst;

	lst = lst_initoption(lst_va, str, index);
	ft_print_char(lst, str[index], 0, 0);
	pf_finaljoin(lst_va, lst->str, lst->count);
	free(lst->str);
	free(lst);
	return (index + 1);
}
