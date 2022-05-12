/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 04:27:56 by brda-sil          #+#    #+#             */
/*   Updated: 2022/05/12 19:31:18 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_width(t_main *config)
{
	int	i;

	i = 0;
	while (i < config->height)
	{
		if (ft_strlen(config->map[i]) != config->width)
			return (0);
		i++;
	}
	return (1);
}

void	count_point(t_main *config, char point)
{
	if (point == 'E')
		config->nb_door++;
	else if (point == 'P')
		config->nb_player++;
	else if (point == 'C')
		config->nb_key++;
}

int	check_wrong_point(t_main *config)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < config->height)
	{
		while (j < config->width)
		{
			if (ft_strchr(GOOD_POINT, config->map[i][j]))
				count_point(config, config->map[i][j]);
			else
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

int	check_surrounded(t_main *config)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < config->height)
	{
		while (j < config->width)
		{
			if (i == 0)
				if (config->map[i][j] != '1')
					return (0);
			if (j == 0)
				if (config->map[i][j] != '1')
					return (0);
			if (j + 1 == config->width)
				if (config->map[i][j] != '1')
					return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

void	check_map(t_main *config, t_textures *textures)
{
	if (!check_width(config))
	{
		free_entry_point(config, textures);
		ft_error("Map is not a square");
	}
	if (!check_surrounded(config))
	{
		free_entry_point(config, textures);
		ft_error("Map no surrounded");
	}
	if (!check_wrong_point(config))
	{
		free_entry_point(config, textures);
		ft_error("Wrong point on the map");
	}
	if (!check_minimum_point(config))
	{
		free_entry_point(config, textures);
		ft_error("Map don't have minimum requirement");
	}
}
