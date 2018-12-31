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

wuchar_t 	*comv_pstr(t_pf *lst, wuchar_t *str, size_t len)
{
	wuchar_t *new;
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (!(new = (wuchar_t*)malloc(sizeof(wuchar_t) * len + 1)))
		ftprintf_error(lst, "pf_putpstr", 1);
	while (str[i] != '\0' && i < len)
	{
		if (str[i] == '\n')
			new[j++] = '$';
		if (ft_isprint(str[i]) || str[i] == '\n' || str[i] == '\t')
			new[j++] = str[i++];
		else
		{
			new[j++] = '^';
			new[j++] = (str[i++] + 64);
		}
	}
	free(str);
	return (new);
}

void pf_stringjoin(t_pf *lst, wuchar_t *str, size_t len, size_t index)
{
	wuchar_t *new;

	if (!(new = (wuchar_t*)malloc(sizeof(wuchar_t) * len + lst->count + 1)))
		ftprintf_error(lst, "pf_string join", 1);
	ft_memcpy(new, lst->str, lst->count);
	ft_memcpy(new + lst->count, str, len);
	lst->count += len;
	new[lst->count] = '\0';
	if (lst->str != NULL)
		free(lst->str);
	lst->str = new;
	if (index == 1)
		free(str);
}

void		pf_itoa(t_pf *lst, unsigned long n)
{
	int		len;
	int		mlen;
	wuchar_t	*new;

	len = ulen_base(n, lst->base);
	if (lst->local == 1 && len > 3)
		len += ((len / 3) - (len % 3 == 0 ? 1 : 0));
	mlen = len;
	if (!(new = (wuchar_t*)malloc(sizeof(wuchar_t) * len + lst->tmp_count + 1)))
		ftprintf_error(lst, "pf_itoa", 1);
	new[len-- + lst->tmp_count] = '\0';
	ft_memcpy(new, lst->tmp_str, lst->tmp_count);
	while (len >= 0)
	{
		if (lst->local == 1 && (mlen - len) % 4 == 0)
			new[lst->tmp_count + len-- ] = '\'';
		if ((n % lst->base) < 10)
			new[lst->tmp_count + len--] = (n % lst->base) + 48;
		else
			new[lst->tmp_count + len--] = (n % lst->base) + (lst->maj == 1 ? 55 : 87);
		n = n / lst->base;
	}
	lst->tmp_count += mlen;
	if (lst->tmp_str != NULL)
		free(lst->tmp_str);
	lst->tmp_str = new;
}

void	pf_putprefix(t_pf *lst, int len, int nb, int point)
{
	wuchar_t *new;
	size_t		llen;

	if (len >= nb)
		return;
	llen = (nb - len) + lst->tmp_count;
	if (!(new = (wuchar_t*)malloc(sizeof(wuchar_t) * llen + 1)))
		ftprintf_error(lst, "pf_putprefix", 1);
	ft_memcpy(new, lst->tmp_str, lst->tmp_count);
	ft_memset(new + lst->tmp_count, (point == 1 ? '0' : ' '), (nb - len));
	lst->tmp_count += (nb - len);
	new[lst->tmp_count] = '\0';
	if (lst->tmp_str != NULL)
		free(lst->tmp_str);
	lst->tmp_str = new;
}

void			pf_putsign(t_pf *lst)
{
	wuchar_t *new;
	size_t len;

	if (lst->psign != 0)
	{
		len = (lst->psign == 3 ? 2 : 1);
		if (!(new = (wuchar_t*)malloc(sizeof(wuchar_t) * len + lst->tmp_count + 1)))
			ftprintf_error(lst, "pf_putsign", 1);
		ft_memcpy(new, lst->tmp_str, lst->tmp_count);
		if (lst->psign == 1 || lst->psign == 2)
			new[lst->tmp_count] = (lst->psign == 1 ? '-' : '+');
		if (lst->psign == 4)
			new[lst->tmp_count] = '.';
		else if (lst->psign == 3)
		{
			new[lst->tmp_count] = '0';
			new[lst->tmp_count + 1] = (lst->maj == 1 ? 'X' : 'x');
		}
		lst->tmp_count += len;
		new[lst->tmp_count] = '\0';
		if (lst->tmp_str != NULL)
			free(lst->tmp_str);
		lst->tmp_str = new;
	}
}
