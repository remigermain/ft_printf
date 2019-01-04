/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   conv_char.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/04 16:23:36 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/04 16:23:41 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static wuchar_t	*pf_convwchar(t_pf *lst, wchar_t wc)
{
	wuchar_t	*new;
	size_t		a;

	if (!(new = (wuchar_t*)malloc(sizeof(wuchar_t) * len_wchar_single(wc) + 1)))
		ftprintf_error(lst, "pf_convwchar", 1);
	a = 0;
	convert_wchar(&new, wc, &a);
	return (new);
}

static void		pf_putchar(t_pf *lst, wuchar_t c, wuchar_t *wc, int index)
{
	size_t max;

	if (index == 1)
		max = len_wuchart(wc);
	else
		max = 1;
	put_prefix(lst, max, FIELD, ZERO);
	put_buff(lst, (index == 1 ? wc : &c), max, index);
	put_prefix(lst, max, -FIELD, 0);
}

int				conv_char(t_pf *lst, char *str, int index)
{
	wuchar_t	*wc;
	size_t		verif;

	lst_putoption(lst, str, index);
	if (CONV != 'c' && CONV != 'C')
		pf_putchar(lst, str[index], 0, 0);
	else
	{
		verif = va_arg(lst->va_copy, int);
		if (verif > 127)
			wc = pf_convwchar(lst, verif);
		if (((LENGHT >= 10 && LENGHT <= 20) || CONV == 'C')
				&& verif > 127)
			pf_putchar(lst, 0, wc, 1);
		else
			pf_putchar(lst, (char)verif, 0, 0);
	}
	return (index + 1);
}
