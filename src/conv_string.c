/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   conv_string.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/04 16:38:13 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/31 15:54:22 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static UCHAR	*comv_pstr(t_pf *lst, UCHAR *str, size_t len)
{
	UCHAR	*new;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!(new = (UCHAR*)malloc(sizeof(UCHAR) * len + 1)))
		ERROR(lst, "pf_putpstr", 1);
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

static UCHAR	*comv_wstr(t_pf *lst, wchar_t *wstr, size_t len)
{
	UCHAR	*str;
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	if (!(str = (UCHAR*)malloc(sizeof(UCHAR) * nlen_wchar(wstr, len))))
		ERROR(lst, "comv_wstr", 1);
	while (wstr[count] != '\0' && count < len && i < len)
		convert_wchar(&str, wstr[count++], &i);
	return (str);
}

void			pf_string(t_pf *lst, UCHAR *str, wchar_t *wstr, int index)
{
	size_t	max;

	max = 0;
	if (index == 0)
		max = (POINT == 0 ? len_pstrn(str, 0, 1) : len_pstrn(str, PRECI, 0));
	else if (index == 1)
		max = (POINT == 0 ? ft_ustrlen(str) : ft_ustrnlen(str, PRECI));
	else if (index == 2)
		max = (POINT == 0 ? len_wchar(wstr) : nlen_wchar(wstr, PRECI));
	put_prefix(lst, max, FIELD, ZERO);
	if (index == 0)
		str = comv_pstr(lst, str, max);
	else if (index == 2)
		str = comv_wstr(lst, wstr, max);
	put_buff(lst, str, max, 1);
	put_prefix(lst, max, -FIELD, 0);
}

void			conv_string(t_pf *lst)
{
	UCHAR	*ustr;
	wchar_t	*wstr;

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
		if (CONV == 'm')
			ustr = ft_strudup(strerror(errno));
		else
		{
			ustr = (UCHAR*)va_arg(lst->va_copy, char*);
			if (ustr == NULL)
				ustr = ft_strudup("(null)");
			else
				ustr = ft_ustrdup(ustr);
		}
		pf_string(lst, ustr, NULL, (CONV == 'r' ? 0 : 1));
	}
}
