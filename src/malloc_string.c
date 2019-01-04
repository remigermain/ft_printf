/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   malloc_string.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/04 16:26:02 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/04 16:26:03 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	comvert_buff(t_pf *lst, void *tmp, size_t len)
{
	wuchar_t	*new;
	size_t		len_malloc;

	len_malloc = lst->count + lst->buff_count + len + 1;
	if ((new = (wuchar_t*)ft_memalloc(len_malloc)) == NULL)
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

void	put_buff(t_pf *lst, void *tmp, size_t len, size_t index)
{
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

void	put_itoa(t_pf *lst, ulong_t n)
{
	wuchar_t	tmp[27];
	int			len;
	int			mlen;

	len = ulen_base(n, BASE);
	if (LOCAL == 1 && (len - 1) > 3)
		len += ((len / 3) - (len % 3 == 0 ? 1 : 0));
	mlen = len;
	len--;
	while (len >= 0)
	{
		if (LOCAL == 1 && ((mlen - len) % 4 == 0))
			tmp[len--] = ',';
		if ((n % BASE) < 10)
			tmp[len--] = (n % BASE) + 48;
		else
			tmp[len--] = (n % BASE) + (MAJ == 1 ? 55 : 87);
		n = n / BASE;
	}
	put_buff(lst, tmp, mlen, 0);
}

void	put_prefix(t_pf *lst, int len, int nb, int point)
{
	size_t		llen;
	wuchar_t	tmp[nb - len];

	llen = (nb - len);
	if (len >= nb)
		return ;
	ft_memset(tmp, (point == 1 ? '0' : ' '), llen);
	put_buff(lst, tmp, llen, 0);
}

void	put_sign(t_pf *lst)
{
	if (PSIGN == 1)
		put_buff(lst, "-", 1, 0);
	else if (PSIGN == 2)
		put_buff(lst, "+", 1, 0);
	else if (PSIGN == 3)
		put_buff(lst, (MAJ == 1 ? "0X" : "0x"), 2, 0);
	else if (PSIGN == 4)
		put_buff(lst, ".", 1, 0);
}
