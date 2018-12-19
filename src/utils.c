/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/12 12:39:33 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/19 15:23:18 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

t_pf	*ft_initpf(t_valst *lst_va)
{
	t_pf *lst;

	if (!(lst = (t_pf*)malloc(sizeof(t_pf))))
		return (NULL);
	lst->ul_nb = 0;
	lst->fl_nb = 0;
	lst->ful_nb = 0;
	lst->hash = 0;
	lst->space = 0;
	lst->zero = 0;
	lst->sign = 0;
	lst->local = 0;
	lst->field = 0;
	lst->point = 0;
	lst->preci = 0;
	lst->maj = 0;
	lst->psign = 0;
	lst->base = 0;
	lst->lenght = 0;
	lst->conv = 0;
	lst->nb_tmp = 1;
	lst->fd = lst_va->fd;
	return (lst);
}

t_valst	*lstva_init(int fd)
{
	t_valst *lst_va;

	if (!(lst_va = (t_valst*)malloc(sizeof(t_valst))))
		exit(0);
	lst_va->count = 0;
	lst_va->fd = fd;
	return (lst_va);
}

void	lstva_digit(t_valst *lst_va, int nb, int index)
{
	int		count;

	count = 0;
	if (index == 0)
		va_copy(lst_va->copy, lst_va->lst_va);
	while (count < (nb - 1))
	{
		va_arg(lst_va->copy, int);
		count++;
	}
}
