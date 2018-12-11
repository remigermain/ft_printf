/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/11 15:09:25 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/10 21:09:02 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_strlen2(const char *str, int i)
{
	while (str[i] != '\0' && str[i] != '%' && str[i] != '{')
		i++;
	return (i);
}

int		ft_dprintf(int fd, const char *format, ...)
{
	t_valst		*lst_va;
	int			i;
	int			tmpi;

	lst_va = lstva_init(fd);
	va_start(lst_va->lst_va, format);
	va_copy(lst_va->copy, lst_va->lst_va);
	i = 0;
	while (format[i] != '\0')
	{
		i = ft_strlen2(format, 0);
		tmpi = i;
		write(lst_va->fd, format, i);
		if (format[i] == '{')
			i = ft_printcolor((char*)format, i, lst_va->fd);
		if (format[i] == '%')
			i = ft_conv(lst_va, (char*)format, i, 1);
		if (lst_va->count == -1)
			return (-1);
		format += i;
		lst_va->count += tmpi;
		i = 0;
	}
	va_end(lst_va->lst_va);
	return (lst_va->count);
}

int		ft_printf(const char *format, ...)
{
	t_valst		*lst_va;
	int			i;
	int			tmpi;

	lst_va = lstva_init(1);
	va_start(lst_va->lst_va, format);
	va_copy(lst_va->copy, lst_va->lst_va);
	i = 0;
	while (format[i] != '\0')
	{
		i = ft_strlen2(format, 0);
		tmpi = i;
		write(lst_va->fd, format, i);
		if (format[i] == '{')
			i = ft_printcolor((char*)format, i, lst_va->fd);
		if (format[i] == '%')
			i = ft_conv(lst_va, (char*)format, i, 1);
		if (lst_va->count == -1)
			return (-1);
		format += i;
		lst_va->count += tmpi;
		i = 0;
	}
	va_end(lst_va->lst_va);
	return (lst_va->count);
}
