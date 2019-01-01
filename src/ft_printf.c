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

static int ftprintf_base(char *str, t_pf *lst, size_t i, size_t j)
{
	va_copy(lst->va_copy, lst->va_lst);
	while (str[i] != '\0' && lst->count != -1)
	{
		j = ft_strlen_perc(str + i, 0);
		put_buff(lst, str + i, j, 0);
		if (str[i + j] == '{')
			i += put_color(lst, str + i + j);
		else if (str[i + j] == '%')
			i +=  find_conv(lst, str + i + j, 1);
		i += j;
	}
	va_end(lst->va_lst);
	va_end(lst->va_copy);
	comvert_buff(lst, NULL, 0);
	return (lst->count);
}

int			ft_sprintf(wuchar_t **dest, const char *format, ...)
{
	t_pf	*lst;
	int			i;

	lst = lst_init();
	va_start(lst->va_lst, format);
	i = ftprintf_base((char*)format, lst, 0, 0);
	*dest = lst->str;
	free(lst);
	return (i);
}

int			ft_dprintf(int fd, const char *format, ...)
{
	t_pf	*lst;
	int			i;

	lst = lst_init();
	va_start(lst->va_lst, format);
	i = ftprintf_base((char*)format, lst, 0, 0);
	write(fd, lst->str, i);
	free(lst->str);
	free(lst);
	return (i);
}

int			ft_printf(const char *format, ...)
{
	t_pf	*lst;
	int			i;

	lst = lst_init();
	va_start(lst->va_lst, format);
	i = ftprintf_base((char*)format, lst, 0, 0);
	write(1, lst->str, i);
	free(lst->str);
	free(lst);
	return (i);
}
