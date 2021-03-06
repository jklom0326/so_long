/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shan <shan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 17:33:45 by shan              #+#    #+#             */
/*   Updated: 2022/07/10 23:34:49 by shan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	ft_check_countent(char *s, t_data *map)
{
	map->c = 0;
	map->p = 0;
	map->e = 0;
	map->i = 0;
	map->z = 0;
	while (s[map->i])
	{
		if (s[map->i] != 'P' && s[map->i] != 'C' && s[map->i] != 'E' \
				&& s[map->i] != '1' && s[map->i] != '0' && s[map->i] != '\n')
			return (1);
		if (s[map->i] == 'P')
			map->p++;
		if (s[map->i] == 'C')
			map->c++;
		if (s[map->i] == '0')
			map->z++;
		if (s[map->i] == 'E')
			map->e++;
		map->i++;
	}
	if (map->p != 1 || map->e == 0 || map->c == 0)
		return (1);
	return (0);
}

int	ft_check_wall(char **map, int *k)
{
	int		i;
	int		j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[0][j])
		{
			if (map[0][j] != '1' || map[i][0] != '1')
				return (1);
			if (map[*k - 1][j] != '1')
				return (1);
			if (map[i][ft_strlen(*map) - 1] != '1')
				return (1);
			if (ft_strlen(map[i]) - 1 != ft_strlen(map[*k - 1]) - 1)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_check_map(char **map, char *s)
{
	int		i;
	int		c;
	t_data	m;

	i = 0;
	c = ft_count_line(s) + 1;
	while (map[i])
		i++;
	if (i != c)
		return (1);
	if (ft_check_wall(map, &c))
		return (1);
	if (ft_check_countent(s, &m))
		return (1);
	return (0);
}

char	**ft_read_map(int fd)
{
	char	*buf;
	char	*s;
	t_data	m;

	buf = (char *)malloc(sizeof(char) * (2));
	if (!buf)
		return (NULL);
	m.c = 1;
	while (m.c > 0)
	{
		m.c = read(fd, buf, 1);
		if (m.c == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[m.c] = '\0';
		s = ft_strjoin(s, buf);
	}
	free(buf);
	m.map = ft_split(s, '\n');
	if (ft_check_map(m.map, s))
		ft_error(2);
	free(s);
	return (m.map);
}
