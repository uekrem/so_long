/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_animation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekrem <hekrem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:51:59 by hekrem            #+#    #+#             */
/*   Updated: 2023/01/23 15:05:30 by hekrem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_animas_coin(int pos_player, t_mlx *mlx)
{
	if (pos_player == 1)
		mlx->photo->coin = mlx_xpm_file_to_image(mlx->start, C_ONE,
				&mlx->photo->x, &mlx->photo->y);
	else if (pos_player == 2)
		mlx->photo->coin = mlx_xpm_file_to_image(mlx->start, C_TWO,
				&mlx->photo->x, &mlx->photo->y);
	else if (pos_player == 3)
		mlx->photo->coin = mlx_xpm_file_to_image(mlx->start, C_THREE,
				&mlx->photo->x, &mlx->photo->y);
	else if (pos_player == 4)
		mlx->photo->coin = mlx_xpm_file_to_image(mlx->start, C_FOUR,
				&mlx->photo->x, &mlx->photo->y);
}

void	ft_animas_wall(int pos_player, t_mlx *mlx)
{
	if (pos_player == 1)
		mlx->photo->wall = mlx_xpm_file_to_image(mlx->start, W_ONE,
				&mlx->photo->x, &mlx->photo->y);
	else if (pos_player == 2)
		mlx->photo->wall = mlx_xpm_file_to_image(mlx->start, W_TWO,
				&mlx->photo->x, &mlx->photo->y);
	else if (pos_player == 3)
		mlx->photo->wall = mlx_xpm_file_to_image(mlx->start, W_THREE,
				&mlx->photo->x, &mlx->photo->y);
	else if (pos_player == 4)
		mlx->photo->wall = mlx_xpm_file_to_image(mlx->start, W_FOUR,
				&mlx->photo->x, &mlx->photo->y);
}

void	ft_animas_enemy(int pos_player, t_mlx *mlx)
{
	if (pos_player == 1)
		mlx->photo->enemy = mlx_xpm_file_to_image(mlx->start, X_ONE,
				&mlx->photo->x, &mlx->photo->y);
	else if (pos_player == 2)
		mlx->photo->enemy = mlx_xpm_file_to_image(mlx->start, X_TWO,
				&mlx->photo->x, &mlx->photo->y);
	else if (pos_player == 3)
		mlx->photo->enemy = mlx_xpm_file_to_image(mlx->start, X_THREE,
				&mlx->photo->x, &mlx->photo->y);
}

void	ft_animas_exit(t_mlx *mlx)
{
	static int	i;

	if (i == 1)
		mlx->photo->exit = mlx_xpm_file_to_image(mlx->start, E_TWO,
				&mlx->photo->x, &mlx->photo->y);
	else if (i == 2)
		mlx->photo->exit = mlx_xpm_file_to_image(mlx->start, E_THREE,
				&mlx->photo->x, &mlx->photo->y);
	else if (i == 3)
		mlx->photo->exit = mlx_xpm_file_to_image(mlx->start, E_FOUR,
				&mlx->photo->x, &mlx->photo->y);
	i++;
}

int	ft_loop_img(t_mlx *mlx)
{
	static int	pos_player;
	static int	loop;

	if (loop < 1500)
	{
		loop++;
		return (0);
	}
	ft_animas_coin(pos_player, mlx);
	ft_animas_enemy(pos_player, mlx);
	ft_animas_wall(pos_player, mlx);
	ft_img_idx(mlx->mapsize, mlx, mlx->photo);
	if (!mlx->mapsize->coin)
		ft_animas_exit(mlx);
	if (pos_player == 4)
		pos_player = 0;
	pos_player++;
	loop = 0;
	return (0);
}
