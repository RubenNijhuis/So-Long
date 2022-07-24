/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_2d_arrlen.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rubennijhuis <rubennijhuis@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/24 19:09:04 by rubennijhui   #+#    #+#                 */
/*   Updated: 2022/06/30 20:39:50 by rubennijhui   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stddef.h>

size_t	ft_2d_arrlen(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i] != NULL)
		i++;
	return (i);
}
