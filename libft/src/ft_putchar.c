/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putchar.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 14:24:30 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/30 21:11:53 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar(char c)
{
	return (ft_putchar_fd(c, 1));
}

int	ft_putwchar(unsigned int c)
{
	return (ft_putwchar_fd(c, 1));
}
