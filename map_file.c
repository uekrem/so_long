/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekrem <hekrem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:50:48 by hekrem            #+#    #+#             */
/*   Updated: 2023/01/23 15:13:33 by hekrem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_file_check(void)
{
	t_temp	temp;

	temp.i = open("./textures/ground.xpm", O_RDONLY);
	temp.j = open("./textures/1co.xpm", O_RDONLY);
	temp.k = open("./textures/2co.xpm", O_RDONLY);
	temp.l = open("./textures/3co.xpm", O_RDONLY);
	temp.h = open("./textures/4co.xpm", O_RDONLY);
	while (temp.i < 0 || temp.j < 0 || temp.k < 0 || temp.l < 0 || temp.h < 0)
	{
		ft_printf("File Not Found!");
		close(temp.i);
		close(temp.j);
		close(temp.k);
		close(temp.l);
		close(temp.h);
		exit(0);
	}
	close(temp.i);
	close(temp.j);
	close(temp.k);
	close(temp.l);
	close(temp.h);
}

void	ft_file_check2(void)
{
	t_temp	temp;

	temp.i = open("./textures/exit.xpm", O_RDONLY);
	temp.j = open("./textures/p_l.xpm", O_RDONLY);
	temp.k = open("./textures/p_r.xpm", O_RDONLY);
	temp.l = open("./textures/p_n.xpm", O_RDONLY);
	temp.h = open("./textures/p_b.xpm", O_RDONLY);
	while (temp.i < 0 || temp.j < 0 || temp.k < 0 || temp.l < 0 || temp.h < 0)
	{
		ft_printf("File Not Found!");
		close(temp.i);
		close(temp.j);
		close(temp.k);
		close(temp.l);
		close(temp.h);
		exit(0);
	}
	close(temp.i);
	close(temp.j);
	close(temp.k);
	close(temp.l);
	close(temp.h);
}

void	ft_file_check3(void)
{
	t_temp	temp;

	temp.i = open("./textures/1_w.xpm", O_RDONLY);
	temp.j = open("./textures/2_w.xpm", O_RDONLY);
	temp.k = open("./textures/3_w.xpm", O_RDONLY);
	temp.l = open("./textures/4_w.xpm", O_RDONLY);
	temp.h = open("./textures/1_x.xpm", O_RDONLY);
	while (temp.i < 0 || temp.j < 0 || temp.k < 0 || temp.l < 0 || temp.h < 0)
	{
		ft_printf("File Not Found!");
		close(temp.i);
		close(temp.j);
		close(temp.k);
		close(temp.l);
		close(temp.h);
		exit(0);
	}
	close(temp.i);
	close(temp.j);
	close(temp.k);
	close(temp.l);
	close(temp.h);
}

void	ft_file_check4(void)
{
	t_temp	temp;

	temp.i = open("./textures/2_x.xpm", O_RDONLY);
	temp.j = open("./textures/3_x.xpm", O_RDONLY);
	temp.k = open("./textures/1_e.xpm", O_RDONLY);
	temp.l = open("./textures/2_e.xpm", O_RDONLY);
	temp.h = open("./textures/3_e.xpm", O_RDONLY);
	while (temp.i < 0 || temp.j < 0 || temp.k < 0 || temp.l < 0 || temp.h < 0)
	{
		ft_printf("File Not Found!");
		close(temp.i);
		close(temp.j);
		close(temp.k);
		close(temp.l);
		close(temp.h);
		exit(0);
	}
	close(temp.i);
	close(temp.j);
	close(temp.k);
	close(temp.l);
	close(temp.h);
}

void	ft_file_map(char *str)
{
	int		fd;
	int		i;

	i = ft_strlen(str) - 1;
	fd = open(str, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("File Not Found!");
		close(fd);
		exit(0);
	}
	close(fd);
	if (str[i] != 'r' || str[i - 1] != 'e' || str[i - 2] != 'b'
		|| str[i - 3] != '.')
	{
		ft_printf(".ber File Not Found!");
		exit(0);
	}
	ft_file_check();
	ft_file_check2();
	ft_file_check3();
	ft_file_check4();
}
