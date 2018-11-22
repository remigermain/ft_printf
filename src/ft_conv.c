/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/11 15:09:25 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/20 22:09:35 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int	*ft_conv3(t_valst *lst_va, char *str, int *tab_i, int index)
{
	int t_index;

	t_index = index;
	if (str[tab_i[0] + index] == '+' || str[tab_i[0] + index] == '-')
		index++;
	else if (str[tab_i[0] + index] == '.')
		index++;
	else if (str[tab_i[0] + index] == '#')
		index++;
	else if (str[tab_i[0] + index] == '$')
		index++;
	else if (str[tab_i[0] + index] == '*')
		index++;
	else if (str[tab_i[0] + index] == ' ')
		index++;
	while (ft_isdigit(str[tab_i[0] + index]))
		index++;
	if (t_index != index)
		tab_i = (ft_conv(lst_va, str, tab_i, index));
	else if (t_index == index)
		tab_i[0] += index;
	return (tab_i);
}

int	*ft_conv2(t_valst *lst_va, char *str, int *tab_i, int index)
{/*
	if (str[tab_i[0] + index] == 'u')
		tab_i = ft_params_u(lst_va, str, tab_i, index);
	else if (str[tab_i[0] + index] == 'U')
		tab_i = ft_params_u2(lst_va, str, tab_i, index);
	else if (str[tab_i[0] + index] == '%')
		tab_i = ft_params_perc(lst_va, str, tab_i, index);
	else if (str[tab_i[0] + index] == 'l' && str[tab_i[0] + index + 1] == 'd')
		tab_i = ft_params_d2(lst_va, str, tab_i, index + 1);
	else if (str[tab_i[0] + index] == 'l' && str[tab_i[0] + index + 1] == 'i')
		tab_i = ft_params_d2(lst_va, str, tab_i, index + 1);
	else if (str[tab_i[0] + index] == 'l' && str[tab_i[0] + index + 1] == 'u')
		tab_i = ft_params_u2(lst_va, str, tab_i, index + 1);
	else if (str[tab_i[0] + index] == 'l' && str[tab_i[0] + index + 1] == 'o')
		tab_i = ft_params_o2(lst_va, str, tab_i, index + 1);
	else if (str[tab_i[0] + index] == 'l' && (str[tab_i[0] + index + 1] == 'x'
				|| str[tab_i[0] + index + 1] == 'X'))
		tab_i = ft_params_x2(lst_va, str, tab_i, index + 1);
	else*/
		tab_i = ft_conv3(lst_va, str, tab_i, index);
	return (tab_i);
}

int	*ft_conv(t_valst *lst_va, char *str, int *tab_i, int index)
{
	if (str[tab_i[0] + index] == 'd' || str[tab_i[0] + index] == 'i'
			|| str[tab_i[0] + index] == 'I')
		tab_i = ft_params_d(lst_va, str, tab_i, index);
/*	else if (str[tab_i[0] + index] == 'D')
		tab_i = ft_params_d2(lst_va, str, tab_i, index);
	else if (str[tab_i[0] + index] == 'o' || str[tab_i[0] + index] == 'O')
		tab_i = ft_params_o(lst_va, str, tab_i, index);
	else if (str[tab_i[0] + index] == 'c' || str[tab_i[0] + index] == 'C')
		tab_i = ft_params_c(lst_va, str, tab_i, index);*/
	else if (str[tab_i[0] + index] == 's' || str[tab_i[0] + index] == 'S')
		tab_i = ft_params_s(lst_va, str, tab_i, index);/*
	else if (str[tab_i[0] + index] == 'p' || str[tab_i[0] + index] == 'P')
		tab_i = ft_params_p(lst_va, str, tab_i, index);
	else if (str[tab_i[0] + index] == 'x' || str[tab_i[0] + index] == 'X')
		tab_i = ft_params_x(lst_va, str, tab_i, index);*/
	else
		tab_i = ft_conv2(lst_va, str, tab_i, index);
	return (tab_i);
}
