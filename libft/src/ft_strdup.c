/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strdup.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/02 17:24:37 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/08 18:06:26 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		len;
	int		count;
	char	*dest;

	len = ft_strlen(s1);
	count = 0;
	if (!(dest = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (s1[count] != '\0')
	{
		dest[count] = s1[count];
		count++;
	}
	dest[count] = '\0';
	return (dest);
}

unsigned char	*ft_ustrndup(unsigned char *s1, size_t len)
{
	size_t					count;
	unsigned char		*dest;

	count = 0;
	if (!(dest = (unsigned char *)malloc(sizeof(unsigned char) * len + 1)))
		return (NULL);
	while (count < len)
	{
		dest[count] = s1[count];
		count++;
	}
	dest[count] = '\0';
	return (dest);
}

unsigned char	*ft_strndup(char *s1, size_t len)
{
	size_t					count;
	unsigned char		*dest;

	count = 0;
	if (!(dest = (unsigned char *)malloc(sizeof(unsigned char) * len + 1)))
		return (NULL);
	while (count < len)
	{
		dest[count] = s1[count];
		count++;
	}
	dest[count] = '\0';
	return (dest);
}
