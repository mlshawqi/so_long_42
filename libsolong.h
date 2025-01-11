#ifndef LIBSOLONG_H
# define LIBSOLONG_H

#include "minilibx-linux/mlx.h"
#include <X11/keysym.h>
#include <X11/X.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

typedef struct	m_data {
	void	*mlx;
	void	*win;
	void	*background;
	void	*wall;
	void	*r_exit[2];
	void	*player[4];
	void	*collect[2];
	void	*enemy[2];
}				mlx_data;

typedef struct wall_data{
	char	**map;
	char	**map_copy;
	int		width;
	int		height;
	int		collectable;
	int		player;
	int		exit;
	int		enemy;
	int 	p;
    int 	c;
    int 	e;
	int		m;
	int 	x;
	int 	y;
}			w_data;

char	*get_next_line(int fd);
char	*ft_strdup(char *s);
char	*ft_strjoin(char *s1, char *s2);
int		ft_str_len(char *s, int sing);
char    **check_map(char *path, w_data *data);
int check_walls(char **map, int w, int h);
int 	charcters(char **s, w_data *wl);
int p_position(char **s, w_data *w);
// int check_pos(char *s, int widt);
// char    **full_str(int fd, w_data *w);
// void flood_fill(char **str, w_data *wl, int x, int y);
void	put_images(mlx_data *d, char **s_map);
char	**ft_split(char const *s, char c);
int		ft_strlen(char *s);
int		ft_strcmp(char *s1, char *s2);
void	ft_free(char **str, int k);
#endif