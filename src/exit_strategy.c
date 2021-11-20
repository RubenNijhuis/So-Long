/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit_strategy.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rnijhuis <rnijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/17 13:49:39 by rnijhuis      #+#    #+#                 */
/*   Updated: 2021/11/20 11:12:52 by rubennijhui   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	exit_strategy(char *message, int status)
{
	printf("%s", message);
	exit(status);
}
