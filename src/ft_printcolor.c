/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/11 15:09:25 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/30 12:06:49 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printcolor2(int i, int fd)
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
	ft_putstr_fd(tab[i], fd);
}

int		ft_printcolor(char *str, int i, int fd)
{
	char	*tab[10];
	int		a;

	tab[0] = "white}";
	tab[1] = "black}";
	tab[2] = "red}";
	tab[3] = "green}";
	tab[4] = "yellow}";
	tab[5] = "blue}";
	tab[6] = "purple}";
	tab[7] = "cyan}";
	tab[8] = "grey}";
	tab[9] = "eoc}";
	a = 0;
	while (a < 10 && ft_strncmp((str + i + 1), tab[a], ft_strlen(tab[a])) != 0)
		a++;
	if (a < 10)
	{
		ft_printcolor2(a, fd);
		return (i + (ft_strlen(tab[a]) + 1));
	}
	return (i);
}
