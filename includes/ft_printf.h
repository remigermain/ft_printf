/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgermain <rgermain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 15:50:06 by rgermain          #+#    #+#             */
/*   Updated: 2019/01/04 16:35:44 by rgermain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../libft/includes/libft.h"
# include "color.h"
# include <stdarg.h>
# include <stdio.h>

# define BUFF_PRINTF 64
# define BUFF_FLOAT 256
# define WUCHAR_T unsigned char
# define ULONG_T unsigned long

/*
** Macro divers
*/
# define ABS(a)				(a < 0 ? -a : a)
# define MAX(a, b)			(a < b ? b : a)
# define MIN(a, b)			(a < b ? a : b)

/*
** raccourcie list
*/
# define EXPONENT lst->exponent
# define HASH lst->hash
# define SPACE	lst->space
# define ZERO lst->zero
# define SIGN lst->sign
# define LOCAL lst->local
# define FIELD lst->field
# define POINT lst->point
# define PRECI lst->preci
# define MAJ lst->maj
# define PSIGN lst->psign
# define BASE lst->base
# define LENGHT lst->lenght
# define CONV lst->conv

typedef struct	s_printf
{
	va_list			va_lst;
	va_list			va_copy;
	int				buff_count;
	WUCHAR_T		buff[BUFF_PRINTF];
	int				count;
	WUCHAR_T		*str;
	ULONG_T			ul_nb;
	ULONG_T			ful_nb;
	long double		fl_nb;
	int				exponent;
	size_t			hash;
	size_t			space;
	size_t			zero;
	size_t			sign;
	size_t			local;
	int				field;
	size_t			point;
	int				preci;
	size_t			maj;
	size_t			psign;
	size_t			base;
	size_t			lenght;
	size_t			conv;
}				t_pf;

/*
**	fonctions main de ft_printf
**	ft_printf.c
*/
int				ft_printf(const char *str, ...);
int				ft_dprintf(int fd, const char *str, ...);
int				ft_sprintf(WUCHAR_T **dest, const char *format, ...);
int				find_conv(t_pf *lst, char *str, int index);

/*
** fonctions des differentes convertion
** conv_*.c
*/
int				conv_int(t_pf *lst, char *str, int index);
int				conv_char(t_pf *lst, char *str, int index);
int				conv_string(t_pf *lst, char *str, int index);
int				conv_double(t_pf *lst, char *str, int index);
int				conv_tabstring(t_pf *lst, char *str, int index);
int				conv_other(t_pf *lst, char *str, int index);

/*
** initialisation lst && fonction pour ajouter les differentes options
** lst_init.c && lst_base.c && lst_initnb.c
*/
t_pf			*lst_init(void);
void			lst_putoption(t_pf *lst, char *str, int index);
void			lst_zero(t_pf *lst);
void			lst_putdollar(t_pf *lst, int len);
void			lst_putint(t_pf *lst);
void			lst_putdouble(t_pf *lst);

/*
** fonctions len_nbr , len no_print char && convert in print, put color
**	utils.c
*/
void			ftprintf_error(t_pf *lst, char *str, size_t index);
int				ulen_base(ULONG_T nb, size_t base);
size_t			len_pstrn(WUCHAR_T *str, size_t len, size_t index);
int				conv_color(t_pf *lst, char *str, int index);

/*
**	fonctions qui put les signes( - , + , 0x )
**			 ajoute les esapces et zero des precisions/field
**				join le str entre eux && ULONG_T itoa avec local
**	utils_put.c
*/
void			comvert_buff(t_pf *lst, void *tmp, size_t len);
void			put_buff(t_pf *lst, void *tmp, size_t len, size_t index);
void			put_itoa(t_pf *lst, ULONG_T n);
void			put_prefix(t_pf *lst, int len, int nb, int point);
void			put_sign(t_pf *lst);

/*
** fonction de debug de la list
**	debug.c
*/
void			debug(t_pf *lst);

#endif
