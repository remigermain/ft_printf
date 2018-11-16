/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/09 15:34:47 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/13 22:40:48 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include "../libft/includes/libft.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct va_list2
{
	va_list	lst_va;
	va_list lst_copy;
}				t_valst;

typedef struct s_option
{
	char	sign;
	int		point;
	int		space;
	int		star;
	int		dollar;
	int		dollar_nb;
	int		nb;
}						t_option;

int		*ft_params_perc(va_list lst_va, char *str, int *tab_i, int index);
int		*ft_params_p(va_list lst_va, char *str, int *tab_i, int index);
int		*ft_params_c(va_list lst_va, char *str, int *tab_i, int index);
int		*ft_params_d(va_list lst_va, char *str, int *tab_i, int index);
int		*ft_params_s(va_list lst_va, char *str, int *tab_i, int index);

int		ft_printf(const char *str, ...);

/*
**  params
*/
int		*ft_main_params2(va_list lst_va, char *str, int *tab_i, int index);
int		*ft_main_params(va_list lst_va, char *str, int *tab_i, int index);

/*
**  option params
*/

int		ft_option_d(va_list lst_va, char *str, int count, int index);






/*
**   utils
**/
char	*ft_strjoin_s2(const char *s1, char *s2);
char	*ft_strjoin_s1(char *s1, const char *s2);
char	*ft_strjoin_s(char *s1, char *s2);
void	ft_strjoin_ss(char **s1, char **s2);
t_option	*ft_put_option(char *str, int count, int index);
t_option	*lst_init(void);
int			ft_calcul_lst(t_option *lst, int nb);

#endif
