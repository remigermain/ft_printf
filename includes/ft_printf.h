/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/09 15:34:47 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/27 19:54:43 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include "../libft/includes/libft.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct va_list2
{
	va_list	lst_va;
	va_list lst_copy;
	int		fd;
}				t_valst;

typedef struct s_option
{
	int 	fd;
	int		zero;
	char	sign;
	int		point;
	int		hash;
	int		space;
	int		star;
	int		star_bf;
	int		star_pos;
	int		dollar;
	int		dollar_nb;
	int		bf_nb;
	int		bf_zero;
	int		af_nb;
	int		af_zero;
	int		nb_tmp;
}						t_option;

/******************************************
**  main
*/

int		main(int argc, char **argv);
int		ft_printf(const char *str, ...);
int		ft_dprintf(int fd, const char *str, ...);

int		*ft_conv(t_valst *lst_va, char *str, int *tab_i, int index);
int		*ft_conv2(t_valst *lst_va, char *str, int *tab_i, int index);
int		*ft_conv3(t_valst *lst_va, char *str, int *tab_i, int index);



/****************************************
**  option params
*/
int		*ft_params_d(t_valst *lst_va, char *str, int *tab_i, int index);
int		ft_option_d(t_valst *lst_va, char *str, int count, int index);

int		*ft_params_s(t_valst *lst_va, char *str, int *tab_i, int index);
int		ft_option_s(t_valst *lst_va, char *str, int count, int index);

int		*ft_params_smaj(t_valst *lst_va, char *str, int *tab_i, int index);
int		ft_option_smaj(t_valst *lst_va, char *str, int count, int index);

int		*ft_params_c(t_valst *lst_va, char *str, int *tab_i, int index);
int		ft_option_c(t_valst *lst_va, char *str, int count, int index);

int		*ft_params_cmaj(t_valst *lst_va, char *str, int *tab_i, int index);
int		ft_option_cmaj(t_valst *lst_va, char *str, int count, int index);

int		*ft_params_p(t_valst *lst_va, char *str, int *tab_i, int index);
int		ft_option_p(t_valst *lst_va, char *str, int count, int index);

int		*ft_params_ld(t_valst *lst_va, char *str, int *tab_i, int index);
int		ft_option_ld(t_valst *lst_va, char *str, int count, int index);

int		*ft_params_lld(t_valst *lst_va, char *str, int *tab_i, int index);
int		ft_option_lld(t_valst *lst_va, char *str, int count, int index);

int		*ft_params_llo(t_valst *lst_va, char *str, int *tab_i, int index);
int		ft_option_llo(t_valst *lst_va, char *str, int count, int index);

int		*ft_params_llu(t_valst *lst_va, char *str, int *tab_i, int index);
int		ft_option_llu(t_valst *lst_va, char *str, int count, int index);

int		*ft_params_o(t_valst *lst_va, char *str, int *tab_i, int index);
int		ft_option_o(t_valst *lst_va, char *str, int count, int index);

int		*ft_params_lo(t_valst *lst_va, char *str, int *tab_i, int index);
int		ft_option_lo(t_valst *lst_va, char *str, int count, int index);

int		*ft_params_u(t_valst *lst_va, char *str, int *tab_i, int index);
int		ft_option_u(t_valst *lst_va, char *str, int count, int index);

int		*ft_params_lu(t_valst *lst_va, char *str, int *tab_i, int index);
int		ft_option_lu(t_valst *lst_va, char *str, int count, int index);

int		*ft_params_x(t_valst *lst_va, char *str, int *tab_i, int index);
int		ft_option_x(t_valst *lst_va, char *str, int count, int index);

int		*ft_params_lx(t_valst *lst_va, char *str, int *tab_i, int index);
int		ft_option_lx(t_valst *lst_va, char *str, int count, int index);

int		*ft_params_lxmaj(t_valst *lst_va, char *str, int *tab_i, int index);
int		ft_option_lxmaj(t_valst *lst_va, char *str, int count, int index);

int		*ft_params_x_maj(t_valst *lst_va, char *str, int *tab_i, int index);
int		ft_option_x_maj(t_valst *lst_va, char *str, int count, int index);


int		*ft_params_lu_maj(t_valst *lst_va, char *str, int *tab_i, int index);
int		ft_option_lu_maj(t_valst *lst_va, char *str, int count, int index);

int		*ft_params_x_maj(t_valst *lst_va, char *str, int *tab_i, int index);
int		ft_option_x_maj(t_valst *lst_va, char *str, int count, int index);

int		*ft_params_llx(t_valst *lst_va, char *str, int *tab_i, int index);
int		ft_option_llx(t_valst *lst_va, char *str, int count, int index);

int		*ft_params_llxmaj(t_valst *lst_va, char *str, int *tab_i, int index);
int		ft_option_llxmaj(t_valst *lst_va, char *str, int count, int index);

int		*ft_params_no(t_valst *lst_va, char *str, int *tab_i, int index);
int		ft_option_no(t_valst *lst_va, char *str, int count, int index);






int		*ft_params_perc(t_valst *lst_va, char *str, int *tab_i, int index);



/****************************************
**   utils
**/

int		ft_print_prefix(int len, int nb, int point);
void	ft_print_sign(int nb, int sign);
void	ft_print_lsign(long nb, int sign);
void	ft_option_star(t_valst *lst_va, t_option *lst);
void	ft_option_star2(t_option *lst, int nb);

int				*init_tab2(void);
t_valst 		*lst_init2(t_valst *lst_va, int nb, int index);
t_option		*lst_init(void);
int				ft_put_digit(t_option *lst_option, char *str, int count);
void			ft_put_star(t_option *lst_option);
t_option		*ft_put_option(char *str, int count, int index);
int				ft_printcolor(char *str, int i);
void			ft_printcolor2(int i);


#endif
