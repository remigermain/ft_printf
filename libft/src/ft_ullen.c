/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ullen.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/16 04:29:48 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/27 18:41:14 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int	ft_ulllen_base(unsigned long long nb, unsigned long base)
{
	int count;

	count = 0;
	while (nb >= base)
	{
		nb /= base;
		count++;
	}
	return (count + 1);
}

int	ft_ulllen(unsigned long long nb)
{
	return (ft_ulllen_base(nb, 10));
}


int	ft_lllen_base(long long nb, int base)
{
	int count;

	count = 0;
	if (nb < -9223372036854775807)
		return (19);
	if (nb < 0)
		nb = -nb;
	while (nb >= base)
	{
		nb /= base;
		count++;
	}
	return (count + 1);
}

int	ft_lllen(long long nb)
{
	return (ft_lllen_base(nb, 10));
}

int	ft_llen_base(long nb, int base)
{
	int count;

	count = 0;
	if (nb < -9223372036854775807)
		return (ft_ulllen_base(-nb, base));
	if (nb < 0)
		nb = -nb;
	while (nb >= base)
	{
		nb /= base;
		count++;
	}
	return (count + 1);
}

int	ft_llen(long  nb)
{
	return (ft_llen_base(nb, 10));
}

int	ft_ullen_base(unsigned long int nb, unsigned long int base)
{
	int count;

	count = 0;
	while (nb >= base)
	{
		nb /= base;
		count++;
	}
	return (count + 1);
}

int	ft_ullen(unsigned long int nb)
{
	return (ft_ullen_base(nb, 10));
}
