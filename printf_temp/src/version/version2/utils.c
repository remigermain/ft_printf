/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/12 12:39:33 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/13 22:27:57 by rgermain    ###    #+. /#+    ###.fr     */
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

t_valst	*ft_lst_init2(t_valst *lst_va, int nb, int index)
{
	int		count;

	count = 0;
	if (index == 0)
		va_copy(lst_va->lst_copy, lst_va->lst_va);
	while(count < (nb - 1));
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
	if (lst->nb < ft_intlen(nb))
	{
		if (lst->sign == '+' && nb >= 0)
			total++;
		total += ft_intlen(nb);
	}
	else
		total += lst->nb;
	if (lst->space == 1 && nb >= 0
		&& lst->nb <= ft_intlen(nb) && lst->sign == 0)
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
	lst_option->nb = 0;
	lst_option->star = 0;
	return (lst_option);
}

t_option	*ft_put_option(char *str, int count, int index)
{
	t_option	*lst_option;

	lst_option = lst_init();
	while (index --)
	{
		if (str[count] == '+' || str[count] == '-')
			lst_option->sign = str[count];
		else if (str[count] == '.')
			lst_option->point = 1;
		else if (str[count] == '*')
			lst_option->star = 1;		
		else if (str[count] == ' ')
			lst_option->space = 1;
		while (ft_isdigit(str[count]))
			lst_option->nb = ((lst_option->nb * 10) + (str[count++] - '0'));
		count++;
	}
	return (lst_option);
}
