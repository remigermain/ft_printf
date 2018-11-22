/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_option_d.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/12 12:38:05 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/15 14:34:57 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_option_d3(int nb, int nb_l, int point)
{
	while (nb < nb_l--)
	{
		if (point == 1)
			ft_putchar('0');
		else
			ft_putchar(' ');
	}
}

void	ft_option_d1(t_option *lst, int nb)
{
	int	tmp_nb;
	int	tmp2;

	if (lst->point == 0)
		tmp_nb = lst->bf_nb;
	if (lst->point == 1)
		tmp_nb = lst->af_nb;
	tmp2 = nb;
	if (lst->sign == '-' && (ft_intlen(nb) < lst->af_nb) && lst->point == 1 && nb < 0)
	{
		nb = -nb;
		ft_putchar('-');
	}
	else if (lst->af_nb < ft_intlen(nb) && lst->bf_nb < ft_intlen(nb))
		ft_putnbr(nb);
//	printf("nb_tmp = %d  af = %d\n", lst->nb_tmp, lst->bf_nb);
	ft_option_d3(0, lst->af_nb , 0);
	if (tmp_nb > ft_intlen(nb))
		ft_putnbr(nb);
	lst->sign = 0;
//	ft_option_dp(lst, tmp2);
}

void	ft_option_d2(t_option *lst, int nb)
{
	if (lst->sign == '+' && nb >= 0 && lst->point == 1)
        ft_putchar('+');
    if (nb < 0 && lst->point == 1)
    {
		nb = -nb;
		ft_putchar('-');
	}
    ft_option_d3(ft_intlen(nb), lst->af_nb, lst->point);
    if (lst->sign == '+' && nb >= 0 && lst->point == 0)
        ft_putchar('+');
    ft_putnbr(nb);
}

void	ft_option_dp(t_option *lst, int nb)
{
	if (lst->bf_nb > lst->af_nb && lst->sign != '-')
	{
		if (lst->sign == '+' && nb >= 0)
				lst->bf_nb--;
		if (lst->af_nb > ft_intlen(nb))
			ft_option_d3(0, (lst->bf_nb - lst->af_nb), 0);
		else 
			ft_option_d3(ft_intlen(nb), lst->bf_nb, 0);
	}
}

int		*ft_calcul22(t_option *lst, int *total, int tmp)
{
	int sign2;
	int sign22;
	int total_tmp;

	sign2 = 0;
	sign22 = 0;
	total_tmp = total[0];
	if (tmp < 0)
	{
		sign2 = 1;
		tmp = -tmp;
	}
	if (lst->star == 1)
	{
		if (total[0] < 0)
		{
			sign22 = 1;
			total_tmp = -total_tmp;
		}

//		dprintf(1, "tmp = %d    lst->bf_nb = %d, lst->af = %d, intlen = %d  total[0] = %d\n", tmp, lst->bf_nb, lst->af_nb, ft_intlen(total_tmp), total[0]); 
		if (tmp > total[1])
			total[1] = tmp;
		if (lst->bf_nb > total[1])
			total[1] = lst->bf_nb;
		if (lst->af_nb >= total[1])
			total[1] = lst->af_nb;
		 if (ft_intlen(total_tmp) >= total[1])
			total[1] = ft_intlen(total_tmp);
	//	if ((lst->sign == '+' && sign22 == 0) || sign22 == 1)
	//		total[1]++;	
	}
	else
	{
		if (lst->bf_nb > total[1])
			total[1] = lst->bf_nb;
		if (lst->af_nb > total[1])
			total[1] = lst->af_nb;
//		printf("totsl1 = %d\n", total[1]);
		if (ft_intlen(tmp) > total[1])
			total[1] = ft_intlen(tmp);
	//	if ((lst->sign == '+' && sign2 == 0) || sign2 == 1)
	I//		total[1]++;
	}
	return (total);
}

int	*ft_option_star(t_valst *lst_va, t_option *lst, int *total)
{
	int	tmp;
	int	tmp2;
	int	sign2;

	tmp = total[0];
	sign2 = 0;
	if (lst->star == 1)
	{
		lst->nb_tmp = total[0];
		tmp = total[0];
		total[0] = va_arg(lst_va->lst_copy, int);
		tmp2 = total[0];
		if (lst->star_pos == 0)
		{
			if (tmp2 < 0)
			{
				sign2 = 1;
				tmp2 = -tmp2;
			}
			if (ft_intlen(tmp2) < lst->af_nb)
				lst->nb_tmp -= lst->af_nb;
			else
				lst->nb_tmp -= ft_intlen(tmp2);
			if ((lst->sign == '+' && sign2 == 0) || sign2 == 1)
				lst->nb_tmp--;
			if (lst->sign != '-')
					ft_option_d3(0, lst->nb_tmp , 0);
		}
		else
			lst->af_nb = lst->nb_tmp;
		total = ft_calcul22(lst, total, tmp);
	}
	else
		total = ft_calcul22(lst, total, tmp);
	return (total);
}

int		ft_option_d(t_valst *lst_va, char *str, int count, int index)
{
	t_option	*lst;
	int			nb;
	int			*total;

	lst = ft_put_option(str, count, index);
	if (lst->dollar == 1)
		lst_va = ft_lst_init2(lst_va, lst->dollar_nb, 0);
	total = tab_2_init();
	total[0] = va_arg(lst_va->lst_copy, int);
	ft_option_dp(lst, total[0]);
	if (lst->space == 1 && total[0] >= 0 && lst->sign == 0
			&& lst->af_nb == 0 && lst->bf_nb == 0)
		ft_putchar(' ');
	total = ft_option_star(lst_va, lst, total);
	if (lst->sign == '-')
		ft_option_d1(lst, total[0]);
	else
		ft_option_d2(lst, total[0]);
	return (total[1]);
}
