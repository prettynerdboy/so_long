/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakin <anakin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 01:45:40 by anakin            #+#    #+#             */
/*   Updated: 2024/11/03 21:32:29 by anakin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#include <stdio.h>

void	player_init(t_game *game,t_map *map)
{
    int y;

	y=0;
    while (y < map->height)
    {
        int x = 0;
        while (x < map->width)
        {
            if (map->mapinfo[y][x] == 'P')
            {
                game->player_x = x;
                game->player_y = y;
				map->mapinfo[y][x]='0';
                return; 
            }
            x++;
        }
        y++;
    }
}

void	*ft_memset(void *b, int c, size_t length)
{
	unsigned char	*p;

	p = (unsigned char *)b;
	while (length--)
		*p++ = (unsigned char)c;
	return (b);
}

static void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, sizeof(c));
}

static void	ft_putstr_fd(const char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(fd, &str[i++], 1);
	}
}

static void	ft_putendl_fd(char *str, int fd)
{
	if (str)
	{
		ft_putstr_fd(str, fd);
		ft_putchar_fd('\n', fd);
	}
}

void print_error(char *msg)
{	
    const char *red = "\033[31m"; 
    const char *reset = "\033[0m"; 
    write(2, red, 5);                
    ft_putendl_fd(msg, 1) ;      
    write(2, reset, 4);
	exit(0);
}