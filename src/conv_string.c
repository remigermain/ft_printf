/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   conv_string.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/04 16:24:33 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/04 16:24:34 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static wuchar_t	*comv_pstr(t_pf *lst, wuchar_t *str, size_t len)
{
	wuchar_t	*new;
	size_t		i;
	size_t		j;

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

static wuchar_t	*comv_wstr(t_pf *lst, wchar_t *wstr, size_t len)
{
	wuchar_t	*str;
	size_t		i;
	size_t		count;

	i = 0;
	count = 0;
	if (!(str = (wuchar_t*)malloc(sizeof(wuchar_t) * nlen_wchar(wstr, len))))
		ftprintf_error(lst, "comv_wstr", 1);
	while (wstr[count] != '\0' && count < len)
		convert_wchar(&str, wstr[count++], &i);
	return (str);
}

void			pf_string(t_pf *lst, wuchar_t *str, wchar_t *wstr, int index)
{
	size_t	len;
	int		max;

	if (index == 2)
		max = len_wchar(wstr);
	else
		max = ft_ustrlen(str);
	if (max == -1)
		return ;
	if (POINT == 1)
		max = ft_min2(PRECI, max);
	put_prefix(lst, max, FIELD, ZERO);
	if (index == 0)
		len = len_pstrn(str, PRECI, POINT);
	else if (index == 1)
		len = (POINT == 0 ? ft_ustrlen(str) : ft_ustrnlen(str, PRECI));
	else
		len = (POINT == 0 ? len_wchar(wstr) : nlen_wchar(wstr, PRECI));
	if (index == 0)
		str = comv_pstr(lst, str, len);
	else if (index == 2)
		str = comv_wstr(lst, wstr, len);
	put_buff(lst, str, len, 1);
	put_prefix(lst, max, -FIELD, 0);
}

int				conv_string(t_pf *lst, char *str, int index)
{
	wuchar_t	*ustr;
	wchar_t		*wstr;

	lst_putoption(lst, str, index);
	if ((LENGHT >= 10 && LENGHT <= 20) || CONV == 'S')
	{
		wstr = va_arg(lst->va_copy, wchar_t*);
		if (wstr == NULL)
			pf_string(lst, ft_strudup("(null)"), NULL, 1);
		else
			pf_string(lst, NULL, wstr, 2);
	}
	else
	{
		ustr = (wuchar_t*)va_arg(lst->va_copy, char*);
		if (ustr == NULL)
			ustr = ft_strudup("(null)");
		else
			ustr = ft_ustrdup(ustr);
		pf_string(lst, ustr, NULL, (CONV == 'r' ? 0 : 1));
	}
	return (index + 1);
}
