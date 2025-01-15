#include "so_long.h"

void load_animation(t_data *data)
{
    data->current_frame = 0;
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
    ft_load_player(data);
}

void    put_player_image(t_data *swan, int x, int y)
{
    if(swan->butterfly_r == 0)
        mlx_put_image_to_window(swan->mlx, swan->win, swan->f_player_r[swan->current_frame], x, y);
    else if(swan->butterfly_r == 1)
        mlx_put_image_to_window(swan->mlx, swan->win, swan->f_player_l[swan->current_frame], x, y);
    return ;
}
int animate(t_data *anim)
{
    static int counter = 2500;
    int i;
    int j;
    int x;
    int y;

    if (counter++ < 3000)
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
                put_player_image(anim, x, y);
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

void    ft_load_player(t_data *data)
{
    data->f_player_r[0] = mlx_xpm_file_to_image(data->mlx, "textures/butterfly1_r.xpm", &(int){0}, &(int){0});
    if(!data->f_player_r[0])
        ft_error(data, "Failed to load frame 0 of pleyer\n", 1);
    data->f_player_r[1] = mlx_xpm_file_to_image(data->mlx, "textures/butterfly2_r.xpm", &(int){0}, &(int){0});
    if(!data->f_player_r[1])
        ft_error(data, "Failed to load frame 0 of pleyer\n", 1);
    data->f_player_l[0] = mlx_xpm_file_to_image(data->mlx, "textures/butterfly1_l.xpm", &(int){0}, &(int){0});
    if(!data->f_player_l[0])
        ft_error(data, "Failed to load frame 0 of pleyer\n", 1);
    data->f_player_l[1] = mlx_xpm_file_to_image(data->mlx, "textures/butterfly2_l.xpm", &(int){0}, &(int){0});
    if(!data->f_player_l[1])
        ft_error(data, "Failed to load frame 0 of pleyer\n", 1);
}
