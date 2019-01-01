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

void 			comvert_buff(t_pf *lst, void *tmp, size_t len)
{
	wuchar_t	*new;

	if (!(new = (wuchar_t*)malloc(lst->count + lst->buff_count + len + 1)))
		ftprintf_error(lst, "comvert_buff", 1);
	new[lst->count + lst->buff_count + len + 1] = '\0';
	ft_memcpy(new, lst->str, lst->count);
	ft_memcpy(new + lst->count, lst->buff, lst->buff_count);
	ft_memcpy(new + lst->count + lst->buff_count, tmp, len);
	if (lst->str != NULL)
		free(lst->str);
	lst->str = new;
	lst->count += lst->buff_count + len;
	lst->buff_count = 0;
}

void 			put_buff(t_pf *lst, void *tmp, size_t len, size_t index)
{
	wuchar_t	*new;

	if (len == 0)
		return ;
	if (((lst->buff_count + len) >= BUFF_PRINTF) || len >= BUFF_PRINTF)
		comvert_buff(lst, tmp, len);
	else
	{
		ft_memcpy(lst->buff + lst->buff_count, tmp, len);
		lst->buff_count += len;
	}
	if (index == 1)
		free(tmp);
}

void		put_itoa(t_pf *lst, unsigned long n)
{
	int		len;
	int		mlen;
	wuchar_t tmp[27];

	len = ulen_base(n, lst->base);
	if (lst->local == 1 && (len - 1) > 3)
		len += ((len / 3) - (len % 3 == 0 ? 1 : 0));
	mlen = len;
	len--;
	while (len >= 0)
	{
		if (lst->local == 1 && ((mlen - len) % 4 == 0))
			tmp[len-- ] = '\'';
		if ((n % lst->base) < 10)
			tmp[len--] = (n % lst->base) + 48;
		else
			tmp[len--] = (n % lst->base) + (lst->maj == 1 ? 55 : 87);
		n = n / lst->base;
	}
	put_buff(lst, tmp, mlen, 0);
}

void	put_prefix(t_pf *lst, int len, int nb, int point)
{
	size_t		llen;
	wuchar_t	tmp[nb - len];

	llen = (nb - len);
	if (len >= nb)
		return;
	ft_memset(tmp, (point == 1 ? '0' : ' '), llen);
	put_buff(lst, tmp, llen, 0);
}

void			put_sign(t_pf *lst)
{
	if (lst->psign == 1)
		put_buff(lst, "-", 1, 0);
	else if (lst->psign == 2)
		put_buff(lst, "+", 1, 0);
	else if (lst->psign == 3)
		put_buff(lst, (lst->maj == 1 ? "0X" : "0x"), 2, 0);
	else if (lst->psign == 4)
		put_buff(lst, ".", 1, 0);
}
