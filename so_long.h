/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shan <shan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 14:02:17 by shan              #+#    #+#             */
/*   Updated: 2022/07/03 23:29:19 by shan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>
# include <fcntl.h>

typedef struct t_data
{
	char	**map
	int		c;
	int		p;
	int		e;
	int		z;
	int		i;
	int		a;
	int		b;
	int		moves;
	void	*img_ground;
	void	*img_monster_ball;
	void	*img_graves;
	void	*img_graves_in;
	void	*img_tree;
	void	*img_trainer1;
	void	*img_trainer2;
