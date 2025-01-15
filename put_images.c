#include "so_long.h"

void    load_image(t_data *data)
{
    data->i_background = mlx_xpm_file_to_image(data->mlx, "textures/background.xpm", &(int){0}, &(int){0});
    if(!data->i_background)
        ft_error(data, "Failed to load frame of background\n", 1);
    data->i_wall = mlx_xpm_file_to_image(data->mlx, "textures/wall.xpm", &(int){0}, &(int){0});
    if(!data->i_wall)
        ft_error(data, "Failed to load frame of walls\n", 1);
    data->i_exit = mlx_xpm_file_to_image(data->mlx, "textures/mushroom1.xpm", &(int){0}, &(int){0});
    if(!data->i_exit)
        ft_error(data, "Failed to load frame of exit\n", 1);
}

void	put_images(t_data *d)
{
    int     i;
    int     y;
    int     x;
    int     j;

    i = 0;
    y = 0;
    while (d->map[i] != NULL)
    {
        x = 0;
        j = 0;
        while(d->map[i][j] != '\n' && d->map[i][j] != '\0')
        {
            if(d->map[i][j] == '1')
                mlx_put_image_to_window(d->mlx, d->win, d->i_wall, x, y);
            if(d->map[i][j] == '0')
                mlx_put_image_to_window(d->mlx, d->win, d->i_background, x, y);
            if(d->map[i][j] == 'E')
                 mlx_put_image_to_window(d->mlx, d->win, d->i_exit, x, y);
            x += 50;  
            j++;       
        }
        i++;
        y += 50;
    }
	//mlx_loop(d->mlx);	
}