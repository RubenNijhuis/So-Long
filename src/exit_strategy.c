/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit_strategy.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rnijhuis <rnijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/17 13:49:39 by rnijhuis      #+#    #+#                 */
/*   Updated: 2022/07/24 14:30:27 by rubennijhui   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

/*
 * Closes the game and free's all data
*/
void	exit_strategy(char *message, int status)
{
	printf("%s", message);
	exit(status);
}
