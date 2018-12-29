/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/09 15:34:47 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/20 18:57:02 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../libft/includes/libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

# define intmax_t long
# define PF_BUFF 10000
# define wuchar_t unsigned char

typedef struct	s_printf
{
	unsigned long	ul_nb;
	unsigned long	ful_nb;
	long double		fl_nb;
	long			nb_tmp;
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
	va_list			va_lst;
	va_list			va_copy;
	int					count;
	wuchar_t		*str;
}				t_pf;

/*
**	fonctions main de ft_printf
**	ft_printf.c
*/
int				ft_printf(const char *str, ...);
int				ft_dprintf(int fd, const char *str, ...);
int				ft_sprintf(wuchar_t **dest, const char *format, ...);

/*
**	fonctions pour trouver quelles sont les parametres
**	ft_conv.c
*/
int				ft_conv(t_pf *lst, char *str, int index);
int				ft_conv2(t_pf *lst, char *str, int index);
int				ft_conv3(t_pf *lst, char *str, int index);

/*
** fonctions des diferents parametres
** ft_params_*.c
*/
int				ft_params_nb(t_pf *lst, char *str, int index);
int				ft_params_char(t_pf *lst, char *str, int index);
int				ft_params_string(t_pf *lst, char *str, int index);
int				ft_params_f(t_pf *lst, char *str, int index);
int				ft_params_ts(t_pf *lst, char *str, int index);

/*
** initialisation des lists && fonction pour initialisation des nombres
** lst_init.c && lst_base.c && lst_initnb.c
*/
t_pf			*lst_init(void);
void      lst_putoption(t_pf *lst, char *str, int index);
void      lst_zero(t_pf *lst);
void			lst_initdollar(t_pf *lst, int nb, int index);
void			lst_putnb(t_pf *lst);

/*
** fonctions len_nbr , len no_print char && convert in print, put color
**	utils.c
*/
int				ft_ulen_base(unsigned long nb, size_t base);
int				ft_ulen(unsigned long nb);
int 			pf_countpstr(char *str, size_t len);
void      pf_putpstr(t_pf *lst, wuchar_t *str);
int				ft_putcolor(t_pf *lst, char *str);

/*
**	fonctions qui put les signes( - , + , 0x )
**			 ajoute les esapces et zero des precision/field
**				join le str entre eux && unsigned long itoa
**	utils_put.c
*/
void 			pf_stringjoin(t_pf *lst, wuchar_t *str, size_t len, size_t index);
void      new_wuchart(t_pf *lst, wuchar_t **new, size_t len);
void 			lstfree_wuchart(t_pf *lst, wuchar_t *new, size_t len);
void			pf_itoa(t_pf *lst, unsigned long n);
void			pf_putprefix(t_pf *lst, int len, int nb, int point);
void			pf_putsign(t_pf *lst);

/*
**	fonctions put_double len_double en unsigned long double !
**	utils_double.c
*/
void			ft_printdouble(t_pf *lst, unsigned long nb[PF_BUFF]);
void 			ft_double_roundup(t_pf *lst, unsigned long nb[PF_BUFF]);

/*
** fonction de debug de la list
**	debug.c
*/
void			debug(t_pf *lst);

#endif
