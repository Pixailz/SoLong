/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 20:38:18 by brda-sil          #+#    #+#             */
/*   Updated: 2022/05/21 21:34:55 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_ascii_o(int global_offset, t_main *config, int offset)
{
	int	i;
	int	j;

	i = 0;
	while (i < 6)
		print_ascii_art_pixel(config, 9 + offset + global_offset, i++ + 3, RED);
	i = 0;
	while (i < 8)
		print_ascii_art_pixel(config, 10 + offset + global_offset \
																, i++ + 2, RED);
	i = 0;
	j = 0;
	while (i < 2)
	{
		while (j < 10)
		{
			if (j < 3 || j > 6)
				print_ascii_art_pixel(config, 11 + offset + i + \
													global_offset, j + 1, RED);
			j++;
		}
		j = 0;
		i++;
	}
	print_ascii_o_end(global_offset, config, offset);
}

void	print_ascii_o_end(int global_offset, t_main *config, int offset)
{
	int	i;

	i = 0;
	while (i < 8)
		print_ascii_art_pixel(config, 13 + offset + global_offset, i++ + 2, \
																		RED);
	i = 0;
	while (i < 6)
		print_ascii_art_pixel(config, 14 + offset + global_offset, i++ + 3, \
																		RED);
}

void	print_ascii_o_shadow(int global_offset, t_main *config, int offset)
{
	int	i;

	i = 0;
	while (i < 4)
		print_ascii_art_pixel(config, 11 + offset + global_offset, i++ + 4, \
																	DARK_RED);
	print_ascii_art_pixel(config, 12 + offset + global_offset, 4, DARK_RED);
	i = 0;
	while (i < 6)
		print_ascii_art_pixel(config, 15 + offset + global_offset, i++ + 4, \
																	DARK_RED);
	print_ascii_art_pixel(config, 14 + offset + global_offset, 10, DARK_RED);
	print_ascii_art_pixel(config, 14 + offset + global_offset, 9, DARK_RED);
	print_ascii_art_pixel(config, 13 + offset + global_offset, 10, DARK_RED);
	print_ascii_art_pixel(config, 13 + offset + global_offset, 11, DARK_RED);
	print_ascii_art_pixel(config, 12 + offset + global_offset, 11, DARK_RED);
}
