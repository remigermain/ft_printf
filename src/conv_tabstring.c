/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   conv_tabstring.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/04 16:39:28 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/04 19:38:47 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static void	pf_puttab_back(t_pf *lst, int len, int b)
{
	int			llen;
	int			ret;
	WUCHAR_T	*str;

	llen = ulen_base(len, 10) + PRECI;
	llen -= (((len % 10) == 0) ? 1 : 0);
	if (PRECI == 1)
	{
		ret = ft_sprintf(&str, " {blue}%*s{eoc} |", llen, "\\0");
		put_buff(lst, str, ret, 1);
	}
	while ((b + PRECI) < len)
	{
		ret = ft_sprintf(&str, " %*C |", llen, ' ');
		put_buff(lst, str, ret, 1);
		b++;
	}
}

static void	pf_puttab_end(t_pf *lst, int larg, int max)
{
	WUCHAR_T	*str;
	int			ret;

	if (PRECI == 1)
	{
		ret = ft_sprintf(&str, "\n[%.*d]| {blue}$NULL{eoc}", larg, max);
		put_buff(lst, str, ret, 1);
	}
}

static void	pf_puttab(t_pf *lst, char **tab, int len, int larg)
{
	WUCHAR_T	*str;
	int			llen;
	int			a;
	int			b;
	int			ret;

	llen = ulen_base(len, 10) + PRECI;
	llen -= (((len % 10) == 0) ? 1 : 0);
	a = -1;
	while (tab[++a] != NULL && (b = -1))
	{
		ret = ft_sprintf(&str, "\n[%.*d]|", larg, a);
		put_buff(lst, str, ret, 1);
		while (tab[a][++b] != '\0')
		{
			ret = ft_sprintf(&str, " %*C |", llen, tab[a][b]);
			put_buff(lst, str, ret, 1);
		}
		pf_puttab_back(lst, len, b);
	}
	pf_puttab_end(lst, larg, ft_maxlen_tab(tab, 0));
}

static void	pf_doublestring(t_pf *lst, char **tab, int len, int larg)
{
	WUCHAR_T	*str;
	int			b;
	int			ret;
	int			llen;

	b = 0;
	len = ft_maxlen_tab(tab, 1) + PRECI;
	larg = ft_maxlen_tab(tab, 0);
	larg = ulen_base(MIN(larg - 1, larg), 10);
	llen = ulen_base(len, 10) + PRECI;
	llen -= (((len % 10) == 0) ? 1 : 0);
	ret = ft_sprintf(&str, "%*.c |", larg + 1, ' ');
	put_buff(lst, str, ret, 1);
	while (b < len)
	{
		ret = ft_sprintf(&str, "[%.*d]|", llen, b++);
		put_buff(lst, str, ret, 1);
	}
	pf_puttab(lst, tab, len, larg);
}

void		conv_tabstring(t_pf *lst)
{
	char		**tab;
	WUCHAR_T	c;

	tab = va_arg(lst->va_copy, char**);
	c = '\n';
	if (POINT == 1)
		pf_doublestring(lst, tab, 0, 0);
	while (*tab != NULL && POINT == 0)
	{
		put_buff(lst, (WUCHAR_T*)*tab, ft_strlen(*tab), 0);
		if (*tab++ != NULL)
			put_buff(lst, &c, 1, 0);
	}
}
