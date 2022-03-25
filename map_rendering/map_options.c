/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_options.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalyeon <sgalyeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 18:54:55 by sgalyeon          #+#    #+#             */
/*   Updated: 2022/03/24 20:06:53 by sgalyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/game.h"

static int	write_in_array(char ***map, char *str)
{
	int	coins;
	int	k;
	int	j;

	coins = 0;
	k = 0;
	j = 0;
	while (*str)
	{
		if (*str == '\n')
		{
			j = 0;
			k++;
			str++;
		}
		if (*str == 'C')
			coins++;
		(*map)[k][j++] = *str;
		str++;
	}
	(*map)[k + 1] = 0;
	return (coins);
}

static int	create_arr(t_map *map_params)
{
	char	**map;
	int		rows;
	int		cols;

	rows = map_params->rows;
	cols = map_params->cols;
	map = (char **)malloc((rows + 1) * cols);
	if (!map)
		return (0);
	while (rows-- > 0)
	{
		map[rows] = (char *)malloc(cols);
		map[rows][cols] = '\0';
		if (!map[rows])
			return (0);
	}
	map_params->coins = write_in_array(&map, map_params->map_str);
	free(map_params->map_str);
	map_params->map_str = NULL;
	map_params->map_arr = map;
	return (1);
}

static void	player_setup(t_game *game)
{
	int		x;
	int		y;

	game->moves = 0;
	game->hero.collected = 0;
	game->game_over = FALSE;
	y = -1;
	while (game->map_params->map_arr[++y])
	{
		x = -1;
		while (game->map_params->map_arr[y][++x])
		{
			if (game->map_params->map_arr[y][x] == 'P')
			{
				game->hero.position.x = x * game->sprite_size.x;
				game->hero.position.y = y * game->sprite_size.y;
				return ;
			}
		}
	}
}

void	map_options(t_game *game, char *filename)
{
	t_map	*map_options;

	map_options = NULL;
	game->death_timer = 0;
	game->anime_timer = 0;
	game->error_msg = "Normal closure. Good bye!\n";
	map_options = check_map(filename);
	if (!map_options
		|| !create_arr(map_options))
	{
		game->error_msg = "Error.\nFail during setting map. Ciao!\n";
		perror("System error");
		ft_close(game);
	}
	game->map_params = map_options;
	player_setup(game);
}
