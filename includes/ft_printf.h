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

typedef struct	s_valist
{
	va_list	lst_va;
	va_list	copy;
	int		fd;
	int		count;
	wuchar_t		*str;
}				t_valst;

typedef struct	s_printf
{
	unsigned long	ul_nb;
	unsigned long	ful_nb;
	long double		fl_nb;
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
	wuchar_t			*str;
	size_t				count;
	long			nb_tmp;
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
int				ft_conv(t_valst *lst_va, char *str, int index);
int				ft_conv2(t_valst *lst_va, char *str, int index);
int				ft_conv3(t_valst *lst_va, char *str, int index);

/*
** fonctions des diferents parametres
** ft_params_*.c
*/
int				ft_params_nb(t_valst *lst_va, char *str, int index);
int				ft_params_char(t_valst *lst_va, char *str, int index);
int				ft_params_perc(t_valst *lst_va, char *str, int index);
int				ft_params_no(t_valst *lst_va, char *str, int index);
int				ft_params_string(t_valst *lst_va, char *str, int index);
int				ft_params_k(t_valst *lst_va, char *str, int index);
int				ft_params_f(t_valst *lst_va, char *str, int index);
int				ft_params_a(t_valst *lst_va, char *str, int index);
int				ft_params_la(t_valst *lst_va, char *str, int index);
int				ft_params_ti(t_valst *lst_va, char *str, int index);
int				ft_params_ts(t_valst *lst_va, char *str, int index);

/*
** initialisation des lists
** lst_init.c && lst_base.c
*/
t_valst		*lstva_init(int fd);
t_pf			*lst_initoption(t_valst *lst_va, char *str, int index);
t_pf			*ft_initpf(void);
void			lstva_digit(t_valst *lst_va, int nb, int index);

/*
**	fonction pour initialisation des nombres
**	lst_initnb.c
*/
void			ft_initnb(t_pf *lst, t_valst *lst_va);
void			ft_signprefix(t_pf *lst);

/*
** fonctions put_nbr et len_nbr en unsigned long
**	utils.c
*/
int				ft_ulen_base(unsigned long nb, size_t base);

/*
**	fonctions qui affiche les couleurs && les signes( - , + , 0x , e+00 ...)
**				&& afficher les esapces et zero des precision/field
**	utils_print.c
*/

void			ft_putsign(t_pf *lst);
void			ft_putprefix(t_pf *lst, int len, int nb, int point);
void			pf_itoa(t_pf *lst, unsigned long n);
void 			pf_finaljoin(t_valst *lst_va, wuchar_t *str, size_t i);
void			pf_tmpjoin(t_pf *lst, wuchar_t *tmp, size_t len);
int 			pf_countpstr(char *str, size_t len);
void      pf_putpstr(t_pf *lst, wuchar_t *str);
int			ft_putcolor(t_valst *lst_va, char *str);

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
