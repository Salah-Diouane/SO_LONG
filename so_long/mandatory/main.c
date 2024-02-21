/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiouane <sdiouane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 22:15:33 by sdiouane          #+#    #+#             */
/*   Updated: 2024/01/31 13:08:43 by sdiouane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map_lenght(t_point *tmp)
{
	if (get_rows(tmp->map) > 163)
	{
		ft_printf("Map too large\n");
		exit(EXIT_FAILURE);
	}
	if (tmp->wdth > 163)
	{
		ft_printf("Map too large\n");
		exit(EXIT_FAILURE);
	}
}

int	key_hook(int key, t_point	*tmp)
{
	if (key == 13 || key == 126)
		move_w(tmp);
	else if (key == 1 || key == 125)
		move_s(tmp);
	else if (key == 0 || key == 123)
		move_a(tmp);
	else if (key == 2 || key == 124)
		move_d(tmp);
	if (key == 53)
		exit(0);
	return (0);
}

void	initia_mlx(t_point *arg)
{
	int	i;

	if (!arg->map && ft_printf("NULL map\n"))
		exit(EXIT_FAILURE);
	find_player(arg, arg->map);
	arg->nbr_coll = 0;
	arg->moves = 0;
	arg->mlx = mlx_init();
	if (!arg->mlx && ft_printf("arg->mlx is NULL\n"))
		exit(EXIT_FAILURE);
	arg->size = 50;
	i = get_rows(arg->map);
	check_map_lenght(arg);
	arg->win = mlx_new_window(arg->mlx, arg->size * arg->wdth,
			arg->size * i, "");
	if (!arg->win && ft_printf("arg->mlx is NULL\n"))
		exit(EXIT_FAILURE);
	first_init(arg);
	draw_map1(arg);
	mlx_hook(arg->win, 2, 0, key_hook, arg);
	mlx_hook(arg->win, 17, 0, exit_game, arg);
	mlx_loop(arg->mlx);
}

void	ber_check(char *map)
{
	if (ft_strlen(map) <= 4
		&& ft_printf("Name should be something then '.ber'\n"))
		exit(EXIT_FAILURE);
	if (ft_strstr(map, ".ber") == 0
		&& ft_printf("Format should be '.ber'\n"))
		exit(EXIT_FAILURE);
}

int	main(int arc, char **arv)
{
	t_point	arg;
	int		fd;

	if (arc == 2)
	{
		ber_check(arv[1]);
		fd = open(arv[1], O_RDONLY, 0777);
		if (fd < 0)
			exit (write(1, "FD error\n", 9));
		arg.map = read_map(fd);
		if ((!arg.map || !arg.map[0]) && ft_printf("NULL Map\n"))
			exit(EXIT_FAILURE);
		arg.wdth = ft_strlen(arg.map[0]);
		arg.len = get_rows(arg.map);
		check_lines_of_map(&arg, arg.len - 1);
		check_valid_path(&arg);
		check_elements_of_map(&arg);
		initia_mlx(&arg);
	}
	else
		ft_printf("Just two parametre!\n");
	return (0);
}
