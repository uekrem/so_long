#include "so_long.h"

int ft_return_exit(t_map *mapsize, int exit_x, int exit_y)
{
    mapsize->map[exit_x][exit_y] = 'F';
    if (!ft_check_prison(mapsize))
        return (0);
    mapsize->map[exit_x][exit_y] = 'E';
    return (1);
}

int ft_check_prison2(t_map *mapsize, int x, int y)
{
    if (mapsize->map[x][y] != '1' && mapsize->visit[x][y] != '1')
    {
        mapsize->visit[x][y] = '1';
        if (mapsize->map[x][y] == 'F')
            return (1);
        if (ft_check_prison2(mapsize, x, y + 1))
            return (1);
        if (ft_check_prison2(mapsize, x + 1, y))
            return (1);
        if (ft_check_prison2(mapsize, x, y - 1))
            return (1);
        if (ft_check_prison2(mapsize, x - 1, y))
            return (1);
    }
    return (0);
}

int ft_check_prison(t_map *mapsize)
{
    t_temp temp;

    temp.i = -1;
    temp.k = -1;
    while (mapsize->visit[++temp.k])
        ft_memset(mapsize->visit[temp.k], '0', ft_strlen(mapsize->map[0]));
    while (mapsize->map[++temp.i])
    {
        temp.j = -1;
        while (mapsize->map[temp.i][++temp.j])
        {
            if (mapsize->map[temp.i][temp.j] == 'P')
            {
                mapsize->p_x = temp.i;
                mapsize->p_y = temp.j;
                if (ft_check_prison2(mapsize, temp.i, temp.j))
                    return (1);
            }
        }
    }
    return (0);
}

int ft_prison(t_map *mapsize, int exit_x, int exit_y)
{
    t_temp temp;
    static int     count;

    mapsize->map[exit_x][exit_y] = '1';
    temp.i = -1;
    while (mapsize->map[++temp.i])
    {
        temp.j = -1;
        while (mapsize->map[temp.i][++temp.j])
        {
            if (mapsize->map[temp.i][temp.j] == 'C')
            {
                mapsize->map[temp.i][temp.j] = 'F';
                count += ft_check_prison(mapsize);
                mapsize->map[temp.i][temp.j] = 'C';
            }
        }
    }
    count += ft_return_exit(mapsize, exit_x, exit_y);
    if (count == (mapsize->coin + 1))
        return (1);
    return (0);
}
