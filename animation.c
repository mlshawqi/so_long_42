#include "minilibx-linux/mlx.h"
#include <X11/keysym.h>
#include <X11/X.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct s_data {
    void    *mlx;
    void    *win;
    void    *frames[2]; // Array to store 4 animation frames
    int     current_frame;
    int     frame_count;
} t_data;

// Function to display frames
int animate(t_data *data) {
    static int counter = 0;

    // Control animation speed (e.g., update every 10 frames)
        if (counter++ < 3900)
            return 0;
        counter = 0;

    // Clear the window (optional, depends on animation type)
    // mlx_clear_window(data->mlx, data->win);

    // Display the current frame
    mlx_put_image_to_window(data->mlx, data->win, 
                            data->frames[data->current_frame], 
                            100, 100);

    // Move to the next frame
    data->current_frame = (data->current_frame + 1) % data->frame_count;

    return 0;
}

int main() {
    t_data  data;

    // Initialize MiniLibX
    data.mlx = mlx_init();
    data.win = mlx_new_window(data.mlx, 800, 600, "Animation");

    // Load frames (you need .xpm files for this example)
    data.frames[0] = mlx_xpm_file_to_image(data.mlx, "textures/butterfly1.xpm", &(int){0}, &(int){0});
    data.frames[1] = mlx_xpm_file_to_image(data.mlx, "textures/butterfly2.xpm", &(int){0}, &(int){0});
    // data.frames[0] = mlx_xpm_file_to_image(data.mlx, "textures/flore1.xpm", &(int){0}, &(int){0});
    // data.frames[1] = mlx_xpm_file_to_image(data.mlx, "textures/flore2.xpm", &(int){0}, &(int){0}); 
    data.frame_count = 2; // Update frame count
    data.current_frame = 0;

    // Hook the animation function to the main loop
    mlx_loop_hook(data.mlx, animate, &data);

    // Run the loop
    mlx_loop(data.mlx);
    mlx_destroy_window(data.mlx, data.win);

    return 0;
}

// void    image_animate(int   size, char  *path,)
// {
//     int i;

//     i = 0;
//     while(i < size)
//     {
//         data.frames[0] = mlx_xpm_file_to_image(data.mlx, "textures/nrabbit1.xpm", &(int){0}, &(int){0});
//     }
// }