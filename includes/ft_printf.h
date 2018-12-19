/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/09 15:34:47 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/19 23:03:30 by rgermain    ###    #+. /#+    ###.fr     */
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

typedef struct	s_valist
{
	va_list	lst_va;
	va_list	copy;
	int		fd;
	int		count;
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
	size_t			fd;
	long			nb_tmp;
}				t_pf;

typedef struct	s_time
{
	int	da;
	int	h;
	int	mi;
	int	d;
	int	mo;
	int	y;
}				t_time;

/*
**	fonctions main de ft_printf
**	ft_printf.c
*/
int				ft_printf(const char *str, ...);
int				ft_dprintf(int fd, const char *str, ...);

/*
**	fonctions pour trouver quelles sont les parametres
**	ft_conv.c
*/
int				ft_conv(t_valst *lst_va, char *str, int i, int index);
int				ft_conv2(t_valst *lst_va, char *str, int i, int index);
int				ft_conv3(t_valst *lst_va, char *str, int i, int index);

/*
** fonctions des diferents parametres
** ft_params_*.c
*/
int				ft_params_nb(t_valst *lst_va, char *str, int i, int index);
int				ft_params_char(t_valst *lst_va, char *str, int i, int index);
int				ft_params_perc(t_valst *lst_va, char *str, int i, int index);
int				ft_params_no(t_valst *lst_va, char *str, int i, int index);
int				ft_params_string(t_valst *lst_va, char *str, int i, int index);
int				ft_params_k(t_valst *lst_va, char *str, int i, int index);
int				ft_params_f(t_valst *lst_va, char *str, int i, int index);
int				ft_params_a(t_valst *lst_va, char *str, int i, int index);
int				ft_params_la(t_valst *lst_va, char *str, int i, int index);
int				ft_params_ti(t_valst *lst_va, char *str, int i, int index);
int				ft_params_ts(t_valst *lst_va, char *str, int i, int index);

/*
** initialisation des lists
** lst_init.c && lst_base.c
*/
t_valst			*lstva_init(int fd);
t_pf			*lst_initoption(t_valst *lst_va, char *str, int i, int index);
t_pf			*ft_initpf(t_valst *lst_va);
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
int				ft_putnbr_ulm(unsigned long nb, size_t b, size_t m, size_t fd);
int				ft_putnbr_ul(unsigned long nb, size_t fd);
int				ft_ulen_base(unsigned long nb, size_t base);
int				ft_ulen(unsigned long nb);

/*
**	fonctions qui affiche les couleurs && les signes( - , + , 0x , e+00 ...)
**				&& afficher les esapces et zero des precision/field
**	utils_print.c
*/
int				ft_print_prefix(int len, int nb, int point, int fd);
int				ft_printcolor(char *str, int i, int fd);
int				ft_print_sign(t_pf *lst);

/*
**	fonctions put_double len_double en unsigned long double !
**	utils_double.c
*/
int				ft_putnbr_dlm(t_pf *lst);
int				ft_calcul_len2(t_pf *lst, int len, int index);

/*
** fonction de debug de la list
**	debug.c
*/
void			debug(t_pf *lst);

#endif
