/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_duel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 07:57:54 by brda-sil          #+#    #+#             */
/*   Updated: 2022/05/14 23:56:02 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	duel_deal_damage(t_main *config, t_enemy *enemy)
{
	config->p_health -= DEFAULT_ENEMY_DAMAGE;
	enemy->health -= DEFAULT_PLAYER_DAMAGE;
	if (enemy->health <= 0)
		config->map_new[enemy->pos_x][enemy->pos_y] = 'k';
	if (config->p_health <= 0)
	{
		config->p_win = -1;
		print_before_win_loose(config);
	}
}

void	duel_check_direction(t_main *config, int i, int j)
{
	if (config->enemy[i]->pos_x == config->p_x + j && \
		config->enemy[i]->pos_y == config->p_y)
	{
		duel_deal_damage(config, config->enemy[i]);
		config->p_step++;
	}
	if (config->enemy[i]->pos_x == config->p_x && \
		config->enemy[i]->pos_y == config->p_y + j)
	{
		duel_deal_damage(config, config->enemy[i]);
		config->p_step++;
	}
}

void	get_nearby_enemy(t_main *config)
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	while (i < config->nb_enemy)
	{
		while (j <= 1)
		{
			duel_check_direction(config, i, j);
			j += 2;
		}
		j = -1;
		i++;
	}
}

void	duel(t_main *config)
{
	get_nearby_enemy(config);
}
