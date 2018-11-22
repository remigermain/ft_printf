/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_trjoin.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 17:55:10 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/12 13:39:37 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strjoin_s(char *s1, char *s2)
{
	int		count;
	int		count_2;
	int		len;
	char	*new;

	count = 0;
	count_2 = 0;
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(new = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (s1[count] != '\0')
	{
		new[count] = s1[count];
		count++;
	}
	while (s2[count_2] != '\0')
		new[count++] = s2[count_2++];
	new[len] = '\0';
	free(s1);
	free(s2);
	return (new);
}

char	*ft_strjoin_s1(char *s1, char const *s2)
{
	int		count;
	int		count_2;
	int		len;
	char	*new;

	count = 0;
	count_2 = 0;
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(new = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (s1[count] != '\0')
	{
		new[count] = s1[count];
		count++;
	}
	while (s2[count_2] != '\0')
		new[count++] = s2[count_2++];
	new[len] = '\0';
	ft_memdel((void**)&s1);
	return (new);
}

char	*ft_strjoin_s2(char const *s1, char *s2)
{
	int		count;
	int		count_2;
	int		len;
	char	*new;

	count = 0;
	count_2 = 0;
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(new = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (s1[count] != '\0')
	{
		new[count] = s1[count];
		count++;
	}
	while (s2[count_2] != '\0')
		new[count++] = s2[count_2++];
	new[len] = '\0';
	ft_memdel((void**)&s2);
	return (new);
}
