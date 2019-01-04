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

static int	find_conv3(t_pf *lst, char *str, int index)
{
	int t_index;

	t_index = index;
	if (str[index] == '+' || str[index] == '-' || str[index] == ' ' ||
	str[index] == '.' || str[index] == '#' || str[index] == '$' ||
	str[index] == '*' || str[index] == 'l' || str[index] == 'h' ||
	str[index] == 'j' || str[index] == 'z' || str[index] == 'L' ||
		str[index] == '\'')
		index++;
	while (ft_isdigit(str[index]))
		index++;
	if (t_index != index)
		index = (find_conv(lst, str, index));
	else if (t_index == index)
		index = conv_char(lst, str, index);
	return (index);
}

static int	find_conv2(t_pf *lst, char *str, int index)
{
	int	*nb;

	if (str[index] == 'n')
	{
		nb = va_arg(lst->va_copy, int*);
		*nb = lst->count;
		index += 1;
	}
	else if (str[index] == 'f' || str[index] == 'F' ||
				str[index] == 'e' || str[index] == 'E' ||
			str[index] == 'g' || str[index] == 'G' ||
		str[index] == 'a' || str[index] == 'A')
			index = conv_double(lst, str, index);
	else if (str[index] == 's' || str[index] == 'r' ||
			str[index] == 'S')
		index = conv_string(lst, str, index);
	else
		index = find_conv3(lst, str, index);
	return (index);
}

int	find_conv(t_pf *lst, char *str, int index)
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
		index = conv_int(lst, str, index);
	else if (str[index] == 'c' || str[index] == 'C' || str[index] == '%')
		index = conv_char(lst, str, index);
	else if (str[index] == 't' && str[index + 1] == 's')
		index = conv_tabstring(lst, str, index + 1);
	else if (str[index] == '@')
		index = conv_other(lst, str, index);
	else if (str[index] == '{')
		index = conv_color(lst, str, index + 1);
	else
		index = find_conv2(lst, str, index);
	return (index);
}
