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
# define BUFF_PRINTF 64
# define BUFF_FLOAT 256
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
	va_list			va_lst;
	va_list			va_copy;
	int					buff_count;
	wuchar_t		buff[BUFF_PRINTF];
	int					count;
	wuchar_t		*str;
	unsigned long	ul_nb;
	unsigned long ful_nb;
	long double		fl_nb;
	int					exponent;
	size_t			hash;
	size_t			space;
	size_t			zero;
	size_t			sign;
	size_t			local;
	int					field;
	size_t			point;
	int					preci;
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
int				ft_sprintf(wuchar_t **dest, const char *format, ...);
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

/*
** initialisation lst && fonction pour ajouter les differentes options
** lst_init.c && lst_base.c && lst_initnb.c
*/
t_pf			*lst_init(void);
void      lst_putoption(t_pf *lst, char *str, int index);
void      lst_zero(t_pf *lst);
void			lst_putdollar(t_pf *lst, int len);
void			lst_putint(t_pf *lst);
void			lst_putdouble(t_pf *lst);

/*
** fonctions len_nbr , len no_print char && convert in print, put color
**	utils.c
*/
void 			ftprintf_error(t_pf *lst, char *str, size_t index);
int				ulen_base(unsigned long nb, size_t base);
size_t 		len_pstrn(wuchar_t *str, size_t len, size_t index);
int				put_color(t_pf *lst, char *str);

/*
**	fonctions qui put les signes( - , + , 0x )
**			 ajoute les esapces et zero des precisions/field
**				join le str entre eux && unsigned long itoa avec local
**	utils_put.c
*/
void 			comvert_buff(t_pf *lst,void *tmp, size_t len);
void 			put_buff(t_pf *lst, void *tmp, size_t len, size_t index);
void			put_itoa(t_pf *lst, unsigned long n);
void			put_prefix(t_pf *lst, int len, int nb, int point);
void			put_sign(t_pf *lst);

/*
** fonction de debug de la list
**	debug.c
*/
void			debug(t_pf *lst);

#endif
