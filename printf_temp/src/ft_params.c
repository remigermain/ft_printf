/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_params.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/13 20:25:54 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/16 09:25:54 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int	*ft_params_d(t_valst *lst_va, char *str, int *tab_i, int index)
{
	tab_i[1] += ft_option_d(lst_va, str, tab_i[0], index);
	tab_i[0] = ((tab_i[0] + index) + 1);
	return (tab_i);
}

int	*ft_params_d2(t_valst *lst_va, char *str, int *tab_i, int index)
{
	tab_i[1] += ft_option_d2(lst_va, str, tab_i[0], index);
	tab_i[0] = ((tab_i[0] + index) + 1);
	return (tab_i);
}

int	*ft_params_o(t_valst *lst_va, char *str, int *tab_i, int index)
{
	tab_i[1] += ft_option_o(lst_va, str, tab_i[0], index);
	tab_i[0] = ((tab_i[0] + index) + 1);
	return (tab_i);
}

int	*ft_params_o2(t_valst *lst_va, char *str, int *tab_i, int index)
{
	tab_i[1] += ft_option_o2(lst_va, str, tab_i[0], index);
	tab_i[0] = ((tab_i[0] + index) + 1);
	return (tab_i);
}

int	*ft_params_c(t_valst *lst_va, char *str, int *tab_i, int index)
{
	tab_i[1] += ft_option_c(lst_va, str, tab_i[0], index);
	tab_i[0] = ((tab_i[0] + index) + 1);
	return (tab_i);
}

int	*ft_params_s(t_valst *lst_va, char *str, int *tab_i, int index)
{
	tab_i[1] += ft_option_s(lst_va, str, tab_i[0], index);
	tab_i[0] = ((tab_i[0] + index) + 1);
	return (tab_i);
}

int	*ft_params_p(t_valst *lst_va, char *str, int *tab_i, int index)
{
	tab_i[1] += ft_option_p(lst_va, str, tab_i[0], index);
	tab_i[0] = ((tab_i[0] + index) + 1);
	return (tab_i);
}

int	*ft_params_perc(t_valst *lst_va, char *str, int *tab_i, int index)
{
	ft_putchar('%');
	tab_i[1] += 1;
	tab_i[0] = ((tab_i[0] + index) + 1);
	return (tab_i);
}

int	*ft_params_u(t_valst *lst_va, char *str, int *tab_i, int index)
{
	tab_i[1] += ft_option_u(lst_va, str, tab_i[0], index);
	tab_i[0] = ((tab_i[0] + index) + 1);
	return (tab_i);
}

int	*ft_params_u2(t_valst *lst_va, char *str, int *tab_i, int index)
{
	tab_i[1] += ft_option_u2(lst_va, str, tab_i[0], index);
	tab_i[0] = ((tab_i[0] + index) + 1);
	return (tab_i);
}

int	*ft_params_x(t_valst *lst_va, char *str, int *tab_i, int index)
{
	tab_i[1] += ft_option_x(lst_va, str, tab_i[0], index);
	tab_i[0] = ((tab_i[0] + index) + 1);
	return (tab_i);
}

int	*ft_params_x2(t_valst *lst_va, char *str, int *tab_i, int index)
{
	tab_i[1] += ft_option_x2(lst_va, str, tab_i[0], index);
	tab_i[0] = ((tab_i[0] + index) + 1);
	return (tab_i);
}
