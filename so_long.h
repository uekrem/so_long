
#ifndef SO_LONG_H
# define SO_LONG_H 
# define exit_path "./textures/exit.xpm"
# define ground_path "./textures/ground.xpm"
# define p_left_path "./textures/player_left.xpm"
# define enemy_path "./textures/enemy.xpm"
# define coin_path "./textures/coin.xpm"
# define wall_path "./textures/wall.xpm"
# define p_right_path "./textures/player_right.xpm"
# define p_normal_path "./textures/player_normal.xpm"
# define p_behind_path "./textures/player_behind.xpm"

# include "./mlx_linux/mlx.h"
# include "./get_next_line/get_next_line.h"
# include <stdio.h>

typedef struct s_photo
{
    void    *player;
    void    *coin;
    void    *enemy;
    void    *exit;
    void    *wall;
    void    *ground;
    int     x;
    int     y;
}   t_photo;

typedef struct s_map
{
    char **map;
    char **visit;
    int width;
    int heigth;
    int total;
    int p_x;
    int p_y;
    int coin;
}   t_map;

typedef struct s_temp
{
    int i;
    int j;
    int k;
    int l;
}   t_temp;

typedef struct s_mlx
{
    void    *start;
    void    *win;
    t_map   *mapsize;
    t_photo *photo;
}t_mlx;


int     ft_multi_strlen(char **s);
void    ft_assign_image();
char    **ft_read_maps(t_map *mapsize, char *map_file);
char    **ft_multi_arr(t_map *map);
int     ft_strchr(char *s, char c);
int	    ft_strlen(const char *s);
void	ft_memset(char	*b, char c, int len);
int     ft_diff(char *s1, char *s2);
int     ft_prison(t_map *mapsize, int exit_x, int exit_y);
int     ft_check_prison(t_map *mapsize);
void    ft_img_addr(t_photo *photo, t_mlx *mlx);
void    ft_img_idx(t_map *mapsize, t_mlx *mlx, t_photo *photo);
int     ft_key_move(int keycode, t_mlx *mlx);
void    ft_close_game(t_mlx *mlx);
char	*ft_itoa(int n);

#endif