/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_decore.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekrem <hekrem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:51:55 by hekrem            #+#    #+#             */
/*   Updated: 2023/01/23 16:04:45 by hekrem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_open_front(t_map *mapsize)
{
	t_temp	temp;

	temp.i = -1;
	while (mapsize->map[++temp.i])
	{
		temp.j = -1;
		while (mapsize->map[temp.i][++temp.j])
			if (mapsize->map[temp.i][temp.j] == 'E')
				return (ft_prison(mapsize, temp.i, temp.j));
	}
	return (0);
}

void	ft_data_maps(char *first_map, t_map *mapsize)
{
	t_temp	temp;

	temp.i = 0;
	temp.j = 0;
	temp.k = -1;
	while (first_map[++temp.k])
	{
		if (first_map[temp.k] != '\n')
		{
			if (temp.j == mapsize->width)
			{
				temp.i++;
				temp.j = 0;
			}
			mapsize->map[temp.i][temp.j++] = first_map[temp.k];
		}
	}
	mapsize->coin = ft_strchr(first_map, 'C');
	free(first_map);
}

char	**ft_create_maps(char *first_map, t_map *mapsize)
{
	int	i;

	i = -1;
	mapsize->map = ft_multi_arr(mapsize);
	mapsize->visit = ft_multi_arr(mapsize);
	if (mapsize->map == NULL || mapsize->visit == NULL)
		return (0);
	ft_data_maps(first_map, mapsize);
	if (ft_open_front(mapsize))
	{
		while (++i < mapsize->height)
			free(mapsize->visit[i]);
		return (mapsize->map);
	}
	while (++i < mapsize->height)
		free(mapsize->map[i]);
	i = -1;
	while (++i < mapsize->height)
		free(mapsize->visit[i]);
	ft_printf("Error\n");
	return (0);
}

int	ft_oth_check(char *first_map, t_map *mapsize)
{
	int	i;

	i = 0;
	while (first_map[i])
	{
		if (first_map[i] != '1' && first_map[i] != '\n')
			return (0);
		if (i <= mapsize->width || i >= ((mapsize->height - 1)
				* mapsize->width))
			i++;
		else
		{
			if (first_map[i + 1] == '\n')
				i += 2;
			else
				i += (mapsize->width - 1);
		}
	}
	if (ft_strchr(first_map, 'P') == 1 && ft_strchr(first_map, 'E') == 1
		&& ft_strchr(first_map, 'C') >= 1 && ft_diff(first_map,
			"01CEPX\n") == 1)
		return (1);
	return (0);
}

char	**ft_read_maps(t_map *mapsize, char *map_file)
{
	char	*first_map;
	int		fd;

	mapsize->width = -1;
	fd = open(map_file, O_RDONLY);
	first_map = get_next_line(fd);
	while (first_map[++mapsize->width])
		if (first_map[mapsize->width] == '\n')
			break ;
	mapsize->height = ft_strchr(first_map, '\n') + 1;
	mapsize->total = mapsize->height * mapsize->width;
	if (ft_oth_check(first_map, mapsize)
		&& mapsize->total == ft_strlen(first_map) - ft_strchr(first_map, '\n'))
		return (ft_create_maps(first_map, mapsize));
	ft_printf("Error\n");
	return (0);
}
