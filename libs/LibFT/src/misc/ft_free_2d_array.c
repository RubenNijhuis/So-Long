/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_free_2d_array.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: rubennijhuis <rubennijhuis@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/24 18:22:39 by rubennijhui   #+#    #+#                 */
/*   Updated: 2022/05/07 12:10:26 by rubennijhui   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_free_2d_array(char ***arr, uint32_t item_amount)
{
	while (item_amount > 0)
	{
		--item_amount;
		free((*arr)[item_amount]);
	}
	free((*arr));
	(*arr) = NULL;
}
