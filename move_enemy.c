/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shan <shan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 02:32:20 by shan              #+#    #+#             */
/*   Updated: 2022/07/05 02:32:20 by shan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"so_long_bonus.h"

void	move_right(t_data *data)
{
	int	x;
	int	y;

	get_index_enemy(data, &x, &y);
	if (data->map[y][x + 1] != '1')
	{
		if (data->map[y][x + 1] == '0')
		{
			data->map[y][x + 1] = 'F';
			data->map[y][x] = '0';
		}
		if (data->map[y][x + 1] == 'P')
			ft_game_msg(2, data);
		if (data->map[y][x + 1] == 'C' || data->map[y][x + 1] == 'E')
			return ;
	}
}

void	move_left(t_data *data)
{
	int	x;
	int	y;

	get_index_enemy(data, &x, &y);
	if (data->map[y][x - 1] != '1')
	{
		if (data->map[y][x - 1] == '0')
		{
			data->map[y][x - 1] = 'F';
			data->map[y][x] = '0';
		}
		if (data->map[y][x - 1] == 'P')
			ft_game_msg(2, data);
		if (data->map[y][x - 1] == 'C' || data->map[y][x - 1] == 'E')
			return ;
	}
}

void	ft_enemy_move(t_data *data)
{
	static int	r;

	if (r == 100 || r == 150 || r == 200 || r == 250)
	{
		move_right(data);
	}
	else if (r == 300 || r == 350 || r == 400 || r == 450)
	{
		move_left(data);
	}
	r++;
	if (r == 451)
		r = 0;
}