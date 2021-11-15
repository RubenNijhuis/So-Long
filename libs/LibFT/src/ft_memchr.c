/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rnijhuis <rnijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/09 09:44:48 by rnijhuis      #+#    #+#                 */
/*   Updated: 2021/11/09 09:44:48 by rnijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *src, int c, size_t n)
{
	const unsigned char	*ptr_src;
	unsigned char		chr;

	ptr_src = (const unsigned char *)src;
	chr = (unsigned char)c;
	while (n > 0)
	{
		if (*ptr_src == chr)
			return ((void *)ptr_src);
		ptr_src++;
		n--;
	}
	return (NULL);
}
