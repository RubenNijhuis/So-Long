/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isinset.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rubennijhuis <rubennijhuis@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/03 22:53:15 by rubennijhui   #+#    #+#                 */
/*   Updated: 2022/05/08 17:34:35 by rubennijhui   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief 
 * Checks if a char is in a set of chars 
 * and returns true of false based on a char
 * 
 * @param c 
 * @param set 
 * @return int32_t
 */
int32_t	ft_isinset(char const *set, char c)
{
	uint32_t	i;

	i = 0;
	while (set[i] != 0)
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}
