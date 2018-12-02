/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_option_d.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/12 12:38:05 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/02 17:02:26 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"
/*
int	ft_putstrw22_fd(char const *s, int fd, int index)
{
	int count;

	count = 0;
	if (!s)
		return (-1);
	while (s[count] != '\0')
	{
		if (index == 1 && str[count] <= 0x7F)
			ft_putwchar(str[count++])
		else if (index == 2 && str[count] <= 0x7FF)
			ft_putwchar(str[count++])
		else if (index == 3 && str[count] <= 0xFFFF)
			ft_putwchar(str[count++])
		else if ((index >= 4 || index == 0) && str[count] <= 0x10FFFF)
			ft_putwchar(str[count++])
		else
			return (-1);
	}
	return (count);
}*/

int	ft_lenwchar(unsigned int c)
{
	int count;

	count = 0;
	if (c <= 0x7F)
		return (1);
	else if (c <= 0x7FF)
		return (2);
	else if (c <= 0xFFFF)
		return (3);
	else if (c <= 0x10FFFF)
		return (4);
	return (count);
}

int	ft_putwchar2_fd(unsigned int c,int fd, int index)
{
	int count;

	count = 0;
	if ((index == 1 || index == 0) && c <= 0x7F)
		count = ft_putwchar_fd(c, fd);
	else if (index == 2 && c <= 0x7FF)
		count = ft_putwchar_fd(c, fd);
	else if (index == 3 && c <= 0xFFFF)
		count = ft_putwchar_fd(c, fd);
	else if (index >= 4 && c <= 0x10FFFF)
		count = ft_putwchar_fd(c, fd);
	else
		count = -1;
	return (count);
}

int		ft_print_cmaj(t_option *lst, unsigned int c)
{
	int count;
	int count2;
	int index;

	count = 0;
	count2 = 0;
	index = lst->bf_nb - ft_lenwchar(c);
	lst->bf_nb -= ft_lenwchar(c);
	if (lst->bf_nb < 0)
		lst->bf_nb = 0;
	if (index < 0)
		index = 0;
	if (lst->flag_l == 1)
		index = 4;
	if (lst->bf_nb < 0 || lst->sign == '-')
	{
		count2 = ft_putwchar2_fd(c, lst->fd, index);
		count = ft_print_prefix(0, lst->bf_nb, 0, lst->fd);
	}
	else
	{
		count = ft_print_prefix(0, lst->bf_nb, lst->bf_zero, lst->fd);
		count2 = ft_putwchar2_fd(c, lst->fd, index);
	}
	if (count2 == -1)
		count = -1;
	else
		count += count2;
	return (count);
}

int		ft_params_cmaj(t_valst *lst_va, t_option *lst, int *tab_i, unsigned int c)
{
	int 			count;

	count = ft_print_cmaj(lst, c);
	if (count == -1)
		count = -1;
	else
		count = tab_i[1] + count;
	return (count);
}
