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

static wuchar_t 	*comv_pstr(t_pf *lst, wuchar_t *str, size_t len)
{
	wuchar_t *new;
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (!(new = (wuchar_t*)malloc(sizeof(wuchar_t) * len + 1)))
		ftprintf_error(lst, "pf_putpstr", 1);
	while (str[i] != '\0' && i < len)
	{
		if (str[i] == '\n')
			new[j++] = '$';
		if (ft_isprint(str[i]) || str[i] == '\n' || str[i] == '\t')
			new[j++] = str[i++];
		else
		{
			new[j++] = '^';
			new[j++] = (str[i++] + 64);
		}
	}
	free(str);
	return (new);
}

static wuchar_t *comv_wstr(t_pf *lst, wchar_t *wstr, size_t len)
{
	wuchar_t *str;
	size_t i;
	size_t count;

	i = 0;
	count = 0;
	if (!(str = (wuchar_t*)malloc(sizeof(wuchar_t) * nlen_wchar(wstr, len))))
		ftprintf_error(lst, "comv_wstr", 1);;
	while (wstr[count] != '\0' && count < len)
		convert_wchar(&str, wstr[count++], &i);
	return (str);
}

void	pf_string(t_pf *lst, wuchar_t *str, wchar_t *wstr, int index)
{
	size_t len;
	size_t max;

	if (index == 2)
		max = len_wchar(wstr);
	else
		max = ft_ustrlen(str);
	if (lst->point == 1)
		max = ft_min2(lst->preci, max);
	put_prefix(lst, max, lst->field, lst->zero);
	if (index == 0)
		len = len_pstrn(str, lst->preci, lst->point);
	else if (index == 1)
		len = (lst->point == 0 ? ft_ustrlen(str) : ft_ustrnlen(str, lst->preci));
	else
		len = (lst->point == 0 ? len_wchar(wstr) : nlen_wchar(wstr, lst->preci));
	if (index == 0)
		str = comv_pstr(lst, str, len);
	else if (index == 2)
		str = comv_wstr(lst, wstr, len);
	put_buff(lst, str, len, 1);
	put_prefix(lst, 0, -lst->field, 0);
}

int			conv_string(t_pf *lst, char *str, int index)
{
	wuchar_t	*ustr;
	wchar_t		*wstr;

	lst_putoption(lst, str, index);
	if ((lst->lenght >= 10 && lst->lenght <= 20) || lst->conv == 'S')
	{
		wstr = va_arg(lst->va_copy, wchar_t*);
		if (wstr == NULL)
			wstr = L"(null)";
		pf_string(lst, NULL, wstr, 2);
	}
	else
	{
		ustr = (wuchar_t*)va_arg(lst->va_copy, char*);
		if (ustr == NULL)
			str = "(null)";
		ustr = ft_ustrdup(ustr);
		pf_string(lst, ustr, NULL, (lst->conv == 'r' ? 0 : 1));
	}
	return (index + 1);
}
