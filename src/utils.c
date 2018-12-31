/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils4.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/27 20:49:03 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/20 19:26:54 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void ftprintf_error(t_pf *lst, char *str, size_t index)
{
	ft_putstr_fd("\n  / \\    WARNING\n / | \\  FT_PRINT ERROR", 2);
	ft_putstr_fd("\n/  o  \\\n-------\n     	[", 2);
	if (index == 1)
		ft_putstr_fd("Error malloc to function \"", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("]     \n\n", 2);
	if (lst != NULL)
	{
		if (lst->str != NULL)
			free(lst->str);
		if (lst->tmp_str != NULL)
			free(lst->tmp_str);
		free(lst);
	}
	exit (0);
}

int	ulen_base(unsigned long nb, size_t base)
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

size_t len_pstr(wuchar_t *str)
{
	return (len_pstrn(str, ft_ustrlen(str)));
}

size_t len_pstrn(wuchar_t *str, size_t len)
{
	size_t i;
	size_t a;

	i = 0;
	a = 0;
	while (str[i] != '\0' && i < len)
	{
		if (ft_isprint(str[i] && str[i] != '\n') || str[i] == '\t')
			a++;
		else
			a += 2;
		i++;
	}
	return (a);
}

int			pf_putcolor(t_pf *lst, char *str)
{
	int ret;

	ret = 0;
	if ((ft_strncmp(str, "{white}", 7) == 0 && (ret = 4)) ||
	(ft_strncmp(str, "{eoc}", 4) == 0 && (ret = 4)))
		pf_stringjoin(lst, ((wuchar_t*)(white)), ft_strlen(white), 0);
	else if (ft_strcmp(str, "{black}") == 0 && (ret = 6))
		pf_stringjoin(lst, ((wuchar_t*)(black)), ft_strlen(black), 0);
	else if (ft_strcmp(str, "{red}") == 0 && (ret = 5))
		pf_stringjoin(lst, ((wuchar_t*)(red)), ft_strlen(red), 0);
	else if (ft_strcmp(str, "{green}") == 0 && (ret = 7))
		pf_stringjoin(lst, ((wuchar_t*)(green)), ft_strlen(green), 0);
	else if (ft_strcmp(str, "{yellow}") == 0 && (ret = 8))
		pf_stringjoin(lst, ((wuchar_t*)(yellow)), ft_strlen(yellow), 0);
	else if ((ft_strncmp(str, "{blue}", 5) == 0) && (ret = 5))
		pf_stringjoin(lst, ((wuchar_t*)(blue)), ft_strlen(blue), 0);
	else if (ft_strcmp(str, "{purple}") == 0 && (ret = 8))
		pf_stringjoin(lst, ((wuchar_t*)(purple)), ft_strlen(purple), 0);
	else if (ft_strcmp(str, "{cyan}") == 0 && (ret = 6))
		pf_stringjoin(lst, ((wuchar_t*)(cyan)), ft_strlen(cyan), 0);
	else if (ft_strcmp(str, "{grey}") == 0 && (ret = 6))
		pf_stringjoin(lst, ((wuchar_t*)(grey)), ft_strlen(grey), 0);
	return (ret + 1);
}
