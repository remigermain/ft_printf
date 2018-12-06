/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_intlen.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/01 15:05:08 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/06 14:08:40 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int	ft_intlen_base(int nb, int base)
{
	int 	count;
	long	n;

	count = 0;
	n = (long)nb;
	if (n < 0 && base == 10)
	{
		n = n * -1;
		count++;
	}
	while (n >= base)
	{
		count++;
		n = n / base;
	}
	return (count + 1);
}

int	ft_intlen(int n)
{
	return (ft_intlen_base(n, 10));
}
