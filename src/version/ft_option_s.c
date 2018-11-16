/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_option_d.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/12 12:38:05 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/13 14:39:30 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_put_params_s2(char *new, int b)
{
	char *tmp;

	tmp = new;
	new = ft_strncpy(ft_strnew(b), new, b);
	free(tmp);
	return (new);
}

char	*ft_put_params_s(char *new, int tab[4])
{
	while (tab[3] < tab[1]--)
	{
		if (tab[2] == '-')
			new = ft_strjoin_s1(new, " ");
		else
			new = ft_strjoin_s2(" ", new);
	}
	return (new);
}

char	*ft_d_option_s(va_list lst_va, char *str, int count, int index)
{
	char	*new;
	int		tab[4];

	new = ft_strdup(va_arg(lst_va, char*));
	tab[0] = 0;
	tab[1] = 0;
	tab[2] = 0;
	tab[3] = count - 1;
	if (new == NULL)
		new = ft_strdup("(null)");
	while (index--)
	{
		if (str[count] == '+' || str[count] == '-')
			tab[2] = (int)str[count];
		if (str[count] == '.')
			tab[0] = 1;
		while (ft_isdigit(str[count]))
			tab[1] = ((tab[1] * 10) + (str[count++] - '0'));
		count++;
	}
	if (count < tab[1] && tab[0] == 0)
		new = ft_put_params_s(new, tab);
	else if (tab[0] == 1)
		new = ft_put_params_s2(new, tab[1]);
	return (new);
}
