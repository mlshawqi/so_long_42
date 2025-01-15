/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saait-si <saait-si@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:11:03 by saait-si          #+#    #+#             */
/*   Updated: 2024/04/30 16:06:23 by saait-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H


#include "minilibx-linux/mlx.h"
#include <X11/keysym.h>
#include <X11/X.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
# include "./gnl/get_next_line.h"
# include "./libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_point
{
	char	*file_name;
	char	**dbl_ptr;
	void	*mlx;
	void	*win;
	void	*wall;
	void	*ground;
	void	*heart;
	void	*left;
	void	*right;
	void	*player;
	void	*exit;
	int		num_of_moves;
	int		c_number;
	int		di;
	int		dj;
	int		fd;
	int		h;
	int		w;
	int		i;
	int		p;
	int		e;
	int		j;
}			t_point;

typedef struct s_wh
{
	int		width;
	int		height;
}			t_wh;

void		validation_extantion(t_point *app, int ac, char **av);
void		validation_exist(t_point *app);
int			ft_contmapline(t_point *app);
char		**read_map(t_point *app);
int			map_height(t_point *app);
void		map_width(t_point *app);
void		draw_map(t_point *app);
int			map_height(t_point *app);
void		ft_border(t_point *app);
int			ft_iselement(char elem);
void		ft_chrcking_how_many_charteres(t_point *app);
void		ft_check(t_point *app);
char		**ft_map_copy(t_point *app);
void		p_position(char **map, int *array);
void		ft_flood_fill(char **map, int i, int j);
void		chack_flood_fill(char **map, t_point *app);
void		ft_checking_path(t_point *app);
int			handle_keys(int keycode, t_point *app);
void		change_player_position(t_point *app);
void		load_images(t_point *app);
int			exit_function(char *msg, t_point *app, int flag);
void		ft_dbl_free(char **ptr);
void		error(char *msg);
void		ft_count_windodw(t_point *app);
#endif