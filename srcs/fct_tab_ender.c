/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_tab_ender.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:40:17 by maskedduck        #+#    #+#             */
/*   Updated: 2022/04/16 13:36:01 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	fct_tab_error(t_mast *ee, char *line, int i)
{
	(void)ee;
	(void)line;
	(void)i;
	return (-190);
}

int	fct_tab_map(t_mast *ee, char *line, int i)
{
	if (line[i] == '0')
		return (-96);
	if (!(ee->sp.n.img && ee->sp.s.img && ee->sp.e.img && ee->sp.w.img))
		return (-205);
	return (parsing_map(ee, line, i));
}

void	destroy_sprites(t_mast *ee)
{
	if (ee->sp.n.img)
		mlx_destroy_image(ee->mlx, ee->sp.n.img);
	if (ee->sp.s.img)
		mlx_destroy_image(ee->mlx, ee->sp.s.img);
	if (ee->sp.e.img)
		mlx_destroy_image(ee->mlx, ee->sp.e.img);
	if (ee->sp.w.img)
		mlx_destroy_image(ee->mlx, ee->sp.w.img);
}
