/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putendl_fd.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 14:13:25 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/30 21:03:30 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_fd(char const *s, int fd)
{
	int count;

	count = 0;
	if (!s)
		return (-1);
	while (s[count] != '\0')
		ft_putchar_fd(s[count++], fd);
	return (count);
}

int	ft_putnstr_fd(char const *s, int len, int fd)
{
	int count;

	count = 0;
	if (!s)
		return (-1);
	while (s[count] != '\0' && count < len)
		ft_putchar_fd(s[count++], fd);
	return (count);
}

int	ft_putstrw_fd(char const *s, int fd)
{
	int count;

	count = 0;
	if (!s)
		return (-1);
	while (s[count] != '\0')
		ft_putwchar_fd(s[count++], fd);
	return (count);
}

int	ft_putnstrw_fd(char const *s, int len, int fd)
{
	int count;

	count = 0;
	if (!s)
		return (-1);
	while (s[count] != '\0' && count < len)
		ft_putwchar_fd(s[count++], fd);
	return (count);
}
