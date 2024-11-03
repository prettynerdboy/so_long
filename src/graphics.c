/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakin <anakin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 05:42:06 by anakin            #+#    #+#             */
/*   Updated: 2024/11/03 22:22:50 by anakin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_images(t_game *game)
{
	int	width;
	int	height;

	game->floor = mlx_xpm_file_to_image(game->mlx_p,
			"./assets/street.xpm", &width, &height);
	game->barrier = mlx_xpm_file_to_image(game->mlx_p,
			"./assets/building.xpm", &width, &height);
	game->player = mlx_xpm_file_to_image(game->mlx_p,
			"./assets/bboy.xpm", &width, &height);
	game->exit = mlx_xpm_file_to_image(game->mlx_p,
			"./assets/bolin.xpm", &width, &height);
	game->collectable = mlx_xpm_file_to_image(game->mlx_p,
			"./assets/mj.xpm", &width, &height);
}

static void	place_player(t_game *game, int axis_y, int axis_x)
{
	mlx_put_image_to_window(game->mlx_p,
		game->win_p, game->player, axis_x * IMGSIZE, axis_y * IMGSIZE);
	game->player_y = axis_y;
	game->player_x = axis_x;
}

void	put_images(t_game *game,t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (map->mapinfo[y][x])
		{
			if (map->mapinfo[y][x] == '1')
				mlx_put_image_to_window(game->mlx_p,game->win_p, game->barrier, x * IMGSIZE, y * IMGSIZE);
			if (map->mapinfo[y][x] == 'C')
			{
            	mlx_put_image_to_window(game->mlx_p,game->win_p, game->floor, x * IMGSIZE, y * IMGSIZE);
	            mlx_put_image_to_window(game->mlx_p,game->win_p, game->collectable, x * IMGSIZE, y * IMGSIZE);
            }
			if (map->mapinfo[y][x] == 'E')
				mlx_put_image_to_window(game->mlx_p,game->win_p, game->exit, x * IMGSIZE, y * IMGSIZE);
			if (map->mapinfo[y][x] == '0')
				mlx_put_image_to_window(game->mlx_p,game->win_p, game->floor, x * IMGSIZE, y * IMGSIZE);
			x++;
		}
		y++;
	}
	place_player(game,game->player_y,game->player_x);
}
