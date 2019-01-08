/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printtab.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/01 13:42:29 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/08 16:28:40 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_printtab(char **tab)
{
	ft_printtab_fd(tab, 1);
}

void	ft_printtab_fd(char **tab, int fd)
{
	int count1;

	count1 = 0;
	while (tab[count1] != NULL)
	{
		ft_putstr_fd(tab[count1], fd);
		if (tab[count1][ft_strlen(tab[count1]) - 1] != '\n')
			ft_putchar_fd('\n', fd);
		count1++;
	}
}

int		ft_maxlen_tab(char **tab, int index)
{
	int	a;
	int	b;
	int	max;

	a = 0;
	max = 0;
	while (tab[a] != NULL)
	{
		b = 0;
		while (tab[a][b] != '\0')
			b++;
		if (b > max)
			max = b;
		a++;
	}
	if (index == 1)
		return (max);
	return (a);
}
