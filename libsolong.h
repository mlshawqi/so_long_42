#ifndef LIBSOLONG_H
#define LIBSOLONG_H

#include "minilibx-linux/mlx.h"
#include <X11/keysym.h>
#include <X11/X.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#define MALLOC_ERROR	1
#define WIDTH			400
#define HEIGHT			400

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

char	*get_next_line(int fd)