/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_params_ts.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/11 20:45:01 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/11 20:45:22 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printback(t_pf *lst, int len2, int b, int c)
{
	int count;

	count = 0;
	if (lst->preci >= 1)
	{
		if (c == '\0')
			ft_dprintf(lst->fd, "{blue}%*c%c{eoc} |", len2 - 1, 92, '0', b++);
		else
			ft_dprintf(lst->fd, "{blue}%*c%c{eoc} |", len2 - 1, 'N', 'O', b++);
	}
	return (b);
}

void	ft_printend(t_pf *lst, char **tab, int larg, int a)
{
	int len;

	len = 0;
	if (lst->preci >= 1)
	{
		len = ft_ulen(larg - 1);
		if (tab[a] == NULL)
			ft_dprintf(lst->fd, "\n[%.*d]  {blue}NULL{eoc} ", len, a);
		else
			ft_dprintf(lst->fd, "\n[%.*d]  {red}NO NU{eoc} ", len, a);
	}
}

int		ft_printtab2(t_pf *lst, char **tab, int larg, int len)
{
	int a;
	int b;
	int i;
	int len2;

	a = 0;
	i = 1;
	if (lst->preci >= 1)
		i = 2;
	len2 = ((ft_ulen(len) + i / 2) + 1);
	while (tab[a] != NULL)
	{
		b = 0;
		ft_dprintf(lst->fd, "\n[%.*d] |", ft_ulen(larg - 1), a);
		while (tab[a][b] != '\0')
			ft_dprintf(lst->fd, "%*c |", len2, tab[a][b++]);
		b = ft_printback(lst, len2, b, tab[a][b]);
		while (b < len)
			ft_dprintf(lst->fd, "%*c |", len2, ' ', b++);
		a++;
	}
	ft_printend(lst, tab, larg, a);
	return (0);
}

int		ft_pf_case(t_pf *lst, char **tab)
{
	int len;
	int larg;
	int	b;
	int i;

	b = 0;
	len = ft_maxlen_tab(tab, 1);
	larg = ft_ulen(ft_maxlen_tab(tab, 0));
	i = 1;
	if (lst->point == 1)
	{
		ft_dprintf(lst->fd, "%*.c |", ft_ulen(larg - 1) + 2, ' ');
		if (lst->preci >= 1)
		{
			i = 2;
			larg++;
			len++;
		}
		while (b < len)
			ft_dprintf(lst->fd, "[%.*d]|", ft_ulen(len) + i - 1, b++);
		ft_printtab2(lst, tab, larg, len);
	}
	else
		ft_printtab_fd(tab, lst->fd);
	return (1);
}

int		ft_params_ts(t_valst *lst_va, char *str, int i, int index)
{
	t_pf	*lst;
	char	**tab;
	int		count;

	lst = lst_initoption(lst_va, str, i, index);
	tab = va_arg(lst_va->copy, char**);
	count = ft_pf_case(lst, tab);
	return (index + 1);
}
