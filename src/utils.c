/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/12 12:39:33 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/16 06:31:07 by rgermain    ###    #+. /#+    ###.fr     */
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

t_option	*lst_init(void)
{
	t_option	*lst_option;
	if (!(lst_option = malloc(sizeof(t_option))))
		exit (1);	
	lst_option->sign = 0;
	lst_option->point = 0;
	lst_option->hash = 0;
	lst_option->space = 0;
	lst_option->af_nb = 0;
	lst_option->af_zero = 0;
	lst_option->nb_tmp = 0;
	lst_option->bf_nb = 0;
	lst_option->bf_zero = 0;
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
	int			zero;
	int 		a;

	lst_option = lst_init();
	dollar = 0;
	a = 0;
	while (a < index)
	{
		zero = 0;
		if (str[count] == '+' || str[count] == '-')
			lst_option->sign = str[count];
		if (str[count] == '.')
			lst_option->point = 1;
		if (str[count] == '#')
			lst_option->hash = 1;
		if (str[count] == '*')
		{
			lst_option->star = 1;
			if (lst_option->point == 1)
				lst_option->star_pos = 1;
		}
		if (str[count] == ' ')
			lst_option->space = 1;
		if (ft_isdigit(str[count]))
		{
			if (str[count] == '0')
				zero = 1;
			lst_option->nb_tmp = 0;
			while (ft_isdigit(str[count]))
			{
				lst_option->nb_tmp = ((lst_option->nb_tmp * 10) + (str[count++] - '0'));
				a++;
			}
			if (str[count] == '$')
			{
				count++;
				a++;
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
			{
				if (zero == 1)
					lst_option->bf_zero = 1;
				lst_option->bf_nb = lst_option->nb_tmp;
			}
			else
			{
				if (zero == 1)
					lst_option->af_zero = 1;
				lst_option->af_nb = lst_option->nb_tmp;
			}
		}
		else
		{
			a++;
			count++;
		}
	}
/*
	printf(1, "count = %d m index = %d\n", count, index);
	
		dprintf(1,"sign = %d\n",lst_option->sign);
		dprintf(1,"point = %d\n",lst_option->point);
		dprintf(1,"space = %d\n",lst_option->space);
		dprintf(1,"af = %d\n",lst_option->af_nb);
		dprintf(1,"af zero = %d\n",lst_option->af_zero);
		dprintf(1,"nb tmp = %d\n",lst_option->nb_tmp);
		dprintf(1,"bf = %d\n",lst_option->bf_nb);
		dprintf(1,"bf zero = %d\n",lst_option->bf_zero);
		dprintf(1,"star = %d\n",lst_option->star);
		dprintf(1,"star pos = %d\n",lst_option->star_pos);
		dprintf(1,"dollar = %d\n",lst_option->dollar);
		dprintf(1,"dollar2 = %d\n",lst_option->dollar2);
		dprintf(1,"dollar nb = %d\n",lst_option->dollar_nb);
		dprintf(1,"dollar nb2 = %d\n",lst_option->dollar_nb2);
	
*/
	return (lst_option);
}
