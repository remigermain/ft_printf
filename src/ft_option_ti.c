/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_option_d.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/12 12:38:05 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/03 12:41:34 by rgermain    ###    #+. /#+    ###.fr     */
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

int		ft_printtabi(t_option *lst, int **tab)
{
	int a;
	int b;

	a = 0;
	while (a < lst->af_nb)
	{
		b = 0;
		ft_dprintf(lst->fd, "\n[%.*d] |", ft_ulen(lst->af_nb - 1), a);
		while (b < lst->bf_nb)
		{
			ft_dprintf(lst->fd, "%*d |", 2, tab[a][b++]);
		}
		a++;
	}
	return (0);
}

int		ft_option_casei(t_option *lst, int **tab)
{
	int	b;

	b = 0;
	if (lst->point == 1)
	{
		ft_dprintf(lst->fd, "%*.c |", ft_ulen(lst->bf_nb) + 2, ' ');
		while (b < lst->bf_nb)
		{
			ft_dprintf(lst->fd, "[%.*d]|", ft_ulen(lst->bf_nb), b);
			b++;
		}
		ft_printtabi(lst, tab);
	}
	else
		ft_printitab_fd(tab, lst->af_nb, lst->bf_nb, lst->fd);
	return (1);
}

int		*ft_params_ti(t_valst *lst_va, char *str, int *tab_i, int index)
{
	t_option	*lst;
	int			**tab;

	lst = ft_put_option(lst_va, str, tab_i[0], index);
	tab = va_arg(lst_va->lst_copy, int**);
	lst->af_nb = va_arg(lst_va->lst_copy, int);
	lst->bf_nb = va_arg(lst_va->lst_copy, int);
	tab_i[1] += ft_option_casei(lst, tab);
	tab_i[0] = ((tab_i[0] + index) + 1);
	return (tab_i);
}
