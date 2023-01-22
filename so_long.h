
#ifndef SO_LONG_H
# define SO_LONG_H 
# define e_one "./textures/exit.xpm"
# define g_one "./textures/ground.xpm"
# define p_l "./textures/p_l.xpm"
# define p_r "./textures/p_r.xpm"
# define p_n "./textures/p_n.xpm"
# define p_b "./textures/p_b.xpm"
# define c_one "./textures/1co.xpm"
# define c_two "./textures/2co.xpm"
# define c_three "./textures/3co.xpm"
# define c_four "./textures/4co.xpm"
# define w_one "./textures/1_w.xpm"
# define w_two "./textures/2_w.xpm"
# define w_three "./textures/3_w.xpm"
# define w_four "./textures/4_w.xpm"
# define x_one "./textures/1_x.xpm"
# define x_two "./textures/2_x.xpm"
# define x_three "./textures/3_x.xpm"

# include "./mlx/mlx.h"
# include "./get_next_line/get_next_line.h"
# include <stdio.h>

typedef struct s_photo
{
    void    *player;
    void    *coin;
    void    *exit;
    void    *wall;
    void    *ground;
    void    *enemy;
    int     x;
    int     y;
}   t_photo;

typedef struct s_map
{
    char        **map;
    char        **visit;
    int         width;
    int         heigth;
    int         total;
    int         p_x;
    int         p_y;
    int         coin;
    int         point;
}   t_map;

typedef struct s_temp
{
    int i;
    int j;
    int k;
    int l;
    int h;
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
int     ft_close_game(t_mlx *mlx);
char	*ft_itoa(int n);
void    ft_put_score(int point, t_mlx *mlx);
void    ft_img_put(char s, t_mlx *mlx, t_photo *photo, t_temp *temp);
int     ft_loop_img(t_mlx *mlx);
void    ft_file_map(char *str);

#endif