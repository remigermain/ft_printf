/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_option_d.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/12 12:38:05 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/13 15:51:01 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_put_params_d5(int nb, int id, char **new)
{
	if (nb < 0)
	{
		*new = ft_strjoin_s1(*new, "-");
		nb = -nb;
	}
	else if (id == '+' && nb >= 0)
		*new = ft_strjoin_s1(*new, "+");
	return (nb);
}

int		ft_put_params_d2(int nb, int id, int point, char **new)
{
	if ((id != 0 && nb >= 0) || point == 1)
	{
		if (point == 0)
			nb = ft_put_params_d5(nb, id, new);
		else
		{
			if (nb < 0)
			{
				nb = -nb;
				*new = ft_strjoin_s2("-", *new);
			}
			else if (id == '+' && nb >= 0)
				*new = ft_strjoin_s2("+", *new);
		}
	}
	return (nb);
}

void	ft_put_params_d3(int nb, int id, int point, char **new)
{
	char	*tmp;

	tmp = ft_itoa(nb);
	if (id == '-' && point != 1)
		*new = ft_strjoin_s1(*new, tmp);
	else if (point == 0)
		*new = ft_strjoin_s2(tmp, *new);
	else if (point == 1)
	{
		if (nb < 0)
			nb -= nb;
		*new = ft_strjoin_s1(*new, tmp);
	}
	free(tmp);
}

char	*ft_put_params_d(int nb, int id, int point, int b)
{
	char	*new;

	new = NULL;
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
		{
			if (new == NULL)
				new = ft_strdup("0");
			else
				new = ft_strjoin_s2("0", new);
		}
	}
	if (new == NULL)
		new = ft_strdup("");
	nb = ft_put_params_d2(nb, id, point, &new);
	ft_put_params_d3(nb, id, point, &new);
	return (new);
}

char	*ft_d_option_d(va_list lst_va, char *str, int count, int index)
{
	int	nb;
	int	b;
	int	point;
	int	id;

	nb = va_arg(lst_va, int);
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
	return (ft_put_params_d(nb, id, point, b));
}
