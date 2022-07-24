/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_repl_chr.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rnijhuis <rnijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/27 18:25:21 by rnijhuis      #+#    #+#                 */
/*   Updated: 2022/06/27 18:28:23 by rnijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_repl_chr(char *line, char cur, char new)
{
	uint32_t	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == cur)
			line[i] = new;
		i++;
	}
}
