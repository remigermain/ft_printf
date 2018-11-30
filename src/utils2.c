/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils2.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/20 16:06:08 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/30 15:26:12 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_prefix(int len, int nb, int point, int fd)
{
	int count;

	count = 0;
	while (len < nb)
	{
		if (point == 1)
			ft_putchar_fd('0', fd);
		else
			ft_putchar_fd(' ', fd);
		count++;
		nb--;
	}
	return (count);
}

void	ft_print_sign(t_option *lst)
{
	if (lst->psign == 1)
		ft_putchar('-');
	else if (lst->psign == 2)
		ft_putchar('+');
}

void	ft_init_nb2(t_option *lst, t_valst *lst_va)
{
	if (lst->unb == 0)
	{
		if (lst->nb2 < 0)
		{
			lst->psign = 1;
			lst->nb2 = -lst->nb2;
		}
		else if (lst->nb2 >= 0 && lst->sign == '+')
			lst->psign = 2;
		else
			lst->psign = 0;
		lst->nb = lst->nb2;
	}
	else
		lst->psign = 0;
}

void	ft_init_unb(t_option *lst, t_valst *lst_va)
{
	unsigned long nb;

	nb = 0;
	if (lst->flag_h == 1)
		nb = va_arg(lst_va->lst_copy, int);
	else if (lst->flag_h == 2)
		nb = va_arg(lst_va->lst_copy, int);
	else if (lst->flag_l == 1 && lst->conv_u == 0)
		nb = va_arg(lst_va->lst_copy, long);
	else if (lst->flag_l == 2 || lst->conv_u > 0)
		nb = va_arg(lst_va->lst_copy, unsigned long);
	else if (lst->flag_j == 1)
		nb = va_arg(lst_va->lst_copy, intmax_t);
	else if (lst->flag_z == 1)
		nb = va_arg(lst_va->lst_copy, size_t);
	else
		nb = va_arg(lst_va->lst_copy, unsigned long);
	lst->nb = nb;
	lst->unb = 1;
	ft_init_nb2(lst, lst_va);
}

void	ft_init_snb(t_option *lst, t_valst *lst_va)
{
	long nb;

	nb = 0;
	if (lst->flag_h == 1)
		nb = (long)va_arg(lst_va->lst_copy, int);
	else if (lst->flag_h == 2)
		nb = (long)va_arg(lst_va->lst_copy, int);
	else if (lst->flag_l == 1 && lst->conv_u == 0)
		nb = (long)va_arg(lst_va->lst_copy, long);
	else if (lst->flag_l == 2 || lst->conv_u > 0)
		nb = va_arg(lst_va->lst_copy, long);
	else if (lst->flag_j == 1)
		nb = (long)va_arg(lst_va->lst_copy, intmax_t);
	else if (lst->flag_z == 1)
		nb = (long)va_arg(lst_va->lst_copy, size_t);
	else
		nb = (long)va_arg(lst_va->lst_copy, int);
	lst->nb2 = nb;
	ft_init_nb2(lst, lst_va);
}

void	ft_init_nb(t_option *lst, t_valst *lst_va)
{
	if (lst->conv_d == 1)
		ft_init_snb(lst, lst_va);
	else
		ft_init_unb(lst, lst_va);
}

void	ft_option_star2(t_option *lst, int nb)
{
	if (lst->star_pos == 1)
		lst->af_nb = ft_max2(lst->bf_nb, nb);
	else if (lst->star_bf == 0)
	{
		if ((ft_abs(nb) > 0 && lst->bf_nb == 0) || nb == 0)
			lst->bf_nb = ft_max2(lst->bf_nb, ft_abs(nb));
		else
			lst->bf_nb = ft_min2(lst->bf_nb, ft_abs(nb));
	}
	else if (nb >= 0)
		lst->bf_nb = ft_abs(nb);
}

void	ft_option_star(t_valst *lst_va, t_option *lst)
{
	int nb;

	nb = 0;
	if (lst->star != 0)
	{
		nb = va_arg(lst_va->lst_copy, int);
		if (lst->point == 1 && lst->af_nb == 0 && lst->bf_nb == 0 && nb != 0)
			lst->point = 0;
		if (lst->star == 1)
			ft_option_star2(lst, nb);
		else
		{
			lst->bf_nb = nb;
			lst->af_nb = ft_abs(va_arg(lst_va->lst_copy, int));
		}
		if (nb < 0 && lst->point == 0)
			lst->sign = '-';
		if (nb < 0 && lst->point == 1 && lst->zero == 0 && lst->bf_nb == 0)
			lst->af_nb = 0;
	}
}
