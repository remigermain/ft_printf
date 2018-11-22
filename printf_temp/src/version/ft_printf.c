/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/11 15:09:25 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/13 14:37:33 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_main_params2(va_list lst_va, char **str, int count, int index)
{
	int t_index;

	t_index = index;
	if ((*str)[count + index] == '+' || (*str)[count + index] == '-')
		index++;
	else if ((*str)[count + index] == '.')
		index++;
	else if (ft_isdigit((*str)[count + index]))
		index++;
	if (t_index != index)
		return (ft_main_params(lst_va, str, count, index));
	else
		return (count);
}

int		ft_main_params(va_list lst_va, char **str, int count, int index)
{
	if ((*str)[count + index] == 'd')
		count = ft_params_d(lst_va, str, count, index);
	else if ((*str)[count + index] == 's')
		count = ft_params_s(lst_va, str, count, index);
	else if ((*str)[count + index] == 'c')
		count = ft_params_c(lst_va, str, count, index);
	else if ((*str)[count + index] == 'p')
		count = ft_params_p(lst_va, str, count, index);
	if ((*str)[count + index] == '%')
		count = ft_params_perc(lst_va, str, count, index);
	else
		count = ft_main_params2(lst_va, str, count, index);
	return (count);
}

int		ft_printf(const char *format, ...)
{
	va_list		lst_va;
	char		*str;
	int			count;
	int			index;

	va_start(lst_va, format);
	str = ft_strdup((char*)format);
	count = 0;
	index = 1;
	while (str[count] != '\0')
	{
		if (str[count] == '%')
			count = ft_main_params(lst_va, &str, count, index);
		else
			count++;
	}
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}
