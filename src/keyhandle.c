/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhandle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakin <anakin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 22:44:06 by anakin            #+#    #+#             */
/*   Updated: 2024/11/03 22:34:48 by anakin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// static int	move_ornot(t_game *game, int next_x, int next_y)
// {
//     if (game->map->mapinfo[next_y][next_x] == '1')
// 		return (0);
// 	if (game->map->mapinfo[next_y][next_x] == 'E')
// 	{
// 		if (game->map->count_c == 0)
//         {
//             printf("\nYou are BOLLING!\n");
//             game_exit(game);
//         }
//         game->player_x = next_x;
//         game->player_y = next_y;
//         game->countmv++;
// 	}
// 	if (game->map->mapinfo[next_y][next_x] == '0')
// 	{
// 		game->player_x = next_x;
// 		game->player_y = next_y;
// 		game->countmv++;
// 	}
// 	if (game->map->mapinfo[next_y][next_x] == 'C')
// 	{
// 		game->map->mapinfo[next_y][next_x] = '0';
// 		game->player_x = next_x;
// 		game->player_y = next_y;
//         game->map->count_c --;
// 		game->countmv++;
// 	}
// 	return (1);
// }

static int	move_ornot(t_game *game, int next_x, int next_y)
{
    if (game->map->mapinfo[next_y][next_x] == '1')
		return (0);
	else
	{
		if (game->map->mapinfo[next_y][next_x] == 'E')
		{
			if (game->map->count_c == 0)
        	{
            	printf("\nYou are BOLLING!\n");
            	game_exit(game);
        	}
		}
		if (game->map->mapinfo[next_y][next_x] == 'C')
		{
			game->map->mapinfo[next_y][next_x] = '0';
        	game->map->count_c --;
		}
		game->player_x = next_x;
    	game->player_y = next_y;
    	game->countmv++;
		return (1);
	}
}

static int	keyboard_w_s(t_game *game, int movement)
{
	int	next_y;
	int	move_flag;

	move_flag=0;
	if (movement == 13)//上
	{
		next_y=game->player_y - 1;
		move_flag = move_ornot(game, game->player_x, next_y);
        if (!move_flag)
			return (move_flag);
	}
	else if (movement == 1)//下
	{
		next_y=game->player_y + 1;
        move_flag = move_ornot(game, game->player_x, next_y);
        if (!move_flag)
			return (move_flag);
	}
	return (move_flag);
}

static int	keyboard_a_d(t_game *game, int movement)
{
	int	next_x;
	int	move_flag;

	move_flag=0;
	if (movement == 0)//左
	{
		next_x=game->player_x - 1;
		move_flag = move_ornot(game, next_x, game->player_y);
        if (!move_flag)
			return (move_flag);
	}
	else if (movement == 2)//右
	{
        next_x=game->player_x + 1;
		move_flag = move_ornot(game, next_x, game->player_y);
        if (!move_flag)
			return (move_flag);
	}
	return (move_flag);
}

int	controls_working(int command, t_game *game)
{
	int	works;

	if (command == 53)
		game_exit(game);
	if (command == 13)
		works = keyboard_w_s(game, command);
	if (command == 1)
		works = keyboard_w_s(game, command);
	if (command == 0)
		works = keyboard_a_d(game, command);
	if (command == 2)
		works = keyboard_a_d(game, command);
	if (works)
	{
		printf("Steps Taken: %i\n", game->countmv);
		put_images(game,game->map);
	}
	return (1);
}
