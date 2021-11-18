/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rnijhuis <rnijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/09 09:44:54 by rnijhuis      #+#    #+#                 */
/*   Updated: 2021/11/09 09:44:55 by rnijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, void const *src, size_t len)
{
	unsigned char	*ptr_src;
	unsigned char	*ptr_dest;

	ptr_src = (unsigned char *) src;
	ptr_dest = (unsigned char *) dest;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (len > 0)
	{
		*ptr_dest = *ptr_src;
		ptr_dest++;
		ptr_src++;
		len--;
	}
	return (dest);
}
