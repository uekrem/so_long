/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekrem <hekrem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:51:29 by hekrem            #+#    #+#             */
/*   Updated: 2023/01/23 15:15:06 by hekrem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_map	mapsize;
	t_mlx	mlx;
	t_photo	photo;

	if (argc != 2)
		exit(0);
	ft_file_map(argv[1]);
	if (ft_read_maps(&mapsize, argv[1]))
	{
		mlx.start = mlx_init();
		mlx.win = mlx_new_window(mlx.start, mapsize.width * 64, mapsize.height
				* 64, "so_long");
		mapsize.point = 0;
		ft_img_addr(&photo, &mlx);
		ft_img_idx(&mapsize, &mlx, &photo);
		mlx.mapsize = &mapsize;
		mlx.photo = &photo;
		mlx_hook(mlx.win, 2, (1L << 0), ft_key_move, &mlx);
		mlx_loop_hook(mlx.start, ft_loop_img, &mlx);
		mlx_hook(mlx.win, 17, 0L, ft_close_game, &mlx);
		mlx_loop(mlx.start);
	}
}
