/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_params_ts.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/11 20:45:01 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/14 14:40:47 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_strjoin_f1(t_pf *lst, wuchar_t *s2, size_t l2)
{
	int		count;
	int		count_2;
	wuchar_t	*new;

	count = 0;
	count_2 = 0;
	if (!(new = (wuchar_t *)malloc(sizeof(wuchar_t) * l2 + lst->count + 1)))
		return ;
	while (count < lst->count)
	{
		new[count] = lst->str[count];
		count++;
	}
	while (count_2 < l2)
		new[count++] = s2[count_2++];
	new[lst->count + l2] = '\0';
	lst->count += l2;
	free(lst->str);
	free(s2);
	lst->str = new;
}

static	void pf_puttab(t_pf *lst, char **tab, int len, int larg)
{
	int a;
	int b;
	char c;
	wuchar_t *str;
	int ret;

	a = 0;
	while (tab[++a] != NULL)
	{
		b = 0;
		ret = ft_sprintf(&str, "\n[%.*d]|", larg, a);
		ft_strjoin_f1(lst, str, ret);
		while (b < len)
		{
			if (b >= ft_strlen(tab[a]))
				c = ' ';
			else
				c = tab[a][b];
			if ((len % 10) == 0)
				ret = ft_sprintf(&str, " %*c |", ft_ulen_base(len, 10) - 1, c);
			else
				ret = ft_sprintf(&str, " %*c |", ft_ulen_base(len, 10), c);
			ft_strjoin_f1(lst, str, ret);
			b++;
		}
	}
}

static	void pf_doublestring(t_pf *lst, char **tab, int len, int larg)
{
	int ret;
	int b;
	wuchar_t *str;

	b = 0;
	len = ft_maxlen_tab(tab, 1);
	larg = ft_ulen_base(ft_maxlen_tab(tab, 0), 10);
	ret = ft_sprintf(&str, "%*.c |", larg + 1, ' ');
	ft_strjoin_f1(lst, str, ret);
	while (b < len)
	{
		if ((len % 10) == 0)
			ret = ft_sprintf(&str, "[%.*d]|", ft_ulen_base(len, 10) - 1, b++);
		else
			ret = ft_sprintf(&str, "[%.*d]|", ft_ulen_base(len, 10), b++);
		ft_strjoin_f1(lst, str, ret);
	}
	pf_puttab(lst, tab, len, larg);
}

int		ft_params_ts(t_valst *lst_va, char *str, int index)
{
	t_pf	*lst;
	char	**tab;

	lst = lst_initoption(lst_va, str, index);
	tab = va_arg(lst_va->copy, char**);
	if (lst->point == 1)
		pf_doublestring(lst, tab, 0, 0);
	else
	while (*tab != NULL)
	{
		ft_strjoin_f1(lst, *tab, ft_strlen(*tab));
		tab++;
		if (*tab != NULL)
			ft_strjoin_f1(lst, "\n", 1);
	}
	pf_finaljoin(lst_va, lst->str, lst->count);
	free(lst->str);
	free(lst);
	return (index + 1);
}
