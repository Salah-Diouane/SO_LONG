/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiouane <sdiouane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:19:02 by sdiouane          #+#    #+#             */
/*   Updated: 2024/01/28 20:49:05 by sdiouane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	row_size(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

char	**read_map(int fd)
{
	char	*line;
	char	*tmp;
	char	**all;

	line = NULL;
	tmp = get_next_line(fd);
	while (tmp)
	{
		if (*tmp == '\n' || *tmp == ' ')
		{
			ft_printf("Invalid Map !!");
			exit(EXIT_FAILURE);
		}
		line = ft_strjoin(line, tmp);
		free(tmp);
		tmp = get_next_line(fd);
	}
	all = ft_split(line, '\n');
	free(line);
	return (all);
}

int	check_first_line(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '1')
			i++;
		else
			return (0);
	}
	return (1);
}

int	contains_only_ones(char	*str)
{
	while (*str != '\0')
	{
		if (*str != '1')
			return (0);
		str++;
	}
	return (1);
}

int	valid_or_invalid_map(char *res)
{
	int	i;

	i = 0;
	while (res[i])
	{
		if (res[i] == '1' || res[i] == '0' || res[i] == 'P' || res[i] == 'C'
			|| res[i] == 'E')
			i++;
		else
			return (0);
	}
	return (1);
}
