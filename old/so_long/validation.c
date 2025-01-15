/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saait-si <saait-si@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 10:10:35 by saait-si          #+#    #+#             */
/*   Updated: 2024/04/30 17:16:06 by saait-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	validation_extantion(t_point *app, int ac, char **av)
{
	char	*ptr;

	if (ac != 2)
		error("----- You need an argv[1] 🐸 -----\n");
	ptr = ft_strrchr(av[1], '.');
	if (ft_strncmp(av[1], ".ber", ft_strlen(".ber")) == 0)
		error ("Name your file 🐸\n");
	if (!ptr || ft_strncmp(ptr, ".ber", ft_strlen(ptr)))
		error("Check your extantion 🐸\n");
	app->file_name = av[1];
}

void	validation_exist(t_point *app)
{
	app->fd = open(app->file_name, O_RDONLY);
	if (app->fd == -1)
		error("The file is not created yet 🐸\n");
}
