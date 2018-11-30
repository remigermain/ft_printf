/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_minmax.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/30 21:04:29 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/30 21:10:02 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int	ft_min2(int nb1, int nb2)
{
	return (nb1 < nb2 ? nb1 : nb2);
}

int	ft_max2(int nb1, int nb2)
{
	return (nb1 > nb2 ? nb1 : nb2);
}

int	ft_abs(int nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}
