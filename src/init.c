/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:27:47 by brda-sil          #+#    #+#             */
/*   Updated: 2022/05/14 22:24:10 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*texture_load(t_main *config, char *path)
{
	int		i;
	void	*tmp;

	tmp = mlx_xpm_file_to_image(config->mlx, path, &i, &i);
	if (!tmp)
	{
		free_entry_point(config);
		ft_printf("ERROR: %s not found\n", path);
		exit(-1);
	}
	config->texture_loaded++;
	return (tmp);
}

void	init_texture_walls(t_main *config)
{
	config->textures->wall_0 = texture_load(config, "res/img/wall_0.xpm");
	config->textures->wall_1_n = texture_load(config, "res/img/wall_1_n.xpm");
	config->textures->wall_1_s = texture_load(config, "res/img/wall_1_s.xpm");
	config->textures->wall_1_e = texture_load(config, "res/img/wall_1_e.xpm");
	config->textures->wall_1_w = texture_load(config, "res/img/wall_1_w.xpm");
	config->textures->wall_2_h = texture_load(config, "res/img/wall_2_h.xpm");
	config->textures->wall_2_v = texture_load(config, "res/img/wall_2_v.xpm");
	config->textures->wall_2_ur = texture_load(config, "res/img/wall_2_ur.xpm");
	config->textures->wall_2_ul = texture_load(config, "res/img/wall_2_ul.xpm");
	config->textures->wall_2_ll = texture_load(config, "res/img/wall_2_ll.xpm");
	config->textures->wall_2_lr = texture_load(config, "res/img/wall_2_lr.xpm");
	config->textures->wall_3_n = texture_load(config, "res/img/wall_3_n.xpm");
	config->textures->wall_3_s = texture_load(config, "res/img/wall_3_s.xpm");
	config->textures->wall_3_e = texture_load(config, "res/img/wall_3_e.xpm");
	config->textures->wall_3_w = texture_load(config, "res/img/wall_3_w.xpm");
	config->textures->wall_4 = texture_load(config, "res/img/wall_4.xpm");
}

void	init_texture(t_main *config)
{
	init_texture_walls(config);
	init_texture_players(config);
	init_texture_enemys(config);
	config->textures->grave = texture_load(config, "res/img/grave.xpm");
	config->textures->ground = texture_load(config, "res/img/ground.xpm");
	config->textures->door_close = texture_load(config, \
												"res/img/door_close.xpm");
	config->textures->door_open = texture_load(config, "res/img/door_open.xpm");
	config->textures->key = texture_load(config, "res/img/key.xpm");
}

void	init_hook(t_main *config)
{
	mlx_hook(config->win, 33, 1L << 17, end_hook, config);
	mlx_loop_hook(config->mlx, draw_map, config);
	mlx_key_hook(config->win, keypress, config);
}

void	init_main(t_main *config)
{
	config->mlx = mlx_init();
	if (config->retry)
		mlx_destroy_window(config->mlx, config->win);
	config->win = mlx_new_window(config->mlx, \
							config->width * BLOCK_SIZE, \
							(config->height * BLOCK_SIZE) + TITLE_PADDING, \
							WIN_TITLE);
	init_hook(config);
	config->texture_loaded = 0;
	config->p_key = 0;
	config->p_win = 0;
	config->p_step = 0;
	config->p_last_step = 0;
	config->p_health = DEFAULT_PLAYER_HEALTH;
	config->saved_block = '0';
	config->is_map_new = 0;
	config->nb_player = 0;
	config->nb_enemy = 0;
	config->nb_door = 0;
	config->nb_key = 0;
	init_texture(config);
}
