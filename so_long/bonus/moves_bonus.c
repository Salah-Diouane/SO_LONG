/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiouane <sdiouane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 11:48:02 by sdiouane          #+#    #+#             */
/*   Updated: 2024/01/29 15:25:06 by sdiouane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	write_mouves(t_point	*tmp)
{
	char	*s;

	s = ft_itoa(tmp->moves);
	ft_printf("->Move Num : %s\n", s);
	mlx_put_image_to_window(tmp->mlx, tmp->win, tmp->wall, 0, 0);
	mlx_put_image_to_window(tmp->mlx, tmp->win, tmp->wall, 50, 0);
	mlx_string_put(tmp->mlx, tmp->win, 0, 0, 0x00000A, "Move Num : ");
	mlx_put_image_to_window(tmp->mlx, tmp->win, tmp->wall, 100, 0);
	mlx_string_put(tmp->mlx, tmp->win, 100, 0, 0x000000, s);
	free(s);
}

void	up(t_point	*tmp)
{
	mlx_put_image_to_window(tmp->mlx, tmp->win, tmp->space,
		tmp->p_x * 50, (tmp->p_y - 1) * 50);
	mlx_put_image_to_window(tmp->mlx, tmp->win, tmp->plyr_up,
		tmp->p_x * 50, (tmp->p_y - 1) * 50);
	mlx_put_image_to_window(tmp->mlx, tmp->win, tmp->space,
		tmp->p_x * 50, (tmp->p_y) * 50);
	mlx_do_sync(tmp->mlx);
	tmp->map[tmp->p_y][tmp->p_x] = '0';
	tmp->map[tmp->p_y - 1][tmp->p_x] = 'P';
	tmp->p_y--;
	tmp->moves++;
	write_mouves(tmp);
	if (tmp->nbr_coll == 0)
	{
		find_exit(tmp, tmp->map);
		mlx_put_image_to_window(tmp->mlx, tmp->win, tmp->exit2,
			tmp->e_x * 50, tmp->e_y * 50);
	}
}

void	down(t_point	*tmp)
{
	mlx_put_image_to_window(tmp->mlx, tmp->win, tmp->space,
		tmp->p_x * 50, (tmp->p_y + 1) * 50);
	mlx_put_image_to_window(tmp->mlx, tmp->win, tmp->plyr_down,
		tmp->p_x * 50, (tmp->p_y + 1) * 50);
	mlx_put_image_to_window(tmp->mlx, tmp->win,
		tmp->space, tmp->p_x * 50, (tmp->p_y) * 50);
	mlx_do_sync(tmp->mlx);
	tmp->map[tmp->p_y][tmp->p_x] = '0';
	tmp->map[tmp->p_y + 1][tmp->p_x] = 'P';
	tmp->p_y++;
	tmp->moves++;
	write_mouves(tmp);
	if (tmp->nbr_coll == 0)
	{
		find_exit(tmp, tmp->map);
		mlx_put_image_to_window(tmp->mlx, tmp->win, tmp->exit2,
			tmp->e_x * 50, tmp->e_y * 50);
	}
}

void	left(t_point *tmp)
{
	mlx_put_image_to_window(tmp->mlx, tmp->win, tmp->space,
		(tmp->p_x - 1) * 50, tmp->p_y * 50);
	mlx_put_image_to_window(tmp->mlx, tmp->win, tmp->plyr_left,
		(tmp->p_x - 1) * 50, tmp->p_y * 50);
	mlx_put_image_to_window(tmp->mlx, tmp->win,
		tmp->space, (tmp->p_x) * 50, tmp->p_y * 50);
	mlx_do_sync(tmp->mlx);
	tmp->map[tmp->p_y][tmp->p_x] = '0';
	tmp->map[tmp->p_y][tmp->p_x - 1] = 'P';
	tmp->p_x--;
	tmp->moves++;
	write_mouves(tmp);
	if (tmp->nbr_coll == 0)
	{
		find_exit(tmp, tmp->map);
		mlx_put_image_to_window(tmp->mlx, tmp->win, tmp->exit2,
			tmp->e_x * 50, tmp->e_y * 50);
	}
}

void	right(t_point *tmp)
{
	mlx_put_image_to_window(tmp->mlx, tmp->win, tmp->space,
		(tmp->p_x + 1) * 50, tmp->p_y * 50);
	mlx_put_image_to_window(tmp->mlx, tmp->win, tmp->plyr_right,
		(tmp->p_x + 1) * 50, tmp->p_y * 50);
	mlx_put_image_to_window(tmp->mlx, tmp->win, tmp->space,
		(tmp->p_x) * 50, tmp->p_y * 50);
	mlx_do_sync(tmp->mlx);
	tmp->map[tmp->p_y][tmp->p_x] = '0';
	tmp->map[tmp->p_y][tmp->p_x + 1] = 'P';
	tmp->p_x++;
	tmp->moves++;
	write_mouves(tmp);
	if (tmp->nbr_coll == 0)
	{
		find_exit(tmp, tmp->map);
		mlx_put_image_to_window(tmp->mlx, tmp->win, tmp->exit2,
			tmp->e_x * 50, tmp->e_y * 50);
	}
}
