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

static size_t	ft_strlen_perc(char *str, size_t j)
{
	while (str[j] != '\0' && str[j] != '{' && str[j] != '%')
			j++;
	return (j);
}

static int ftprintf_base(char *str, t_valst *lst_va, size_t i, size_t j)
{
	va_copy(lst_va->copy, lst_va->lst_va);
	while (str[i] != '\0' && lst_va->count != -1)
	{
		j = ft_strlen_perc(str + i, 0);
		pf_finaljoin(lst_va, (wuchar_t*)(str + i), j);
		if (str[i + j] == '{')
			i += ft_putcolor(lst_va, str + i + j);
		else if (str[i + j] == '%')
			i += ft_conv(lst_va, str + i + j, 1);
		i += j;
	}
	va_end(lst_va->lst_va);
	va_end(lst_va->copy);
	return (lst_va->count);
}

int			ft_sprintf(wuchar_t **dest, const char *format, ...)
{
	t_valst	*lst_va;
	int			i;

	lst_va = lstva_init(1);
	va_start(lst_va->lst_va, format);
	i = ftprintf_base((char*)format, lst_va, 0, 0);
	*dest = ft_ustrndup(lst_va->str, i);
	free(lst_va->str);
	free(lst_va);
	return (i);
}

int			ft_dprintf(int fd, const char *format, ...)
{
	t_valst	*lst_va;
	int			i;

	lst_va = lstva_init(fd);
	va_start(lst_va->lst_va, format);
	i = ftprintf_base((char*)format, lst_va, 0, 0);
	write(lst_va->fd, lst_va->str, i);
	free(lst_va->str);
	free(lst_va);
	return (i);
}

int			ft_printf(const char *format, ...)
{
	t_valst	*lst_va;
	int			i;

	lst_va = lstva_init(1);
	va_start(lst_va->lst_va, format);
	i = ftprintf_base((char*)format, lst_va, 0, 0);
	write(lst_va->fd, lst_va->str, i);
	free(lst_va->str);
	free(lst_va);
	return (i);
}
