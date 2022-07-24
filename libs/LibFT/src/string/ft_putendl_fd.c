/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putendl_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rubennijhuis <rubennijhuis@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/12 15:50:37 by rubennijhui   #+#    #+#                 */
/*   Updated: 2022/05/07 12:11:01 by rubennijhui   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, uint32_t fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}
