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
	void	*r_exit;
	void	*player;
	void	*collect;
	void	*enemy;
}				mlx_data;

char	*get_next_line(int fd);
char	*ft_strdup(char *s);
char	*ft_strjoin(char *s1, char *s2);
int		ft_str_len(char *s, int sing);
char    *check_map(char *map, int  *h, int *w);
int check_walls(char *str, int *w, int hght);
int charcters(char *st);
int check_pos(char *s, int widt);
char    *full_str(int fd, int *hg);
int	ft_strcmp(char *s1, char *s2);
void	put_images(mlx_data *d, char *s_map);

#endif