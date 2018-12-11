/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lst_init.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/06 13:27:18 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/11 21:03:13 by rgermain    ###    #+. /#+    ###.fr     */
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
	if (lst->point == 1)
		lst->zero = 0;
}

int		ft_putflag_conv(t_pf *lst, char *str, int count)
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
	count++;
	return (count);
}

int		lst_putdigit(t_valst *lst_va, t_pf *lst, char *str, int count)
{
	int nb_tmp;

	nb_tmp = 0;
	if (str[count] == '+')
		lst->sign = str[count++];
	else if (str[count] == '-')
		lst->nb_tmp = str[count++] - 46;
	else if (ft_isdigit(str[count]) == 1 || str[count] == '*'
			|| str[count] == '$')
	{
		if (ft_isdigit(str[count]) == 1)
			nb_tmp = ft_atoi2(str + count, &count);
		if (str[count] == '*' || str[count] == '$')
		{
			if (str[count] == '$')
				lstva_digit(lst_va, nb_tmp, 0);
			nb_tmp = va_arg(lst_va->copy, int);
			count++;
		}
		if (lst->point == 0)
			lst->field = (nb_tmp * lst->nb_tmp);
		else
			lst->preci = nb_tmp;
	}
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
		if (str[count] == '.')
			lst->point = str[count++] - 45;
		else if (str[count] == '0')
			lst->zero = str[count++] - 47;
		else if (str[count] == 39)
			lst->local = str[count++] - 38;
		else if (str[count] == '#')
			lst->hash = str[count++] - 34;
		else if (str[count] == ' ')
			lst->space = str[count++] - 31;
		else if (ft_isalpha(str[count]) || str[count] == '%')
			count = ft_putflag_conv(lst, str, count);
		else
			count = lst_putdigit(lst_va, lst, str, count);
	}
	ft_init_base(lst);
	return (lst);
}
