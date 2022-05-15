/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 19:00:32 by brda-sil          #+#    #+#             */
/*   Updated: 2022/05/15 22:12:47 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_win(t_main *config, int x, int y)
{
	config->p_win = 1;
	config->map_new[config->p_x + x][config->p_y + y] = 'e';
	config->map_new[config->p_x][config->p_y] = '0';
	return (2);
}

int	main(int argc, char **argv)
{
	t_main		config;
	t_textures	textures;

	if (argc != 2)
		ft_error("Not enought args");
	config.retry = 1;
	config.texture_loaded = 0;
	while (config.retry)
	{
		ft_printf("Starting games\n");
		config.textures = &textures;
		parse_map(&config, argv[1]);
		init_main(&config);
		if (config.nb_enemy > 0)
			init_enemy(&config);
		parse_wall(&config);
		mlx_loop(config.mlx);
		usleep(0.25 * 1000000);
		free_entry_point(&config);
	}
	return (0);
}
