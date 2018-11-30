/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/12 12:39:33 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/30 20:37:40 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_put_digit(t_option *lst_option, char *str, int count)
{
	if (str[count] == '0')
		lst_option->zero = 1;
	lst_option->nb_tmp = 0;
	while (ft_isdigit(str[count]))
		lst_option->nb_tmp = ((lst_option->nb_tmp * 10) + (str[count++] - '0'));
	if (str[count] == '$')
	{
		count++;
		lst_option->dollar = 1;
		lst_option->dollar_nb = lst_option->nb_tmp;
	}
	else if (lst_option->point == 0)
	{
		if (lst_option->zero == 1)
			lst_option->bf_zero = 1;
		lst_option->bf_nb = lst_option->nb_tmp;
	}
	else
		lst_option->af_nb = lst_option->nb_tmp;
	return (count);
}

void		ft_put_star(t_option *lst_option)
{
	lst_option->star++;
	if (lst_option->point == 1)
		lst_option->star_pos = 1;
	if (lst_option->bf_nb != 0)
		lst_option->star_bf = 1;
}

void		ft_putflags2(t_option *lst, char *str, int count)
{
	if (str[count] == 'o' || str[count] == 'O')
		lst->base = 8;
	else if (str[count] == 'd' || str[count] == 'i' ||
			str[count] == 'D' || str[count] == 'I')
	{
		if (str[count] == 'D' || str[count] == 'I')
			lst->conv_d++;
		lst->conv_d++;
		lst->base = 10;
	}
	else if (str[count] == 'u' || str[count] == 'U')
	{
		lst->conv_u = 1;
		lst->base = 10;
	}
}

void		ft_putflags(t_option *lst, char *str, int count)
{
	if (str[count] == 'h')
		lst->flag_h++;
	else if (str[count] == 'l')
		lst->flag_l++;
	else if (str[count] == 'j')
		lst->flag_j++;
	else if (str[count] == 'z')
		lst->flag_z++;
	else if (str[count] == 'x' || str[count] == 'X' ||
			str[count] == 'p')
	{
		if (str[count] == 'p')
			lst->conv_p = 1;
		else if (str[count] == 'X')
			lst->maj = 1;
		lst->base = 16;
	}
	else
		ft_putflags2(lst, str, count);
}

t_option	*ft_put_option(t_valst *lst_va, char *str, int count, int index)
{
	t_option	*lst_option;

	lst_option = lst_init();
	while (index > 0)
	{
		lst_option->zero = 0;
		if (str[count] == '+' || str[count] == '-')
			lst_option->sign = str[count];
		else if (str[count] == '.')
			lst_option->point = 1;
		else if (str[count] == '#')
			lst_option->hash = 1;
		else if (str[count] == '*')
			ft_put_star(lst_option);
		else if (str[count] == ' ')
			lst_option->space = 1;
		if (ft_isdigit(str[count]))
			count = ft_put_digit(lst_option, str, count);
		else
			count++;
		ft_putflags(lst_option, str, count);
		index--;
	}
	ft_option_star(lst_va, lst_option);
	return (lst_option);
}