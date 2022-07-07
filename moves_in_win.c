/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_in_win.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shan <shan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 02:32:35 by shan              #+#    #+#             */
/*   Updated: 2022/07/05 02:32:35 by shan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long_bonus.h"

static	long int	ft_len(long n)
{
	int	i;

	i = 0;
	if (n <= 0)
	{
		n = n * -1 ;
		i++;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int			len;
	char		*b;
	long		l;

	l = n;
	len = ft_len(l);
	b = (char *)malloc((len + 1) * sizeof(char));
	if (!b)
		return (NULL);
	b[len--] = '\0';
	if (l == 0)
		b[0] = '0';
	if (l < 0)
	{
		b[0] = '-';
		l = l * -1;
	}
	while (l > 0)
	{
		b[len--] = (l % 10) + 48;
		l = l / 10;
	}
	return (b);
}

void	move_in_win(t_data *data)
{
	char	*s;

	s = ft_itoa(data->moves);
	mlx_string_put(data->mlx_ptr, data->mlx_win, 24, 36, 0xFF0000, s);
	free(s);
}