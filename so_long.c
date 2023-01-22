#include "so_long.h"

void    ft_file_check()
{
    int fd;
    int fd2;
    int fd3;

    fd = open("./textures/exit.xpm", O_RDONLY);
    fd2 = open("./textures/ground.xpm", O_RDONLY);
    fd3 = open("./textures/p_l.xpm", O_RDONLY);
    while (fd < 0 || fd2 < 0 || fd3 < 0)
    {
        printf("File Not Found!");
        close(fd);
        close(fd2);
        close(fd3);
        exit(0);
    }
    close(fd);
    close(fd2);
    close(fd3);
}

void    ft_file_check2()
{
    int fd;
    int fd2;
    int fd3;
    int fd4;
    int fd5;

    fd = open("./textures/1co.xpm", O_RDONLY);
    fd2 = open("./textures/1_w.xpm", O_RDONLY);
    fd3 = open("./textures/p_r.xpm", O_RDONLY);
    fd4 = open("./textures/p_n.xpm", O_RDONLY);
    fd5 = open("./textures/p_b.xpm", O_RDONLY);
    while (fd < 0 || fd2 < 0 || fd3 < 0 || fd4 < 0)
    {
        printf("File Not Found!");
        close(fd);
        close(fd2);
        close(fd3);
        close(fd4);
        close(fd5);
        exit(0);
    }
    close(fd);
    close(fd2);
    close(fd3);
    close(fd4);
    close(fd5);
}

void    ft_file_map(char *str)
{
    int fd;
    int i;

    i = ft_strlen(str) - 1;
    fd = open(str, O_RDONLY);
    if (fd < 0)
    {
        printf("File Not Found!");
        close(fd);
        exit(0);
    }
    close(fd);
    if (str[i] != 'r' || str[i - 1] != 'e' 
        || str[i - 2] != 'b' || str[i - 3] != '.')
    {
        printf(".ber File Not Found!");
        exit(0);
    }
    ft_file_check();
    ft_file_check2();
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
	loop = 0;
    if (pos_player == 1)
    {
        mlx->photo->coin = mlx_xpm_file_to_image(mlx->start, c_one, &mlx->photo->x, &mlx->photo->y);
        mlx->photo->wall = mlx_xpm_file_to_image(mlx->start, w_one, &mlx->photo->x, &mlx->photo->y);
        mlx->photo->enemy = mlx_xpm_file_to_image(mlx->start, x_one, &mlx->photo->x, &mlx->photo->y);
    }
    else if (pos_player == 2)
        {
        mlx->photo->coin = mlx_xpm_file_to_image(mlx->start, c_two, &mlx->photo->x, &mlx->photo->y);
        mlx->photo->wall = mlx_xpm_file_to_image(mlx->start, w_two, &mlx->photo->x, &mlx->photo->y);
        mlx->photo->enemy = mlx_xpm_file_to_image(mlx->start, x_two, &mlx->photo->x, &mlx->photo->y);
    }
    else if (pos_player == 3)
        {
        mlx->photo->coin = mlx_xpm_file_to_image(mlx->start, c_three, &mlx->photo->x, &mlx->photo->y);
        mlx->photo->wall = mlx_xpm_file_to_image(mlx->start, w_three, &mlx->photo->x, &mlx->photo->y);
        mlx->photo->enemy = mlx_xpm_file_to_image(mlx->start, x_three, &mlx->photo->x, &mlx->photo->y);
    }
    else if (pos_player == 4)
    {
        mlx->photo->coin = mlx_xpm_file_to_image(mlx->start, c_four, &mlx->photo->x, &mlx->photo->y);
        mlx->photo->wall = mlx_xpm_file_to_image(mlx->start, w_four, &mlx->photo->x, &mlx->photo->y);
        pos_player = 0;
    }
    ft_img_idx(mlx->mapsize, mlx, mlx->photo);
    pos_player++;
	return (0);
}

int main(int argc, char **argv)
{
    t_map   mapsize;
    t_mlx   mlx;
    t_photo photo;

    if (argc != 2)
        exit(0);
    ft_file_map(argv[1]);
    if (ft_read_maps(&mapsize, argv[1]))
    {
        mlx.start = mlx_init();
        mlx.win = mlx_new_window(mlx.start,mapsize.width * 64, mapsize.heigth * 64, "so_long");
        mapsize.point = 0;
        ft_img_addr(&photo, &mlx);
        ft_img_idx(&mapsize, &mlx, &photo);
        mlx.mapsize = &mapsize;
        mlx.photo = &photo;
        mlx_hook(mlx.win,  2, (1L << 0), ft_key_move, &mlx);
        mlx_loop_hook(mlx.start, ft_loop_img, &mlx);
        mlx_hook(mlx.win,  17, 0L, ft_close_game, &mlx);
        mlx_loop(mlx.start);
    }
}