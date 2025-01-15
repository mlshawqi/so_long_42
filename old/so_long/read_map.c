/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saait-si <saait-si@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 10:13:47 by saait-si          #+#    #+#             */
/*   Updated: 2024/04/29 18:59:56 by saait-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_contmapline(t_point *app)
{
	char	*line;

	app->i = 0;
	app->fd = open(app->file_name, O_RDONLY);
	line = get_next_line(app->fd);
	while (line)
	{
		app->i++;
		free(line);
		line = get_next_line(app->fd);
	}
	return (app->i);
}

char	**read_map(t_point *app)
{
	char	**temp;
	char	*line;
	int		i;

	app->h = ft_contmapline(app);
	app->fd = open(app->file_name, O_RDONLY);
	line = get_next_line(app->fd);
	i = 0;
	temp = malloc((app->h + 1) * sizeof(char *));
	if (!temp)
		return (NULL);
	while (line)
	{
		if (line[0] == '\n')
			error("🐸 Your map contains an empty line 🐸\n");
		temp[i] = ft_strdup(line);
		i++;
		free(line);
		line = get_next_line(app->fd);
	}
	temp[i] = NULL;
	return (temp);
}
