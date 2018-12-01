/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_option_d.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/12 12:38:05 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/01 17:10:29 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_strlen2(wchar_t *str)
{
	int len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}
int		ft_putnstrw2_fd(wchar_t *str, int len, int fd)
{
	int count;

	count = 0;
	while (str[count] != '\0' && count < len)
		write(fd, &str[count++], 1);
	return (count);
}

int		ft_putstrw2_fd(wchar_t *str, int fd)
{
	int count;

	count = 0;
	while (str[count] != '\0')
		write(fd, &str[count++], 1);
	return (count);
}

static int	ft_option_neg2(t_option *lst, wchar_t *new, int count)
{
	int len;
	int max;
	int min;

	len = ft_strlen2(new);
	max = ft_max2(len, lst->af_nb);
	min = ft_min2(len, lst->af_nb);
	if (lst->point == 1)
	{
		count += ft_putnstrw2_fd(new, lst->af_nb, lst->fd);
		count += ft_print_prefix(min, lst->bf_nb, 0, lst->fd);
	}
	else
	{
		count += ft_putstrw2_fd(new, lst->fd);
		count += ft_print_prefix(max, lst->bf_nb, 0, lst->fd);
	}
	return (count);
}

static int	ft_option_pos2(t_option *lst, wchar_t *new, int count)
{
	int len;
	int max;
	int min;

	len = ft_strlen2(new);
	max = ft_max2(len, lst->af_nb);
	min = ft_min2(len, lst->af_nb);
	if (lst->point == 1)
	{
		count += ft_print_prefix(min, lst->bf_nb, lst->bf_zero, lst->fd);
		count += ft_putnstrw2_fd(new, lst->af_nb, lst->fd);
	}
	else
	{
		count += ft_print_prefix(max, lst->bf_nb, lst->bf_zero, lst->fd);
		count += ft_putstrw2_fd(new, lst->fd);
	}
	return (count);
}

int			*ft_params_smaj(t_valst *lst_va, char *str, int *tab_i, int index)
{
	t_option	*lst;
	wchar_t		*new;

	lst = ft_put_option(lst_va, str, tab_i[0], index);
	new = va_arg(lst_va->lst_copy, wchar_t*);
	lst->af_nb = ft_abs(lst->af_nb);
	if (lst->sign != '-')
		tab_i[1] += ft_option_pos2(lst, new, 0);
	else
		tab_i[1] += ft_option_neg2(lst, new, 0);
	tab_i[0] = ((tab_i[0] + index) + 1);
	return (tab_i);
}
