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
void    check_path(t_data *g, int argc, char *argv[])
{
    int len;

    if(argc == 2)
    {
        len = ft_strlen(argv[1]);
        if (ft_strcmp(argv[1] + (len - 4), ".ber") != 0 || open(argv[1], O_RDONLY) < 0)
            ft_error(g, "wrong extension '_'\n", 0);
        g->path = ft_strdup(argv[1]);   
    }
    else
        ft_error(g, "Need argv[1]\n", 0);
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
    mlx_loop(game.mlx);
    
    printf("nice ");
}