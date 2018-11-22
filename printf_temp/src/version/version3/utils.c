/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/12 12:39:33 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/14 14:36:29 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"


int		ft_strlen_start(char *str, int count)
{
	int a;

	a = 0;
	while (str[count + a] != '\0')
		a++;
	return (a);
}

int		*tab_2_init(void)
{
	int	*total;

	if (!(total = (int*)malloc(sizeof(int) * 2)))
		exit (0);
	total[0] = 0;
	total[1] = 0;
	return (total);
}

t_valst	*ft_lst_init2(t_valst *lst_va, int nb, int index)
{
	int		count;

	count = 0;
	if (index == 0)
		va_copy(lst_va->lst_copy, lst_va->lst_va);
	while(count < (nb - 1))
	{
		va_arg(lst_va->lst_copy, int);
		count++;
	}
	return (lst_va);
}

int	ft_calcul_lst(t_option *lst, int nb)
{
	int total;

	total = 0;
	if (lst->af_nb < ft_intlen(nb))
	{
		if (lst->sign == '+' && nb >= 0)
			total++;
		total += ft_intlen(nb);
	}
	else
		total += lst->af_nb;
	if (lst->space == 1 && nb >= 0
		&& lst->af_nb <= ft_intlen(nb) && lst->sign == 0)
		total++;
	return (total);
}

t_option	*lst_init(void)
{
	t_option	*lst_option;
	if (!(lst_option = malloc(sizeof(t_option))))
		exit (1);	
	lst_option->sign = 0;
	lst_option->point = 0;
	lst_option->space = 0;
	lst_option->af_nb = 0;
	lst_option->nb_tmp = 0;
	lst_option->bf_nb = 0;
	lst_option->star = 0;
	lst_option->star_pos = 0;
	lst_option->dollar = 0;
	lst_option->dollar2 = 0;
	lst_option->dollar_nb = 0;
	lst_option->dollar_nb2 = 0;
	return (lst_option);
}

t_option	*ft_put_option(char *str, int count, int index)
{
	t_option	*lst_option;
	int			dollar;

	lst_option = lst_init();
	dollar = 0;
	while (index --)
	{
		if (str[count] == '+' || str[count] == '-')
			lst_option->sign = str[count];
		else if (str[count] == '.')
			lst_option->point = 1;
		else if (str[count] == '*')
		{
			lst_option->star = 1;
			if (lst_option->point == 1)
				lst_option->star_pos = 1;
		}
		else if (str[count] == ' ')
			lst_option->space = 1;
		if (ft_isdigit(str[count]))
		{
			lst_option->nb_tmp = 0;
			while (ft_isdigit(str[count]))	
				lst_option->nb_tmp = ((lst_option->nb_tmp * 10) + (str[count++] - '0'));
			if (str[count] == '$')
			{
				if (dollar == 1)
				{
					lst_option->dollar2 = 1;
					lst_option->dollar_nb2 = lst_option->nb_tmp;
				}
				else
				{	
					dollar = 1;
					lst_option->dollar = 1;
					lst_option->dollar_nb = lst_option->nb_tmp;
				}
			}
			else if (lst_option->point == 0)
				lst_option->bf_nb = lst_option->nb_tmp;
			else
				lst_option->af_nb = lst_option->nb_tmp;
		}
		else
			count++;
	}
	return (lst_option);
}
