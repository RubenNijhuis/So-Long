/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_tolower.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rubennijhuis <rubennijhuis@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/12 15:51:04 by rubennijhui   #+#    #+#                 */
/*   Updated: 2022/05/07 12:17:14 by rubennijhui   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int32_t	ft_tolower(int32_t c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}
