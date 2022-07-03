/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shan <shan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 14:02:17 by shan              #+#    #+#             */
/*   Updated: 2022/07/04 01:15:47 by shan             ###   ########.fr       */
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
	void	*img_cave;
	void	*img_cave_in;
	void	*img_tree;
	void	*img_trainer1;
	void	*img_trainer2;
	void	*mlx_ptr;
	void	*mlx_win;
}t_data;

char	*get_next_line(int fd);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlcpy(char *dst, char const *src, size_t dstsize);
size_t	ft_strlen(char const *s);
char	ft_strchar(char *s, int c);
