/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 16:59:52 by brda-sil          #+#    #+#             */
/*   Updated: 2022/05/12 19:30:59 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "ft_printf.h"
# include "mlx.h"
# include "get_next_line.h"
# include <unistd.h>
# include <stdlib.h>

# define WIN_TITLE "SO LONG..."
# define BLOCK_SIZE 32
# define GOOD_POINT "10EPC"

// STRUCTURES
typedef struct s_textures {
	void	*player;
	void	*wall;
	void	*ground;
	void	*door_open;
	void	*door_close;
	void	*key;
}				t_textures;

typedef struct s_main {
	void	*mlx;
	void	*win;
	char	**map;
	int		width;
	int		height;
	int		nb_player;
	int		nb_door;
	int		nb_key;
}				t_main;

// init.c
void	*texture_load(t_main *config, char *path);
void	init_texture(t_main *config, t_textures *textures);
void	init_main(t_main *config, char *title);
void	init_entry_point(t_main *config, t_textures *textures);

// free.c
void	free_texture(t_main *config, void *texture);
void	free_entry_point(t_main *config, t_textures *textures);

// parse.c
int		check_ext(char *file_name);
void	parse_map(t_main *config, char *file_name);
char	*get_all_file(char *file_name);

// map_check.c
void	check_map(t_main *config, t_textures *textures);
int		check_wrong_point(t_main *config);
void	count_point(t_main *config, char point);
int		check_width(t_main *config);

// map_check_2.c
int		check_minimum_point(t_main *config);

// draw.c
void	draw_map(t_main *config, t_textures *textures);
void	draw_block(t_textures *textures, t_main *config, int x, int y);
#endif
