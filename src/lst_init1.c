/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/12 12:39:33 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/05 17:55:21 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_putflags3(t_option *lst, char *str, int count)
{
	if (str[count] == 'g' || str[count] == 'G')
	{
		if (lst->point == 0 && lst->af_nb == 0)
		{
			lst->point = 1;
			lst->af_nb = 5;
		}
		else
			lst->af_nb -= 2;
		lst->base = 10;
	}
	else if (str[count] == 'd' || str[count] == 'i' ||
			str[count] == 'D' || str[count] == 'I')
	{
		if (str[count] == 'D' || str[count] == 'I')
			lst->conv_d++;
		lst->conv_d++;
		lst->base = 10;
	}
	else if (str[count] == 'u' || str[count] == 'U' ||
			str[count] == 'f' || str[count] == 'F')
	{
		if (str[count] == 'U')
			lst->conv_u++;
		lst->conv_u++;
		lst->base = 10;
	}
}

void		ft_putflags2(t_option *lst, char *str, int count)
{
	if (str[count] == 'o' || str[count] == 'O')
	{
		if (str[count] == 'O')
			lst->conv_o++;
		lst->conv_o++;
		lst->base = 8;
	}
	else if (str[count] == 'a' || str[count] == 'A')
	{
		if (str[count] == 'A')
			lst->maj = 1;
		lst->conv_p++;
		lst->base = 16;
	}
	else if (str[count] == 'e' || str[count] == 'E')
	{
		if (str[count] == 'E')
			lst->maj = 1;
		lst->conv_o++;
		lst->base = 10;
	}
	else
		ft_putflags3(lst, str, count);
}
