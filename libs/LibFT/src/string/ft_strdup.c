/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rubennijhuis <rubennijhuis@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/12 15:50:45 by rubennijhui   #+#    #+#                 */
/*   Updated: 2022/05/03 22:41:18 by rubennijhui   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief 
 * Duplicates a given string and returns a 
 * pointer to the newly allocated string
 * 
 * @param s1 string to be duplicated
 * @return char* 
 */
char	*ft_strdup(const char *s1)
{
	char	*string;

	string = ft_calloc((ft_strlen(s1) + 1), sizeof(char));
	if (string == NULL)
		return (NULL);
	ft_strlcpy(string, s1, ft_strlen(s1) + 1);
	return (string);
}
