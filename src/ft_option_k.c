/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_option_d.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/12 12:38:05 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/03 16:16:09 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_print_day(unsigned int index, int lan)
{
	if (index == 1)
		return (lan != 1 ? "Monday" : "Lundi");
	else if (index == 2)
		return (lan != 1 ? "Tuesday" : "Mardi");
	else if (index == 3)
		return (lan != 1 ? "Wednesday" : "Mercredi");
	else if (index == 4)
		return (lan != 1 ? "Tjirsday" : "Jeudi");
	else if (index == 5)
		return (lan != 1 ? "Friday" : "Vendredi");
	else if (index == 6)
		return (lan != 1 ? "Saturday" : "Samedi");
	else
		return (lan != 1 ? "Sunday" : "Dimanche");
}

char	*ft_print_month(unsigned int index, int lan)
{
	if (index == 1)
		return (lan != 1 ? "January" : "Janvier");
	else if (index == 2)
		return (lan != 1 ? "February" : "Fevrier");
	else if (index == 3)
		return (lan != 1 ? "March" : "Mars");
	else if (index == 4)
		return (lan != 1 ? "April" : "Avril");
	else if (index == 5)
		return (lan != 1 ? "May" : "Mai");
	else if (index == 6)
		return (lan != 1 ? "June" : "Juin");
	else if (index == 7)
		return (lan != 1 ? "July" : "Juillet");
	else if (index == 8)
		return (lan != 1 ? "August" : "Aout");
	else if (index == 9)
		return (lan != 1 ? "September" : "Septembre");
	else if (index == 10)
		return (lan != 1 ? "October" : "Octobre");
	else if (index == 11)
		return (lan != 1 ? "November" : "Novembre");
	else
		return (lan != 1 ? "December" : "Decembre");
}

int		*ft_params_k(t_valst *lst_va, char *str, int *tab_i, int index)
{
	t_time		*t;
	t_option	*lst;
	char		*da;
	char		*mo;
	int			fd;

	lst = ft_put_option(lst_va, str, tab_i[0], index);
	if (!(t = malloc(sizeof(t_time))))
		return (0);
	fd = lst->fd;
	da = ft_print_day(va_arg(lst_va->lst_copy, int), lst->af_nb);
	t->h = va_arg(lst_va->lst_copy, int);
	t->mi = va_arg(lst_va->lst_copy, int);
	t->d = va_arg(lst_va->lst_copy, int);
	mo = ft_print_month(va_arg(lst_va->lst_copy, int), lst->af_nb);
	t->y = va_arg(lst_va->lst_copy, int);
	if (lst->bf_nb == 1)
		ft_dprintf(fd, "%s %d %s %d, %d:%d", da, t->d, mo, t->y, t->h, t->mi);
	else
		ft_dprintf(fd, "%s %d:%d ,%d %s %d", da, t->h, t->mi, t->d, mo, t->y);
	tab_i[0] += index + 1;
	return (tab_i);
}
