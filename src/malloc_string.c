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

void pf_stringjoin(t_pf *lst, wuchar_t *str, size_t len, size_t index)
{
	wuchar_t *new;
	size_t		count;

	count = 0;
	if (!(new = (wuchar_t*)malloc(sizeof(wuchar_t) * len + lst->count + 1)))
		return ;
	ft_memcpy(new, lst->str, lst->count);
	ft_memcpy(new + lst->count, str, len);
	lstfree_wuchart(lst, new, len);
	if (index == 1)
		free(str);
}

void 	lstfree_wuchart(t_pf *lst, wuchar_t *new, size_t len)
{
	lst->count += len;
	new[lst->count] = '\0';
	if (lst->str != NULL)
		free(lst->str);
	lst->str = new;
}

void		pf_itoa(t_pf *lst, unsigned long n)
{
	int		len;
	int		mlen;
	wuchar_t	*new;

	len = ft_ulen_base(n, lst->base);
	if (lst->local == 1 && len > 3)
		len += ((len / 3) - (len % 3 == 0 ? 1 : 0));
	mlen = len;
	if (!(new = (wuchar_t*)malloc(sizeof(wuchar_t) * len + lst->count + 1)))
		return ;
	ft_memcpy(new, lst->str, lst->count);
	len--;
	while (len >= 0)
	{
		if (lst->local == 1 && (mlen - len) % 4 == 0)
			new[lst->count + len-- ] = '\'';
		if ((n % lst->base) < 10)
			new[lst->count + len--] = (n % lst->base) + 48;
		else if (lst->maj == 1)
			new[lst->count + len--] = (n % lst->base) + 55;
		else
			new[lst->count + len--] = (n % lst->base) + 87;
		n = n / lst->base;
	}
	lstfree_wuchart(lst, new, mlen);
}

void	pf_putprefix(t_pf *lst, int len, int nb, int point)
{
	wuchar_t *new;
	int 			count;
	size_t		llen;

	count = 0;
	if (len >= nb)
		return;
	llen = (nb - len) + lst->count + 1;
	if (!(new = (wuchar_t*)malloc(sizeof(wuchar_t) * llen)))
		return ;
	ft_memcpy(new, lst->str, lst->count);
	ft_memset(new + lst->count, (point == 1 ? '0' : ' '), (nb - len));
	lstfree_wuchart(lst, new, (nb - len));
}

void			pf_putsign(t_pf *lst)
{
	wuchar_t *new;
	size_t len;

	if (lst->psign != 0)
	{
		len = (lst->psign == 3 ? 2 : 1);
		if (!(new = (wuchar_t*)malloc(sizeof(wuchar_t) * len)))
			return ;
		ft_memcpy(new, lst->str, lst->count);
		if (lst->psign == 1 || lst->psign == 2)
			new[lst->count] = (lst->psign == 1 ? '-' : '+');
		else if (lst->psign == 3)
		{
			new[lst->count] = '0';
			new[lst->count + 1] = (lst->maj == 1 ? 'X' : 'x');
		}
		lstfree_wuchart(lst, new, len);
	}
}
