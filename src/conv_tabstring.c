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

static	void pf_puttab_back(t_pf *lst, int len, int b)
{
	int 			llen;
	int				ret;
	wuchar_t	*str;

	llen = ft_ulen_base(len, 10) + lst->preci;
	llen -= (((len % 10) == 0) ? 1 : 0);
	if (lst->preci == 1)
	{
		ret = ft_sprintf(&str, " {blue}%*s{eoc} |", llen, "\\0");
		pf_stringjoin(lst, str, ret, 1);
	}
	while ((b + lst->preci) < len)
	{
		ret = ft_sprintf(&str, " %*C |", llen, ' ');
		pf_stringjoin(lst, str, ret, 1);
		b++;
	}
}

static	void pf_puttab_end(t_pf *lst, int larg, int max)
{
	int 			ret;
	wuchar_t	*str;

	if (lst->preci == 1)
	{
		ret = ft_sprintf(&str, "\n[%.*d]| {blue}$NULL{eoc}", larg, max);
		pf_stringjoin(lst, str, ret, 1);
	}
}

static	void pf_puttab(t_pf *lst, char **tab, int len, int larg)
{
	wuchar_t	*str;
	int				llen;
	int 			a;
	int 			b;
	int 			ret;

	llen = ft_ulen_base(len, 10) + lst->preci;
	llen -= (((len % 10) == 0) ? 1 : 0);
	a = -1;
	while (tab[++a] != NULL && (b = -1))
	{
		ret = ft_sprintf(&str, "\n[%.*d]|", larg, a);
		pf_stringjoin(lst, str, ret, 1);
		while (tab[a][++b] != '\0')
		{
			ret = ft_sprintf(&str, " %*C |", llen, tab[a][b]);
			pf_stringjoin(lst, str, ret, 1);
		}
		pf_puttab_back(lst, len, b);
	}
	pf_puttab_end(lst, larg, ft_maxlen_tab(tab, 0));
}

static	void pf_doublestring(t_pf *lst, char **tab, int len, int larg)
{
	wuchar_t *str;
	int				b;
	int				ret;
	int				llen;

	b = 0;
	len = ft_maxlen_tab(tab, 1) + lst->preci;
	larg = ft_maxlen_tab(tab, 0);
	larg = ft_ulen_base(ft_min2(larg - 1, larg), 10);
	llen = ft_ulen_base(len, 10) + lst->preci;
	llen -= (((len % 10) == 0) ? 1 : 0);
	ret = ft_sprintf(&str, "%*.c |", larg + 1, ' ');
	pf_stringjoin(lst, str, ret, 1);
	while (b < len)
	{
		ret = ft_sprintf(&str, "[%.*d]|", llen, b++);
		pf_stringjoin(lst, str, ret, 1);
	}
	pf_puttab(lst, tab, len, larg);
}

int		conv_tabstring(t_pf *lst, char *str, int index)
{
	char		**tab;
	wuchar_t c;

	lst_putoption(lst, str, index);
	tab = va_arg(lst->va_copy, char**);
	c = '\n';
	if (lst->point == 1)
		pf_doublestring(lst, tab, 0, 0);
	while (*tab != NULL && lst->point == 0)
	{
		pf_stringjoin(lst, (wuchar_t*)*tab, ft_strlen(*tab), 0);
		if (*tab++ != NULL)
			pf_stringjoin(lst, &c, 1, 0);
	}
	return (index + 1);
}
