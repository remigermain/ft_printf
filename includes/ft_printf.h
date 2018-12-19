/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/09 15:34:47 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/19 19:16:54 by rgermain    ###    #+. /#+    ###.fr     */
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

typedef	struct	s_valist
{
	va_list	lst_va;
	va_list	copy;
	int		fd;
	int		count;
}				t_valst;

typedef	struct	s_printf
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
**  main
*/
int			main(int argc, char **argv);
int			ft_printf(const char *str, ...);
int			ft_dprintf(int fd, const char *str, ...);
int			ft_conv(t_valst *lst_va, char *str, int i, int index);
int			ft_conv2(t_valst *lst_va, char *str, int i, int index);
int			ft_conv3(t_valst *lst_va, char *str, int i, int index);

/*
**  option params
*/
int			ft_params_nb(t_valst *lst_va, char *str, int i, int index);
int			ft_params_char(t_valst *lst_va, char *str, int i, int index);
int			ft_params_perc(t_valst *lst_va, char *str, int i, int index);
int			ft_params_no(t_valst *lst_va, char *str, int i, int index);
int			ft_params_string(t_valst *lst_va, char *str, int i, int index);
int			ft_params_lstring(t_valst *lst_va, t_pf *lst);
int			ft_params_k(t_valst *lst_va, char *str, int i, int index);
int			ft_params_f(t_valst *lst_va, char *str, int i, int index);
int			ft_params_a(t_valst *lst_va, char *str, int i, int index);
int			ft_params_la(t_valst *lst_va, char *str, int i, int index);
int			ft_params_ti(t_valst *lst_va, char *str, int i, int index);
int			ft_params_ts(t_valst *lst_va, char *str, int i, int index);

/*
**   utils
*/
t_valst		*lstva_init(int fd);
void		lstva_digit(t_valst *lst_va, int nb, int index);
t_pf		*lst_initoption(t_valst *lst_va, char *str, int i, int index);
int			lst_putstar_doll(t_valst *lst_va, t_pf *lst, char *str, int count);
t_pf		*ft_initpf(t_valst *lst);

int			ft_putnbr_ulm(unsigned long nb, size_t base, size_t maj, size_t fd);
int			ft_putnbr_ul(unsigned long nb, size_t fd);
int			ft_ulen_base(unsigned long nb, size_t base);
int			ft_ulen(unsigned long nb);
int			ft_atoi2(const char *str, int *count);
int			ft_calcul_len2(t_pf *lst, int len, int index);
int			ft_countchar(wchar_t c);

/*
** utils print
*/
int			ft_print_prefix(int len, int nb, int point, int fd);
int			ft_print_sign(t_pf *lst);
int			ft_printcolor(char *str, int i, int fd);
void		ft_printcolor2(int i, int fd);
int			ft_putnbr_dlm(t_pf *lst);
void		debug(t_pf *lst);

/*
**	lst_init
*/
void		ft_initnb(t_pf *lst, t_valst *lst_va);
void		ft_init_snb(t_pf *lst, t_valst *lst_va);
void		ft_init_unb(t_pf *lst, t_valst *lst_va);
void		ft_signprefix(t_pf *lst);
int			ft_signcalc(t_pf *lst);
int			ft_hashcalc(t_pf *lst, int index, int len);
int			ft_spacecalc(t_pf *lst, int len, int i);

#endif
