/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit_strategy.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rnijhuis <rnijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/17 13:49:39 by rnijhuis      #+#    #+#                 */
/*   Updated: 2021/11/22 13:15:21 by rnijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

/*
 * Free map
 */
// void	free_map(t_game_data *gd)

/*
 * Free images
 */
// void	free_images(t_game_data *gd)

/*
 * Free enemies
 */
// void	free_enemies(t_game_data *gd)

/*
 * Closes the game and free's all data
*/
void	exit_strategy(char *message, int status)
{
	printf("%s", message);
	exit(status);
}
