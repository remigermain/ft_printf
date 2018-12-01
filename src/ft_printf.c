/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/11 15:09:25 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/01 16:46:52 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_dprintf(int fd, const char *format, ...)
{
	t_valst		*lst_va;
	int			*tab_i;

	if (!(lst_va = malloc(sizeof(t_valst))))
		return (0);
	va_start(lst_va->lst_va, format);
	lst_va = lst_initva(lst_va, 0, 0);
	lst_va->fd = fd;
	tab_i = init_tab2();
	while (format[tab_i[0]] != '\0')
	{
		if (format[tab_i[0]] == '{')
			tab_i[0] = ft_printcolor((char*)format, tab_i[0], lst_va->fd);
		if (format[tab_i[0]] == '%')
			tab_i = ft_conv(lst_va, (char*)format, tab_i, 1);
		else
		{
			ft_putchar_fd(format[tab_i[0]++], lst_va->fd);
			tab_i[1]++;
		}
		if (tab_i[1] == -1)
			return (-1);
	}
	va_end(lst_va->lst_va);
	return (tab_i[1]);
}

int		ft_printf(const char *format, ...)
{
	t_valst		*lst_va;
	int			*tab_i;

	if (!(lst_va = malloc(sizeof(t_valst))))
		return (0);
	va_start(lst_va->lst_va, format);
	lst_va = lst_initva(lst_va, 0, 0);
	lst_va->fd = 1;
	tab_i = init_tab2();
	while (format[tab_i[0]] != '\0')
	{
		if (format[tab_i[0]] == '{')
			tab_i[0] = ft_printcolor((char*)format, tab_i[0], lst_va->fd);
		if (format[tab_i[0]] == '%')
			tab_i = ft_conv(lst_va, (char*)format, tab_i, 1);
		else
		{
			ft_putchar_fd(format[tab_i[0]++], lst_va->fd);
			tab_i[1]++;
		}
		if (tab_i[1] == -1)
			return (-1);
	}
	va_end(lst_va->lst_va);
	return (tab_i[1]);
}
