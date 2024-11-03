/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakin <anakin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 23:01:34 by anakin            #+#    #+#             */
/*   Updated: 2024/11/03 03:52:37 by anakin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	width_of_map(char *string)
{
	int	width;

	width = 0;
	while (string[width] != '\0')
		width++;
	if (string[width - 1] == '\n')
		width--;
	return (width);
}

static int add_line(t_map *map, char *line)
{
    char **tmp;
    int i;

    if (!line)
        return (0);
    map->height++;
    tmp = (char **)malloc(sizeof(char *) * (map->height + 1));
    if (!tmp)
    {
        free(line);
        return (0);
    }
    tmp[map->height] = NULL;
    i = 0;
    while (i < map->height - 1)
    {
        tmp[i] = ft_strdup(map->mapinfo[i]); 
        i++;
    }
    tmp[i] = line; 
    if (map->mapinfo)
        wp_free(&(map->mapinfo));
    map->mapinfo = tmp;
    return (1);
}

t_map *map_reading(char **argv)
{
    t_map *map;
    int fd;
    char *readmap;

    map = (t_map *)malloc(sizeof(t_map));
    if (!map)
        return (NULL);
    ft_memset(map, 0, sizeof(t_map));
    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
        return (NULL);
    readmap = get_next_line(fd);
    while (readmap != NULL)
    {
        if (!add_line(map, readmap))
        {
            free(readmap);
            close(fd);
            return (0);
        }
        readmap = get_next_line(fd); 
    }
    close(fd);
    map->width = width_of_map(map->mapinfo[0]);
    return (map);
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
//     if (!map)
//         return (1);
//     printf("width=%d\n",map->width);
//     printf("height=%d\n",map->height);
//    while(map->mapinfo[i])
//    {
//         printf("line=%s",map->mapinfo[i]);
//         i++;
//    }
//    wp_free(&(map->mapinfo));
//    free(map);
// }