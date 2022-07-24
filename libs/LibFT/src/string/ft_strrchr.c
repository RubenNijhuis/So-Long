/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rubennijhuis <rubennijhuis@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/12 15:50:59 by rubennijhui   #+#    #+#                 */
/*   Updated: 2022/05/07 12:14:19 by rubennijhui   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int32_t c)
{
	uint32_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	while (i + 1 != 0)
	{
		if ((char)s[i] == (char)c)
			return ((char *)s + i);
		i--;
	}
	return (0);
}
