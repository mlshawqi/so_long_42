/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaouk <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-17 11:38:38 by machaouk          #+#    #+#             */
/*   Updated: 2025-01-17 11:38:38 by machaouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_strline(char *line)
{
	int	i;

	i = 0;
	while (line && line[i] != '\n' && line[i] != '\0')
		i++;
	return (i);
}

void	ft_save(int fd, char *line, t_data *d)
{
	int	i;

	i = 0;
	while (line != NULL)
	{
		if (line[0] == '\n' || ft_strline(line) != d->width)
		{
			free(line);
			ft_msg_destroy(d, "Error\nEmpty line or Inconsistent widths.!❌\n");
		}
		d->height++;
		if (d->height > 50)
			ft_msg_destroy(d, "Error\nMap height exceeds 50 characters.❌\n");
		d->map[i] = ft_strdup(line);
		if (!d->map[i] || d->height > 50)
		{
			free(line);
			ft_msg_destroy(d, "Error\nFailed to stor the map.❌\n");
		}
		free(line);
		line = get_next_line(fd);
		i++;
	}
	d->map[i] = NULL;
}

void	save_map(int fd, t_data *w)
{
	char	*line;

	line = get_next_line(fd);
	if (!line || line[0] == '\n')
	{
		if (line)
			free(line);
		close(fd);
		ft_message("Empty line or Nothing to read in the file!❌\n");
	}
	w->width = ft_strlen(line) - 1;
	if (w->width > 50)
	{
		free(line);
		close(fd);
		ft_message("Map width exceeds 50 characters.❌\n");
	}
	w->map = ft_calloc(w->width + 1, sizeof(char *));
	if (!w->map)
	{
		free(line);
		close(fd);
		exit(0);
	}
	ft_save(fd, line, w);
}

char	**copy_map(char **arr, int size)
{
	char	**str;
	int		i;

	str = ft_calloc(size + 1, sizeof(char *));
	if (!str)
		return (NULL);
	i = 0;
	while (i < size)
	{
		str[i] = strdup(arr[i]);
		if (!str[i])
		{
			ft_free(str);
			return (NULL);
		}
		i++;
	}
	str[i] = NULL;
	return (str);
}
