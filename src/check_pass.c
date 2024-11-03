/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pass.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakin <anakin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 02:52:44 by anakin            #+#    #+#             */
/*   Updated: 2024/11/03 08:20:24 by anakin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_map *mapcpy(const t_map *src)
{
    t_map *copy ;
    int i;
    
    copy = (t_map *)malloc(sizeof(t_map));
    if (!copy)
        return NULL;
    copy->width = src->width;
    copy->height = src->height;
    copy->count_c = src->count_c;
    copy->mapinfo = (char **)malloc((src->height +1) * sizeof(char *));
    if (!copy->mapinfo)
    {
        free(copy);
        return NULL;
    }
    i = 0;
    while (i < src->height)
    {
        copy->mapinfo[i]=ft_strdup(src->mapinfo[i]);
        if(!copy->mapinfo[i])
            return (map_free(copy), NULL);
        i++;
    }
    copy->mapinfo[i] = NULL;
    return copy;
}

static t_player *init_player(const t_map *map)
{
    t_player *player;
    int x;
    int y;
    player = (t_player *)malloc(sizeof(t_player));
    if (!player)
         return NULL;
    player->item_count = 0;
    player->exit_count = 0;
    y = 0;
    while (y < map->height)
    {
        x = 0;
        while (x < map->width)
        {
            if (map->mapinfo[y][x] == 'P')
            {
                player->x = x;
                player->y = y;
                break;
            }
            x++;
        }
        y++;
    }
    return (player);
}

static void dfs_search(t_map *map, t_player *player, int x, int y)
{
    if (x < 0 || x >= map->width || y < 0 || y >= map->height 
    || map->mapinfo[y][x] == '1')
        return;
    if (map->mapinfo[y][x] == 'E')
        player->exit_count++;
    if (map->mapinfo[y][x] == 'C')
        player->item_count++;
        
    map->mapinfo[y][x] = '1';
    
    dfs_search(map, player, x + 1, y);
    dfs_search(map, player, x - 1, y); 
    dfs_search(map, player, x, y + 1); 
    dfs_search(map, player, x, y - 1); 
}

void check_clearable(t_map *map)
{
    t_map *copy;
    t_player *tester;
    copy=mapcpy(map);
    if(!copy)
    {
        map_free(map);
        print_error("failed, copy map");
    }
    tester=init_player(map);
    if(!tester)
    {
        map_free(map);
        print_error("failed check");
    }
    dfs_search(copy, tester,tester->x,tester->y);
    map_free(copy);
    if (tester->exit_count == map->count_e 
    && tester->item_count == map->count_c)
        free(tester);
    else
    {
        free(tester);
        print_error("Error\nThe map is not clearable");
    }
}

// __attribute__((destructor)) static void destructor()
// {
// 	system("leaks -q a.out");
// }

// //test copy
// void check_clearable(t_map *map)
// {
//     t_map *copy;
//     copy=mapcpy(map);
    
//     int i;
//     i = 0;
//     printf("src\n");
//     while(map->mapinfo[i])
//     {
//         printf("line=%s",map->mapinfo[i]);
//          i++;
//     }
//     map_free(map);
//     i = 0;
//     printf("\ncopy\n");
//     while(copy->mapinfo[i])
//     {
//         printf("line=%s",copy->mapinfo[i]);
//         i++;
//     }
//     map_free(copy);
// }

//tester clearable
// void check_clearable(t_map *map)
// {
//     t_map *copy;
//     t_player *tester;
//     copy=mapcpy(map);
//     if(!copy)
//     {
//         map_free(map);
//         print_error("failed, copy map");
//     }
//     tester=init_player(map);
//     if(!tester)
//     {
//         map_free(map);
//         print_error("failed check");
//     }
//     printf("player,start_x=%d,start_y=%d,item=%d ,exit=%d\n",tester->x,tester->y,tester->item_count,tester->exit_count);
//     // dfs_search(copy, tester);
//     dfs_search(copy, tester,tester->x,tester->y);
//     printf("after,dfs,start_x=%d,start_y=%d,item=%d ,exit=%d\n",tester->x,tester->y,tester->item_count,tester->exit_count);
//     if (tester->exit_count == map->count_e 
//     && tester->item_count == map->count_c)
//         printf("The map is clearable!\n");
//     else
//         printf("The map is not clearable!\n");

//     // メモリの解放
//     free(tester);
//     map_free(copy);
// }
