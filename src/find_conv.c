/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/11 15:09:25 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/04 19:54:49 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int			find_conv(t_pf *lst, char *str, int ret)
{
	int	*nb;

	ret = lst_putoption(lst, str, 1);
	if (CONV == 'n' && (nb = va_arg(lst->va_copy, int*)))
		*nb = lst->count;
	else if (CONV == 'f' || CONV == 'F' || CONV == 'e' || CONV == 'E' ||
			CONV == 'g' || CONV == 'G')
		conv_double(lst);
	else if (CONV == 's' || CONV == 'r' || CONV == 'S')
		conv_string(lst);
	else if (CONV == 'd' || CONV == 'i' || CONV == 'D' || CONV == 'I' ||
		CONV == 'x' || CONV == 'X' || CONV == 'o' || CONV == 'O' || CONV == 'u'
		|| CONV == 'U' || CONV == 'p' || CONV == 'b' || CONV == 'B')
		conv_int(lst);
	else if (CONV == 't' && str[ret + 1] == 's')
		conv_tabstring(lst);
	else if (CONV == '@')
		conv_other(lst);
	else if (CONV == '{')
		conv_color(lst, str, 0 + 1);
	else if (CONV != 0)
		conv_char(lst);
	return (ret);
}
