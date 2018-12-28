/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils4.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/27 20:49:03 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/20 19:26:54 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ulen_base(unsigned long nb, size_t base)
{
	int count;

	count = 0;
	while (nb >= base)
	{
		nb /= base;
		count++;
	}
	return (count + 1);
}

int pf_countpstr(char *str, size_t len)
{
	int i;
	int a;

	i = 0;
	a = 0;
	while (str[i] != '\0' && i < len)
	{
		if (ft_isprint(str[i]) || (str[i] >= 9 && str[i] <= 13))
			a++;
		else
			a += 2;
		i++;
	}
	return (a);
}

void 	pf_putpstr(t_pf *lst, char_t *str)
{
	int i;
	int j;
	int len;
	char_t *new;

	i = 0;
	j = 0;
	len = pf_countpstr(str, ft_strlen(str));
	if (lst->point == 1)
		len = ft_max2(len, lst->preci);
	if (!(new = (char_t*)malloc(sizeof(char_t) + len)))
		return ;
	while (str[i] != '\0' && i < len)
	{
		if (ft_isprint(str[i]) || (str[i] >= 9 && str[i] <= 13))
			new[j++] = str[i++];
		else
		{
			new[j++] = '^';
			new[j++] = (str[i++] + 64);
		}
	}
	pf_tmpjoin(lst, new, len);
}

static void	ft_putcolor2(t_valst *lst_va, int i)
{
	char	*tab[10];

	tab[0] = "\033[0m";
	tab[1] = "\033[30m";
	tab[2] = "\033[31m";
	tab[3] = "\033[32m";
	tab[4] = "\033[33m";
	tab[5] = "\033[34m";
	tab[6] = "\033[35m";
	tab[7] = "\033[36m";
	tab[8] = "\033[37m";
	tab[9] = "\033[0m";
	pf_finaljoin(lst_va, tab[i], ft_strlen(tab[i]));
}

int			ft_putcolor(t_valst *lst_va, char *str)
{
	char	*tab[10];
	int		a;

	tab[0] = "{white}";
	tab[1] = "{black}";
	tab[2] = "{red}";
	tab[3] = "{green}";
	tab[4] = "{yellow}";
	tab[5] = "{blue}";
	tab[6] = "{purple}";
	tab[7] = "{cyan}";
	tab[8] = "{grey}";
	tab[9] = "{eoc}";
	a = 0;
	while (a < 10 && ft_strncmp((str), tab[a], ft_strlen(tab[a])) != 0)
		a++;
	if (a < 10)
	{
		ft_putcolor2(lst_va, a);
		return (ft_strlen(tab[a]));
	}
	pf_finaljoin(lst_va, str, 1);
	return (1);
}
