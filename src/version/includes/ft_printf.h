/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/09 15:34:47 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/16 09:15:10 by rgermain    ###    #+. /#+    ###.fr     */
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
}				t_valst;

typedef struct s_option
{
	char	sign;
	int		point;
	int		hash;
	int		space;
	int		star;
	int		star_pos;
	int		dollar;
	int		dollar2;
	int		dollar_nb;
	int		dollar_nb2;
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
int		*ft_main_params(t_valst *lst_va, char *str, int *tab_i, int index);
int		*ft_main_params2(t_valst *lst_va, char *str, int *tab_i, int index);




/****************************************
**  option params
*/
int		*ft_params_d(t_valst *lst_va, char *str, int *tab_i, int index);
int		*ft_params_d2(t_valst *lst_va, char *str, int *tab_i, int index);
int		*ft_params_o(t_valst *lst_va, char *str, int *tab_i, int index);
int		*ft_params_o2(t_valst *lst_va, char *str, int *tab_i, int index);
int		*ft_params_c(t_valst *lst_va, char *str, int *tab_i, int index);
int		*ft_params_s(t_valst *lst_va, char *str, int *tab_i, int index);
int		*ft_params_p(t_valst *lst_va, char *str, int *tab_i, int index);
int		*ft_params_perc(t_valst *lst_va, char *str, int *tab_i, int index);
int		*ft_params_x(t_valst *lst_va, char *str, int *tab_i, int index);
int		*ft_params_x2(t_valst *lst_va, char *str, int *tab_i, int index);
int		*ft_params_u(t_valst *lst_va, char *str, int *tab_i, int index);
int		*ft_params_u2(t_valst *lst_va, char *str, int *tab_i, int index);






/****************************************
**  files with index
*/


int		ft_option_d(t_valst *lst_va, char *str, int count, int index);
int		ft_option_o(t_valst *lst_va, char *str, int count, int index);
int		ft_option_o2(t_valst *lst_va, char *str, int count, int index);
int		ft_option_c(t_valst *lst_va, char *str, int count, int index);
int		ft_option_s(t_valst *lst_va, char *str, int count, int index);
int		ft_option_p(t_valst *lst_va, char *str, int count, int index);
int		ft_option_x(t_valst *lst_va, char *str, int count, int index);
int		ft_option_x2(t_valst *lst_va, char *str, int count, int index);
int		ft_option_u(t_valst *lst_va, char *str, int count, int index);
int		ft_option_u2(t_valst *lst_va, char *str, int count, int index);
int		ft_option_d2(t_valst *lst_va, char *str, int count, int index);






/****************************************
**   utils
**/

t_option		*ft_put_option(char *str, int count, int index);
t_option		*lst_init(void);
t_valst 		*ft_lst_init2(t_valst *lst_va, int nb, int index);
int				*tab_2_init(void);

#endif
