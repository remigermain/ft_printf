/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putchar.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 14:24:30 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/27 17:31:11 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"


int		ft_min2(int nb1, int nb2)
{
	if (nb1 > nb2)
		return (nb2);
	return (nb1);
}

int		ft_max2(int nb1, int nb2)
{
	if (nb1 < nb2)
		return (nb2);
	return (nb1);
}


void	ft_putchar(char c)
{
	write(1, &c, sizeof(c));
}
