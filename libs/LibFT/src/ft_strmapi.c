/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rnijhuis <rnijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/09 09:45:48 by rnijhuis      #+#    #+#                 */
/*   Updated: 2021/11/09 09:45:48 by rnijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*string;
	unsigned int	i;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	string = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (string == NULL)
		return (NULL);
	while (s[i] != 0)
	{
		string[i] = f(i, s[i]);
		i++;
	}
	string[i] = 0;
	return (string);
}
