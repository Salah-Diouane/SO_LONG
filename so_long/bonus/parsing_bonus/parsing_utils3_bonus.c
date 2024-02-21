/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils3_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiouane <sdiouane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:20:49 by sdiouane          #+#    #+#             */
/*   Updated: 2024/01/28 00:15:39 by sdiouane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	ft_strstr(const char	*s, const char	*to_find)
{
	size_t	j;
	size_t	i;
	size_t	x;
	char	*str;

	i = 0;
	j = 0;
	x = 0;
	str = (char *)s;
	if (to_find[j] == 0)
		return (0);
	if (str == NULL)
		return (0);
	while (str[i++] != '\0')
	{
		while (str[i + j] == to_find[j] && str[i + j] != '\0')
		{
			j++;
			x = i;
		}
		if (to_find[j] == '\0' && str[x + j] == '\0')
			return (1);
		j = 0;
	}
	return (0);
}

void	flood_fill(char **map, int y, int x, int row)
{
	if (y < 0 || y >= ft_strlen(map[0]) || x < 0 || x >= row
		|| map[x][y] == '1' || map[x][y] == 'F' || map[x][y] == 'E'
			|| map[x][y] == 'N')
		return ;
	map[x][y] = 'F';
	flood_fill(map, y - 1, x, row);
	flood_fill(map, y + 1, x, row);
	flood_fill(map, y, x - 1, row);
	flood_fill(map, y, x + 1, row);
}

void	find_player(t_point	*p, char	**str)
{
	int	i;
	int	j;

	i = 0;
	while (str && str[i] != NULL)
	{
		j = 0;
		while (str[i][j] != '\0')
		{
			if (str[i][j] == 'P')
			{
				p->p_x = j;
				p->p_y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	find_exit(t_point	*p, char	**str)
{
	int	i;
	int	cmp;
	int	j;

	i = 0;
	cmp = 0;
	while (str[i] != NULL)
	{
		j = 0;
		while (str[i][j] != '\0')
		{
			if (str[i][j] == 'E')
			{
				p->e_x = j;
				p->e_y = i;
				cmp++;
				return ;
			}
			j++;
		}
		i++;
	}
}

int	valid(char	**res, int index)
{
	char	*line;
	int		i;

	i = 0;
	while (i < index)
	{
		line = res[i];
		while (*line != '\0')
		{
			if (*line == '0' || *line == 'C')
				return (0);
			line++;
		}
		i++;
	}
	return (1);
}
