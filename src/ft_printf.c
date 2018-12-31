/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/11 15:09:25 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/19 23:16:03 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ftprintf_base(const char *format, t_valst *lst_va)
{
	int	i;

	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '{')
			i = ft_printcolor((char*)format, i, lst_va->fd);
		if (format[i] == '%')
			i = ft_conv(lst_va, (char*)format, i, 1);
		else
		{
			ft_putchar_fd(format[i++], lst_va->fd);
			lst_va->count++;
		}
		if (lst_va->count == -1)
			return (-1);
	}
	return (lst_va->count);
}

int			ft_dprintf(int fd, const char *format, ...)
{
	t_valst	*lst_va;
	int		count;

	lst_va = lstva_init(fd);
	va_start(lst_va->lst_va, format);
	va_copy(lst_va->copy, lst_va->lst_va);
	count = ftprintf_base(format, lst_va);
	va_end(lst_va->lst_va);
	va_end(lst_va->copy);
	free(lst_va);
	return (lst_va->count);
}

int			ft_printf(const char *format, ...)
{
	t_valst	*lst_va;
	int		count;

	lst_va = lstva_init(1);
	va_start(lst_va->lst_va, format);
	va_copy(lst_va->copy, lst_va->lst_va);
	count = ftprintf_base(format, lst_va);
	va_end(lst_va->lst_va);
	va_end(lst_va->copy);
	free(lst_va);
	return (lst_va->count);
}
