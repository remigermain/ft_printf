/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_params_ti.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/11 20:45:34 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/14 14:40:36 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printitab_fd(int **tab, int ligne, int col, int fd)
{
	int a;
	int b;

	a = 0;
	while (a < ligne)
	{
		b = 0;
		while (b < col)
			ft_dprintf(fd, "%d", tab[a][b++]);
		if (a < ligne - 1)
			ft_dprintf(fd, "\n");
		a++;
	}
	return (0);
}

int		ft_printtabi(t_pf *lst, int **tab)
{
	int a;
	int b;

	a = 0;
	while (a < lst->preci)
	{
		b = 0;
		ft_dprintf(lst->fd, "\n[%.*d] |", ft_ulen(lst->preci - 1), a);
		while (b < lst->field)
		{
			ft_dprintf(lst->fd, "%*d |", 2, tab[a][b++]);
		}
		a++;
	}
	return (0);
}

int		ft_pf_casei(t_pf *lst, int **tab)
{
	int	b;

	b = 0;
	if (lst->point == 1)
	{
		ft_dprintf(lst->fd, "%*.c |", ft_ulen(lst->field) + 2, ' ');
		while (b < lst->field)
		{
			ft_dprintf(lst->fd, "[%.*d]|", ft_ulen(lst->field), b);
			b++;
		}
		ft_printtabi(lst, tab);
	}
	else
		ft_printitab_fd(tab, lst->preci, lst->field, lst->fd);
	return (1);
}

int		ft_params_ti(t_valst *lst_va, char *str, int i, int index)
{
	t_pf	*lst;
	int		**tab;

	lst = lst_initoption(lst_va, str, i, index);
	tab = va_arg(lst_va->copy, int**);
	lst->preci = va_arg(lst_va->copy, int);
	lst->field = va_arg(lst_va->copy, int);
	lst_va->count += ft_pf_casei(lst, tab);
	free(lst);
	return (index + i);
}
