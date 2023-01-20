#include "so_long.h"

void    ft_file_check()
{
    int fd;
    int fd2;
    int fd3;

    fd = open("./textures/exit.xpm", O_RDONLY);
    fd2 = open("./textures/ground.xpm", O_RDONLY);
    fd3 = open("./textures/player_left.xpm", O_RDONLY);
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

    fd = open("./textures/coin.xpm", O_RDONLY);
    fd2 = open("./textures/wall.xpm", O_RDONLY);
    fd3 = open("./textures/player_right.xpm", O_RDONLY);
    fd4 = open("./textures/player_normal.xpm", O_RDONLY);
    fd5 = open("./textures/player_behind.xpm", O_RDONLY);
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
        ft_img_addr(&photo, &mlx);
        ft_img_idx(&mapsize, &mlx, &photo);
        mlx.mapsize = &mapsize;
        mlx.photo = &photo;
        mlx_hook(mlx.win,  2, (1L << 0), ft_key_move, &mlx);
        mlx_hook(mlx.win,  17, 0L, ft_close_game, &mlx);
        mlx_loop(mlx.start);
    }
}