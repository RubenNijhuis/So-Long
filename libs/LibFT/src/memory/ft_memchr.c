/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rubennijhuis <rubennijhuis@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/12 15:50:24 by rubennijhui   #+#    #+#                 */
/*   Updated: 2022/05/07 12:09:21 by rubennijhui   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *src, int32_t c, size_t n)
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
