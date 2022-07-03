/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shan <shan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 02:25:23 by shan              #+#    #+#             */
/*   Updated: 2022/07/04 02:25:23 by shan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    take_img(t_data *data)
{
    data->img_trainer = mlx_xpm_file_to_image(data->mlx_ptr, \
    "./img/img_trainer1,xpm", &data->a, &data->b);
    data->img_rival = mlx_xpm_file_to_image(data->mlx_ptr, \
		"./img/rival.xpm", &data->a, &data->b);
	data->img_cave_in = mlx_xpm_file_to_image(data->mlx_ptr, \
		"./img/img_cave_in.xpm", &data->a, &data->b);
	data->img_cave = mlx_xpm_file_to_image(data->mlx_ptr, \
		"./img/img_cave.xpm", &data->a, &data->b);
	data->img_monster_ball = mlx_xpm_file_to_image(data->mlx_ptr, \
		"./img/img_monster_ball.xpm", &data->a, &data->b);
	data->img_tree = mlx_xpm_file_to_image(data->mlx_ptr, \
		"./img/img_tree.xpm", &data->a, &data->b);
}

void    move_trainer(t_data *m)
{
    static int  i;
    static int  j;

    if (i % 10 == 0)
    {
        if (j)
        {
            j = 0;
            m->img_trainer = mlx_xpm_file_to_image(m->mlx_ptr, \
            "./img/img_trainer1.xpm", &m->a, &m->b);
        }
        else
        {
            j = 1;
            m->img_trainer = mlx_xpm_file_to_image(m->mlx_ptr, \
            "./img/img_trainer2.xpm", &m->a, &m->b);
        }   
    }    
    if (i == 100000)
        i = 0;
    i++;
}

void    draw_map(t_data *data, int j)
{
    if (data->map[data->i][j] == '1')
        mlx_xpm_file_to_window(data->mlx_ptr, data->mlx_win, \
        data->img_tree * 32, data->i * 32);
    if (data->map[data->i][j] == '0')
        mlx_xpm_file_to_window(data->mlx_ptr, data->mlx_win, \
        data->img_ground * 32, data->i * 32);
    if (data->map[data->i][j] == 'C')
        mlx_xpm_file_to_window(data->mlx_ptr, data->mlx_win, \
        data->img_monster_ball * 32, data->i * 32);
    if (data->map[data->i][j] == 'E')
        mlx_xpm_file_to_window(data->mlx_ptr, data->mlx_win, \
        data->img_cave * 32, data->i * 32);
    if (data->map[data->i][j] == 'P')
        mlx_xpm_file_to_window(data->mlx_ptr, data->mlx_win, \
        data->img_trainer * 32, data->i * 32);
} 