/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtoupper.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jobvan-d <jobvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/14 12:54:21 by jobvan-d      #+#    #+#                 */
/*   Updated: 2022/06/22 14:44:12 by jobvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* converts a string to uppercase. */
char	*ft_strtoupper(char *s)
{
	const char	*orig;

	orig = s;
	while (*s != 0)
	{
		if (*s >= 'a' && *s <= 'z')
		{
			*s -= ('a' - 'A');
		}
		s++;
	}
	return ((char *)orig);
}
