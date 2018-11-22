/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_option_d.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/12 12:38:05 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/12 15:53:07 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_params_p2(long nb, int id, int point, char **new)
{
	char	*tmp;

	tmp = ft_itoa_base(nb, 16, 0);
	if (!*new)
		*new = ft_strdup("");
	if (id == '-')
	{
		*new = ft_strjoin_s2(tmp, *new);
		*new = ft_strjoin_s2("0x", *new);
	}
	else
		*new = ft_strjoin_s1(*new, tmp);
	free(tmp);
}

char	*ft_put_params_p(long nb, int id, int point, int b)
{
	char	*new;

	new = NULL;
	if (id != '-')
		new = ft_strdup("0x");
	if (point == 1)
		b++;
	else if (point == 0)
		b--;
	while (ft_intlen(nb, 10) < b--)
	{
		if (point == 0)
		{
			if (new == NULL)
				new = ft_strdup(" ");
			else
				new = ft_strjoin_s2(" ", new);
		}
		else
			new = ft_strjoin_s1(new, "0");
	}
	ft_put_params_p2(nb, id, point, &new);
	return (new);
}

char	*ft_d_option_p(va_list lst_va, char *str, int count, int index)
{
	long	nb;
	int		b;
	int		point;
	int		id;

	nb = va_arg(lst_va, long);
	point = 0;
	b = 0;
	id = 0;
	while (index--)
	{
		if (str[count] == '+' || str[count] == '-')
			id = (int)str[count];
		if (str[count] == '.')
			point = 1;
		while (ft_isdigit(str[count]))
			b = ((b * 10) + (str[count++] - '0'));
		count++;
	}
	if (nb >= 0 && id == '+' && point == 0)
		b--;
	if (point == 1 && nb < 0)
		b++;
	return (ft_put_params_p(nb, id, point, b));
}
