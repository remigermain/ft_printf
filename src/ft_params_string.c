/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_params_char.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/10 16:21:44 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/19 23:23:13 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static wuchar_t *comv_wstr(wchar_t *wstr, size_t len)
{
	wuchar_t *str;
	size_t i;
	size_t count;

	i = 0;
	count = 0;
	if (!(str = (wuchar_t*)malloc(sizeof(wuchar_t) * nlenstrwchar(wstr, len))))
		return (NULL);
	while (wstr[count] != '\0' && count < len)
		convert_wchar(&str, wstr[count++], &i);
	return (str);
}

static	int	put_string(t_pf *lst, wuchar_t *str, wchar_t *wstr, int index)
{
	int count;
	int preci;

	count = 0;
	preci = lst->preci;
	if (lst->point == 0 && index == 1)
		pf_tmpjoin(lst, str, ft_strlen(str), 0);
	else if (index == 1)
		pf_tmpjoin(lst, str, ft_min2(ft_strlen(str), preci), 0);
	else if (index == 0)
		pf_putpstr(lst, str);
	else if (lst->point == 0 && index == 2)
		pf_tmpjoin(lst, comv_wstr(wstr, lenstrwchar(wstr)), lenstrwchar(wstr), 1);
	else if (index == 2)
		pf_tmpjoin(lst, comv_wstr(wstr, preci), nlenstrwchar(wstr, preci), 1);
	return (count);
}

static int	pf_string(t_pf *lst, wuchar_t *str, wchar_t *wstr, int index)
{
	int count;
	int max;
	int len;

	count = 0;
	if (index == 2)
		len = lenstrwchar(wstr);
	else
		len = ft_strlen(str);
	if (lst->point == 1)
		max = ft_min2(lst->preci, len);
	else
		max = len;
	ft_putprefix(lst, max, lst->field, lst->zero);
	put_string(lst, str, wstr, index);
	ft_putprefix(lst, count, -lst->field, 0);
	return (count);
}

static void	initstring(t_va *lst_va, wuchar_t **cstr, wchar_t **wstr, int i)
{
	if (i == 1)
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

int			ft_params_string(t_va *lst_va, char *str, int index)
{
	t_pf	*lst;
	int		count;
	wuchar_t	*cstr;
	wchar_t	*wstr;

	count = 0;
	lst = lst_initoption(lst_va, str, index);
	lst->preci = ft_abs(lst->preci);
	if ((lst->lenght >= 10 && lst->lenght <= 20) || lst->conv == 'S')
	{
		initstring(lst_va, &cstr, &wstr, 1);
		count = pf_string(lst, cstr, wstr, 2);
	}
	else
	{
		initstring(lst_va, &cstr, &wstr, 0);
		if (lst->conv == 'r')
			count = pf_string(lst, cstr, wstr, 0);
		else
			count = pf_string(lst, cstr, wstr, 1);
	}
	pf_finaljoin(lst_va, lst->str, lst->count);
	free(lst->str);
	free(lst);
	return (index + 1);
}
