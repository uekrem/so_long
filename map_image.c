#include "so_long.h"

int    ft_close_game(t_mlx *mlx)
{
    int i;

    i = -1;
    mlx_destroy_image(mlx->start, mlx->photo->coin);
    mlx_destroy_image(mlx->start, mlx->photo->exit);
    mlx_destroy_image(mlx->start, mlx->photo->ground);
    mlx_destroy_image(mlx->start, mlx->photo->player);
    mlx_destroy_image(mlx->start, mlx->photo->wall);
    mlx_destroy_image(mlx->start, mlx->photo->enemy);
    while (mlx->mapsize->map[++i])
        free(mlx->mapsize->map[i]);
    //free(mlx->mapsize->map[i]);
    free(mlx->mapsize->map);
    mlx_destroy_window(mlx->start, mlx->win);
    system("leaks so_long");
    exit(0);
}

void    ft_img_put(char s, t_mlx *mlx, t_photo *photo, t_temp *temp)
{
    if (s == 'C')
        mlx_put_image_to_window(mlx->start, mlx->win, photo->coin, temp->l, temp->k);
    else if (s == 'E')
        mlx_put_image_to_window(mlx->start, mlx->win, photo->exit, temp->l, temp->k);
    else if (s == '0')
        mlx_put_image_to_window(mlx->start, mlx->win, photo->ground, temp->l, temp->k);
    else if (s == '1')
        mlx_put_image_to_window(mlx->start, mlx->win, photo->wall, temp->l, temp->k);
    else if (s == 'P')
        mlx_put_image_to_window(mlx->start, mlx->win, photo->player, temp->l, temp->k);
    else if (s == 'X')
        mlx_put_image_to_window(mlx->start, mlx->win, photo->enemy, temp->l, temp->k);
}

void    ft_img_idx(t_map *mapsize, t_mlx *mlx, t_photo *photo)
{
    t_temp  temp;

    temp.i = -1;
    temp.k = 0;
    while (mapsize->map[++temp.i])
    {
        temp.j = -1;
        temp.l = 0;
        while (mapsize->map[temp.i][++temp.j])
        {
            ft_img_put(mapsize->map[temp.i][temp.j], mlx, photo, &temp);
            temp.l += 64;
        }
        temp.k += 64;
    }
    ft_put_score(mlx->mapsize->point, mlx);
}

void    ft_img_addr(t_photo *photo, t_mlx *mlx)
{
    photo->exit = mlx_xpm_file_to_image(mlx->start, e_one, &photo->x, &photo->y);
    photo->player = mlx_xpm_file_to_image(mlx->start, p_n, &photo->x, &photo->y);
    photo->coin = mlx_xpm_file_to_image(mlx->start, c_one, &photo->x, &photo->y);
    photo->ground = mlx_xpm_file_to_image(mlx->start, g_one, &photo->x, &photo->y);
    photo->wall = mlx_xpm_file_to_image(mlx->start, w_one, &photo->x, &photo->y);
    photo->enemy = mlx_xpm_file_to_image(mlx->start, x_one, &photo->x, &photo->y);
}