/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_option_d.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/12 12:38:05 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/12 16:52:31 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_d_option_perc(va_list lst_va, char *str, int count, int index)
{
	char	*new;
	int		b;
	int		id;

	new = ft_strnew(2);
	new[0] = '%';
	b = 0;
	id = 0;
	while (index--)
	{
		if (str[count] == '+' || str[count] == '-')
			id = (int)str[count];
		while (ft_isdigit(str[count]))
			b = ((b * 10) + (str[count++] - '0'));
		count++;
	}
	while (b-- > 1)
	{
		if (id == '-')
			new = ft_strjoin_s1(new, " ");
		else
			new = ft_strjoin_s2(" ", new);
	}
	return (new);
}
