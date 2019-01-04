/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   conv_char.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/04 16:37:51 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/04 19:38:26 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static WUCHAR_T	*pf_convwchar(t_pf *lst, wchar_t wc)
{
	WUCHAR_T	*new;
	size_t		a;

	if (!(new = (WUCHAR_T*)malloc(len_wchar_single(wc) + 1)))
		ftprintf_error(lst, "pf_convwchar", 1);
	a = 0;
	convert_wchar(&new, wc, &a);
	return (new);
}

static void		pf_putchar(t_pf *lst, WUCHAR_T c, WUCHAR_T *wc, int index)
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

void			conv_char(t_pf *lst)
{
	WUCHAR_T	*wc;
	size_t		verif;

	if (CONV != 'c' && CONV != 'C')
		pf_putchar(lst, CONV, 0, 0);
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
}
