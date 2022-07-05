/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shan <shan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:52:53 by shan              #+#    #+#             */
/*   Updated: 2022/07/04 16:52:53 by shan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"so_long_bonus.h"

int	check_all(char *s, t_data *map)
{
	if (s[map->i] != 'P' && s[map->i] != 'C' && s[map->i] != 'E' && s[map->i] \
	!= '1' && s[map->i] != '0' && s[map->i] != '\n' && s[map->i] != 'F')
		return (1);
	return (0);
}

int	ft_count_line(char *s)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			c++;
		i++;
	}
	return (c);
}

int	ft_mapelines(t_data *n)
{
	int	i;

	i = 0;
	while (n->map[i])
	{
		i++;
	}
	return (i);
}

int	ft_strcmp(char *s, char *p)
{
	int	i;

	i = 0;
	while (s[i] && p[i] && s[i] == p[i])
		i++;
	return (s[i] - p[i]);
}

void	ft_error(int n)
{
	if (n == 1)
		write(2, "Error in fd\n", 13);
	if (n == 2)
		write(2, "Error in map\n", 13);
	if (n == 3)
		write(2, "Error in path\n", 15);
	exit(1);
}