/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_toupper.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rubennijhuis <rubennijhuis@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/12 15:51:05 by rubennijhui   #+#    #+#                 */
/*   Updated: 2022/05/07 12:13:49 by rubennijhui   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int32_t	ft_toupper(int32_t c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}
