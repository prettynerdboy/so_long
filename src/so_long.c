/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakin <anakin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:16:57 by anakin            #+#    #+#             */
/*   Updated: 2024/11/03 22:50:06 by anakin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// 移動のカウンターをft-printfに直す->(keyhandle.c)
//ftprintfの追加か似たもののコーディング
//ゴールに重なった時の処理、
//バツボタンを押した時に正常に終了させる
//ウィンドウの最小化？


__attribute__((destructor)) static void destructor()
{
	system("leaks -q so_long");
}

int	main(int argc, char **argv)
{
	t_map *map;
	t_game game;
    

	if (argc != 2)
		return (0);
	map=map_reading(argv);
	validation(map);
	ft_memset(&game, 0, sizeof(t_game));
	game.mlx_p = mlx_init();
	// printf("mlxpointer=%p\n",game.mlx_p);
	game.win_p = mlx_new_window(game.mlx_p, (map->width * IMGSIZE),
			(map->height * IMGSIZE), "so_long");
	// printf("window,pointer=%p\n",game.win_p);
	load_images(&game); 
	// printf("window,pointer=%p\n",game.win_p);
	// printf("floor=%p\n",game.floor);
	// printf("barrier=%p\n",game.barrier);
	// printf("player=%p\n",game.player);
	// printf("exit=%p\n",game.exit);
	// printf("collect=%p\n",game.collectable);
	player_init(&game,map);
	put_images(&game,map);
	game.map=map;
	mlx_key_hook(game.win_p, controls_working, &game);
	mlx_hook(game.win_p, 17, 0, (void *)exit, 0);
	mlx_loop(game.mlx_p);
	game_exit(&game);
}
