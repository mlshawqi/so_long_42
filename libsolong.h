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
#include "get_next_line.h"

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

#endif