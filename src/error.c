/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakin <anakin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 22:33:52 by anakin            #+#    #+#             */
/*   Updated: 2024/11/03 23:30:30 by anakin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void wp_free(char ***str)
{
    int i;

    if (!str || !*str)
        return;
    i = 0;
    while ((*str)[i])
    {
        free((*str)[i]);
        (*str)[i] = NULL;
        i++;
    }
    free(*str);
    *str = NULL;
}

void map_free(t_map *map)
{
	wp_free(&(map->mapinfo));
	free(map);
}
void	game_exit(t_game *game)
{               
	if(game->collectable)
		mlx_destroy_image(game->mlx_p, game->collectable);
	if(game->exit)
		mlx_destroy_image(game->mlx_p, game->exit);
	if(game->player)
		mlx_destroy_image(game->mlx_p, game->player);
	if(game->barrier)
		mlx_destroy_image(game->mlx_p, game->barrier);
	if(game->floor)
		mlx_destroy_image(game->mlx_p, game->floor);
	if (game->win_p)
		mlx_destroy_window(game->mlx_p, game->win_p);
	map_free(game->map);
	exit(0);
}