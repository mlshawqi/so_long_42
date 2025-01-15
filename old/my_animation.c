#include "minilibx-linux/mlx.h"
#include <X11/keysym.h>
#include <X11/X.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include "libft/libft.h"
#include "git_next_line/get_next_line.h"

typedef struct s_mlx{
    void    *mlx;
    void    *win;
}   t_mlx;

typedef struct s_animation {
    char    **frames;     // Array of frame images
    int     frame_count;  // Number of frames
    int     current_frame;// Current frame index
    int     x;            // X position on the window
    int     y;            // Y position on the window
} t_animation;

void    load_image(t_mlx *d, char *path, int size, int n_frams)
{

    mlx_xpm_file_to_image(d->mlx, "textures/back1.xpm", &img_width, &img_height);

}

int main()
{
    t_mlx   data;
    t_animation image;

    data.mlx = mlx_init();
    if(data.mlx == NULL)
         return (0);
    data.win = mlx_new_window(data.mlx, 500, 600, "my_animate");
    if(data.win == NULL)
    {
        mlx_destroy_display(data.mlx); // Cleanup MLX connection
        free(data.mlx);
        return (0);
    }
    image.frames = malloc(sizeof(char *) * 5);
    if(!image.frames)
        return (0);
}