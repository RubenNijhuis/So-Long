/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rnijhuis <rnijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/09 09:44:50 by rnijhuis      #+#    #+#                 */
/*   Updated: 2021/11/09 09:44:51 by rnijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*one;
	const unsigned char	*two;

	one = s1;
	two = s2;
	while (n != 0)
	{
		if (*one != *two)
			return (*one - *two);
		n--;
		one++;
		two++;
	}
	return (0);
}
