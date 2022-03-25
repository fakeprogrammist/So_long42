/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalyeon <sgalyeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 18:15:35 by sgalyeon          #+#    #+#             */
/*   Updated: 2022/03/24 18:50:05 by sgalyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/game.h"

static void	coins_handler(t_game *game)
{
	game->hero.collected += 1;
	game->map_params->map_arr[game->hero.position.y / 60]
	[game->hero.position.x / 60] = '0';
	if (game->hero.collected == game->map_params->coins)
	{
		game->exit_current = game->open_exit.reference;
		game->hero.exit_available = TRUE;
	}
}

static void	exit_handler(t_game *game)
{
	printf("VICTORY! New adventures await you.\n");
	ft_close(game);
}

int	handler_moves(t_game *game, char *next_pos)
{
	if (*next_pos == 'E' && game->hero.exit_available == TRUE)
		exit_handler(game);
	else if (*next_pos != '1' && *next_pos != 'E')
	{
		if (*next_pos == 'C')
		{
			coins_handler(game);
			*next_pos = '0';
		}
	}
	else if (*next_pos == '1' || *next_pos == 'E')
		return (0);
	++game->moves;
	return (1);
}
