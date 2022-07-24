/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isalnum.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rubennijhuis <rubennijhuis@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/12 15:49:57 by rubennijhui   #+#    #+#                 */
/*   Updated: 2022/05/07 12:08:17 by rubennijhui   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int32_t	ft_isalnum(int32_t c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
