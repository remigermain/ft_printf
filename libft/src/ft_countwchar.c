/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_countwchar.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/19 21:57:13 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/19 22:45:25 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int	ft_countwchar(wchar_t c)
{
	if (c <= 0x7F)
		return (1);
	if (c <= 0x7FF)
		return (2);
	if (c <= 0xFFFF)
		return (3);
	if (c <= 0x10FFFF)
		return (4);
	return (-1);
}

int ft_countwchars(wchar_t *str)
{
	size_t count;
	size_t a;

	count = 0;
	a = 0;
	while (str[a] != '\0')
		count += ft_countwchar(str[a++]);
	return (count);
}

int ft_countnwchars(wchar_t *str, size_t len)
{
	size_t count;
	size_t a;

	count = 0;
	a = 0;
	while (str[a] != '\0' && a < len)
		count += ft_countwchar(str[a++]);
	return (count);
}
