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
int main(int argc, char *argv[])
{
    t_data game;
    check_path(&game, argc, argv);
    check_map(&game);
    check2_map(&game);
    game.mlx = mlx_init();
    if (game.mlx == NULL)
        ft_error(&game, "Error: mlx_init failed\n", 1);
    game.win = mlx_new_window(game.mlx, game.width * 50, game.height * 50, "swan");
    if (game.win == NULL)
        ft_destroy(&game);
    put_images(&game);
    load_animation(&game);
    mlx_loop_hook(game.mlx, animate, &game);
    mlx_loop(game.mlx);

    //printf("nice ");
}