/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_params_char.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/10 16:21:44 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/19 22:20:41 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static int		verif(wchar_t *str)
{
	int count;
	int	a;

	count = 0;
	a = 0;
	while (str[a] != '\0')
	{
		if (str[a] > 0x10FFFF)
			return (-1);
		a++;
	}
	return (count);
}

static int		count_wchart(wchar_t *str)
{
	int count;
	int	a;

	count = 0;
	a = 0;
	while (str[a] != '\0')
		count += ft_countwchar(str[a++]);
	return (count);
}

static int		ft_option_string2(t_pf *lst, wchar_t *str)
{
	int count;
	int max;
	int len;

	count = 0;
	len = count_wchart(str);
	if (verif(str) == -1)
		return (-1);
	if (lst->point == 1)
		max = ft_min2(lst->preci, len);
	else
		max = len;
	count += ft_print_prefix(max, lst->field, lst->zero, lst->fd);
	if (lst->point == 0)
		count += ft_putstrw_fd(str, lst->fd);
	else
		count += ft_putnstrw_fd(str, lst->preci, lst->fd);
	count += ft_print_prefix(count, -lst->field, 0, lst->fd);
	return (count);
}

int				ft_params_lstring(t_valst *lst_va, t_pf *lst)
{
	int		count;
	wchar_t	*str2;

	count = 0;
	str2 = va_arg(lst_va->copy, wchar_t*);
	if (str2 == NULL)
		str2 = L"(null)";
	count = ft_option_string2(lst, str2);
	return (count);
}
