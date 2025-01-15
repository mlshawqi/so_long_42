#include "so_long.h"

void    ft_error(t_data *game, char *msg, int flag)
{
    write(1, "Error: ", 7);
    write(1, msg, ft_strlen(msg));
    if(flag == 1)
    ft_free(game->map);
    exit(0);
}
void    ft_destroy(t_data *d)
{
    if(d->win)
        mlx_destroy_window(d->mlx, d->win);
    mlx_destroy_display(d->mlx);
    free(d->mlx);
    ft_free(d->map);
    exit(0);
}