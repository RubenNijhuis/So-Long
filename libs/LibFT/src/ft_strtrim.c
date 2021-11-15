/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rnijhuis <rnijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/09 09:45:52 by rnijhuis      #+#    #+#                 */
/*   Updated: 2021/11/09 09:45:53 by rnijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	contains(char c, char const *set)
{
	unsigned int	i;

	i = 0;
	while (set[i] != 0)
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *src, char const *set)
{
	char			*string;
	const char		*end;
	size_t			len;

	if (src == NULL)
		return (NULL);
	while (contains(*src, set))
		++src;
	if (*src == '\0')
		return (ft_strdup(""));
	end = ft_strchr(src, 0) - 1;
	while (contains(*end, set))
		--end;
	len = end - src + 1;
	string = malloc((len + 1) * sizeof(char));
	if (string == NULL)
		return (NULL);
	ft_strlcpy(string, src, len + 1);
	return (string);
}
