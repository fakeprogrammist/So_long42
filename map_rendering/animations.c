/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalyeon <sgalyeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 14:19:52 by akitty            #+#    #+#             */
/*   Updated: 2022/03/25 19:24:57 by sgalyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/game.h"

static int	player_animation(t_game *game, int x, int y)
{
	show_moves(game);
	if (game->game_over == TRUE)
	{
		ft_close(game);
	}
	mlx_put_image_to_window(game->mlx, game->window.reference,
		game->hero.img_current, x, y);
	return (1);
}

int	animations(t_game *game)
{
	mlx_clear_window(game->mlx, game->window.reference);
	draw_static_items(game);
	player_animation(game, game->hero.position.x, game->hero.position.y);
	return (1);
}
