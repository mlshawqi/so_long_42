/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaouk <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-15 22:19:52 by machaouk          #+#    #+#             */
/*   Updated: 2025/01/16 11:18:17 by machaouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"
# include <stdlib.h>
# include "gnl/get_next_line.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <string.h>
# include <unistd.h>

# define ESCAPE 65307
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_UP 65362
# define KEY_DOWN 65364
# define MAX 100099999

typedef struct s_data
{
	void	*mlx;
	void	*win;
	char	*path;
	int		width;
	int		height;
	char	**map;
	int		collectable;
	int		exit;
	int		player;
	int		p_x;
	int		p_y;
	int		p;
	int		c;
	int		e;
	void	*i_background;
	void	*i_wall;
	void	*f_exit[2];
	void	*f_player_r[2];
	void	*f_player_l[2];
	void	*frame_collectable[2];
	void	*frame_enemy[2];
	int		current_frame;
	int		movement;
	char	*n_move;
	int		collecting;
	int		butterfly_r;
	int	fd;
}			t_data;

void		check_walls(t_data *walls);
void		save_map(int fd, t_data *w);
int			p_position(t_data *w);
int			characters(t_data *wl);
void		check_map(t_data *dt);
void		ft_message(char *msj);
void		check_path(t_data *g, int argc, char *argv[]);
int			ft_iselement(char c);
void		check2_map(t_data *data);
void		flood_fill(char **str, t_data *wl, int x, int y);
char		**copy_map(char **arr, int size);
void		ft_destroy(t_data *d);
void		put_images(t_data *d);
void		load_animation(t_data *data);
int			animate(t_data *anim);
void		ft_destroy(t_data *d);
void		ft_msg_destroy(t_data *data, char *msg);
void		check_key(t_data *var, int x, int y);
int			ft_close(int keycode, t_data *vars);
void		ft_draw_map(t_data *game);
void		load_image(t_data *data);
char		*ft_itoa(int n);
void		ft_load_player(t_data *data);
void		put_animate_image(t_data *swan, char hint, int x, int y);
void		textures(t_data *t);
void		ft_save(int fd, char *line, t_data *d);
void		put_null(t_data *game);
int		handle_window_close(t_data *vars);
#endif
