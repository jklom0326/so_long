/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shan <shan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:52:49 by shan              #+#    #+#             */
/*   Updated: 2022/07/04 16:52:49 by shan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_index(t_data *map, int *x, int *y)
{
	*y = 0;
	while (map->map[*y])
	{
		*x = 0;
		while (map->map[*y][*x])
		{
			if (map->map[*y][*x] == 'P')
				return ;
			(*x)++;
		}
		(*y)++;
	}
}

void	count_collect(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	data->c = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'C')
				data->c++;
			j++;
		}
		i++;
	}
	return ;
}

void	count_moves(t_data *data)
{
	int			x;
	int			y;
	static int	n;
	static int	w;

	get_index(data, &x, &y);
	if (n != x || w != y)
	{
		data->moves++;
		n = x;
		w = y;
		ft_putnbr_fd(data->moves, 1);
		write(1, "\n", 1);
	}
}

void	ft_game_msg(int n, t_data *data)
{
	if (n == 1)
	{
		write(1, "you win !\n", 11);
		ft_free_map(data);
		exit (0);
	}
}
