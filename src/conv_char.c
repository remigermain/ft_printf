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

static wuchar_t *pf_convwchar(t_pf *lst, wchar_t wc)
{
	wuchar_t	*new;
	size_t		a;

	if (!(new = (wuchar_t*)malloc(sizeof(wuchar_t) * len_wchar_single(wc) + 1)))
		ftprintf_error(lst, "pf_convwchar", 1);
	a = 0;
	convert_wchar(&new, wc, &a);
	return (new);
}

static void	pf_putchar(t_pf *lst, wuchar_t c, wuchar_t *wc, int index)
{
	size_t max;
	wuchar_t *new;

	if (index == 1)
		max = len_wuchart(wc);
	else
		max = 1;
	pf_putprefix(lst, max, lst->field, lst->zero);
	if (!(new = (wuchar_t*)malloc(sizeof(wuchar_t) * max + lst->tmp_count + 1)))
		ftprintf_error(lst, "pf_string join", 1);
	ft_memcpy(new, lst->tmp_str, lst->tmp_count);
	ft_memcpy(new + lst->tmp_count, (index == 1 ? wc : &c), max);
	lst->tmp_count += max;
	new[lst->tmp_count] = '\0';
	if (lst->tmp_str != NULL)
		free(lst->tmp_str);
	lst->tmp_str = new;
	if (index == 1)
		free(wc);
	pf_putprefix(lst, max, -lst->field, 0);
}

int			conv_char(t_pf *lst, char *str, int index)
{
	wuchar_t *wc;

	lst_putoption(lst, str, index);
	if ((lst->lenght >= 10 && lst->lenght <= 20) || lst->conv == 'C')
	{
		wc = pf_convwchar(lst, va_arg(lst->va_copy, wchar_t));
		pf_putchar(lst, 0, wc, 1);
	}
	else if (lst->conv == 'c')
		pf_putchar(lst, (wuchar_t)(char)va_arg(lst->va_copy, int), 0, 0);
	else
		pf_putchar(lst, str[index], 0, 0);
	pf_stringjoin(lst, lst->tmp_str, lst->tmp_count, 1);
	return (index + 1);
}
