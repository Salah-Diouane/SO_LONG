/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiouane <sdiouane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 10:41:05 by sdiouane          #+#    #+#             */
/*   Updated: 2024/01/28 00:07:22 by sdiouane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_game(void)
{
	ft_printf("You left my game !\n");
	exit(EXIT_SUCCESS);
}

void	first_draw(t_point *arg, int i, int j)
{
	if (arg->map[i][j] == '1')
		mlx_put_image_to_window(arg->mlx, arg->win,
			arg->wall, j * 50, i * 50);
	else if (arg->map[i][j] == '0')
		mlx_put_image_to_window(arg->mlx, arg->win, arg->space, j * 50, i * 50);
	else if (arg->map[i][j] == 'P')
		mlx_put_image_to_window(arg->mlx, arg->win,
			arg->plyr_down, j * 50, i * 50);
	else if (arg->map[i][j] == 'E')
		mlx_put_image_to_window(arg->mlx, arg->win, arg->exit1, j * 50, i * 50);
	else if (arg->map[i][j] == 'C')
	{
		mlx_put_image_to_window(arg->mlx, arg->win, arg->coll, j * 50, i * 50);
		arg->nbr_coll++;
	}
}

void	draw_map1(t_point	*arg)
{
	int	i;
	int	j;	

	i = -1;
	while (arg->map[++i] != NULL)
	{
		j = -1;
		while (arg->map[i][++j] != '\n' && arg->map[i][j])
		{
			first_draw(arg, i, j);
		}
	}
}

int	get_rows(char **str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

void	first_init(t_point *arg)
{
	arg->space = mlx_xpm_file_to_image(arg->mlx, "./mandatory/textr/space1.xpm",
			&arg->size, &arg->size);
	arg->plyr_down = mlx_xpm_file_to_image(arg->mlx,
			"./mandatory/textr/player1.xpm", &arg->size, &arg->size);
	arg->coll = mlx_xpm_file_to_image(arg->mlx,
			"./mandatory/textr/dimnd.xpm", &arg->size, &arg->size);
	arg->wall = mlx_xpm_file_to_image(arg->mlx, "./mandatory/textr/wall1.xpm",
			&arg->size, &arg->size);
	arg->exit1 = mlx_xpm_file_to_image(arg->mlx, "./mandatory/textr/close.xpm",
			&arg->size, &arg->size);
	arg->exit2 = mlx_xpm_file_to_image(arg->mlx, "./mandatory/textr/open.xpm",
			&arg->size, &arg->size);
	if ((!arg->space || !arg->plyr_down || !arg->coll || !arg->wall
			|| !arg->exit1 || !arg->exit2)
		&& ft_printf("invalid path for pictures !!\n"))
		exit(EXIT_FAILURE);
}
