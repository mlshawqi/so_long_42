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

#define ESCAPE 65307
#define KEY_LEFT 65361
#define KEY_RIGHT 65363
#define KEY_UP 65362
#define KEY_DOWN 65364
#define KEYPress 2
#define KEYPRESSMask 1L<<0

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
    void    *i_background;
    void    *i_wall;
    void    *i_exit;
    void    *i_player;
    void    *i_collectable;
    void    *i_enemy;
    void    *frame_player[2];
    void    *frame_collectable[2];
    void    *frame_enemy[2];
    int     current_frame;
    int     movement;
    char    *n_move;
    int     collecting;
}           t_data;


void    check_walls(t_data *walls);
void    save_map(int fd, t_data *w);
int     p_position(t_data *w);
int     charcters(t_data *wl);
void    check_map(t_data *dt);
void    ft_error(t_data *game, char *msj, int flag);
void    check_path(t_data *g, int argc, char *argv[]);
int     ft_iselement(char c);
void    check2_map(t_data *data);
void    flood_fill(char **str, t_data *wl, int x, int y);
char    **copy_map(char **arr, int size);
void    ft_destroy(t_data *d);
void	put_images(t_data *d);
void    load_animation(t_data *data);
int     animate(t_data *anim);
void    ft_destroy(t_data *d);
void    ft_msg_destroy(t_data *data, char *msg);
void	check_key(t_data *var, int x, int y);
int	    ft_close(int keycode, t_data *vars);
void    ft_draw_map(t_data *game);
void    load_image(t_data *data);
char	*ft_itoa(int n);

#endif