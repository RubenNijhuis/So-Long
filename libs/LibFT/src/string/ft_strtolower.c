/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtolower.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jobvan-d <jobvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/14 12:54:20 by jobvan-d      #+#    #+#                 */
/*   Updated: 2022/06/22 14:44:25 by jobvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* converts a string to lowercase. */
char	*ft_strtolower(char *s)
{
	const char	*orig;

	orig = s;
	while (*s != 0)
	{
		if (*s >= 'A' && *s <= 'Z')
		{
			*s += ('a' - 'A');
		}
		s++;
	}
	return ((char *)orig);
}
