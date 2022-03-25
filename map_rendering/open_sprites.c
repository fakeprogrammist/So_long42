/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalyeon <sgalyeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 18:55:01 by sgalyeon          #+#    #+#             */
/*   Updated: 2022/03/25 18:59:32 by sgalyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/game.h"

static int	another_sprites(t_game *game)
{
	game->background.reference = mlx_xpm_file_to_image(game->mlx,
			"sprites/bg0.xpm",
			&(game->sprite_size.x), &(game->sprite_size.y));
	game->walls.reference = mlx_xpm_file_to_image(game->mlx,
			"sprites/wall0.xpm",
			&(game->sprite_size.x), &(game->sprite_size.y));
	game->exit.reference = mlx_xpm_file_to_image(game->mlx,
			"sprites/portal/portal0.xpm",
			&(game->sprite_size.x), &(game->sprite_size.y));
	game->gems.reference = mlx_xpm_file_to_image(game->mlx,
			"sprites/gem.xpm",
			&(game->sprite_size.x), &(game->sprite_size.y));
	game->exit_current = game->exit.reference;
	if (!game->background.reference
		|| !game->walls.reference
		|| !game->exit.reference
		|| !game->gems.reference)
		return (0);
	return (1);
}

void	open_sprites(t_game *game)
{
	if (!another_sprites(game))
	{
		game->error_msg = "Error.\nFail during opening sprites. Arrivederci!\n";
		ft_close(game);
	}
	open_player_sprites(game);
}
