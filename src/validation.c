/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakin <anakin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 22:31:26 by anakin            #+#    #+#             */
/*   Updated: 2024/11/03 04:14:40 by anakin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//ok
static void check_square(t_map *map)
{
    if(map->width==map->height)
    {
		map_free(map);
        print_error("Error\nNo input square");
    }
    else
    return;
}

static int	horizontalwall(t_map *map)
{
	int	j;

	j = 0;
	while (j < map->width) 
	{
		if (map->mapinfo[0][j] != '1' || map->mapinfo[map->height - 1][j] != '1')
			return (0); 
		j++;
	}
	return (1);
}

static int	verticalwall(t_map *map)
{
	int	y;

	y = 0;
	while (y < map->height)
	{
		if (!(map->mapinfo[y][0] == '1' && map->mapinfo[y][map->width - 1] == '1'))
			return (0);
		y++;
	}
	return (1);
}

static void	check_walls(t_map *map)
{
	if (!(verticalwall(map)) || !(horizontalwall(map)))
	{
		map_free(map);
		print_error("Error\nMissing the walls");
	}
}

static void	count_checker(t_map *map, int y, int x)
{
	if (map->mapinfo[y][x] != '1' &&
		map->mapinfo[y][x] != '0' &&
		map->mapinfo[y][x] != 'P' &&
		map->mapinfo[y][x] != 'E' &&
		map->mapinfo[y][x] != 'C' &&
		map->mapinfo[y][x] != '\n')
	{
		map_free(map);
		print_error("Error\nCheck your map , input only '1' '0' 'P' 'E' 'C'");
	}
	if (map->mapinfo[y][x]== 'C')
			map->count_c++;
	if (map->mapinfo[y][x] == 'P')
			map->count_p++;
	if (map->mapinfo[y][x] == 'E')
			map->count_e++;
}

static void	check_chracters(t_map *map)
{
	int x;
	int	y;

	y = 0;
	while (y < map->height - 1)
	{
		x = 0;
		while (x <= map->width)
		{
			count_checker(map, y, x);
			x++;
		}
		y++;
	}
	if (!(map->count_p == 1 && map->count_c >= 1
			&& map->count_e == 1))
	{
		map_free(map);
        print_error("Error\nInvalid input");
	}
}

void	validation(t_map *map)
{
    check_square(map);
	check_walls(map);
	check_chracters(map);
    check_clearable(map);
}

// __attribute__((destructor)) static void destructor()
// {
// 	system("leaks -q a.out");
// }

// int	main(int argc, char **argv)
// {
// 	t_map *map;
//     int i;
//     int j;
    
//     i=0;
// 	if (argc != 2)
// 		return (0);
// 	map=map_reading(argv);
// 	validation(map);
// 	printf("mapinfo\n");
// 	printf("item=%d\n",map->count_c);
// 	printf("player=%d\n",map->count_p);
// 	printf("exit=%d\n",map->count_e);
// 	// map_free(map);
// }