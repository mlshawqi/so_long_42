#include "so_long.h"

// void load_animation(mlx_data *data, int anim_index, char **frame_paths, int frame_count, int x, int y)
// {
//     t_animation *anim = &data->animations[anim_index];

//     anim->frame_count = frame_count;
//     anim->current_frame = 0;
//     anim->x = x;
//     anim->y = y;
//     anim->frames = malloc(sizeof(void *) * frame_count);

//     for (int i = 0; i < frame_count; i++) {
//         anim->frames[i] = mlx_xpm_file_to_image(data->mlx, frame_paths[i], &(int){0}, &(int){0});
//         if (!anim->frames[i]) {
//             fprintf(stderr, "Error: Failed to load frame %d of animation %d\n", i, anim_index);
//             exit(1);
//         }
//     }
// }

// void animate(mlx_data *data)
// {
//     static int counter = 1900;
//     t_animation *anim;
//     if (counter++ < 1900)
//         return;
//     counter = 0;    
//     int i = 0;
//     while(i < 4)
//     {  
//         anim = &data->animations[i];
//         mlx_put_image_to_window(data->mlx, data->win, anim->frames[anim->current_frame], anim->x, anim->y);
//         anim->current_frame = (anim->current_frame + 1) % anim->frame_count;
//         i++;
//     }
// }

// void load_frames(mlx_data *data, char hint, int x, int y)
// {
//     // Paths for the frames of each animation
//     char *anim1_frames[] = {"textures/nrabbit1.xpm", "textures/nrabbit2.xpm", "textures/nrabbit3.xpm", "textures/nrabbit4.xpm"};
//     char *anim2_frames[] = {"textures/burroww1.xpm", "textures/burrow2.xpm"};
//     char *anim3_frames[] = {"textures/carrot1.xpm", "textures/carrot2.xpm"};
//     char *anim4_frames[] = {"textures/enemy1.xpm", "textures/enemy22.xpm"};

//     // Load animations with different frame counts
//     if(hint == 'P')
//         load_animation(data, 0, anim1_frames, 4, x, y); // 4 frames
//     else if(hint == 'E')
//         load_animation(data, 1, anim2_frames, 2, x, y); // 2 frames
//     else if(hint == 'C')
//         load_animation(data, 2, anim3_frames, 2, x, y); // 3 frames
//     else if(hint == 'M')
//         load_animation(data, 3, anim4_frames, 2, x, y); // 5 frames

//     return;
// }

// int	put_images(mlx_data *d)
// {
// 	int		img_width;
// 	int		img_height;
//     int     i;

//     i = 0;
//     if(d->key == 0)
//     {
//         d->background = mlx_xpm_file_to_image(d->mlx, "textures/back1.xpm", &img_width, &img_height);
// 	    d->wall = mlx_xpm_file_to_image(d->mlx, "textures/rocket.xpm", &img_width, &img_height);
//     }


//     int x;
//     int y = 0;
//     int j;
//     while (d->map[i] != NULL)
//     {
//         x = 0;
//         j = 0;
//         while(d->map[i][j] != '\n' && d->map[i][j] != '\0')
//         {
//             if(d->map[i][j] == '1')
//             {
//                 if(d->key == 0)
//                     mlx_put_image_to_window(d->mlx, d->win, d->wall, x, y);
//             }   
//             else if(d->map[i][j] == '0')
//             {
//                 if(d->key == 0)
//                    mlx_put_image_to_window(d->mlx, d->win, d->background, x, y);
//             }
//             else if(d->map[i][j] == 'P')
//             {
//                 if(d->key == 0)
//                     load_frames(d, 'P', x, y);
//                 animate(d);
//             }
//             else if(d->map[i][j] == 'C')
//             {
//                 if(d->key == 0)
//                     load_frames(d, 'C', x, y);
//                 animate(d);
//             }
//             else if(d->map[i][j] == 'E')
//             {
//                 if(d->key == 0)
//                     load_frames(d, 'E', x, y);
//                 animate(d);
//             }
//             else if(d->map[i][j] == 'M')
//             {
//                 if(d->key == 0)
//                     load_frames(d, 'M', x, y);
//                 animate(d);
//             }
//             x += 50;  
//             j++;       
//         }
//         i++;
//         y += 50;
//     }
//     d->key = 1;
//     return (0);
// }

//__________________________________________________________________________________________

void    file_to_image(t_data *data)
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
    file_to_image(d);
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
	mlx_loop(d->mlx);	
}