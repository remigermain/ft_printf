/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_params.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/12 12:37:01 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/13 14:41:36 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_params_p(va_list lst_va, char **str, int count, int index)
{
	char	*tmp;
	char	*new;
	char	*new2;

	new = ft_d_option_p(lst_va, *str, count, index);
	new2 = ft_strsub(*str, 0, count);
	tmp = ft_strjoin_s(new2, new);
	new = ft_strdup((*str + ((count + index) + 1)));
	ft_memdel((void**)str);
	*str = ft_strjoin_s(tmp, new);
	return (count + index - 1);
}

int		ft_params_perc(va_list lst_va, char **str, int count, int index)
{
	char	*tmp;
	char	*new;
	char	*new2;

	new = ft_d_option_perc(lst_va, *str, count, index);
	new2 = ft_strsub(*str, 0, count);
	tmp = ft_strjoin_s(new2, new);
	new = ft_strdup((*str + ((count + index) + 1)));
	ft_memdel((void**)str);
	*str = ft_strjoin_s(tmp, new);
	return (count + index - 1);
}


int		ft_params_c(va_list lst_va, char **str, int count, int index)
{
	char	*tmp;
	char	*new;
	char	*new2;

	new = ft_d_option_c(lst_va, *str, count, index);
	new2 = ft_strsub(*str, 0, count);
	tmp = ft_strjoin_s(new2, new);
	new = ft_strdup((*str + ((count + index) + 1)));
	ft_memdel((void**)str);
	*str = ft_strjoin_s(tmp, new);
	return (count + index - 1);
}

int		ft_params_s(va_list lst_va, char **str, int count, int index)
{
	char	*tmp;
	char	*new;
	char	*new2;

	new = ft_d_option_s(lst_va, *str, count, index);
	new2 = ft_strsub(*str, 0, count);
	printf("new2 = %s\n", new2);
	tmp = ft_strjoin_s(new2, new);
	printf("%s\n", tmp);
	sleep(2);
	new = ft_strdup((*str + ((count + index) + 1)));
	ft_memdel((void**)str);
	*str = ft_strjoin_s(tmp, new);
	return (count + index - 1);
}

int		ft_params_d(va_list lst_va, char **str, int count, int index)
{
	char	*tmp;
	char	*new;
	char	*new2;

	new = ft_d_option_d(lst_va, *str, count, index);
	new2 = ft_strsub(*str, 0, count);
	tmp = ft_strjoin_s(new2, new);
	new = ft_strdup((*str + ((count + index) + 1)));
	ft_memdel((void**)str);
	*str = ft_strjoin_s(tmp, new);
	return (count + index - 1);
}
