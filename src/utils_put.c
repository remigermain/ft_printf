/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/11 15:09:25 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/19 22:12:13 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void			pf_tmpjoin(t_pf *lst, char_t *str, size_t len)
{
	char_t	*new;
	int		count;
	int		i;

	count = 0;
	i = 0;
	if (!(new = (char_t*)malloc(sizeof(char_t) * (len + lst->count))))
		return ;
	while (count < lst->count)
	{
		new[count] = lst->str[count];
		count++;
	}
	while (len-- > 0)
	{
		new[count + i] = str[i];
		i++;
	}
	lst->count += i;
	if (lst->str != NULL)
		free(lst->str);
	lst->str = new;
}

void		pf_itoa(t_pf *lst, unsigned long n)
{
	int		len;
	int		mlen;
	char_t	*str;

	len = ft_ulen_base(n, lst->base);
	if (lst->local == 1 && len > 3)
		len += (len / 3) - (len % 3 == 0 ? 1 : 0);
	mlen = len;
	if (!(str = (char_t*)malloc(sizeof(char_t) * len + 1)))
		return ;
	str[len--] = '\0';
	while (len >= 0)
	{
		if (lst->local == 1 && (mlen - len) % 4 == 0)
			str[len--] = '\'';
		if ((n % lst->base) < 10)
			str[len--] = (n % lst->base) + 48;
		else if (lst->maj == 1)
			str[len--] = (n % lst->base) + 55;
		else
			str[len--] = (n % lst->base) + 87;
		n = n / lst->base;
	}
	pf_tmpjoin(lst, str, mlen);
	free(str);
}

void 		pf_finaljoin(t_valst *lst_va, char_t *str, size_t i)
{
	int			count;
	int			count_2;
	char_t	*new;

	count = 0;
	count_2 = 0;
	if (str == NULL || i == 0 ||
		!(new = (char_t*)malloc(sizeof(char_t) * lst_va->count + i)))
		return ;
	while (count < lst_va->count)
	{
		new[count] = lst_va->str[count];
		count++;
	}
	while (count_2 < i)
		new[count++] = str[count_2++];
	lst_va->count += i;
	if (lst_va->str != NULL)
		free(lst_va->str);
	lst_va->str = new;
}


void	ft_putprefix(t_pf *lst, int len, int nb, int point)
{
	char_t *str;
	int count;

	count = 0;
	if (len >= nb)
		return;
	if (!(str = (char_t*)malloc(sizeof(char_t) * (nb - len))))
		return ;
	while ((len + count) < nb)
		str[count++] = (point == 1 ? '0' : ' ');
	pf_tmpjoin(lst, str, count);
	free(str);
}

void			ft_print_sign(t_pf *lst)
{
	if (lst->psign == 1)
		pf_tmpjoin(lst, "-", 1);
	else if (lst->psign == 2)
		pf_tmpjoin(lst, "+", 1);
	else if (lst->psign == 3 && lst->maj == 1)
		pf_tmpjoin(lst, "0X", 2);
	else if (lst->psign == 3 && lst->maj == 0)
		pf_tmpjoin(lst, "0x", 2);
}
