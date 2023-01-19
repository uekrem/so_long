#include "so_long.h"

void    ft_plyr_direction(int keycode, t_mlx *mlx)
{
    if (keycode == 13)
        mlx->photo->player = mlx_xpm_file_to_image(mlx->start, p_behind_path, &mlx->photo->x, &mlx->photo->y);
    else if (keycode == 0)
        mlx->photo->player = mlx_xpm_file_to_image(mlx->start, p_left_path, &mlx->photo->x, &mlx->photo->y);
    else if (keycode == 1)
        mlx->photo->player = mlx_xpm_file_to_image(mlx->start, p_normal_path, &mlx->photo->x, &mlx->photo->y);
    else if (keycode == 2)
        mlx->photo->player = mlx_xpm_file_to_image(mlx->start, p_right_path, &mlx->photo->x, &mlx->photo->y);
}

void    ft_put_score(char *point, t_mlx *mlx)   //score düzellltltlttl 
{
    mlx_string_put(mlx->start, mlx->win, 100, 100, 000000, point);
    free(point);
}

void    ft_move(t_mlx *mlx, int x, int y)
{
    static int count;                           
    static int  point;

    if (count == mlx->mapsize->coin && mlx->mapsize->map[x][y] == 'E')
    {
        mlx->mapsize->map[mlx->mapsize->p_x][mlx->mapsize->p_y] = '0';
        mlx->mapsize->map[x][y] = 'P';
        mlx->mapsize->p_x = x;
        mlx->mapsize->p_y = y;
        printf("Win! Puan Durumun:%d", ++point);        //çıkış yaparken leak
        ft_put_score(ft_itoa(point), mlx);
        exit(1);
    }
    if (mlx->mapsize->map[x][y] != '1' && mlx->mapsize->map[x][y] != 'E')
    {
        if (mlx->mapsize->map[x][y] == 'C')
        {
            printf("Puan Durumu:%d\n", ++point);
            count++;
        }
        mlx->mapsize->map[mlx->mapsize->p_x][mlx->mapsize->p_y] = '0';
        mlx->mapsize->map[x][y] = 'P';
        mlx->mapsize->p_x = x;
        mlx->mapsize->p_y = y;
        printf("Puan Durumu:%d\n", ++point);
        ft_put_score(ft_itoa(point), mlx);
    }
}

int    ft_key_move(int keycode, t_mlx *mlx)
{
    mlx_clear_window(mlx->start, mlx->win);
    ft_plyr_direction(keycode, mlx);
    if (keycode == 13)
        ft_move(mlx, mlx->mapsize->p_x - 1, mlx->mapsize->p_y);
    else if (keycode == 0)
        ft_move(mlx, mlx->mapsize->p_x, mlx->mapsize->p_y - 1);
    else if (keycode == 1)
        ft_move(mlx, mlx->mapsize->p_x + 1, mlx->mapsize->p_y);
    else if (keycode == 2)
        ft_move(mlx, mlx->mapsize->p_x, mlx->mapsize->p_y + 1);
    else if (keycode == 53)             //çıkış yaparken leak
    {

        exit(1);
    }
    ft_img_idx(mlx->mapsize, mlx, mlx->photo);
    return (keycode);
}