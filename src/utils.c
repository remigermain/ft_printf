/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/12 12:39:33 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/01 14:18:35 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void		lst_init2(t_option *lst_option)
{
	lst_option->point = 0;
	lst_option->hash = 0;
	lst_option->space = 0;
	lst_option->af_nb = 0;
	lst_option->nb_tmp = 0;
	lst_option->bf_nb = 0;
	lst_option->bf_zero = 0;
	lst_option->star = 0;
	lst_option->star_bf = 0;
	lst_option->star_pos = 0;
	lst_option->dollar = 0;
	lst_option->dollar_nb = 0;
}

t_option	*lst_init(void)
{
	t_option	*lst_option;

	if (!(lst_option = malloc(sizeof(t_option))))
		exit(0);
	lst_option->unb = 0;
	lst_option->flag_h = 0;
	lst_option->flag_l = 0;
	lst_option->flag_j = 0;
	lst_option->flag_z = 0;
	lst_option->conv_d = 0;
	lst_option->conv_p = 0;
	lst_option->conv_u = 0;
	lst_option->nb = 0;
	lst_option->nb2 = 0;
	lst_option->psign = 0;
	lst_option->base = 0;
	lst_option->fd = 0;
	lst_option->sign = 0;
	lst_option->zero = 0;
	lst_init2(lst_option);
	return (lst_option);
}

int			*init_tab2(void)
{
	int	*total;

	if (!(total = (int*)malloc(sizeof(int) * 2)))
		exit(0);
	total[0] = 0;
	total[1] = 0;
	return (total);
}

t_valst		*lst_initva(t_valst *lst_va, int nb, int index)
{
	int		count;

	count = 0;
	if (index == 0)
		va_copy(lst_va->lst_copy, lst_va->lst_va);
	while (count < (nb - 1))
	{
		va_arg(lst_va->lst_copy, int);
		count++;
	}
	return (lst_va);
}
