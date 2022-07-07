/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_key_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shan <shan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 02:22:59 by shan              #+#    #+#             */
/*   Updated: 2022/07/07 02:22:59 by shan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	encounter_cave(t_data *map, int *c)
{
	int		x;
	int		y;

	get_index(map, &x, &y);
	if (*c == 0)
		map->cave = map->cave_in;
	if (map->map[y][x - 1] == 'C')
	{
		map->map[y][x - 1] = 'P';
		map->map[y][x] = '0';
		count_moves(map);
		(*c)--;
	}
	if (map->map[y][x - 1] == '0')
	{
		map->map[y][x - 1] = 'P';
		map->map[y][x] = '0';
		count_moves(map);
	}
	if (map->map[y][x - 1] == 'E')
	{
		if(*c == 0)
			ft_game_msg(1, map);
		else
		{
			map->map[y][x - 1] = 'P';
			map->map[y][x] = 'E';
			count_moves(map);
		}
	}
}