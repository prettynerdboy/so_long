/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakin <anakin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 22:51:17 by anakin            #+#    #+#             */
/*   Updated: 2024/11/03 21:29:45 by anakin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include "../minilibx/mlx.h"
# include "./get_next_line.h"

#define IMGSIZE 100

typedef struct s_player
{
    int x;
    int y;
    int item_count;
    int exit_count;
}t_player;

typedef struct s_map
{
    char **mapinfo;
    int width;
    int height;
    int count_p;
    int count_c;
    int count_e;
} t_map;


typedef struct s_game
{
    t_map *map;
    int player_x;                // プレイヤーのX座標
    int player_y;              // プレイヤーのY座標
    char position;
    int countmv;               // 移動回数
    
    // graphics
    void *floor;               // 床画像
    void *barrier;             // 壁画像
    void *player;              // プレイヤー画像
    void *exit;                // 出口画像
    void *collectable;         // アイテム画像
    
    //mlx
    void *mlx_p;          // MiniLibXの初期化ポインタ
    void *win_p;          // ウィンドウポインタ
} t_game;

//readmap
t_map *map_reading(char **argv);

//validation
void	validation(t_map *map);
void    check_clearable(t_map *map);
// t_player *init_player(const t_map *map);

//graphics
void	load_images(t_game *game);
void	put_images(t_game *game,t_map *map);

//keyhandle
int	controls_working(int command, t_game *game);

//error 
// int	exit_point(t_complete *game);
void	game_exit(t_game *game);
void    print_error(char *msg);
void    wp_free(char ***str);
void     map_free(t_map *map);

//utility
void	player_init(t_game *game,t_map *map);
void	*ft_memset(void *b, int c, size_t length);

#endif
