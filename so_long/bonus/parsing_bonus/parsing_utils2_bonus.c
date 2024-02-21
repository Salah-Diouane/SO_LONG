/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils2_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiouane <sdiouane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:20:11 by sdiouane          #+#    #+#             */
/*   Updated: 2024/01/28 07:31:09 by sdiouane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	valid_path(char	*res)
{
	int	i;

	i = 0;
	while (res[i] != '\0')
	{
		if (res[i] == '0' || res[i] == 'C')
			return (0);
		else
			i++;
	}
	return (1);
}

int	check_all_lines(char	**res)
{
	int	len;
	int	i;
	int	len_case;

	i = 1;
	len = ft_strlen(res[0]);
	while (res[i] != NULL)
	{
		len_case = ft_strlen(res[i]);
		if (len != len_case)
			return (0);
		i++;
	}
	return (1);
}

int	find_caractere(char **str, char c)
{
	int	i;
	int	cmp;
	int	j;

	cmp = 0;
	i = 0;
	while (str[i] != NULL)
	{
		j = 0;
		while (str[i][j] != '\0')
		{
			if (str[i][j] == c)
			{
				cmp++;
				if (cmp > 1)
					return (0);
			}
			j++;
		}
		i++;
	}
	return (cmp == 1);
}

int	count_char(char **map)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	i = 0;
	j = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int	extremites(char **map, int len)
{
	int	i;

	i = 1;
	while (map[i] != NULL)
	{
		if (map[i][0] != '1' || map[i][len - 1] != '1')
		{
			return (0);
		}
		i++;
	}
	return (1);
}
