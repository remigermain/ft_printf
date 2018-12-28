/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/11 15:09:25 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/19 22:31:53 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conv3(t_va *lst_va, char *str, int index)
{
	int t_index;

	t_index = index;
	if (str[index] == '+' || str[index] == '-')
		index++;
	else if (str[index] == ' ' || str[index] == '.')
		index++;
	else if (str[index] == '#' || str[index] == '$' ||
			str[index] == '*')
		index++;
	else if (str[index] == 'l' || str[index] == 'h')
		index++;
	else if (str[index] == 'j' || str[index] == 'z')
		index++;
	else if (str[index] == 'L' || str[index] == 39)
		index++;
	while (ft_isdigit(str[index]))
		index++;
	if (t_index != index)
		index = (ft_conv(lst_va, str, index));
	else if (t_index == index)
		index = ft_params_no(lst_va, str, index);
	return (index);
}

int	ft_conv2(t_va *lst_va, char *str, int index)
{
	int	*nb;

	if (str[index] == 'n')
	{
		nb = va_arg(lst_va->copy, int*);
		*nb = lst_va->count;
		index += 1;
	}
	else if (str[index] == 'f' || str[index] == 'F')
		index = ft_params_f(lst_va, str, index);
	else if (str[index] == 's' || str[index] == 'r' ||
			str[index] == 'S')
		index = ft_params_string(lst_va, str, index);
	else
		index = ft_conv3(lst_va, str, index);
	return (index);
}

int	ft_conv(t_va *lst_va, char *str, int index)
{
	if (str[index] == '\0')
		index = index;
	else if (str[index] == 'd' || str[index] == 'i' ||
			str[index] == 'D' || str[index] == 'I' ||
			str[index] == 'x' || str[index] == 'X' ||
			str[index] == 'o' || str[index] == 'O' ||
			str[index] == 'u' || str[index] == 'U' ||
			str[index] == 'p' || str[index] == 'b' ||
			str[index] == 'B')
		index = ft_params_nb(lst_va, str, index);
	else if (str[index] == 'c' || str[index] == 'C')
		index = ft_params_char(lst_va, str, index);
	else if (str[index] == 't' && str[index + 1] == 's')
		index = ft_params_ts(lst_va, str, index + 1);
	else if (str[index] == '%')
		index = ft_params_perc(lst_va, str, index);
	else
		index = ft_conv2(lst_va, str, index);
	return (index);
}
