/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiouane <sdiouane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 15:01:34 by sdiouane          #+#    #+#             */
/*   Updated: 2024/01/27 02:45:47 by sdiouane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	check_flood_fill(char	**tmp)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tmp[i])
	{
		j = 0;
		while (tmp[i][j])
		{
			if ((tmp[i][j] == 'C' || tmp[i][j] == 'E')
			&& (tmp[i - 1][j] != 70 && tmp[i + 1][j] != 70
			&& tmp[i][j + 1] != 70 && tmp[i][j - 1] != 70))
			{
				ft_printf("Invalid Path !\n");
				exit (EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
}

void	check_lines_of_map(t_point *arg, int i)
{
	if (check_all_lines((*arg).map) == 0)
	{
		ft_printf("invalid map (first line must be equal all) \n");
		exit (EXIT_FAILURE);
	}
	if (check_first_line((*arg).map[0]) == 0)
	{
		ft_printf("invalid map (in first line) \n");
		exit (EXIT_FAILURE);
	}
	if (contains_only_ones((*arg).map[i]) == 0)
	{
		ft_printf("invalid map (in last line) \n");
		exit (EXIT_FAILURE);
	}
}

void	check_elements_of_map(t_point	*arg)
{
	int	i;

	if (find_caractere((*arg).map, 'P') == 0
		&& ft_printf("invalid map !(player) \n"))
		exit (EXIT_FAILURE);
	if (find_caractere((*arg).map, 'E') == 0
		&& ft_printf("invalid map !(exit) \n"))
		exit (EXIT_FAILURE);
	if (count_char((*arg).map) == 0
		&& ft_printf("invalid map !(collectins) \n"))
		exit (EXIT_FAILURE);
	if (extremites((*arg).map, (*arg).wdth) == 0
		&& ft_printf("invalid map !(borders) \n"))
		exit (EXIT_FAILURE);
	i = -1;
	while ((*arg).map[++i] != NULL)
	{
		if (valid_or_invalid_map((*arg).map[i]) == 0)
		{
			ft_printf("invalid map !(1, 0, P, C, E, N) \n");
			exit (EXIT_FAILURE);
		}
	}
}

void	ft_free_tab2(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	check_valid_path(t_point *arg)
{
	char	**tmp;
	int		i;

	find_player(arg, arg->map);
	tmp = (char **)malloc(sizeof(char *) * (arg->len + 1));
	if (!tmp)
	{
		ft_free_tab2(tmp);
		return ;
	}
	i = -1;
	while (arg->map[++i])
	{
		tmp[i] = ft_strdup(arg->map[i]);
		if (!tmp[i])
		{
			ft_free_tab2(tmp);
			return ;
		}
	}
	tmp[arg->len] = NULL;
	flood_fill(tmp, arg->p_x, arg->p_y, arg->len);
	check_flood_fill(tmp);
	ft_free_tab2(tmp);
}
