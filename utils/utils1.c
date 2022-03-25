/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalyeon <sgalyeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 18:25:15 by sgalyeon          #+#    #+#             */
/*   Updated: 2022/03/25 19:00:06 by sgalyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/game.h"

void	free_map(t_map *map_params)
{
	int	rows;

	rows = map_params->rows;
	if (map_params->map_str)
		free(map_params->map_str);
	if (map_params->map_arr)
	{
		while (--rows >= 0)
			free(map_params->map_arr[rows]);
		free(map_params->map_arr);
	}
}

int	ft_close(t_game *game)
{
	if (game)
	{
		if (game->map_params)
		{
			if (game->map_params)
				free_map(game->map_params);
			free(game->map_params);
		}
	}
	ft_destroy_window(game);
	printf("%s", game->error_msg);
	exit(0);
	return (0);
}

void	show_moves(t_game *game)
{
	char	*moves;

	moves = ft_itoa(game->moves);
	if (!moves)
		ft_close(game);
	mlx_string_put(game->mlx, game->window.reference, 10,
		game->window.size.y - 30, 0xccccff, "Moves: ");
	mlx_string_put(game->mlx, game->window.reference, 90,
		game->window.size.y - 30, 0xccccff, moves);
	free(moves);
}
