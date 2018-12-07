/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lst_init.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/06 13:27:18 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/07 13:39:12 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init_base(t_pf *lst)
{
	if (lst->conv == 'x' || lst->conv == 'X' || lst->conv == 'p' ||
			lst->conv == 'a' || lst->conv == 'A' ||
			lst->conv == 'e' || lst->conv == 'E')
		lst->base = 16;
	else if (lst->conv == 'u' || lst->conv == 'U' ||
			lst->conv == 'f' || lst->conv == 'F' ||
			lst->conv == 'i' || lst->conv == 'I' ||
			lst->conv == 'd' || lst->conv == 'D' ||
			lst->conv == 'g' || lst->conv == 'G')
		lst->base = 10;
	else if (lst->conv == 'o' || lst->conv == 'O')
		lst->base = 8;
	else if (lst->conv == 'b' || lst->conv == 'B')
		lst->base = 2;
	if (!ft_islowercase(lst->conv))
		lst->maj = 1;
}

void	ft_putflag_conv(t_pf *lst, char *str, int count)
{
	if (str[count] == 'h')
		lst->lenght++;
	else if (str[count] == 'l' || str[count] == 'L')
		lst->lenght += 10;
	else if (str[count] == 'j')
		lst->lenght += 100;
	else if (str[count] == 'z')
		lst->lenght += 1000;
	else if (str[count] == 't')
		lst->lenght += 10000;
	else
		lst->conv = str[count];
}

int		lst_putdigit2(t_valst *lst_va, t_pf *lst, char *str, int count)
{
	int nb_temp;

	nb_temp = 0;
	if (ft_isdigit(str[count]))
	{
		nb_temp = ft_atoi(str + count);
		count += ft_intlen(nb_temp);
	}
	else if (str[count] == '*' || str[count] == '$')
	{
		if (str[count] == '$')
		{
			nb_temp = ft_atoi(str + count + 1);
			lstva_digit(lst_va, nb_temp, 1, 0);
			count += ft_intlen(nb_temp);
		}
		nb_temp = va_arg(lst_va->copy, int);
		count++;
	}
	if (lst->point == 0)
		lst->field = (nb_temp * lst->nb_tmp);
	else if (lst->point == 1)
		lst->preci = (nb_temp * lst->nb_tmp);
	return (count);
}

int		lst_putdigit(t_valst *lst_va, t_pf *lst, char *str, int count)
{
	if (((str[count] == '+' || str[count] == '-') && (ft_isdigit(str[count + 1])
				|| str[count + 1] == '*' || str[count + 1] == '$')) ||
			ft_isdigit(str[count]) || str[count] == '*' || str[count] == '$')
	{
		lst->nb_tmp = 1;
		if (str[count] == '0' && lst->point == 0)
		{
			if (lst->sign != '+')
				lst->zero = 1;
			count++;
		}
		if (str[count] == '-' || str[count] == '+')
		{
			if (str[count] == '-')
				lst->nb_tmp = -1;
			count++;
		}
		count = lst_putdigit2(lst_va, lst, str, count);
	}
	else
		count++;
	return (count);
}

t_pf	*lst_initoption(t_valst *lst_va, char *str, int i, int index)
{
	t_pf	*lst;
	int		count;

	lst = ft_initpf(lst_va);
	count = i + 1;
	while (count <= (i + index))
	{
		if (str[count] == '+' || (str[count] == '-' &&
					!ft_isdigit(str[count + 1])))
			lst->sign = str[count];
		else if (str[count] == '.')
			lst->point = 1;
		else if (str[count] == 39)
			lst->local = 1;
		else if (str[count] == '#')
			lst->hash = 1;
		else if (str[count] == ' ')
			lst->space = 1;
		else if (ft_isalpha(str[count]))
			ft_putflag_conv(lst, str, count);
		count = lst_putdigit(lst_va, lst, str, count);
	}
	ft_init_base(lst);
	return (lst);
}
