/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiouane <sdiouane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 21:57:43 by sdiouane          #+#    #+#             */
/*   Updated: 2024/01/30 00:41:57 by sdiouane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_w(t_point *tmp)
{
	if (tmp->map[tmp->p_y - 1][tmp->p_x] != '1' &&
			tmp->map[tmp->p_y -1][tmp->p_x] != 'E')
	{
		if (tmp->map[tmp->p_y - 1][tmp->p_x] == 'C')
			tmp->nbr_coll--;
		up(&tmp);
		if (tmp->nbr_coll == 0)
		{
			find_exit(tmp, tmp->map);
			mlx_put_image_to_window(tmp->mlx, tmp->win, tmp->exit2,
				tmp->e_x * 50, tmp->e_y * 50);
		}
	}
	else if (tmp->map[tmp->p_y - 1][tmp->p_x] == 'E' && tmp->nbr_coll == 0)
	{
		ft_printf("    {YOU WIIIIN ✅}\n");
		exit(0);
	}
}

void	move_s(t_point *tmp)
{
	if (tmp->map[tmp->p_y + 1][tmp->p_x] != '1'
			&& tmp->map[tmp->p_y + 1][tmp->p_x] != 'E')
	{
		if (tmp->map[tmp->p_y + 1][tmp->p_x] == 'C')
			tmp->nbr_coll--;
		down(&tmp);
		if (tmp->nbr_coll == 0)
		{
			find_exit(tmp, tmp->map);
			mlx_put_image_to_window(tmp->mlx, tmp->win, tmp->exit2,
				tmp->e_x * 50, tmp->e_y * 50);
		}
	}
	else if (tmp->map[tmp->p_y + 1][tmp->p_x] == 'E' && tmp->nbr_coll == 0)
	{
		ft_printf("    {YOU WIIIIN ✅}\n");
		exit(0);
	}
}

void	move_a(t_point *tmp)
{
	if (tmp->map[tmp->p_y][tmp->p_x - 1] != '1'
			&& tmp->map[tmp->p_y][tmp->p_x - 1] != 'E')
	{
		if (tmp->map[tmp->p_y][tmp->p_x - 1] == 'C')
			tmp->nbr_coll--;
		left(&tmp);
		if (tmp->nbr_coll == 0)
		{
			find_exit(tmp, tmp->map);
			mlx_put_image_to_window(tmp->mlx, tmp->win, tmp->exit2,
				tmp->e_x * 50, tmp->e_y * 50);
		}
	}
	else if (tmp->map[tmp->p_y][tmp->p_x - 1] == 'E' && tmp->nbr_coll == 0)
	{
		ft_printf("    {YOU WIIIIN ✅}\n");
		exit(0);
	}
}

void	move_d(t_point *tmp)
{
	if (tmp->map[tmp->p_y][tmp->p_x + 1] != '1'
			&& tmp->map[tmp->p_y][tmp->p_x + 1] != 'E')
	{
		if (tmp->map[tmp->p_y][tmp->p_x + 1] == 'C')
			tmp->nbr_coll--;
		right(&tmp);
		if (tmp->nbr_coll == 0)
		{
			find_exit(tmp, tmp->map);
			mlx_put_image_to_window(tmp->mlx, tmp->win, tmp->exit2,
				tmp->e_x * 50, tmp->e_y * 50);
		}
	}
	else if (tmp->map[tmp->p_y][tmp->p_x + 1] == 'E' && tmp->nbr_coll == 0)
	{
		ft_printf("    {YOU WIIIIN ✅}\n");
		exit(0);
	}
}
