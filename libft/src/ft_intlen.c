/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_intlen.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/01 15:05:08 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/30 20:53:07 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int	ft_intlen_base(int n, int base)
{
	int count;

	count = 0;
	if (n == -2147483648 && base == 10)
		return (11);
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
