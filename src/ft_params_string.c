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
	if (!(str = (wuchar_t*)malloc(sizeof(wuchar_t) * nlen_strwchar(wstr, len))))
		ftprintf_error("comv_wstr", 1);;
	while (wstr[count] != '\0' && count < len)
		convert_wchar(&str, wstr[count++], &i);
	return (str);
}

static	void	pf_putstring(t_pf *lst, wuchar_t *str, wchar_t *wstr, int index)
{
	if (lst->point == 0 && index == 2)
		str = comv_wstr(wstr, len_strwchar(wstr));
	else if (index == 2)
		str = comv_wstr(wstr, ft_min2(lst->preci, len_strwchar(wstr)));
	if (lst->point == 0 && index == 1)
		pf_stringjoin(lst, str, ft_strlen(str), 1);
	else if (index == 1)
		pf_stringjoin(lst, str, ft_min2(ft_strlen(str), lst->preci), 1);
	else if (index == 0)
		pf_putpstr(lst, str);
	else if (lst->point == 0 && index == 2)
		pf_stringjoin(lst, str, len_strwchar(wstr), 1);
	else if (index == 2)
		pf_stringjoin(lst, str, nlen_strwchar(wstr, lst->preci), 1);
}

static void	pf_string(t_pf *lst, wuchar_t *str, wchar_t *wstr, int index)
{
	int max;

	if (index == 2)
		max = len_strwchar(wstr);
	else
		max = ft_strlen(str);
	if (lst->point == 1)
		max = ft_min2(lst->preci, max);
	pf_putprefix(lst, max, lst->field, lst->zero);
	pf_putstring(lst, str, wstr, index);
	pf_putprefix(lst, 0, -lst->field, 0);
}

int			ft_params_string(t_pf *lst, char *str, int index)
{
	wuchar_t	*cstr;
	wchar_t		*wstr;

	lst_putoption(lst, str, index);
	if ((lst->lenght >= 10 && lst->lenght <= 20) || lst->conv == 'S')
	{
		wstr = va_arg(lst->va_copy, wchar_t*);
		if (wstr == NULL)
			wstr = L"(null)";
		pf_string(lst, cstr, wstr, 2);
	}
	else
	{
		cstr = (char*)va_arg(lst->va_copy, char*);
		if (cstr == NULL)
			cstr = "(null)";
		cstr = ft_strdup(cstr);
		if (lst->conv == 'r')
			pf_string(lst, cstr, wstr, 0);
		else
			pf_string(lst, cstr, wstr, 1);
	}
	return (index + 1);
}
