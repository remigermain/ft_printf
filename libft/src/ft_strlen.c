/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlen.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/02 17:17:10 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/06 12:48:03 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	return ((*s ? 1 + ft_strlen(s + 1) : 0));
}

size_t	ft_strnlen(const char *s, size_t max)
{
	return (((*s && max > 0) ? 1 + ft_strnlen(s + 1, max - 1) : 0));
}

size_t	ft_ustrlen(const unsigned char *s)
{
	return ((*s ? 1 + ft_ustrlen(s + 1) : 0));
}

size_t	ft_ustrnlen(const unsigned char *s, size_t max)
{
	return (((*s != '\0' && max > 0) ? 1 + ft_ustrnlen(s + 1, max - 1) : 0));
}
