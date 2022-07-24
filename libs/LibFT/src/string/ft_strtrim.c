/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rubennijhuis <rubennijhuis@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/12 15:51:01 by rubennijhui   #+#    #+#                 */
/*   Updated: 2022/05/03 22:56:46 by rubennijhui   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

/**
 * @brief 
 * Trims the start and end of a string based 
 * on a set of characters
 * 
 * @param src String to be trimmed
 * @param set 
 * @return char* 
 */
char	*ft_strtrim(char const *src, char const *set)
{
	char			*string;
	const char		*end;
	size_t			len;

	if (src == NULL)
		return (NULL);
	while (ft_isinset(set, *src))
		++src;
	if (*src == '\0')
		return (ft_strdup(""));
	end = ft_strchr(src, 0) - 1;
	while (ft_isinset(set, *end))
		--end;
	len = end - src + 1;
	string = ft_calloc((len + 1), sizeof(char));
	if (string == NULL)
		return (NULL);
	ft_strlcpy(string, src, len + 1);
	return (string);
}
