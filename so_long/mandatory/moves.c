/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiouane <sdiouane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 11:48:02 by sdiouane          #+#    #+#             */
/*   Updated: 2024/01/28 20:08:31 by sdiouane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	up(t_point	**tmp)
{
	mlx_put_image_to_window((*tmp)->mlx, (*tmp)->win, (*tmp)->space,
		(*tmp)->p_x * 50, ((*tmp)->p_y - 1) * 50);
	mlx_put_image_to_window((*tmp)->mlx, (*tmp)->win, (*tmp)->plyr_down,
		(*tmp)->p_x * 50, ((*tmp)->p_y - 1) * 50);
	mlx_put_image_to_window((*tmp)->mlx, (*tmp)->win, (*tmp)->space,
		(*tmp)->p_x * 50, ((*tmp)->p_y) * 50);
	(*tmp)->map[(*tmp)->p_y][(*tmp)->p_x] = '0';
	(*tmp)->map[(*tmp)->p_y - 1][(*tmp)->p_x] = 'P';
	(*tmp)->p_y--;
	(*tmp)->moves++;
	ft_printf(" +-> Move Num |-> %d <-|\n", ((*tmp))->moves);
}

void	down(t_point	**tmp)
{
	mlx_put_image_to_window((*tmp)->mlx, (*tmp)->win, (*tmp)->space,
		(*tmp)->p_x * 50, ((*tmp)->p_y + 1) * 50);
	mlx_put_image_to_window((*tmp)->mlx, (*tmp)->win, (*tmp)->plyr_down,
		(*tmp)->p_x * 50, ((*tmp)->p_y + 1) * 50);
	mlx_put_image_to_window((*tmp)->mlx, (*tmp)->win,
		(*tmp)->space, (*tmp)->p_x * 50, ((*tmp)->p_y) * 50);
	(*tmp)->map[(*tmp)->p_y][(*tmp)->p_x] = '0';
	(*tmp)->map[(*tmp)->p_y + 1][(*tmp)->p_x] = 'P';
	(*tmp)->p_y++;
	(*tmp)->moves++;
	ft_printf(" +-> Move Num |-> %d <-|\n", ((*tmp))->moves);
}

void	left(t_point **tmp)
{
	mlx_put_image_to_window((*tmp)->mlx, (*tmp)->win, (*tmp)->space,
		((*tmp)->p_x - 1) * 50, (*tmp)->p_y * 50);
	mlx_put_image_to_window((*tmp)->mlx, (*tmp)->win, (*tmp)->plyr_down,
		((*tmp)->p_x - 1) * 50, (*tmp)->p_y * 50);
	mlx_put_image_to_window((*tmp)->mlx, (*tmp)->win,
		(*tmp)->space, ((*tmp)->p_x) * 50, (*tmp)->p_y * 50);
	(*tmp)->map[(*tmp)->p_y][(*tmp)->p_x] = '0';
	(*tmp)->map[(*tmp)->p_y][(*tmp)->p_x - 1] = 'P';
	(*tmp)->p_x--;
	(*tmp)->moves++;
	ft_printf(" +-> Move Num |-> %d <-|\n", ((*tmp))->moves);
}

void	right(t_point **tmp)
{
	mlx_put_image_to_window((*tmp)->mlx, (*tmp)->win, (*tmp)->space,
		((*tmp)->p_x + 1) * 50, (*tmp)->p_y * 50);
	mlx_put_image_to_window((*tmp)->mlx, (*tmp)->win, (*tmp)->plyr_down,
		((*tmp)->p_x + 1) * 50, (*tmp)->p_y * 50);
	mlx_put_image_to_window((*tmp)->mlx, (*tmp)->win, (*tmp)->space,
		((*tmp)->p_x) * 50, (*tmp)->p_y * 50);
	(*tmp)->map[(*tmp)->p_y][(*tmp)->p_x] = '0';
	(*tmp)->map[(*tmp)->p_y][(*tmp)->p_x + 1] = 'P';
	(*tmp)->p_x++;
	(*tmp)->moves++;
	ft_printf(" +-> Move Num |-> %d <-|\n", ((*tmp))->moves);
}
