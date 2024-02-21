/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiouane <sdiouane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 11:18:13 by sdiouane          #+#    #+#             */
/*   Updated: 2024/01/28 23:18:52 by sdiouane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdbool.h>
# include <mlx.h>
# include <stdarg.h>

# define A 0
# define S 1
# define D 2
# define W 13
# define KEY_ESC 53 

# define ARROW_UP 126
# define ARROW_DOWN 125
# define ARROW_LEFT 123
# define ARROW_RIGHT 124

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1337
# endif

typedef struct s_point
{
	int		e_x;
	int		e_y;
	int		x;
	int		y;

	int		p_x;	
	int		p_y;

	int		enm_x;
	int		enm_y;
	int		len;
	int		wdth;
	int		fd;
	void	*mlx;
	void	*win;
	int		size;

	void	*plyr_up;
	void	*plyr_down;
	void	*plyr_left;
	void	*plyr_right;

	void	*wall;
	void	*coll;
	void	*exit1;
	void	*exit2;
	void	*space;

	char	**map;
	char	*addr;
	int		*keys;
	int		nbr_coll;
	int		moves;
}	t_point;

// ft_printf
int		ft_putchar(char x);
int		ft_putnbr(long n, int base, int type);
int		ft_putstring(char *s);
int		ft_format(char c, va_list lst, int cmp);
int		ft_printf(const char *s, ...);

// get next line :
int		ft_strlen(char *s);
int		find(char *s, char c);
char	*ft_join(char *dest, char *s1, char *s2);
char	*ft_strjoin(char *start, char *buff);
char	*ft_read_line(char *s);
char	*get_next_line(int fd);
char	**ft_split(char const *s, char c);
void	ft_free_tab(char **tab);
char	*ft_strdup(char *s1);
char	*move_string(char *s);

// so_long :
char	**read_map(int fd);
int		check_first_line(char *str);
int		valid_or_invalid_map(char *res);
int		valid_path(char *res);
int		check_all_lines(char	**res);
int		find_caractere(char **str, char c);
int		count_char(char **map);
int		extremites(char **map, int len);
void	find_player(t_point *p, char **str);
void	find_exit(t_point *p, char **str);
int		contains_only_ones(char *str);
void	check_lines_of_map(t_point *arg, int i);
void	check_valid_path(t_point *arg);
void	check_elements_of_map(t_point *arg);
void	initia_mlx(t_point *arg);
void	first_init(t_point *arg);
void	draw_map1(t_point	*arg);
int		get_rows(char **str);
int		ft_strstr(const char	*s, const char	*to_find);
void	ber_check(char *map);
int		exit_game(void);

//moves :
void	up(t_point **tmp);
void	down(t_point **tmp);
void	left(t_point **tmp);
void	right(t_point **tmp);
void	move_w(t_point *tmp);
void	move_s(t_point *tmp);
void	move_a(t_point *tmp);
void	move_d(t_point *tmp);
void	flood_fill(char **map, int x, int y, int row);

#endif