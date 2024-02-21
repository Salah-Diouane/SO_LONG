/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiouane <sdiouane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 21:57:43 by sdiouane          #+#    #+#             */
/*   Updated: 2024/01/30 00:45:49 by sdiouane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	move_w(t_point *tmp)
{
	if (tmp->map[tmp->p_y - 1][tmp->p_x] != '1' &&
			tmp->map[tmp->p_y -1][tmp->p_x] != 'E' &&
				tmp->map[tmp->p_y -1][tmp->p_x] != 'N')
	{
		if (tmp->map[tmp->p_y - 1][tmp->p_x] == 'C')
			tmp->nbr_coll--;
		up(tmp);
	}
	else if (tmp->map[tmp->p_y - 1][tmp->p_x] == 'E' && tmp->nbr_coll == 0)
	{
		ft_printf("    {YOU WIIIIN ✅}\n");
		exit(EXIT_SUCCESS);
	}
	else if (tmp->map[tmp->p_y - 1][tmp->p_x] == 'N')
		(ft_printf("    {YOU loss}\n"), exit(EXIT_FAILURE));
	else if (tmp->map[tmp->p_y - 1][tmp->p_x] == '1'
		|| tmp->map[tmp->p_y - 1][tmp->p_x] == 'E')
	{
		mlx_put_image_to_window(tmp->mlx, tmp->win, tmp->plyr_up, tmp->p_x * 50,
			tmp->p_y * 50);
		mlx_put_image_to_window(tmp->mlx, tmp->win, tmp->space, tmp->p_x * 50,
			tmp->p_y * 50);
		mlx_put_image_to_window(tmp->mlx, tmp->win, tmp->plyr_up, tmp->p_x * 50,
			tmp->p_y * 50);
	}
}

void	move_s(t_point *tmp)
{
	if (tmp->map[tmp->p_y + 1][tmp->p_x] != '1'
			&& tmp->map[tmp->p_y + 1][tmp->p_x] != 'E'
				&& tmp->map[tmp->p_y + 1][tmp->p_x] != 'N')
	{
		if (tmp->map[tmp->p_y + 1][tmp->p_x] == 'C')
			tmp->nbr_coll--;
		down(tmp);
	}
	else if (tmp->map[tmp->p_y + 1][tmp->p_x] == 'E' && tmp->nbr_coll == 0)
	{
		ft_printf("    {YOU WIIIIN ✅}\n");
		exit(EXIT_SUCCESS);
	}
	else if (tmp->map[tmp->p_y + 1][tmp->p_x] == 'N')
		(ft_printf("    {YOU loss}\n"), exit(EXIT_FAILURE));
	else if (tmp->map[tmp->p_y + 1][tmp->p_x] == '1'
		|| tmp->map[tmp->p_y + 1][tmp->p_x] == 'E')
	{
		mlx_put_image_to_window(tmp->mlx, tmp->win, tmp->plyr_down,
			tmp->p_x * 50, tmp->p_y * 50);
		mlx_put_image_to_window(tmp->mlx, tmp->win, tmp->space,
			tmp->p_x * 50, tmp->p_y * 50);
		mlx_put_image_to_window(tmp->mlx, tmp->win, tmp->plyr_down,
			tmp->p_x * 50, tmp->p_y * 50);
	}
}

void	move_a(t_point *tmp)
{
	if (tmp->map[tmp->p_y][tmp->p_x - 1] != '1'
			&& tmp->map[tmp->p_y][tmp->p_x - 1] != 'E'
				&& tmp->map[tmp->p_y][tmp->p_x - 1] != 'N')
	{
		if (tmp->map[tmp->p_y][tmp->p_x - 1] == 'C')
			tmp->nbr_coll--;
		left(tmp);
	}
	else if (tmp->map[tmp->p_y][tmp->p_x - 1] == 'E' && tmp->nbr_coll == 0)
	{
		ft_printf("    {YOU WIIIIN ✅}\n");
		exit(EXIT_SUCCESS);
	}
	else if (tmp->map[tmp->p_y][tmp->p_x - 1] == 'N')
		(ft_printf("    {YOU loss}\n"), exit(EXIT_FAILURE));
	else if (tmp->map[tmp->p_y][tmp->p_x - 1] == '1'
		|| tmp->map[tmp->p_y][tmp->p_x - 1] == 'E')
	{
		mlx_put_image_to_window(tmp->mlx, tmp->win, tmp->plyr_left,
			tmp->p_x * 50, tmp->p_y * 50);
		mlx_put_image_to_window(tmp->mlx, tmp->win, tmp->space,
			tmp->p_x * 50, tmp->p_y * 50);
		mlx_put_image_to_window(tmp->mlx, tmp->win, tmp->plyr_left,
			tmp->p_x * 50, tmp->p_y * 50);
	}
}

void	move_d(t_point *tmp)
{
	if (tmp->map[tmp->p_y][tmp->p_x + 1] != '1'
			&& tmp->map[tmp->p_y][tmp->p_x + 1] != 'E'
				&& tmp->map[tmp->p_y][tmp->p_x + 1] != 'N')
	{
		if (tmp->map[tmp->p_y][tmp->p_x + 1] == 'C')
			tmp->nbr_coll--;
		right(tmp);
	}
	else if (tmp->map[tmp->p_y][tmp->p_x + 1] == 'E' && tmp->nbr_coll == 0)
	{
		ft_printf("    {YOU WIIIIN ✅}\n");
		exit(EXIT_SUCCESS);
	}
	else if (tmp->map[tmp->p_y][tmp->p_x + 1] == 'N')
		(ft_printf("    {YOU loss}\n"), exit(EXIT_FAILURE));
	else if (tmp->map[tmp->p_y][tmp->p_x + 1] == '1'
		|| tmp->map[tmp->p_y][tmp->p_x + 1] == 'E')
	{
		mlx_put_image_to_window(tmp->mlx, tmp->win, tmp->plyr_right,
			tmp->p_x * 50, tmp->p_y * 50);
		mlx_put_image_to_window(tmp->mlx, tmp->win, tmp->space,
			tmp->p_x * 50, tmp->p_y * 50);
		mlx_put_image_to_window(tmp->mlx, tmp->win, tmp->plyr_right,
			tmp->p_x * 50, tmp->p_y * 50);
	}
}
