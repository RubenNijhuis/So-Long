/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstnew.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rnijhuis <rnijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/09 09:44:41 by rnijhuis      #+#    #+#                 */
/*   Updated: 2021/11/09 09:44:41 by rnijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	struct s_list	*block;

	block = (t_list *) malloc(sizeof(*block));
	if (block == NULL)
		return (NULL);
	block->content = content;
	block->next = NULL;
	return (block);
}
