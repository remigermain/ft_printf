/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/12 12:39:33 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/20 21:53:12 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

t_option	*lst_init(void)
{
	t_option	*lst_option;

	if (!(lst_option = malloc(sizeof(t_option))))
		exit(0);
	lst_option->fd = 0;
	lst_option->sign = 0;
	lst_option->zero = 0;
	lst_option->point = 0;
	lst_option->hash = 0;
	lst_option->space = 0;
	lst_option->af_nb = 0;
	lst_option->af_zero = 0;
	lst_option->nb_tmp = 0;
	lst_option->bf_nb = 0;
	lst_option->bf_zero = 0;
	lst_option->star = 0;
	lst_option->star_bf = 0;
	lst_option->star_pos = 0;
	lst_option->dollar = 0;
	lst_option->dollar_nb = 0;
	return (lst_option);
}

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
	{
		if (lst_option->zero == 1)
			lst_option->af_zero = 1;
		lst_option->af_nb = lst_option->nb_tmp;
	}
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

t_option	*ft_put_option(char *str, int count, int index)
{
	t_option	*lst_option;

	lst_option = lst_init();
	while (index--)
	{
		lst_option->zero = 0;
		if (str[count] == '+' || str[count] == '-')
			lst_option->sign = str[count];
		if (str[count] == '.')
			lst_option->point = 1;
		if (str[count] == '#')
			lst_option->hash = 1;
		if (str[count] == '*')
			ft_put_star(lst_option);
		if (str[count] == ' ')
			lst_option->space = 1;
		if (ft_isdigit(str[count]))
			count = ft_put_digit(lst_option, str, count);
		else
			count++;
	}
	return (lst_option);
}
