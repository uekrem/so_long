/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekrem <hekrem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:51:45 by hekrem            #+#    #+#             */
/*   Updated: 2023/01/23 15:01:52 by hekrem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define G_ONE "./textures/ground.xpm"
# define P_L "./textures/p_l.xpm"
# define P_R "./textures/p_r.xpm"
# define P_N "./textures/p_n.xpm"
# define P_B "./textures/p_b.xpm"
# define C_ONE "./textures/1co.xpm"
# define C_TWO "./textures/2co.xpm"
# define C_THREE "./textures/3co.xpm"
# define C_FOUR "./textures/4co.xpm"
# define W_ONE "./textures/1_w.xpm"
# define W_TWO "./textures/2_w.xpm"
# define W_THREE "./textures/3_w.xpm"
# define W_FOUR "./textures/4_w.xpm"
# define X_ONE "./textures/1_x.xpm"
# define X_TWO "./textures/2_x.xpm"
# define X_THREE "./textures/3_x.xpm"
# define E_ONE "./textures/exit.xpm"
# define E_TWO "./textures/1_e.xpm"
# define E_THREE "./textures/2_e.xpm"
# define E_FOUR "./textures/3_e.xpm"

# include "./ft_printf/ft_printf.h"
# include "./get_next_line/get_next_line.h"
# include "./mlx/mlx.h"

typedef struct s_photo
{
	void	*player;
	void	*coin;
	void	*exit;
	void	*wall;
	void	*ground;
	void	*enemy;
	int		x;
	int		y;
}			t_photo;

typedef struct s_map
{
	char	**map;
	char	**visit;
	int		width;
	int		height;
	int		total;
	int		p_x;
	int		p_y;
	int		coin;
	int		point;
}			t_map;

typedef struct s_temp
{
	int		i;
	int		j;
	int		k;
	int		l;
	int		h;
}			t_temp;

typedef struct s_mlx
{
	void	*start;
	void	*win;
	t_map	*mapsize;
	t_photo	*photo;
}			t_mlx;

int			ft_multi_strlen(char **s);
void		ft_assign_image(void);
char		**ft_read_maps(t_map *mapsize, char *map_file);
char		**ft_multi_arr(t_map *map);
int			ft_strchr(char *s, char c);
int			ft_strlen(const char *s);
void		ft_memset(char *b, char c, int len);
int			ft_diff(char *s1, char *s2);
int			ft_prison(t_map *mapsize, int exit_x, int exit_y);
int			ft_check_prison(t_map *mapsize);
void		ft_img_addr(t_photo *photo, t_mlx *mlx);
void		ft_img_idx(t_map *mapsize, t_mlx *mlx, t_photo *photo);
int			ft_key_move(int keycode, t_mlx *mlx);
int			ft_close_game(t_mlx *mlx);
char		*ft_itoa(int n);
void		ft_put_score(int point, t_mlx *mlx);
void		ft_img_put(char s, t_mlx *mlx, t_photo *photo, t_temp *temp);
int			ft_loop_img(t_mlx *mlx);
void		ft_file_map(char *str);

#endif