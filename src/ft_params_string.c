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
	size_t len2;
	size_t i;
	size_t count;

	len2 = ft_countnwchars(wstr, len); 
	i = 0;
	count = 0;
	if (!(str = (wuchar_t*)malloc(sizeof(wuchar_t) * len2)))
		return (NULL);
	while (wstr[count] != '\0' && count < len)
	{
		if (wstr[count] <= 0x7F)
			str[i++] = wstr[count];
		else if (wstr[count] <= 0x7FF)
		{
			str[i++] = 192 + (wstr[count] / 64);
			str[i++] = 128 + (wstr[count] % 64);
		}
		else if (wstr[count] <= 0xFFFF)
		{
			str[i++] = 224 + (wstr[count] / 4096);
			str[i++] = 128 + ((wstr[count] / 64) % 64);
			str[i++] = 128 + (wstr[count] % 64);
		}
		else if (wstr[count] <= 0x10FFFF)
		{
			str[i++] = 240 + (wstr[count] / 262144);
			str[i++] = 128 + ((wstr[count] / 4096) % 64);
			str[i++] = 128 + ((wstr[count] / 64) % 64);
			str[i++] = 128 + (wstr[count] % 64);
		}
		count++;
	}
	return (str);
}

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

static	int	ft_print_string(t_pf *lst, wuchar_t *str, wchar_t *wstr, int index)
{
	int count;

	count = 0;
	if (lst->point == 0 && index == 1)
		pf_tmpjoin(lst, str, ft_strlen(str));
	else if (index == 1)
		pf_tmpjoin(lst, str, ft_min2(ft_strlen(str), lst->preci));
	else if (index == 0)
		pf_putpstr(lst, str);
	else if (lst->point == 0 && index == 2)
		pf_tmpjoin(lst, comv_wstr(wstr, ft_countwchars(wstr)), ft_countwchars(wstr));
	else if (index == 2)
		pf_tmpjoin(lst, comv_wstr(wstr, lst->preci), ft_countnwchars(wstr, lst->preci));
	return (count);
}

static int	ft_option_string(t_pf *lst, wuchar_t *str, wchar_t *wstr, int index)
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
	ft_putprefix(lst, max, lst->field, lst->zero);
	ft_print_string(lst, str, wstr, index);
	ft_putprefix(lst, count, -lst->field, 0);
	return (count);
}

static void	initstring(t_valst *lst_va, wuchar_t **cstr, wchar_t **wstr, int index)
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
			*cstr = ft_strndup("(null)", 6);
	}
}

int			ft_params_string(t_valst *lst_va, char *str, int index)
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
		count = ft_option_string(lst, cstr, wstr, 2);
	}
	else
	{
		initstring(lst_va, &cstr, &wstr, 0);
		if (lst->conv == 'r')
			count = ft_option_string(lst, cstr, wstr, 0);
		else
			count = ft_option_string(lst, cstr, wstr, 1);
	}
	if (count == -1)
		lst_va->count = -1;
	else
		pf_finaljoin(lst_va, lst->str, lst->count);
	free(lst->str);
	free(lst);
	return (index + 1);
}
