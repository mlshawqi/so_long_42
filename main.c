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
void    ft_msg_destroy(t_data *data, char *msg)
{
    write(1, msg, ft_strlen(msg));
    if(data->win)
        mlx_destroy_window(data->mlx, data->win);
    mlx_destroy_display(data->mlx);
    free(data->mlx);
    ft_free(data->map);
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
    ft_draw_map(&game);
    game.movement = 0;
    game.collecting = 0;
    mlx_hook(game.win, 2, 1L<<0, ft_close, &game);
    mlx_loop(game.mlx);

    printf("nice ");
}