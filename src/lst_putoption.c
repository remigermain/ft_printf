/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lst_init.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/06 13:27:18 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/20 13:05:08 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static void	lst_undefined(t_pf *lst)
{
	if (lst->zero > 1 && lst->point > 1)
		lst->zero = 0;
	else if (lst->zero > 1)
		lst->zero = 1;
	if (lst->point > 1)
	{
		lst->point = 0;
		lst->preci = 0;
	}
	if (lst->conv != 'i' && lst->conv != 'd' && lst->conv != 'u' &&
			lst->conv != 'f' && lst->conv != 'F' && lst->conv != 'g' &&
			lst->conv != 'G')
		lst->local = 0;
	if (lst->conv == 's' || lst->conv == 'S')
		lst->preci = ABS(lst->preci);
}

static void	lst_base(t_pf *lst)
{
	if (lst->conv == 'x' || lst->conv == 'X' || lst->conv == 'p'
				|| lst->conv == 'a' || lst->conv == 'A')
		lst->base = 16;
	else if (lst->conv == 'o' || lst->conv == 'O')
		lst->base = 8;
	else if (lst->conv == 'b' || lst->conv == 'B')
		lst->base = 2;
	else
		lst->base = 10;
	if (!ft_islowercase(lst->conv))
		lst->maj = 1;
	lst_undefined(lst);
}

static int	lst_putflag_conv(t_pf *lst, char *str, int count)
{
	if (str[count] == 'h')
		lst->lenght++;
	else if (str[count] == 'l')
		lst->lenght += 10;
	else if (str[count] == 'j')
		lst->lenght += 100;
	else if (str[count] == 'z')
		lst->lenght += 1000;
	else if (str[count] == 't')
		lst->lenght += 10000;
	else if (str[count] == 'L')
		lst->lenght += 100000;
	else
		lst->conv = str[count];
	count++;
	return (count);
}

static int	lst_putdigit(t_pf *lst, char *str, int count, int *neg)
{
	int nb_tmp;

	nb_tmp = 0;
	if (str[count] == '+')
		lst->sign = str[count++];
	else if (str[count] == '-')
		(*neg) = str[count++] - 46;
	else if (ft_isdigit(str[count]) == 1 || str[count] == '*'
			|| str[count] == '$')
	{
		if (ft_isdigit(str[count]) == 1)
			nb_tmp = ft_atoi2(str + count, &count);
		if (str[count] == '*' || str[count] == '$')
		{
			if (str[count] == '$')
				lst_putdollar(lst, nb_tmp);
			nb_tmp = va_arg(lst->va_copy, int);
			count++;
		}
		if (lst->point == 0)
			lst->field = (nb_tmp * (*neg));
		else
			lst->preci = nb_tmp;
	}
	return (count);
}

void   lst_putoption(t_pf *lst, char *str, int index)
{
	int		count;
	int		neg;

	count = 1;
	neg = 1;
	lst_zero(lst);
	while (count <= index)
	{
		if (str[count] == '.')
			lst->point += str[count++] - 45;
		else if (str[count] == '0' && lst->point == 0)
			lst->zero += str[count++] - 47;
		else if (str[count] == 39)
			lst->local = str[count++] - 38;
		else if (str[count] == '#')
			lst->hash = str[count++] - 34;
		else if (str[count] == ' ')
			lst->space = str[count++] - 31;
		else if (ft_isdigit(str[count]) == 1 || str[count] == '+' ||
				str[count] == '-' || str[count] == '*' || str[count] == '$')
			count = lst_putdigit(lst, str, count, &neg);
		else
			count = lst_putflag_conv(lst, str, count);
	}
	lst_base(lst);
}
