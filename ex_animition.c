#include "minilibx-linux/mlx.h"
#include <X11/keysym.h>
#include <X11/X.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

//correct one for animation
// #define FRAME_DELAY 150000 // 150ms delay between frames

typedef struct s_animation {
    void    **frames;     // Array of frame images
    int     frame_count;  // Number of frames
    int     current_frame;// Current frame index
    int     x;            // X position on the window
    int     y;            // Y position on the window
} t_animation;

typedef struct s_data {
    void        *mlx;
    void        *win;
    t_animation animations[4]; // Array of 4 animations
} t_data;

void load_animation(t_data *data, int anim_index, char **frame_paths, int frame_count, int x, int y) {
    t_animation *anim = &data->animations[anim_index];

    anim->frame_count = frame_count;
    anim->current_frame = 0;
    anim->x = x;
    anim->y = y;
    anim->frames = malloc(sizeof(void *) * frame_count);

    for (int i = 0; i < frame_count; i++) {
        anim->frames[i] = mlx_xpm_file_to_image(data->mlx, frame_paths[i], &(int){0}, &(int){0});
        if (!anim->frames[i]) {
            fprintf(stderr, "Error: Failed to load frame %d of animation %d\n", i, anim_index);
            exit(1);
        }
    }
}

int animate(t_data *data) {
    static int counter = 1900;
    t_animation *anim;
    if (counter++ < 1900)
        return 0;
    counter = 0;    
    int i = 0;
    while(i < 4)
    {  
        anim = &data->animations[i];
        mlx_put_image_to_window(data->mlx, data->win, anim->frames[anim->current_frame], anim->x, anim->y);
        anim->current_frame = (anim->current_frame + 1) % anim->frame_count;
        i++;
    }
    return 0;
}

int main() {
    t_data data;

    data.mlx = mlx_init();
    data.win = mlx_new_window(data.mlx, 800, 600, "Different Animations");

    // Paths for the frames of each animation
    char *anim1_frames[] = {"textures/nrabbit1.xpm", "textures/nrabbit2.xpm", "textures/nrabbit3.xpm", "textures/nrabbit4.xpm"};
    char *anim2_frames[] = {"textures/burroww1.xpm", "textures/burrow2.xpm"};
    char *anim3_frames[] = {"textures/carrot1.xpm", "textures/carrot2.xpm"};
    char *anim4_frames[] = {"textures/enemy1.xpm", "textures/enemy22.xpm"};

    // Load animations with different frame counts
    load_animation(&data, 0, anim1_frames, 4, 50, 100); // 4 frames
    load_animation(&data, 1, anim2_frames, 2, 200, 250); // 2 frames
    load_animation(&data, 2, anim3_frames, 2, 350, 400); // 3 frames
    load_animation(&data, 3, anim4_frames, 2, 450, 500); // 5 frames

    // Animation loop
    mlx_loop_hook(data.mlx, animate, &data);
    mlx_loop(data.mlx);

    return 0;
}
