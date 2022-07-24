/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_nbrlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rubennijhuis <rubennijhuis@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/12 15:46:45 by rubennijhui   #+#    #+#                 */
/*   Updated: 2022/05/07 12:10:32 by rubennijhui   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

uint32_t	ft_nbrlen(int64_t nb)
{
	uint32_t	len;

	len = 0;
	if (nb < 0)
		len++;
	if (nb > LONG_MAX || nb < LONG_MIN)
		return (nb);
	while (nb)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}
