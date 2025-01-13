#ifndef SO_LONG_H
#define SO_LONG_H

#include "minilibx-linux/mlx.h"
#include <X11/keysym.h>
#include <X11/X.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include "libft/libft.h"
#include "gnl/get_next_line.h"


typedef struct s_data
{
    void    *mlx;
    void    *win;
    char    *path;
    int     width;
    int     height;
    char    **map;
    int     collectable;
    int     exit;
    int     player;
    int     p_x;
    int     p_y;
    int     p;
    int     c;
    int     e;
}           t_data;


void    check_walls(t_data *walls);
void    save_map(int fd, t_data *w);
int p_position(t_data *w);
int charcters(t_data *wl);
void    check_map(t_data *dt);
void    ft_error(t_data *game, char *msj, int flag);
void    check_path(t_data *g, int argc, char *argv[]);
int ft_iselement(char c);
void    check2_map(t_data *data);
void flood_fill(char **str, t_data *wl, int x, int y);
char    **copy_map(char **arr, int size);
void    ft_destroy(t_data *d);


#endif