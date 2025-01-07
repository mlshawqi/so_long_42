#include "libsolong.h"
#include "git_next_line/get_next_line.h"


//gcc -Lminilibx-linux -lmlx_Linux -lX11 -lXext

int check_walls(char *str, int *w, int hght)
{
    int i;
    int len;
    int line;

    i = 0;
    line = 0;
    while(str[i] != '\0')
    {
        len = 0;
        line++;
        while(str[i] != '\n' && str[i] != '\0')
        {
            if(*w == 0 || len == 0 || str[i + 1] == '\n' || line == hght)
            {
                if(str[i] != '1')
                    return (1);
            }
            i++;
            len++;
        }
        if(*w == 0)
            *w += i;
        i++;
    }
    return (0);
}
int check_pos(char *s, int widt)
{
    int i;
    int line;
    int c = 0;
    int e = 0;
    int p = 0;

    i = 0;
    while(s[i] != '\0')
    {
        line = 0;
        while(s[i] != '\n' && s[i] != '\0')
        {
            if((s[i] == 'P' || s[i] == 'E' || s[i] == 'C') && (s[i + 1] == '1' && s[i - 1] == '1') 
                                            && (s[i - widt - 1] == '1' && s[i + widt + 1] == '1'))
                return (1);
            if(s[i] == 'P')
                p++;
            if(s[i] == 'E')
                e++;
            if(s[i] == 'C')
                c++;
            line++;
            i++;         
        }
        if(line != widt)
            return (1);
        i++;
    }   
    if(c == 0 || (p > 1  || p == 0) || (e > 1 || e == 0))
        return (1);

    return (0);
}
char    *check_map(int  *h, int *w)
{
    char    *str;
    char    *tmp;
    char    *line;
    int     fd;

    fd = open("maps/map.ber", O_RDONLY);
	line = get_next_line(fd);
    str = NULL;
    while(line != NULL)
    {
        (*h)++;
        tmp = str;
        str = ft_strjoin(str, line); 
        free(line);
        free(tmp);
        if(!str)
        {
            close(fd);
            return (NULL);
        }
        line = get_next_line(fd);
    }
    close(fd);
    if(check_walls(str, w, *h) == 1 || check_pos(str, *w))
    {
        free(str);
        str = NULL;
    }
    return (str);
}

int	main()
{
	mlx_data	data;
    char        *map;
    int         height = 0;
    int         width = 0;

    map = check_map(&height, &width);
    if(map == NULL)
    {
        printf("not valide %d  %d\n", height, width);
        return (0);
    }
    data.mlx = mlx_init();
    if(data.mlx == NULL)
		return (0);    
    data.win = mlx_new_window(data.mlx, width * 50, height * 50, "so_long");
	if(data.win == NULL)
	{
		mlx_destroy_display(data.mlx); // Cleanup MLX connection
		free(data.mlx);
		return (0);
	}
    
	mlx_loop(data.mlx);

	// mlx_destroy_window(data.mlx, data.win);
    // mlx_destroy_display(data.mlx);
	// free(data.mlx);
    return (0);
}
