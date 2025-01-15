#include "so_long.h"

// typedef struct s_animation {
//     void    **frames;     // Array of frame images
//     int     frame_count;  // Number of frames
//     int     current_frame;// Current frame index
//     int     x;            // X position on the window
//     int     y;            // Y position on the window
// } t_animation;

// typedef struct s_data {
//     void        *mlx;
//     void        *win;
//     t_animation animations[4]; // Array of 4 animations
// } t_data;

void load_animation(t_data *data)
{
    data->current_frame = 0;
    data->frame_player[0] = mlx_xpm_file_to_image(data->mlx, "textures/butterfly1.xpm", &(int){0}, &(int){0});
    if(!data->frame_player[0])
        ft_error(data, "Failed to load frame 0 of pleyer\n", 1);
    data->frame_player[1] = mlx_xpm_file_to_image(data->mlx, "textures/butterfly2.xpm", &(int){0}, &(int){0});
    if(!data->frame_player[1])
        ft_error(data, "Failed to load frame 0 of pleyer\n", 1);
    data->frame_collectable[0] = mlx_xpm_file_to_image(data->mlx, "textures/flower1.xpm", &(int){0}, &(int){0});
    if(!data->frame_collectable[0])
        ft_error(data, "Failed to load frame 0 of collectable\n", 1);
    data->frame_collectable[1] = mlx_xpm_file_to_image(data->mlx, "textures/flower2.xpm", &(int){0}, &(int){0});
    if(!data->frame_collectable[1])
        ft_error(data, "Failed to load frame 1 of collectable\n", 1);
    data->frame_enemy[0] = mlx_xpm_file_to_image(data->mlx, "textures/spider1.xpm", &(int){0}, &(int){0});
    if(!data->frame_enemy[0])
        ft_error(data, "Failed to load frame 0 of enemy\n", 1);
    data->frame_enemy[1] = mlx_xpm_file_to_image(data->mlx, "textures/spider2.xpm", &(int){0}, &(int){0});
    if(!data->frame_enemy[1])
        ft_error(data, "Failed to load frame 1 of enemy\n", 1);
}

int animate(t_data *anim)
{
    static int counter = 2500;
    int i;
    int j;
    int x;
    int y;

    if (counter++ < 2500)
        return 0;
    counter = 0;
    i = 0;
    y = 0;
    while(anim->map[i] != NULL)
    {
        j = 0;
        x = 0;
        while(anim->map[i][j] != '\0' && anim->map[i][j] != '\n')
        {
            if(anim->map[i][j] == 'P')
                mlx_put_image_to_window(anim->mlx, anim->win, anim->frame_player[anim->current_frame], x, y);
            else if(anim->map[i][j] == 'C')
                mlx_put_image_to_window(anim->mlx, anim->win, anim->frame_collectable[anim->current_frame], x, y);
            else if(anim->map[i][j] == 'M')
                mlx_put_image_to_window(anim->mlx, anim->win, anim->frame_enemy[anim->current_frame], x, y);
            j++;
            x += 50;
        }
        i++;
        y += 50;
    }
    anim->current_frame = (anim->current_frame + 1) % 2;
 
    return 0;
}
void    ft_draw_map(t_data *game)
{
    load_image(game);
    put_images(game);
    load_animation(game);
    game->n_move = ft_strjoin("movement : ", ft_itoa(game->movement));
    mlx_string_put(game->mlx, game->win, 20, 20, 0xFF0000, game->n_move);
    mlx_loop_hook(game->mlx, animate, game);
}
// void load_animation(t_data *data, int anim_index, char **frame_paths, int frame_count, int x, int y)
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

// int animate(mlx_data *data, int s)
// {
//     static int counter = 1900;
//     t_animation *anim;
//     anim = &data->animations[s];
//     if (counter++ < 1900)
//         return 0;
//     counter = 0;    
//     int i = 0;
//     while(i < anim->frame_count)
//     {  
//         mlx_put_image_to_window(data->mlx, data->win, anim->frames[anim->current_frame], anim->x, anim->y);
//         anim->current_frame = (anim->current_frame + 1) % anim->frame_count;
//         i++;
//     }
//     return 0;
// }

// int load_frames(mlx_data *data, char hint, int x, int y)
// {
//     // Paths for the frames of each animation
//     char *anim1_frames[] = {"textures/buterfly1.xpm", "textures/butterfly2.xpm"};
//     char *anim2_frames[] = {"textures/flore1.xpm", "textures/flore2.xpm"};
//     // char *anim3_frames[] = {"textures/carrot1.xpm", "textures/carrot2.xpm"};
//     // char *anim4_frames[] = {"textures/enemy1.xpm", "textures/enemy22.xpm"};

//     // Load animations with different frame counts
//     if(hint == 'P')
//         load_animation(&data, 0, anim1_frames, 4, x, y); // 4 frames
//     else if(hint == 'E')
//         load_animation(&data, 1, anim2_frames, 2, x, y); // 2 frames
//     else if(hint == 'C')
//         load_animation(&data, 2, anim3_frames, 2, x, y); // 3 frames
//     else if(hint == 'M')
//         load_animation(&data, 3, anim4_frames, 2, x, y); // 5 frames

//     return 0;
// }


//_______________________________________________________________________________________________

// //correct one for animation
// // #define FRAME_DELAY 150000 // 150ms delay between frames

// typedef struct s_animation {
//     void    **frames;     // Array of frame images
//     int     frame_count;  // Number of frames
//     int     current_frame;// Current frame index
//     int     x;            // X position on the window
//     int     y;            // Y position on the window
// } t_animation;

// typedef struct s_data {
//     void        *mlx;
//     void        *win;
//     t_animation animations[4]; // Array of 4 animations
// } t_data;

// void load_animation(t_data *data, int anim_index, char **frame_paths, int frame_count, int x, int y) {
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

// int animate(t_data *data) {
//     static int counter = 1900;
//     t_animation *anim;
//     if (counter++ < 3900)
//         return 0;
//     counter = 0;    
//     int i = 0;
//     while(i < 4)
//     {  
//         anim = &data->animations[i];
//         mlx_put_image_to_window(data->mlx, data->win, anim->frames[anim->current_frame], anim->x, anim->y);
//         anim->current_frame = (anim->current_frame + 1) % anim->frame_count;
//         i++;
//     }
//     return 0;
// }

// int main() {
//     t_data data;

//     data.mlx = mlx_init();
//     data.win = mlx_new_window(data.mlx, 800, 600, "Different Animations");

//     // Paths for the frames of each animation
//     char *anim1_frames[] = {"textures/butterfly1.xpm", "textures/butterfly2.xpm"};
//     char *anim2_frames[] = {"textures/mushroom1.xpm", "textures/mushroom2.xpm"};
//     char *anim3_frames[] = {"textures/spider1.xpm", "textures/spider2.xpm"};
//     char *anim4_frames[] = {"textures/flower1.xpm", "textures/flower2.xpm"};

//     // Load animations with different frame counts
//     load_animation(&data, 0, anim1_frames, 2, 50, 100); // 4 frames
//     load_animation(&data, 1, anim2_frames, 2, 200, 250); // 2 frames
//     load_animation(&data, 2, anim3_frames, 2, 350, 400); // 3 frames
//     load_animation(&data, 3, anim4_frames, 2, 450, 500); // 5 frames

//     // Animation loop
//     mlx_loop_hook(data.mlx, animate, &data);
//     mlx_loop(data.mlx);

//     return 0;
// }
