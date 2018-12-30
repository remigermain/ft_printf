/* ************************************************************************** */
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

# define intmax_t long
# define PF_BUFF 10000
# define wuchar_t unsigned char
/*
** color
*/
# define white 	"\033[0m"
# define black  "\033[30m"
# define red 		"\033[31m"
# define green  "\033[32m"
# define yellow "\033[33m"
# define blue	  "\033[34m"
# define purple "\033[35m"
# define cyan	  "\033[36m"
# define grey		"\033[37m"

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
	int					tmp_count;
	wuchar_t		*tmp_str;
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
**	find_conv.c
*/
int				find_conv(t_pf *lst, char *str, int index);
int				find_conv2(t_pf *lst, char *str, int index);
int				find_conv3(t_pf *lst, char *str, int index);

/*
** fonctions des differentes convertion
** conv_*.c
*/
int				conv_int(t_pf *lst, char *str, int index);
int				conv_char(t_pf *lst, char *str, int index);
int				conv_string(t_pf *lst, char *str, int index);
int				conv_double(t_pf *lst, char *str, int index);
int				conv_tabstring(t_pf *lst, char *str, int index);

/*
** initialisation lst && fonction pour ajouter les differentes options
** lst_init.c && lst_base.c && lst_initnb.c
*/
t_pf			*lst_init(void);
void      lst_putoption(t_pf *lst, char *str, int index);
void      lst_zero(t_pf *lst);
void			lst_putdollar(t_pf *lst, int len);
void			lst_putnb(t_pf *lst);

/*
** fonctions len_nbr , len no_print char && convert in print, put color
**	utils.c
*/
void 			ftprintf_error(t_pf *lst, char *str, size_t index);
int				ft_ulen_base(unsigned long nb, size_t base);
size_t 			pf_countpstr(wuchar_t *str, size_t len);
void      pf_putpstr(t_pf *lst, wuchar_t *str);
int				pf_putcolor(t_pf *lst, char *str);

/*
**	fonctions qui put les signes( - , + , 0x )
**			 ajoute les esapces et zero des precisions/field
**				join le str entre eux && unsigned long itoa avec local
**	utils_put.c
*/
void 			pf_tmpstringjoin(t_pf *lst, wuchar_t *str, size_t len, size_t index);
void 			pf_stringjoin(t_pf *lst, wuchar_t *str, size_t len, size_t index);
void			pf_itoa(t_pf *lst, unsigned long n);
void			pf_putprefix(t_pf *lst, int len, int nb, int point);
void			pf_putsign(t_pf *lst);

/*
** fonction de debug de la list
**	debug.c
*/
void			debug(t_pf *lst);

#endif
