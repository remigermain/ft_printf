/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_atoi.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/02 11:14:09 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/10 13:14:30 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_atoi2(const char *str, int *count)
{
	int	a;
	int	b;
	int	neg;

	a = 0;
	b = 0;
	neg = 1;
	while (str[a] == ' ' || (str[a] >= 9 && str[a] <= 13))
		a++;
	if (str[a] == '+' || str[a] == '-')
	{
		if (str[a] == '-')
			neg = -1;
		a++;
	}
	while (str[a] >= '0' && str[a] <= '9')
	{
		b = ((b * 10) + (str[a] - '0'));
		a++;
	}
	*count += a;
	return (b * neg);
}