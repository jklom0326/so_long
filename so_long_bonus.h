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
#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include "./minilibx-linux/mlx.h"
# include <fcntl.h>
typedef struct t_data
{
	char	**map;
	int		c;
	int		p;
	int		e;
	int		z;
	int		i;
	int		a;
	int		b;
	int		moves;
	void	*ground;
	void	*trainer;
	void	*rival;
	void	*cave;
	void	*cave_in;
	void	*tree;
	void	*monster_ball;
	void	*mlx_ptr;
	void	*mlx_win;
}t_data;

char	*ft_itoa(int n);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const	char *s);
char	*ft_strchr(char *s, int c);
char	*ft_strrchr(const char *s, int c);
void	ft_putstr(char *s);
int		ft_count_line(char *s);
int		ft_strcmp(char *s, char *p);
void	ft_error(int n);
int		ft_exit(t_data *data);
void	ft_free_map(t_data *data);
void	ft_game_msg(int n, t_data *data);
char	**ft_read_map(int fd);
int		ft_check_map(char **map, char *s);
int		ft_check_walles(char **map, int *k);
int		ft_check_countent(char *s, t_data *map);
int		ft_mapelines(t_data *n);
void	get_index(t_data *map, int *x, int *y);
void	take_img(t_data *data);
int		draw_map(t_data *data);
void	draw_map_2(t_data *data, int j);
void	move_player(t_data *m);
int		take_key(int key, t_data *m);
void	get_index(t_data *map, int *x, int *y);
void	count_collect(t_data *data);
void	count_moves(t_data *data);
void	key_0(t_data *map, int *c);
void	key_1(t_data *map, int *c);
void	key_2(t_data *map, int *c);
void	key_13(t_data *map, int *c);
void	move_in_win(t_data *data);
void	get_index_enemy(t_data *map, int *x, int *y);
void	ft_enemy_move(t_data *data);
int		check_all(char *s, t_data *map);
#endif