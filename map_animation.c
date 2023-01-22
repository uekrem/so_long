#include "so_long.h"

void    ft_animas_coin(int  pos_player, t_mlx *mlx)
{
    if (pos_player == 1)
        mlx->photo->coin = mlx_xpm_file_to_image(mlx->start, c_one, &mlx->photo->x, &mlx->photo->y);
    else if (pos_player == 2)
        mlx->photo->coin = mlx_xpm_file_to_image(mlx->start, c_two, &mlx->photo->x, &mlx->photo->y);
    else if (pos_player == 3)
        mlx->photo->coin = mlx_xpm_file_to_image(mlx->start, c_three, &mlx->photo->x, &mlx->photo->y);
    else if (pos_player == 4)
        mlx->photo->coin = mlx_xpm_file_to_image(mlx->start, c_four, &mlx->photo->x, &mlx->photo->y);
}

void    ft_animas_wall(int  pos_player, t_mlx *mlx)
{
    if (pos_player == 1)
        mlx->photo->wall = mlx_xpm_file_to_image(mlx->start, w_one, &mlx->photo->x, &mlx->photo->y);
    else if (pos_player == 2)
        mlx->photo->wall = mlx_xpm_file_to_image(mlx->start, w_two, &mlx->photo->x, &mlx->photo->y);
    else if (pos_player == 3)
        mlx->photo->wall = mlx_xpm_file_to_image(mlx->start, w_three, &mlx->photo->x, &mlx->photo->y);
    else if (pos_player == 4)
        mlx->photo->wall = mlx_xpm_file_to_image(mlx->start, w_four, &mlx->photo->x, &mlx->photo->y);
}

void    ft_animas_enemy(int  pos_player, t_mlx *mlx)
{
    if (pos_player == 1)
        mlx->photo->enemy = mlx_xpm_file_to_image(mlx->start, x_one, &mlx->photo->x, &mlx->photo->y);
    else if (pos_player == 2)
        mlx->photo->enemy = mlx_xpm_file_to_image(mlx->start, x_two, &mlx->photo->x, &mlx->photo->y);
    else if (pos_player == 3)
        mlx->photo->enemy = mlx_xpm_file_to_image(mlx->start, x_three, &mlx->photo->x, &mlx->photo->y);
}

int ft_loop_img(t_mlx *mlx)
{
    static int  pos_player;
    static int  loop;

    if (loop < 1500)
	{
		loop++;
		return (0);
	}
    ft_animas_coin(pos_player, mlx);
    ft_animas_enemy(pos_player, mlx);
    ft_animas_wall(pos_player, mlx);
    ft_img_idx(mlx->mapsize, mlx, mlx->photo);
    if (pos_player == 4)
        pos_player = 0;
    pos_player++;
    loop = 0;
	return (0);
}