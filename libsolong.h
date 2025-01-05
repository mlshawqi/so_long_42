#ifndef LIBSOLONG_H
#define LIBSOLONG_H

#include "minilibx-linux/mlx.h"
#include <X11/keysym.h>
#include <X11/X.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define MALLOC_ERROR	1
#define WIDTH			400
#define HEIGHT			400

typedef struct	m_data{
	void	*connection;
	void	*window;
}				mlx_data;

typedef struct	i_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				image_data;