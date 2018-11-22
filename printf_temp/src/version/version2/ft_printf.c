/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/11 15:09:25 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/13 22:30:17 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		*ft_main_params2(va_list lst_va, char *str, int *tab_i, int index)
{
	int t_index;

	t_index = index;
	if (str[tab_i[0] + index] == '+' || str[tab_i[0] + index] == '-')
		index++;
	else if (str[tab_i[0] + index] == '.')
		index++;
	else if (str[tab_i[0] + index] == ' ')
		index++;
	else if (str[tab_i[0] + index] == '*')
		index++;
	while (ft_isdigit(str[tab_i[0] + index]))
		index++;
	if (t_index != index)
		tab_i = (ft_main_params(lst_va, str, tab_i, index));
	return (tab_i);
}

int		*ft_main_params(va_list lst_va, char *str, int *tab_i, int index)
{
	if (str[tab_i[0] + index] == 'd')
		tab_i = ft_params_d(lst_va, str, tab_i, index);/*
	else if (str[tab_i[0] + index] == 's')
		tab_i = ft_params_s(lst_va, str, tab_i, index);
	else if (str[tab_i[0] + index] == 'c')
		tab_i = ft_params_c(lst_va, str, tab_i, index);
	else if (str[tab_i[0] + index] == 'p')
		tab_i = ft_params_p(lst_va, str, tab_i, index);
	if (str[tab_i[0] + index] == '%')
		tab_i = ft_params_perc(lst_va, str, tab_i, index);*/
	else
		tab_i = ft_main_params2(lst_va, str, tab_i, index);
	return (tab_i);
}

int		ft_printf(const char *format, ...)
{
	va_list		l_va;
	t_valst		*lst_va;
	int			*tab_i;

	va_start(lst_va, format);
	lst_va = malloc(sizeof(t_valst));
	va_copy(lst_va->lst_va, l_va);
	tab_i = malloc(sizeof(int) * 2);
	tab_i[0] = 0;
	tab_i[1] = 0;
	while (format[tab_i[0]] != '\0')
	{
		if (format[tab_i[0]] == '%')
			tab_i = ft_main_params(lst_va, (char*)format, tab_i, 1);
		else
		{
			ft_putchar(format[tab_i[0]++]);
			tab_i[1]++;
		}
	}
	va_end(lst_va);
	return (tab_i[1]);
}
