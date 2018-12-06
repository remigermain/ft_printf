/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/11 15:09:25 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/06 20:26:24 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conv2(t_valst *lst_va, char *str, int i, int index)
{
	int t_index;

	t_index = index;
	if (str[i + index] == '+' || str[i + index] == '-')
		index++;
	else if (str[i + index] == ' ' || str[i + index] == '.')
		index++;
	else if (str[i + index] == '#' || str[i + index] == '$' ||
			str[i + index] == '*')
		index++;
	else if (str[i + index] == 'l' || str[i + index] == 'h')
		index++;
	else if (str[i + index] == 'j' || str[i + index] == 'z')
		index++;
	else if (str[i + index] == 'L' || str[i + index] == 39)
		index++;
	while (ft_isdigit(str[i + index]))
		index++;
	if (t_index != index)
		i = (ft_conv(lst_va, str, i, index));
	else
		return (i + index);
	return (i);
}

int	ft_conv(t_valst *lst_va, char *str, int i, int index)
{
	if (str[i + index] == '\0')
		i += index;
	else if (str[i + index] == 'd' || str[i + index] == 'i' ||
			str[i + index] == 'D' || str[i + index] == 'I' ||
			str[i + index] == 'x' || str[i + index] == 'X' ||
			str[i + index] == 'o' || str[i + index] == 'O' ||
			str[i + index] == 'u' || str[i + index] == 'U' ||
			str[i + index] == 'p' || str[i + index] == 'b' ||
			str[i + index] == 'B')
		i += ft_params_nb(lst_va, str, i, index);
	else
		i = ft_conv2(lst_va, str, i, index);
	return (i);
}
