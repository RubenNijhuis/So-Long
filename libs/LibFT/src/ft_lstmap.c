/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rnijhuis <rnijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/09 09:44:38 by rnijhuis      #+#    #+#                 */
/*   Updated: 2021/11/09 09:44:39 by rnijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*copy_list;
	t_list	*mapped_block;

	copy_list = NULL;
	while (lst != NULL && f != NULL)
	{
		mapped_block = ft_lstnew(f(lst->content));
		if (mapped_block == NULL)
		{
			ft_lstclear(&copy_list, del);
			return (NULL);
		}
		ft_lstadd_back(&copy_list, mapped_block);
		lst = lst->next;
	}
	return (copy_list);
}
