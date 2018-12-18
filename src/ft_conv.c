/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/11 15:09:25 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/18 16:06:34 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conv3(t_valst *lst_va, char *str, int i, int index)
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
	else if (t_index == index)
		i += ft_params_no(lst_va, str, i, index);
	return (i);
}

int	ft_conv2(t_valst *lst_va, char *str, int i, int index)
{
	int	nb;

	if (str[i + index] == 'n')
	{
		nb = va_arg(lst_va->copy, int);
		nb = lst_va->count;
		i += index + 1;
	}
	else if (str[i + index] == 'f' || str[i + index] == 'F'
			|| str[i + index] == 'e' || str[i + index] == 'E'
			|| str[i + index] == 'g' || str[i + index] == 'G')
		i += ft_params_f(lst_va, str, i, index);
	else if (str[i + index] == 'a' || str[i + index] == 'A')
		i += ft_params_a(lst_va, str, i, index);
	else
		i = ft_conv3(lst_va, str, i, index);
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
	else if (str[i + index] == 'c' || str[i + index] == 'C')
		i += ft_params_char(lst_va, str, i, index);
	else if (str[i + index] == 'k')
		i += ft_params_k(lst_va, str, i, index);
	else if (str[i + index] == '%')
		i += ft_params_perc(lst_va, str, i, index);
	else if (str[i + index] == 's' || str[i + index] == 'r')
		i += ft_params_string(lst_va, str, i, index);
	else if (str[i + index] == 't' && str[i + index + 1] == 's')
		i += ft_params_ts(lst_va, str, i, index);
	else if (str[i + index] == 't' && str[i + index + 1] == 'i')
		i += ft_params_ti(lst_va, str, i, index);
	else
		i = ft_conv2(lst_va, str, i, index);
	return (i);
}
