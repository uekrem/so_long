/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_key_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekrem <hekrem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:50:56 by hekrem            #+#    #+#             */
/*   Updated: 2023/01/23 16:14:38 by hekrem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_plyr_direction(int keycode, t_mlx *mlx)
{
	if (keycode == 13)
		mlx->photo->player = mlx_xpm_file_to_image(mlx->start, P_B,
				&mlx->photo->x, &mlx->photo->y);
	else if (keycode == 0)
		mlx->photo->player = mlx_xpm_file_to_image(mlx->start, P_L,
				&mlx->photo->x, &mlx->photo->y);
	else if (keycode == 1)
		mlx->photo->player = mlx_xpm_file_to_image(mlx->start, P_N,
				&mlx->photo->x, &mlx->photo->y);
	else if (keycode == 2)
		mlx->photo->player = mlx_xpm_file_to_image(mlx->start, P_R,
				&mlx->photo->x, &mlx->photo->y);
}

void	ft_put_score(int point, t_mlx *mlx)
{
	char	*score;

	score = ft_itoa(point);
	mlx_string_put(mlx->start, mlx->win, 20, 20, 0x00FFFFFF, score);
	free(score);
}

void	ft_value_swap(t_mlx *mlx, int x, int y)
{
	mlx->mapsize->map[mlx->mapsize->p_x][mlx->mapsize->p_y] = '0';
	mlx->mapsize->map[x][y] = 'P';
	mlx->mapsize->p_x = x;
	mlx->mapsize->p_y = y;
}

void	ft_move(t_mlx *mlx, int x, int y)
{
	if (!mlx->mapsize->coin && mlx->mapsize->map[x][y] == 'E')
	{
		ft_value_swap(mlx, x, y);
		ft_printf("Walk:%d\nWin!", mlx->mapsize->point += 1);
		ft_close_game(mlx);
	}
	if (mlx->mapsize->map[x][y] == 'X')
	{
		ft_printf("Lose!");
		ft_close_game(mlx);
	}
	else if (mlx->mapsize->map[x][y] != '1' && mlx->mapsize->map[x][y] != 'E')
	{
		if (mlx->mapsize->map[x][y] == 'C')
			mlx->mapsize->coin -= 1;
		ft_value_swap(mlx, x, y);
		ft_printf("Walk:%d\n", mlx->mapsize->point += 1);
	}
}

int	ft_key_move(int keycode, t_mlx *mlx)
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
	else if (keycode == 53)
		ft_close_game(mlx);
	ft_img_idx(mlx->mapsize, mlx, mlx->photo);
	return (keycode);
}
