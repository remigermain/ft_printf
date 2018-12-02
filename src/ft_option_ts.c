/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_option_d.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/12 12:38:05 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/02 20:56:26 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_fprinttab(char **tab, int fd)
{
	int a;
	int count;

	a = 0;
	count = 0;
	while (tab[a] != NULL)
	{
		count += ft_putstr_fd(tab[a++], fd);
		count += ft_putchar_fd('\n', fd);
	}
	return (count);
}

int		maxlen(char **tab, int index)
{
	int	len;
	int	a;

	len = 0;
	a = 0;
	while (tab[a] != NULL)
		len = ft_max2(len, ft_strlen(tab[a++]));
	if (index == 1)
		return (len);
	return (a);
}

int		ft_printback(t_option *lst, int len2, int b, int c)
{
	int count;

	count = 0;
	if (lst->bf_nb != 2)
	{
		if (c == '\0')
			ft_dprintf(lst->fd, "%*c%c |", len2 - 1, 92, '0', b++);
		else
			ft_dprintf(lst->fd, "%*c%c |", len2 - 1, 'N', 'O', b++);
	}
	return (b);
}

void	ft_printend(t_option *lst, char **tab, int larg, int a)
{
	if (lst->af_nb == 1)
	{
		if (tab[a] == NULL)
			ft_dprintf(lst->fd, "\n[%.*d]  NULL", ft_ulen(larg - 1) + 1, a);
		else
			ft_dprintf(lst->fd, "\n[%.*d]  NO NU", ft_ulen(larg - 1) + 1, a);
	}
}

int		ft_printtab2(t_option *lst, char **tab, int larg, int len)
{
	int a;
	int b;
	int i;
	int len2;

	a = 0;
	i = 1;
	if (lst->af_nb == 1)
		i = 2;
	len2 = ((ft_ulen(len) + i / 2) + 1);
	while (tab[a] != NULL)
	{
		b = 0;
		ft_dprintf(lst->fd, "\n[%.*d] |", ft_ulen(larg - 1) + 1, a);
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

int		ft_option_case(t_option *lst, char **tab)
{
	int len;
	int larg;
	int	b;
	int i;

	b = 0;
	len = maxlen(tab, 1);
	larg = ft_ulen(maxlen(tab, 0));
	i = 1;
	if (lst->point == 1)
	{
		ft_dprintf(lst->fd, "%*.c%*c|", larg - 1 + 3, ' ', larg - 1, ' ');
		if (lst->af_nb == 1)
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
		ft_fprinttab(tab, lst->fd);
	return (2);
}

int		*ft_params_ts(t_valst *lst_va, char *str, int *tab_i, int index)
{
	t_option	*lst;
	char		**tab;

	lst = ft_put_option(lst_va, str, tab_i[0], index);
	tab = va_arg(lst_va->lst_copy, char**);
	tab_i[1] += ft_option_case(lst, tab);
	tab_i[0] = ((tab_i[0] + index) + 1);
	return (tab_i);
}
