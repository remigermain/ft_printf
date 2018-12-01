/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/11 15:09:25 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/01 15:43:34 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int	*ft_conv2(t_valst *lst_va, char *str, int *tab_i, int index)
{
	int t_index;

	t_index = index;
	if (str[tab_i[0] + index] == '+' || str[tab_i[0] + index] == '-')
		index++;
	else if (str[tab_i[0] + index] == ' ' || str[tab_i[0] + index] == '.')
		index++;
	else if (str[tab_i[0] + index] == '#' || str[tab_i[0] + index] == '$' ||
			str[tab_i[0] + index] == '*')
		index++;
	else if (str[tab_i[0] + index] == 'l' || str[tab_i[0] + index] == 'h')
		index++;
	else if (str[tab_i[0] + index] == 'j' || str[tab_i[0] + index] == 'z')
		index++;
	while (ft_isdigit(str[tab_i[0] + index]))
		index++;
	if (t_index != index)
		tab_i = (ft_conv(lst_va, str, tab_i, index));
	else if (t_index == index)
		tab_i = ft_params_no(lst_va, str, tab_i, index);
	return (tab_i);
}

int	*ft_conv(t_valst *lst_va, char *str, int *tab_i, int index)
{
	if (str[tab_i[0] + index] == '\0')
		tab_i[0] += index;
	else if (str[tab_i[0] + index] == 'd' || str[tab_i[0] + index] == 'i' ||
			str[tab_i[0] + index] == 'D' || str[tab_i[0] + index] == 'I' ||
			str[tab_i[0] + index] == 'x' || str[tab_i[0] + index] == 'X' ||
			str[tab_i[0] + index] == 'o' || str[tab_i[0] + index] == 'O' ||
			str[tab_i[0] + index] == 'u' || str[tab_i[0] + index] == 'U' ||
			str[tab_i[0] + index] == 'p')
		tab_i = ft_params_d(lst_va, str, tab_i, index);
	else if (str[tab_i[0] + index] == 'c')
		tab_i = ft_params_c(lst_va, str, tab_i, index);
	else if (str[tab_i[0] + index] == 'C')
		tab_i = ft_params_cmaj(lst_va, str, tab_i, index);
	else if (str[tab_i[0] + index] == '%')
		tab_i = ft_params_perc(lst_va, str, tab_i, index);
	else if (str[tab_i[0] + index] == 's')
		tab_i = ft_params_s(lst_va, str, tab_i, index);
	else if (str[tab_i[0] + index] == 'S')
		tab_i = ft_params_smaj(lst_va, str, tab_i, index);
	else
		tab_i = ft_conv2(lst_va, str, tab_i, index);
	return (tab_i);
}
