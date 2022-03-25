/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_player_sprites.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalyeon <sgalyeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 18:54:58 by sgalyeon          #+#    #+#             */
/*   Updated: 2022/03/25 18:59:20 by sgalyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/game.h"

static int	sprites(t_game *game)
{
	game->hero.up_sprites.img_0 = mlx_xpm_file_to_image(game->mlx,
			"sprites/character/character0.xpm",
			&(game->sprite_size.x), &(game->sprite_size.y));
	if (!game->hero.up_sprites.img_0)
		return (0);
	return (1);
}

void	open_player_sprites(t_game *game)
{
	if (!sprites(game))
	{
		game->error_msg
			= "Error.\nFail during opening player's sprites. Arrivederci!\n";
		ft_close(game);
	}
	game->hero.refs_current = &game->hero.up_sprites;
	game->hero.img_current = game->hero.up_sprites.img_0;
}
